// Options to control how MicroPython is built for this port,
// overriding defaults in py/mpconfig.h.

// Board-specific definitions
#include "mpconfigboard.h"

#include <stdint.h>
#include <alloca.h>

#if !MICROPY_ESP_IDF_4
#include "rom/ets_sys.h"
#endif

#define MODULE_RIC_ENABLED (1)

// You can disable the built-in MicroPython compiler by setting the following
// config option to 0.  If you do this then you won't get a REPL prompt, but you
// will still be able to execute pre-compiled scripts, compiled with mpy-cross.
#define MICROPY_ENABLE_COMPILER             (1)
#define MICROPY_REPL_EVENT_DRIVEN           (1)

// #define MICROPY_DYNAMIC_COMPILER    (1)

// object representation and NLR handling
#define MICROPY_OBJ_REPR                    (MICROPY_OBJ_REPR_A)
#define MICROPY_NLR_SETJMP                  (1)

// memory allocation policies
#define MICROPY_ALLOC_PATH_MAX              (128)

// emitters
#define MICROPY_PERSISTENT_CODE_LOAD        (1)
#define MICROPY_EMIT_XTENSAWIN              (0)

// compiler configuration
#define MICROPY_COMP_MODULE_CONST           (1)
#define MICROPY_COMP_CONST                  (1)
#define MICROPY_COMP_DOUBLE_TUPLE_ASSIGN    (1)
#define MICROPY_COMP_TRIPLE_TUPLE_ASSIGN    (1)

// optimisations
#define MICROPY_OPT_COMPUTED_GOTO           (1)
#define MICROPY_OPT_MPZ_BITWISE             (1)

// Python internal features
#define MICROPY_READER_VFS                  (1)
#define MICROPY_ENABLE_GC                   (1)
#define MICROPY_ENABLE_FINALISER            (0)
#define MICROPY_STACK_CHECK                 (1)
#define MICROPY_ENABLE_EMERGENCY_EXCEPTION_BUF (0)
#define MICROPY_KBD_EXCEPTION               (1)
#define MICROPY_HELPER_REPL                 (1)
#define MICROPY_REPL_EMACS_KEYS             (0)
#define MICROPY_REPL_AUTO_INDENT            (1)
#define MICROPY_LONGINT_IMPL                (MICROPY_LONGINT_IMPL_MPZ)
#define MICROPY_ENABLE_SOURCE_LINE          (0)
#define MICROPY_ERROR_REPORTING             (MICROPY_ERROR_REPORTING_NORMAL)
#define MICROPY_WARNINGS                    (1)
#define MICROPY_FLOAT_IMPL                  (MICROPY_FLOAT_IMPL_FLOAT)
#define MICROPY_CPYTHON_COMPAT              (0)
#define MICROPY_STREAMS_NON_BLOCK           (0)
#define MICROPY_STREAMS_POSIX_API           (1)
#define MICROPY_MODULE_BUILTIN_INIT         (0)
#define MICROPY_MODULE_WEAK_LINKS           (1)
#define MICROPY_MODULE_FROZEN_STR           (0)
#define MICROPY_MODULE_FROZEN_MPY           (1)
#define MICROPY_QSTR_EXTRA_POOL             mp_qstr_frozen_const_pool
#define MICROPY_CAN_OVERRIDE_BUILTINS       (1)
#define MICROPY_USE_INTERNAL_ERRNO          (1)
#define MICROPY_USE_INTERNAL_PRINTF         (0) // ESP32 SDK requires its own printf
#define MICROPY_ENABLE_SCHEDULER            (1)
#define MICROPY_SCHEDULER_DEPTH             (8)
#define MICROPY_VFS                         (0)

// control over Python builtins
#define MICROPY_PY_FUNCTION_ATTRS           (1)
#define MICROPY_PY_DESCRIPTORS              (1)
#define MICROPY_PY_STR_BYTES_CMP_WARN       (1)
#define MICROPY_PY_BUILTINS_DICT_FROMKEYS   (0)
#define MICROPY_PY_BUILTINS_STR_UNICODE     (1)
#define MICROPY_PY_BUILTINS_STR_CENTER      (1)
#define MICROPY_PY_BUILTINS_STR_PARTITION   (1)
#define MICROPY_PY_BUILTINS_STR_SPLITLINES  (1)
#define MICROPY_PY_BUILTINS_BYTEARRAY       (1)
#define MICROPY_PY_BUILTINS_MEMORYVIEW      (0)
#define MICROPY_PY_BUILTINS_SET             (0)
#define MICROPY_PY_BUILTINS_SLICE           (1)
#define MICROPY_PY_BUILTINS_SLICE_ATTRS     (0)
#define MICROPY_PY_BUILTINS_SLICE_INDICES   (0)
#define MICROPY_PY_BUILTINS_FROZENSET       (0)
#define MICROPY_PY_BUILTINS_PROPERTY        (0)
#define MICROPY_PY_BUILTINS_RANGE_ATTRS     (0)
#define MICROPY_PY_BUILTINS_ROUND_INT       (1)
#define MICROPY_PY_ALL_SPECIAL_METHODS      (0)
#define MICROPY_PY_BUILTINS_COMPILE         (0)
#define MICROPY_PY_BUILTINS_ENUMERATE       (0)
#define MICROPY_PY_BUILTINS_EXECFILE        (0)
#define MICROPY_PY_BUILTINS_FILTER          (0)
#define MICROPY_PY_BUILTINS_REVERSED        (0)
#define MICROPY_PY_BUILTINS_NOTIMPLEMENTED  (0)
#define MICROPY_PY_BUILTINS_INPUT           (0)
#define MICROPY_PY_BUILTINS_MIN_MAX         (1)
#define MICROPY_PY_BUILTINS_POW3            (1)
#define MICROPY_PY_BUILTINS_HELP            (1)
#define MICROPY_PY_BUILTINS_HELP_TEXT       esp32_help_text
#define MICROPY_PY_BUILTINS_HELP_MODULES    (0)
#define MICROPY_PY___FILE__                 (0)
#define MICROPY_PY_MICROPYTHON_MEM_INFO     (0)
#define MICROPY_PY_ARRAY                    (0)
#define MICROPY_PY_ARRAY_SLICE_ASSIGN       (0)
#define MICROPY_PY_ATTRTUPLE                (0)
#define MICROPY_PY_COLLECTIONS              (0)
#define MICROPY_PY_COLLECTIONS_DEQUE        (0)
#define MICROPY_PY_COLLECTIONS_ORDEREDDICT  (0)
#define MICROPY_PY_MATH                     (0)
#define MICROPY_PY_MATH_SPECIAL_FUNCTIONS   (0)
#define MICROPY_PY_MATH_ISCLOSE             (0)
#define MICROPY_PY_CMATH                    (0)
#define MICROPY_PY_GC                       (1)
#define MICROPY_PY_IO                       (0)
#define MICROPY_PY_IO_IOBASE                (0)
#define MICROPY_PY_IO_FILEIO                (0)
#define MICROPY_PY_IO_BYTESIO               (0)
#define MICROPY_PY_IO_BUFFEREDWRITER        (0)
#define MICROPY_PY_STRUCT                   (1)
#define MICROPY_PY_SYS                      (0)
#define MICROPY_PY_SYS_MAXSIZE              (0)
#define MICROPY_PY_SYS_MODULES              (0)
#define MICROPY_PY_SYS_EXIT                 (0)
#define MICROPY_PY_SYS_STDFILES             (0)
#define MICROPY_PY_SYS_STDIO_BUFFER         (0)
#define MICROPY_PY_UERRNO                   (0)
#define MICROPY_PY_USELECT                  (0)
#define MICROPY_PY_UTIME_MP_HAL             (1)
#define MICROPY_PY_THREAD                   (1)
#define MICROPY_PY_THREAD_GIL               (1)
#define MICROPY_PY_THREAD_GIL_VM_DIVISOR    (32)

// extended modules
#define MICROPY_PY_UASYNCIO                 (0)
#define MICROPY_PY_UCTYPES                  (0)
#define MICROPY_PY_UZLIB                    (0)
#define MICROPY_PY_UJSON                    (0)
#define MICROPY_PY_URE                      (0)
#define MICROPY_PY_URE_SUB                  (0)
#define MICROPY_PY_UHEAPQ                   (0)
#define MICROPY_PY_UTIMEQ                   (0)
#define MICROPY_PY_UHASHLIB                 (0)
#define MICROPY_PY_UHASHLIB_SHA1            (0)
#define MICROPY_PY_UHASHLIB_SHA256          (0)
#define MICROPY_PY_UCRYPTOLIB               (0)
#define MICROPY_PY_UBINASCII                (0)
#define MICROPY_PY_UBINASCII_CRC32          (0)
#define MICROPY_PY_URANDOM                  (0)
#define MICROPY_PY_URANDOM_EXTRA_FUNCS      (0)
#define MICROPY_PY_OS_DUPTERM               (0)
#define MICROPY_PY_MACHINE                  (0)
#define MICROPY_PY_MACHINE_PIN_MAKE_NEW     mp_pin_make_new
#define MICROPY_PY_MACHINE_PULSE            (0)
#define MICROPY_PY_MACHINE_I2C              (0)
#define MICROPY_PY_MACHINE_I2C_MAKE_NEW     machine_hw_i2c_make_new
#define MICROPY_PY_MACHINE_SPI              (0)
#define MICROPY_PY_MACHINE_SPI_MSB          (0)
#define MICROPY_PY_MACHINE_SPI_LSB          (1)
#define MICROPY_PY_MACHINE_SPI_MAKE_NEW     machine_hw_spi_make_new
#define MICROPY_HW_ENABLE_SDCARD            (0)
#define MICROPY_HW_SOFTSPI_MIN_DELAY        (0)
#define MICROPY_HW_SOFTSPI_MAX_BAUDRATE     (ets_get_cpu_frequency() * 1000000 / 200) // roughly
#define MICROPY_PY_USSL                     (0)
#define MICROPY_SSL_MBEDTLS                 (0)
#define MICROPY_PY_USSL_FINALISER           (0)
#define MICROPY_PY_UWEBSOCKET               (0)
#define MICROPY_PY_WEBREPL                  (0)
#define MICROPY_PY_FRAMEBUF                 (0)
#define MICROPY_PY_USOCKET_EVENTS           (MICROPY_PY_WEBREPL)
#define MICROPY_PY_BLUETOOTH_RANDOM_ADDR    (0)
#define MICROPY_PY_BLUETOOTH_DEFAULT_GAP_NAME ("ESP32")

// fatfs configuration
#define MICROPY_FATFS_ENABLE_LFN            (1)
#define MICROPY_FATFS_RPATH                 (2)
#define MICROPY_FATFS_MAX_SS                (4096)
#define MICROPY_FATFS_LFN_CODE_PAGE         437 /* 1=SFN/ANSI 437=LFN/U.S.(OEM) */
#define mp_type_fileio                      mp_type_vfs_fat_fileio
#define mp_type_textio                      mp_type_vfs_fat_textio

// use vfs's functions for import stat and builtin open
// #define mp_import_stat mp_vfs_import_stat
// #define mp_builtin_open mp_vfs_open
// #define mp_builtin_open_obj mp_vfs_open_obj

// extra built in names to add to the global namespace
/*#define MICROPY_PORT_BUILTINS \
    { MP_OBJ_NEW_QSTR(MP_QSTR_input), (mp_obj_t)&mp_builtin_input_obj }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_open), (mp_obj_t)&mp_builtin_open_obj },
*/

// extra built in modules to add to the list of known ones
// extern const struct _mp_obj_module_t esp_module;
// extern const struct _mp_obj_module_t esp32_module;
extern const struct _mp_obj_module_t utime_module;
// extern const struct _mp_obj_module_t uos_module;
// extern const struct _mp_obj_module_t mp_module_usocket;
// extern const struct _mp_obj_module_t mp_module_machine;
// extern const struct _mp_obj_module_t mp_module_network;
// extern const struct _mp_obj_module_t mp_module_onewire;

#define MICROPY_PORT_BUILTIN_MODULES \
    { MP_OBJ_NEW_QSTR(MP_QSTR_utime), (mp_obj_t)&utime_module }, 

/*   { MP_OBJ_NEW_QSTR(MP_QSTR_esp), (mp_obj_t)&esp_module }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_esp32), (mp_obj_t)&esp32_module }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_uos), (mp_obj_t)&uos_module }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_usocket), (mp_obj_t)&mp_module_usocket }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_machine), (mp_obj_t)&mp_module_machine }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_network), (mp_obj_t)&mp_module_network }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR__onewire), (mp_obj_t)&mp_module_onewire }, \
    { MP_OBJ_NEW_QSTR(MP_QSTR_uhashlib), (mp_obj_t)&mp_module_uhashlib }, \
*/

#define MP_STATE_PORT MP_STATE_VM

struct _machine_timer_obj_t;

#if MICROPY_BLUETOOTH_NIMBLE
struct mp_bluetooth_nimble_root_pointers_t;
#define MICROPY_PORT_ROOT_POINTER_BLUETOOTH_NIMBLE struct _mp_bluetooth_nimble_root_pointers_t *bluetooth_nimble_root_pointers;
#else
#define MICROPY_PORT_ROOT_POINTER_BLUETOOTH_NIMBLE
#endif

#define MICROPY_PORT_ROOT_POINTERS \
    const char *readline_hist[8]; \
    mp_obj_t machine_pin_irq_handler[40]; \
    struct _machine_timer_obj_t *machine_timer_obj_head; \
    mp_obj_t ric_event_callback; \
    MICROPY_PORT_ROOT_POINTER_BLUETOOTH_NIMBLE

// type definitions for the specific machine

#define BYTES_PER_WORD (4)
#define MICROPY_MAKE_POINTER_CALLABLE(p) ((void *)((mp_uint_t)(p)))
#define MP_PLAT_PRINT_STRN(str, len) mp_hal_stdout_tx_strn_cooked(str, len)
void *esp_native_code_commit(void *, size_t, void *);
#define MP_PLAT_COMMIT_EXEC(buf, len, reloc) esp_native_code_commit(buf, len, reloc)
#define MP_SSIZE_MAX (0x7fffffff)

// Note: these "critical nested" macros do not ensure cross-CPU exclusion,
// the only disable interrupts on the current CPU.  To full manage exclusion
// one should use portENTER_CRITICAL/portEXIT_CRITICAL instead.
#include "freertos/FreeRTOS.h"
#define MICROPY_BEGIN_ATOMIC_SECTION() portENTER_CRITICAL_NESTED()
#define MICROPY_END_ATOMIC_SECTION(state) portEXIT_CRITICAL_NESTED(state)

#if MICROPY_PY_USOCKET_EVENTS
#define MICROPY_PY_USOCKET_EVENTS_HANDLER extern void usocket_events_handler(void); usocket_events_handler();
#else
#define MICROPY_PY_USOCKET_EVENTS_HANDLER
#endif

#if MICROPY_PY_THREAD
#define MICROPY_EVENT_POLL_HOOK \
    do { \
        extern void mp_handle_pending(bool); \
        mp_handle_pending(true); \
        MICROPY_PY_USOCKET_EVENTS_HANDLER \
        MP_THREAD_GIL_EXIT(); \
        MP_THREAD_GIL_ENTER(); \
    } while (0);
#else
#define MICROPY_EVENT_POLL_HOOK \
    do { \
        extern void mp_handle_pending(bool); \
        mp_handle_pending(true); \
        MICROPY_PY_USOCKET_EVENTS_HANDLER \
        asm ("waiti 0"); \
    } while (0);
#endif

// Functions that should go in IRAM
#define MICROPY_WRAP_MP_KEYBOARD_INTERRUPT(f) IRAM_ATTR f

#define UINT_FMT "%u"
#define INT_FMT "%d"

typedef int32_t mp_int_t; // must be pointer size
typedef uint32_t mp_uint_t; // must be pointer size
typedef long mp_off_t;
// ssize_t, off_t as required by POSIX-signatured functions in stream.h
#include <sys/types.h>

// board specifics
#define MICROPY_PY_SYS_PLATFORM "esp32"

// #ifndef MICROPY_HW_ENABLE_MDNS_QUERIES
// #define MICROPY_HW_ENABLE_MDNS_QUERIES      (1)
// #endif

// #ifndef MICROPY_HW_ENABLE_MDNS_RESPONDER
// #define MICROPY_HW_ENABLE_MDNS_RESPONDER    (1)
// #endif
