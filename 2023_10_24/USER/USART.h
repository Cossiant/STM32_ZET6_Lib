//
// Created by Admin on 2023/10/24 0024.
//

#ifndef INC_2023_10_24_USART_H
#define INC_2023_10_24_USART_H

#include "include.h"

typedef struct
{
    u8 Read_USART;	//��ȡ�����ĵ�������
    u32 Read_Data;	//��ȡ������ȫ������
    u8 Read_Data_Flag;	//�Ƿ������ݶ�ȡ
    u32 Read_Str;				//��ȡ������Э������
    u8 Read_Str_Flag;		//�Ƿ���Э���ȡ
    u8 UploadToPC_Flag;	//�Ƿ��͵�PC
		u8 LED_Data;				//LED�ĵ�ǰ״̬
}USART_Read_Data;

void USART1_Init_Config(void);
void USART_SendByte(USART_TypeDef *pUSARTx, u8 data);
void USART1_IT_Config(void);
void Read_Data_Init(USART_Read_Data *Data);
#endif //INC_2023_10_24_USART_H
