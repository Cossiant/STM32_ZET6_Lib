#include "include.h"

/*  д��֮��ǵ���include.h��������д����ļ�
*   ����ǰ�ǵ���Keil�������ø�д����ļ�������h��c�ļ�
*   ��Clion���б༭��ʱ��ǵ���GBK��ʽ���¼��أ�������������
*   Clion�ᱨwhile��ѭ�����棬�����
*/
USART_Read_Data Read_Data;

/*  �˳���ʵ�ֵ�Ŀ�꣺
 * 1�����ڷ��ͣ�����ָ�ͷ��ָ��
 * 2��LED״̬���ƣ�ͨ�����ڶ�����������������С�ƿ���
 * 3��LED״̬��ȡ����ʱ��С������״̬��ȡ
 * 4��LED״̬���ͣ�ͨ�����ڷ���LED��״̬
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

void TIM3_IRQHandler(void)   //TIM3�ж�
{
    if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
    {
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);  //���TIMx�����жϱ�־
        printf("%c", Read_Data.LED_Data);
    }
}

void TIM5_IRQHandler(void)   //TIM3�ж�
{
    if (TIM_GetITStatus(TIM5, TIM_IT_Update) != RESET)  //���TIM3�����жϷ������
    {
        TIM_ClearITPendingBit(TIM5, TIM_IT_Update);  //���TIMx�����жϱ�־
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
//            printf("%c", Read_Data.Read_USART); ���ͳɹ�����
        }
        if (Read_Data.Read_Str_Flag == 4) {
            if (Read_Data.Read_Str == 0xAABBCCDD) {
                Read_Data.Read_Data_Flag = 1;
//                printf("ok");		��ͷ���ճɹ�����
            }
        }
        if ((Read_Data.Read_Str_Flag > 4) && (Read_Data.Read_Data_Flag == 1)) {
            Read_Data.Read_Data = (Read_Data.Read_Data << 8) | Read_Data.Read_USART;
//            printf("%c", Read_Data.Read_USART);  //��ȡ������ɷ���
        }
        if ((Read_Data.Read_Str_Flag >= 8) && (Read_Data.Read_Data_Flag == 1)) {
            Read_Data.Read_Str_Flag = 0;
            Read_Data.Read_Data_Flag = 0;
        }
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);
    }
}



