/*!
    \file 	main.c
    \brief 	main function 
    
    \version 2020-04-01, V1.0.0, 
*/
/* Includes ------------------*/
#include "stm32f4xx.h"
#include <stdio.h>
#include "main.h"
#include "systick.h"
#include "usart.h"
#include "stm32f4xx_gpio.h"


/* --------宏定义--------------*/
#define LED0 		GPIOF, GPIO_Pin_9
#define LED1 		GPIOF, GPIO_Pin_10

#define led0_off() 	GPIO_SetBits(LED0)
#define led0_on() 	GPIO_ResetBits(LED0)

#define led1_off() 	GPIO_SetBits(LED1)
#define led1_on() 	GPIO_ResetBits(LED1)


/* --------变量----------------*/

/* --------函数----------------*/

void led_init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9 | GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOF, &GPIO_InitStructure);
}

void led_flash(void)
{
    led0_on();
    led1_off();
    delay_1ms(1000);
    led0_off();
    led1_on();
    
    delay_1ms(100);
}

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    /* configure systick */
    systick_config();
    
    usart1_init();
    
    led_init();
    
    while (1)
    {
    	printf("hello world\r\n");
    	led_flash();
    }
    
}



/****END OF FILE****/
