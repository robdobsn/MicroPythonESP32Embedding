/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// RIC Micropython
//
// Rob Dobson 2016-20
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdint.h>
#include <stddef.h>
#include "MicropyExecTask.h"
#include <RingBufferRTOS.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

class Micropython
{
public:
    Micropython();
    virtual ~Micropython();

    // Start micropython
    void start(bool useSPIRAM, bool useAllStdHeapAvail, uint32_t maxHeapToUse,
                uint32_t taskPriority, uint32_t taskStackSize);

    // Add to task queue
    void addToQueue(const char* filename, bool clearQueue, bool stopExisting);
    
    // Register event callback
    void regEventCallback(void* callbackObj);

    // Perform event callback
    void performEventCallback(const char* pJsonStr);

    // Stop executing / clear queue
    void stopExecution(bool clearQueue, bool stopExisting);

private:
    static void mp_task(void *pvParameter);

    // Queue for micropython execution
    static const int EXEC_QUEUE_SIZE = 3;
    RingBufferRTOS<MicropyExecTask, EXEC_QUEUE_SIZE> _execQueue;

    // Task handle
    TaskHandle_t mp_main_task_handle;
    bool _isStarted;

    // Python program running
    volatile bool _isPythonProgramRunning;

    // Heap details
    volatile bool _useSPIRAM;
    volatile bool _useAllStdHeapAvail;
    volatile uint32_t _maxHeapToUse;

    // Sub-thread stack size
    static uint32_t _mpSubThreadStackSize;

    // Event callback
    void* _eventCallback;
};
