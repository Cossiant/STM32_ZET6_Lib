#include "include.h"

/*  写完之后记得在include.h当中引用写完的文件
*   编译前记得在Keil当中引用刚写完的文件，包括h和c文件
*   在Clion进行编辑的时候记得以GBK格式重新加载，否则会出现乱码
*   Clion会报while死循环警告，请忽略
*/

unsigned char flag_Init_Num = 1;

/*********************************************************************************************/
//实验一
////外部中断4响应函数
//void EXTI4_IRQHandler(void) {
//    if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
//        flag_Init_Num = 0;
//        EXTI_ClearITPendingBit(EXTI_Line4);
//    }
//}
////外部中断3响应函数
//void EXTI3_IRQHandler(void) {
//    if (EXTI_GetITStatus(EXTI_Line3) != RESET) {
//        flag_Init_Num = 1;
//        EXTI_ClearITPendingBit(EXTI_Line3);
//    }
//}

/*********************************************************************************************/
//实验二
void EXTI4_IRQHandler(void) {
    if (EXTI_GetITStatus(EXTI_Line4) != RESET) {
        flag_Init_Num = 1-flag_Init_Num;
        EXTI_ClearITPendingBit(EXTI_Line4);
    }
}
//外部中断3响应函数
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
