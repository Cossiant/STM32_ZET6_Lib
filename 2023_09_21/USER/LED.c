#include "include.h"

//��ʼ��PB�˿ڵ�LED��
void LED_B_Display_Init(void) {
    GPIO_InitTypeDef LED_InitTypeDef;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    LED_InitTypeDef.GPIO_Pin = GPIO_Pin_5;
    LED_InitTypeDef.GPIO_Speed = GPIO_Speed_50MHz;
    LED_InitTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOB, &LED_InitTypeDef);
}

//��ʼ��PE�˿ڵ�LED��
void LED_E_Display_Init(void) {
    GPIO_InitTypeDef LED_InitTypeDef;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

    LED_InitTypeDef.GPIO_Pin = GPIO_Pin_5;
    LED_InitTypeDef.GPIO_Speed = GPIO_Speed_50MHz;
    LED_InitTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOE, &LED_InitTypeDef);
}

//��ʼ��LED1
void LED_1_Init(void) {
    GPIO_InitTypeDef LED_InitTypeDef;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    LED_InitTypeDef.GPIO_Pin = GPIO_Pin_5;
    LED_InitTypeDef.GPIO_Speed = GPIO_Speed_50MHz;
    LED_InitTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOB, &LED_InitTypeDef);
}

//��ʼ��LED2
void LED_2_Init(void) {
    GPIO_InitTypeDef LED_InitTypeDef;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);

    LED_InitTypeDef.GPIO_Pin = GPIO_Pin_5;
    LED_InitTypeDef.GPIO_Speed = GPIO_Speed_50MHz;
    LED_InitTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOE, &LED_InitTypeDef);
}

void BEEP_Init(void) {
    GPIO_InitTypeDef BEEP_InitTypeDef;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    BEEP_InitTypeDef.GPIO_Pin = GPIO_Pin_8;
    BEEP_InitTypeDef.GPIO_Speed = GPIO_Speed_50MHz;
    BEEP_InitTypeDef.GPIO_Mode = GPIO_Mode_Out_PP;

    GPIO_Init(GPIOB, &BEEP_InitTypeDef);
}

void LED_Scanf(unsigned char *System_Num) {
//ʵ��һ
/**************************************************************************************************/
//    if (*System_Num == 0) {
//        GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_SET);
//        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_RESET);
//    } else if (*System_Num == 1) {
//        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_SET);
//        GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_SET);
//        Delay_ms(1000);
//        GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_RESET);
//        Delay_ms(1000);
//    }
/**************************************************************************************************/
//ʵ���
    if (*System_Num == 0) {
        //С����˸�����ҳ��������ҷ�������
        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_RESET);
        GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_SET);
        Delay_ms(200);
        GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_RESET);
        Delay_ms(200);
        GPIO_WriteBit(GPIOB, GPIO_Pin_8, Bit_SET);
    } else if (*System_Num == 1) {
        //С����˸�����Ҳ��������ҷ���������
        GPIO_WriteBit(GPIOE, GPIO_Pin_5, Bit_SET);
        GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_SET);
        Delay_ms(200);
        GPIO_WriteBit(GPIOB, GPIO_Pin_5, Bit_RESET);
        Delay_ms(200);
        GPIO_WriteBit(GPIOB, GPIO_Pin_8, Bit_RESET);
    }
}

