#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_spi_flash.h"

QueueHandle_t imq;
void one_task(void *data)
{  while(1)
{
    printf("task one\n");
    vTaskDelay(10000/portTICK_PERIOD_MS);
}
}
void two_task(void *data)
{
    while(1)
    {
    printf("task two\n");
    vTaskDelay(20000/portTICK_PERIOD_MS);
}
}
void three_task(void *data)
{while(1)
{
    printf("task three\n");
    vTaskDelay(50000/portTICK_PERIOD_MS);
}
}void four_task(void *data)
{ int data =25;
    while(1)
{ 
    printf("task four\n");
     xQueueSend(imq,&data,0);
    vTaskDelay(3000/portTICK_PERIOD_MS);
}
}
void five_task(void *data)
{ int buff;
    while(1)
{
    printf("task five\n");
    xQueueReceive(imq,&buff,0);
    printf("data from t4 is %d\n",buff);
    vTaskDelay(2000/portTICK_PERIOD_MS);
}
}
void app_main(void)
{
    
    xTaskCreate(one_task,"first",1024 ,NULL,8,NULL);
    xTaskCreate(two_task,"second",1024 ,NULL ,5,NULL);
    xTaskCreate(three_task"thied",1024 NULL,4,NULL);
    xTaskCreate(four_task"four",1024 NULL,3,NULL);
xTaskCreate(five_task"five",1024 NULL,2,NULL);
     imq=xQueueCreate(5,sizeof(int));

    while(1)
    {
        printf(" hello\n",);
        
        vTaskDelay(2000/portTICK_PERIOD_MS);

    }
}