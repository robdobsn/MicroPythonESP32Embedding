#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "Micropython.h"

// Micropython
Micropython _micropython;

extern "C" void app_main(void)
{
    int i = 0;
    _micropython.start(true, true, 65536, 1, 16384);
    while (1) {
        printf("[%d] Hello world!\n", i);
        i++;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
        _micropython.addToQueue("test.py", false, false);
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
