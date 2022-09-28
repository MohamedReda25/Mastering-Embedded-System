/*
 * Section_1.c
 *
 * Created: 9/11/2022 7:58:05 PM
 * Author : Mohamed Reda
 */ 


#include <util/delay.h>
#include "Atmega32_Drivers.h"
#include "GPIO.h"
#include "LCD.h"

#define F_CPU 8000000UL

GPIO_Pinconfig_t config;
int main(void)
{

	LCD_INIT();
	_delay_ms(50);
	LCD_WRITE_STRING("LEARN IN DEPTH");	
	
	
	
	
	while (1)
	{
		
		
		
	}
	
}

