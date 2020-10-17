#include <string.h>
#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sum.h"

void callingFunc()
{
  ESP_LOGI("TASK1", "1 - In func");
  char buffer[10];
  ESP_LOGI("TASK1", "2 - In func");
  memset(buffer, 'x', sizeof(buffer));
  ESP_LOGI("TASK1", "3 - In func");
  ESP_LOGI("BUFFER", "buffer is %s\n", buffer);
}

void task1(void *params)
{
  ESP_LOGI("TASK1", "Before func");
  callingFunc();
  ESP_LOGI("TASK1", "After func");
  vTaskDelete(NULL);  
}

void app_main()
{
  ESP_LOGI("MAIN", "EXECUTING TASK");
  xTaskCreate(task1, "task1", 1024 * 2, NULL, 5, NULL);
}
