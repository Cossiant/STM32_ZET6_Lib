#include "include.h"

/*  写完之后记得在include.h当中引用写完的文件
*   编译前记得在Keil当中引用刚写完的文件，包括h和c文件
*   在Clion进行编辑的时候记得以GBK格式重新加载，否则会出现乱码
*   Clion会报while死循环警告，请忽略
*/
USART_Read_Data Read_Data;

/*  此程序实现的目标：
 * 1、串口发送：发送指令报头和指令
 * 2、LED状态控制：通过串口读出来的数据来进行小灯控制
 * 3、LED状态读取：此时的小灯亮灭状态读取
 * 4、LED状态发送：通过串口发送LED的状态
 */


int main(void) {
    LED_Init();
    USART1_Init_Config();
    USART1_IT_Config();
    Read_Data_Init(&Read_Data);
    TIM3_Int_Init(7199, 9999);
    TIM5_Int_Init(7199, 9999 * 3);
    while (1) {
        LED_Display(&Read_Data);
    }
}

void TIM3_IRQHandler(void)   //TIM3中断
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
    {
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //清除TIMx更新中断标志
        printf("%c", Read_Data.LED_Data);
    }
}

void TIM5_IRQHandler(void)   //TIM3中断
{
    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
    {
        TIM_ClearITPendingBit(TIM5, TIM_IT_Update);  //清除TIMx更新中断标志
        Read_Data.Read_Data = Read_Data.Read_Data+0x00010000;
        if (Read_Data.Read_Data == 0x00030000)Read_Data.Read_Data = 0x00000000;
    }
}

void USART1_IRQHandler(void) {
    if (USART_GetITStatus(USART1, USART_IT_RXNE) == SET) {
        Read_Data.Read_USART = USART_ReceiveData(USART1);
        Read_Data.Read_Str_Flag++;
        if (Read_Data.Read_Str_Flag <= 4) {
            Read_Data.Read_Str = (Read_Data.Read_Str << 8) | Read_Data.Read_USART;
//            printf("%c", Read_Data.Read_USART); 发送成功反馈
        }
        if (Read_Data.Read_Str_Flag == 4) {
            if (Read_Data.Read_Str == 0xAABBCCDD) {
                Read_Data.Read_Data_Flag = 1;
//                printf("ok");		报头接收成功反馈
            }
        }
        if ((Read_Data.Read_Str_Flag > 4) && (Read_Data.Read_Data_Flag == 1)) {
            Read_Data.Read_Data = (Read_Data.Read_Data << 8) | Read_Data.Read_USART;
//            printf("%c", Read_Data.Read_USART);  //读取数据完成反馈
        }
        if ((Read_Data.Read_Str_Flag >= 8) && (Read_Data.Read_Data_Flag == 1)) {
            Read_Data.Read_Str_Flag = 0;
            Read_Data.Read_Data_Flag = 0;
        }
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}



