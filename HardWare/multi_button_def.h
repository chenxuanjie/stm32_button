#ifndef __MULTI_BUTTON_DEF_H
#define __MULTI_BUTTON_DEF_H


#define B1_GPIO_Port	GPIOB
#define B1_Pin			GPIO_Pin_1
#define B2_GPIO_Port	GPIOB
#define B2_Pin			GPIO_Pin_11

enum Button_IDs {
	btn1_id,
	btn2_id,
};

void button_GPIO_Init(void);
uint8_t read_button_GPIO(uint8_t button_id);
void __timer_start(void (*Function)(void),uint8_t size, uint8_t time);

#endif
