//
// Created by Admin on 2023/10/26 0026.
//

#include "include.h"

void Delay_ms(u16 time) {
    u16 i = 0;
    while (time--) {
        i = 12000;
        while (i--);
    }
}

void LED_Init(void) {
    GPIO_InitTypeDef LED;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

    LED.GPIO_Speed = GPIO_Speed_50MHz;
    LED.GPIO_Pin = GPIO_Pin_5;
    LED.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOE, &LED);
}

void LED_Display(USART_Read_Data *LED_Data) {
    //关闭led
    if (LED_Data->Read_Data == 0x00000000) {
        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_SET);
				LED_Data->LED_Data = 0x00;
    }
    //开启LED
    if (LED_Data->Read_Data == 0x00010000) {
        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_RESET);
				LED_Data->LED_Data = 0x01;
    }
    //启动闪烁
    if (LED_Data->Read_Data == 0x00020000) {
				LED_Data->LED_Data = 0x02;
        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_RESET);
        Delay_ms(100);
        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_SET);
        Delay_ms(100);
    }
}
