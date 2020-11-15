/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RIC Micropython
//
// Rob Dobson 2016-20
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Micropython.h"

#include "esp_system.h"
#include "esp_task.h"
#include "soc/cpu.h"
#include "esp_log.h"

#ifdef __cplusplus  
extern "C" { 
#endif
#include "py/mperrno.h"
#include "py/runtime.h"
#include "py/stackctrl.h"
#include "py/gc.h"
#include "py/lexer.h"
#include "mphal.h"
#include "lib/mp-readline/readline.h"
#include "lib/utils/pyexec.h"
#include "esp32/spiram.h"
#ifdef __cplusplus 
} 
#endif 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Consts and Statics
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Logging
static const char* MODULE_PREFIX = "uPy";

// Debug
// #define MICROPYTHON_DEBUG_SUBSCRIPTIONS

// This will be set when start() is called
uint32_t Micropython::_mpSubThreadStackSize = 0;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Constructor / Destructor
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Micropython::Micropython()
{
    mp_main_task_handle = NULL;
    _isStarted = false;
    _isPythonProgramRunning = false;

    // Event callback
    _eventCallback = mp_const_none;
}

Micropython::~Micropython()
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Start
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Micropython::start(bool useSPIRAM, bool useAllStdHeapAvail, uint32_t maxHeapToUse, 
            uint32_t taskPriority, uint32_t taskStackSize)
{
    if (_isStarted)
        return;
    _useSPIRAM = useSPIRAM;
    _useAllStdHeapAvail = useAllStdHeapAvail;
    _maxHeapToUse = maxHeapToUse;
    _mpSubThreadStackSize = taskStackSize;

    // Start task
    xTaskCreatePinnedToCore(mp_task, "mp_task", taskStackSize, this, 
                    taskPriority, &mp_main_task_handle, MP_TASK_COREID);

    // Started
    _isStarted = true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Stop
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Micropython::stopExecution(bool clearQueue, bool stopExisting)
{
    ESP_LOGI(MODULE_PREFIX, "stopExecution clearQueue %d stopExisting %d isRunning %d",
            clearQueue, stopExisting, _isPythonProgramRunning);

    // Clear queue if required
    if (clearQueue)
        _execQueue.clear();

    // Request stop running task
    if (_isPythonProgramRunning && stopExisting)
        mp_keyboard_interrupt();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Add to queue
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Micropython::addToQueue(const char* pyStr, bool clearQueue, bool stopExisting)
{
    // Handle stopping
    stopExecution(clearQueue, stopExisting);

    // Add to queue
    MicropyExecTask task(pyStr, true);
    _execQueue.put(task);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Register event callback
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Micropython::regEventCallback(void* callbackObj)
{
    ESP_LOGI(MODULE_PREFIX, "regEventCallback");
    _eventCallback = callbackObj;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Pass event to micropython - calls callback if specified
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Micropython::performEventCallback(const char* pJsonStr)
{
    mp_obj_t callbackObj = MP_OBJ_FROM_PTR(_eventCallback);
    if (callbackObj != mp_const_none) 
    {
        mp_obj_t arg = mp_obj_new_str(pJsonStr, strlen(pJsonStr)); 
        // ESP_LOGI(MODULE_PREFIX, "performEventCallback %p", MP_OBJ_TO_PTR(arg));
        mp_sched_schedule(callbackObj, arg);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Micropython task
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Micropython::mp_task(void *pvParameter)
{
    Micropython* pThis = (Micropython*)pvParameter;
    volatile uint32_t sp = (uint32_t)get_sp();

#if MICROPY_PY_THREAD
    mp_thread_init(pxTaskGetStackStart(NULL), _mpSubThreadStackSize / sizeof(uintptr_t));
#endif

    // Check memory to use
    uint8_t* mp_task_heap = NULL;
    size_t mp_task_heap_size = 0;
    if (pThis->_useAllStdHeapAvail)
        mp_task_heap_size = heap_caps_get_largest_free_block(MALLOC_CAP_8BIT);
    else
        mp_task_heap_size = pThis->_maxHeapToUse;
    mp_task_heap = (uint8_t*)malloc(mp_task_heap_size);
    ESP_LOGI(MODULE_PREFIX, "mp_task StdHeap size %d bytes ok %d", mp_task_heap_size, mp_task_heap != NULL);

    // Check heap ok
    if (!mp_task_heap || (mp_task_heap_size == 0))
    {
        // Delete task if it exits
        vTaskDelete(NULL);
    }

    // initialise the stack pointer for the main thread
    mp_stack_set_top((void *)sp);
    mp_stack_set_limit(_mpSubThreadStackSize - 1024);
    gc_init(mp_task_heap, mp_task_heap + mp_task_heap_size);
    mp_init();
    mp_obj_list_init((mp_obj_list_t*)mp_sys_path, 0);
    mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(MP_QSTR_));
    mp_obj_list_append(mp_sys_path, MP_OBJ_NEW_QSTR(MP_QSTR__slash_lib));
    mp_obj_list_init((mp_obj_list_t*)mp_sys_argv, 0);
    readline_init0();

    // Loop monitoring for MicropyExecTask(s) and executes
    while(1)
    {
        // See if anything queued up for Micropython to do
        MicropyExecTask task;
        if (pThis->_execQueue.get(task))
        {
            pThis->_isPythonProgramRunning = true;
            if (task._isFile && task._pExecStr)
            {
                int rslt = pyexec_file_if_exists(task._pExecStr);
                pThis->_isPythonProgramRunning = false;
                ESP_LOGI(MODULE_PREFIX, "mp_task exec %s rslt %d", task._pExecStr, rslt);
            }
        }
        // Allow other threads a look-in
        vTaskDelay(1);
    }
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Helpers
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int vprintf_null(const char *format, va_list ap) {
    // do nothing: this is used as a log target during raw repl mode
    return 0;
}

// This is a fiddle to allow a test file to run
mp_import_stat_t mp_import_stat(const char *path) {
    return MP_IMPORT_STAT_FILE;
}

void nlr_jump_fail(void *val) {
    printf("NLR jump failed, val=%p\n", val);
    esp_restart();
}

