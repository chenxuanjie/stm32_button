#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "multi_button_def.h"


void button_GPIO_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint8_t read_button_GPIO(uint8_t button_id)
{
	// you can share the GPIO read function with multiple Buttons
	switch(button_id)
	{
		case btn1_id:
			return GPIO_ReadInputDataBit(B1_GPIO_Port, B1_Pin);
		case btn2_id:
			return GPIO_ReadInputDataBit(B2_GPIO_Port, B2_Pin);
		default:
			return 0;
	}
}

void __timer_start(void (*Function)(void),uint8_t size, uint8_t time)
{
	Function();
	Delay_ms(time);
}
