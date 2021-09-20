#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timer.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

void *const timer_id;
TimerHandler_t timer_handle;

void callback(TimerHandler_t xTimer)
{
    printf("timer faired\n");

}

void one_task(void *data)
{  while(1)
{
    printf("task one\n");
    vTaskDelay(1000/portTICK_PERIOD_MS);
}
}
void two_task(void *data)
{
    while(1)
    {
    printf("task two\n");
    vTaskDelay(2000/portTICK_PERIOD_MS);
}
}
void three_task(void *data)
{   timer_handle=XTimweCreate("timer",(10000/portTICK_PERIOD_MS),pdFALSE,timer_id,callback);
    xTimerStart(my_timer_handle,1);

    while(1)
{
    printf("task three\n");
    vTaskDelay(5000/portTICK_PERIOD_MS);
}
void app_main(void)
{
    
    xTaskCreate(one_task,"first",1024 ,NULL,8,NULL);
    xTaskCreate(two_task,"second",1024 ,NULL ,5,NULL);
    xTaskCreate(three_task"thied",1024 NULL,4,NULL);
}