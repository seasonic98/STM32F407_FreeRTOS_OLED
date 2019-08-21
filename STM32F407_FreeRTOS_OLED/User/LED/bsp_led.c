// bsp :board support package 板级支持包

#include "bsp_led.h"

void LED_GPIO_Config(void)
{
    /* 以下四个步骤适合所有外设的初始化 */

    /* 第一步：开GPIO的时钟 */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    /* 第二步：定义一个GPIO初始化结构体 */
    GPIO_InitTypeDef GPIO_InitStruct;

    /* 第三步：配置GPIO初始化结构体的成员 */
    GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
    GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;

    /* 第四步：调用GPIO初始化函数，把配置好的结构体的成员的参数写入寄存器 */
    GPIO_Init(GPIOF, &GPIO_InitStruct);

    GPIO_ResetBits(GPIOF, GPIO_Pin_9 | GPIO_Pin_10);
}

void Led1_ON(void)
{
    GPIO_ResetBits(GPIOF, GPIO_Pin_9);
}

void Led1_OFF(void)
{
    GPIO_SetBits(GPIOF, GPIO_Pin_9);
}

void Led2_ON(void)
{
    GPIO_ResetBits(GPIOF, GPIO_Pin_10);
}

void Led2_OFF(void)
{
    GPIO_SetBits(GPIOF, GPIO_Pin_10);
}