//
// Created by Admin on 2023/9/7 0007.
//
#include "include.h"

//NVIC≥ı ºªØ

void NVIC_Configure(void) {
    NVIC_InitTypeDef NVIC_START;
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_START.NVIC_IRQChannel = EXTI4_IRQn;
    NVIC_START.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_START.NVIC_IRQChannelSubPriority = 0;
    NVIC_START.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_START);

    NVIC_START.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_START.NVIC_IRQChannelPreemptionPriority = 0;
    NVIC_START.NVIC_IRQChannelSubPriority = 1;
    NVIC_START.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&NVIC_START);
}

void KEY_Configure(void) {
    GPIO_InitTypeDef KEY;
    EXTI_InitTypeDef EXTI_KEY;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE | RCC_APB2Periph_AFIO, ENABLE);
    KEY.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_3;
    KEY.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_Init(GPIOE, &KEY);
    GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource4);
    EXTI_KEY.EXTI_Line = EXTI_Line4;
    EXTI_KEY.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_KEY.EXTI_Trigger = EXTI_Trigger_Rising_Falling;
    EXTI_KEY.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_KEY);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOE, GPIO_PinSource3);
    EXTI_KEY.EXTI_Line = EXTI_Line3;
    EXTI_KEY.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_KEY.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_KEY.EXTI_LineCmd = ENABLE;
    EXTI_Init(&EXTI_KEY);
}


