#include "FreeRTOS.h"
#include "task.h"

#include "bsp_led.h"

/* 创建任务句柄 */
static TaskHandle_t TaskCreate_handle;
/* 创建任务堆栈 */
#define TaskCreate_stack 128
/* 用于创建任务 */
static void TaskCreate(void *pvParameters);

/* LED任务句柄 */
static TaskHandle_t LED_Task_handle;
/* LED任务堆栈 */
#define LED_Task_stack 128
/* LED_Task任务实现 */
static void LED_Task(void *pvParameters);

/*
*************************************************************************
*                             函数声明
*************************************************************************
*/

int main(void)
{
    LED_GPIO_Config();
    // xTaskCreate((TaskFunction_t)TaskCreate,          //任务函数
    //             (const char *)"TaskCreate",          //任务名称
    //             (uint16_t)TaskCreate_stack,          //堆栈大小
    //             (void *const)NULL,                   //传递给任务函数的参数
    //             (UBaseType_t)3,                      //任务优先级
    //             (TaskHandle_t *)&TaskCreate_handle); //任务句柄
    // vTaskStartScheduler();                           //开启任务调度
    while (1)
    {
        /* code */
        Led1_ON();
        Led2_ON();
    }
}

void TaskCreate(void *pvParameters)
{
    taskENTER_CRITICAL(); //进入临界区保护

    xTaskCreate((TaskFunction_t)LED_Task,          //任务函数
                (const char *)"LED_Task",          //任务名称
                (uint16_t)LED_Task_stack,          //堆栈大小
                (void *const)NULL,                 //传递给任务函数的参数
                (UBaseType_t)4,                    //任务优先级
                (TaskHandle_t *)&LED_Task_handle); //任务句柄

    vTaskDelete(TaskCreate); //删除任务

    taskEXIT_CRITICAL(); //退出临界区保护
}

void LED_Task(void *pvParameters)
{
    Led1_ON();
    vTaskDelay(500);
    Led1_OFF();
    vTaskDelay(500);
}