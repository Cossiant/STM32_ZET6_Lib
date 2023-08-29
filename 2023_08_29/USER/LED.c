#include "stm32f10x.h"

void LED_B_Display_Init(void)
{
	GPIO_InitTypeDef LED_InitTypeDef;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	LED_InitTypeDef.GPIO_Pin = GPIO_Pin_5;
	LED_InitTypeDef.GPIO_Speed = GPIO_Speed_50MHz;
	LED_InitTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOB,&LED_InitTypeDef);
}

void LED_E_Display_Init(void)
{
	GPIO_InitTypeDef LED_InitTypeDef;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	LED_InitTypeDef.GPIO_Pin = GPIO_Pin_5;
	LED_InitTypeDef.GPIO_Speed = GPIO_Speed_50MHz;
	LED_InitTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;
	
	GPIO_Init(GPIOE,&LED_InitTypeDef);
}

void DS_delay(uint32_t Count)	//ÑÓ³Ùº¯Êý
{
	
	while(Count != 0)			//¿Õ×ª
	{
			Count--;
	}
	
}

