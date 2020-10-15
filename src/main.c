#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sum.h"

void app_main()
{
  int i = 0;
  while (1) {
    int sumResult = sum(i++, 2);
    ESP_LOGI("TAG1", "Hello, World!");
    ESP_LOGI("SUM", "%d", sumResult);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}
