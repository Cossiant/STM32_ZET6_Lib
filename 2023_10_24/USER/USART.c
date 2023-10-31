//
// Created by Admin on 2023/10/24 0024.
//

#include "include.h"

void USART1_Init_Config(void) {
    USART_InitTypeDef USART_Init_Struct;
    GPIO_InitTypeDef GPIO_Init_Struct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_9;
    GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_Init_Struct);

    GPIO_Init_Struct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init_Struct.GPIO_Pin = GPIO_Pin_10;
    GPIO_Init_Struct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_Init_Struct);

    USART_StructInit(&USART_Init_Struct);
    USART_Init_Struct.USART_BaudRate = 9600;
    USART_Init_Struct.USART_WordLength = USART_WordLength_8b;
    USART_Init_Struct.USART_StopBits = USART_StopBits_1;
    USART_Init_Struct.USART_Parity = USART_Parity_No;
    USART_Init_Struct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_Init_Struct.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART1, &USART_Init_Struct);
    USART_Cmd(USART1, ENABLE);
}

void USART1_IT_Config(void)
{
    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    NVIC_InitTypeDef NVIC_Init_struct;
    NVIC_Init_struct.NVIC_IRQChannel = USART1_IRQn;
    NVIC_Init_struct.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init_struct.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_Init_struct.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_Init_struct);
}

void USART_SendByte(USART_TypeDef *pUSARTx, u8 data) {
    USART_SendData(pUSARTx, data);
    while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TXE) == RESET);
}

int fputc(int ch,FILE *p)
{
    USART_SendData(USART1,(u8)ch);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET);
    return ch;
}

void Read_Data_Init(USART_Read_Data *Data)
{
    Data->Read_Data_Flag = 0;
    Data->Read_Data = 0;
    Data->Read_Str = 0;
    Data->Read_Str_Flag = 0;
    Data->Read_USART = 0;
    Data->UploadToPC_Flag = 0;
}

