#include "include.h"

/*  д��֮��ǵ���include.h��������д����ļ�
*   ����ǰ�ǵ���Keil�������ø�д����ļ�������h��c�ļ�
*   ��Clion���б༭��ʱ��ǵ���GBK��ʽ���¼��أ�������������
*   Clion�ᱨwhile��ѭ�����棬�����
*/

unsigned char flag_Init_Num = 1;

/*********************************************************************************************/
//ʵ��һ
////�ⲿ�ж�4��Ӧ����
//void EXTI4_IRQHandler(void) {
//    if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
//        flag_Init_Num = 0;
//        EXTI_ClearITPendingBit(EXTI_Line4);
//    }
//}
////�ⲿ�ж�3��Ӧ����
//void EXTI3_IRQHandler(void) {
//    if (EXTI_GetITStatus(EXTI_Line3) != RESET) {
//        flag_Init_Num = 1;
//        EXTI_ClearITPendingBit(EXTI_Line3);
//    }
//}

/*********************************************************************************************/
//ʵ���
void EXTI4_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
        flag_Init_Num = 1-flag_Init_Num;
        EXTI_ClearITPendingBit(EXTI_Line4);
    }
}
//�ⲿ�ж�3��Ӧ����
void EXTI3_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line3) != RESET) {
        flag_Init_Num = 1-flag_Init_Num;
        EXTI_ClearITPendingBit(EXTI_Line3);
    }
}
/*******************************************************************************************/
int main(void) {
    NVIC_Configure();
    KEY_Configure();
    LED_1_Init();
    LED_2_Init();
    BEEP_Init();
    while (1) {
        LED_Scanf(&flag_Init_Num);
    }
}
