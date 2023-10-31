//
// Created by Admin on 2023/10/24 0024.
//

#ifndef INC_2023_10_24_USART_H
#define INC_2023_10_24_USART_H

#include "include.h"

typedef struct
{
    u8 Read_USART;	//读取出来的单个数据
    u32 Read_Data;	//读取出来的全部数据
    u8 Read_Data_Flag;	//是否开启数据读取
    u32 Read_Str;				//读取出来的协议数据
    u8 Read_Str_Flag;		//是否开启协议读取
    u8 UploadToPC_Flag;	//是否发送到PC
		u8 LED_Data;				//LED的当前状态
}USART_Read_Data;

void USART1_Init_Config(void);
void USART_SendByte(USART_TypeDef *pUSARTx, u8 data);
void USART1_IT_Config(void);
void Read_Data_Init(USART_Read_Data *Data);
#endif //INC_2023_10_24_USART_H
