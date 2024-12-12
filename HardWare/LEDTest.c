#include "stm32f10x.h"                  // Device header
#include "LEDTest.h"

#define LEDTEST_RCC		RCC_APB2Periph_GPIOC
#define LEDTEST_GPIO	GPIOC
#define LEDTEST_PIN		GPIO_Pin_13


void LEDTest_Init(void)
{
	RCC_APB2PeriphClockCmd(LEDTEST_RCC, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = LEDTEST_PIN;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(LEDTEST_GPIO, &GPIO_InitStructure);
	
	GPIO_SetBits(LEDTEST_GPIO, LEDTEST_PIN);
}

void LEDTest_ON(void)
{
	GPIO_ResetBits(LEDTEST_GPIO, LEDTEST_PIN);
}

void LEDTest_OFF(void)
{
	GPIO_SetBits(LEDTEST_GPIO, LEDTEST_PIN);
}

void LEDTest_Turn(void)
{
	if (GPIO_ReadOutputDataBit(LEDTEST_GPIO, LEDTEST_PIN) == 0)
	{
		GPIO_SetBits(LEDTEST_GPIO, LEDTEST_PIN);
	}
	else
	{
		GPIO_ResetBits(LEDTEST_GPIO, LEDTEST_PIN);
	}
}

