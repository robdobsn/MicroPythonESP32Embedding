#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <esp_log.h>
#include <esp_spiffs.h>

#include "Micropython.h"

// Micropython
Micropython _micropython;

static const char* MODULE_PREFIX = "MAIN";

extern "C" void registerSPIFFS()
{
    // Using ESP32 native SPIFFS support
    esp_vfs_spiffs_conf_t conf = {
        .base_path = "/spiffs",
        .partition_label = NULL,
        .max_files = 5,
        .format_if_mount_failed = false
    };        
    // Use settings defined above to initialize and mount SPIFFS filesystem.
    // Note: esp_vfs_spiffs_register is an all-in-one convenience function.
    esp_err_t ret = esp_vfs_spiffs_register(&conf);
    if (ret != ESP_OK)
    {
        if (ret == ESP_FAIL)
            ESP_LOGW(MODULE_PREFIX, "setup failed mount/format SPIFFS");
        else if (ret == ESP_ERR_NOT_FOUND)
            ESP_LOGW(MODULE_PREFIX, "setup failed to find SPIFFS partition");
        else
            ESP_LOGW(MODULE_PREFIX, "setup failed to init SPIFFS (error %s)", esp_err_to_name(ret));
    }
    else
    {
        // Get SPIFFS info
        size_t total = 0, used = 0;
        esp_err_t ret = esp_spiffs_info(NULL, &total, &used);
        if (ret != ESP_OK)
            ESP_LOGW(MODULE_PREFIX, "setup failed to get SPIFFS info (error %s)", esp_err_to_name(ret));
        else
            ESP_LOGI(MODULE_PREFIX, "setup SPIFFS partition size total %d, used %d", total, used);
    }
}

extern "C" void app_main(void)
{
    registerSPIFFS();
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
