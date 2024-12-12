#include "stm32f10x.h"                  // Device header
#include "multi_button.h"
#include "multi_button_def.h"
#include "OLED.h"
#include "Delay.h"


struct Button btn1;
struct Button btn2;


void BTN1_PRESS_DOWN_Handler(void* btn){
	OLED_Clear();
	OLED_ShowString(1,1,"btn press down");
}
void BTN1_PRESS_UP_Handler(void* btn){
	OLED_ShowString(1,1,"btn press up  ");
}
void BTN1_PRESS_REPEAT_Handler(void* btn){
	OLED_ShowString(2,1,"btn press repeat");
}
void BTN1_SINGLE_Click_Handler(void* btn){
	OLED_ShowString(3,1,"btn single click");
}
void BTN1_DOUBLE_Click_Handler(void* btn){
	OLED_ShowString(3,1,"btn double click");
}
void BTN1_LONG_PRESS_START_Handler(void* btn){
	OLED_ShowString(3,1,"btn lpress start");
}
void BTN1_LONG_PRESS_HOLD_Handler(void* btn){
	OLED_ShowString(4,1,"btn lpress hold");
}

void BTN2_PRESS_DOWN_Handler(void* btn)
{
	//do something...
	OLED_ShowString(3,2,"btn2 press down");
}


int main(void)
{
	OLED_Init();
	button_GPIO_Init();
	
	button_init(&btn1, read_button_GPIO, 0, btn1_id);
	button_init(&btn2, read_button_GPIO, 0, btn2_id);

	button_attach(&btn1, PRESS_DOWN,       BTN1_PRESS_DOWN_Handler);
	button_attach(&btn1, PRESS_UP,         BTN1_PRESS_UP_Handler);
	button_attach(&btn1, PRESS_REPEAT,     BTN1_PRESS_REPEAT_Handler);
	button_attach(&btn1, SINGLE_CLICK,     BTN1_SINGLE_Click_Handler);
	button_attach(&btn1, DOUBLE_CLICK,     BTN1_DOUBLE_Click_Handler);
	button_attach(&btn1, LONG_PRESS_START, BTN1_LONG_PRESS_START_Handler);
	button_attach(&btn1, LONG_PRESS_HOLD,  BTN1_LONG_PRESS_HOLD_Handler);
	
	button_attach(&btn2, PRESS_DOWN,       BTN2_PRESS_DOWN_Handler);	
	
	button_start(&btn1);
	button_start(&btn2);
	

	while(1)
	{
		__timer_start(button_ticks, 0, 5);	
	}
}

