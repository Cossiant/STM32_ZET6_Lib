#include "stm32f10x.h"
#include "LED.H"


int main(void)
{
	LED_B_Display_Init();
	LED_E_Display_Init();
	while(1)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		DS_delay(5000000);
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
		DS_delay(5000000);
	}
}

