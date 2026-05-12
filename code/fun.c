#include "headfile.h"

void led_show(uint8_t led ,uint8_t mode)
{
    HAL_GPIO_WritePin(GPIOD ,GPIO_PIN_2,GPIO_PIN_SET);
   if(mode)
   {
   HAL_GPIO_WritePin(GPIOC ,(GPIO_PIN_8<< (led - 1)) ,GPIO_PIN_RESET );
   }
   else
   {
    HAL_GPIO_WritePin(GPIOC ,(GPIO_PIN_8<< (led - 1)) ,GPIO_PIN_SET );
   }
    HAL_GPIO_WritePin(GPIOD ,GPIO_PIN_2,GPIO_PIN_RESET);
}

char text[20] ;


void lcd_show(void )
{
	sprintf (text , " el ");
	LCD_DisplayStringLine(Line1 ,(uint8_t *)text);
}


