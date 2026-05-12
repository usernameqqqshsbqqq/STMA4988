#include "headfile.h"

uint8_t B1_state;
uint8_t B1_last_state;
uint8_t B2_state;
uint8_t B2_last_state;
uint8_t B3_state;
uint8_t B3_last_state;
uint8_t B4_state;
uint8_t B4_last_state;

void key_scan(void )
{
    B1_state = HAL_GPIO_ReadPin(GPIOB ,GPIO_PIN_0);
	B2_state = HAL_GPIO_ReadPin(GPIOB ,GPIO_PIN_1);
	B3_state = HAL_GPIO_ReadPin(GPIOB ,GPIO_PIN_2);
	B4_state = HAL_GPIO_ReadPin(GPIOA ,GPIO_PIN_0);
	if(B1_state == 0 && B1_last_state == 1)
	{
	 TIM3->ARR = 800-1;       // 1250 - 
    TIM3->CCR1 = 400;       
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
	HAL_Delay(650);
    A4988_Stop();
	}
	B1_last_state =  B1_state ;
	
		if(B2_state == 0 && B2_last_state == 1)
	{
	 led_show(1,0);
	}
	B2_last_state =  B2_state ;	
	if(B3_state == 0 && B3_last_state == 1)
	{
	 
	}
	B3_last_state =  B3_state ;	
	if(B4_state == 0 && B4_last_state == 1)
	{
	 
	}
	B4_last_state =  B4_state ;

}

