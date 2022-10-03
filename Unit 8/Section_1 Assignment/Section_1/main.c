/*
 * Section_1.c
 *
 * Created: 9/11/2022 7:58:05 PM
 * Author : Mohamed Reda
 */ 


#include <util/delay.h>
#include "Atmega32_Drivers.h"
#include "MCAL\GPIO.h"
#include "HAL\LCD.h"
#include "MCAL\UART.h"

#define F_CPU 8000000UL

int main(void)
{
	char* st;
	LCD_INIT();
	UART_INIT();
	LCD_GOTO_XY(1,0);
	
	LCD_WRITE_STRING("UART TR");
	_delay_ms(1500);
	
	unsigned char str[15] = "Learn in depth";
	UART_SEND_STRING(str);
	
	
	while (1)
	{
		LCD_GOTO_XY(2,0);
		st = UART_RECIEVE_STRING();
		LCD_WRITE_STRING(st);
		_delay_ms(10000);
		LCD_clear_screen();
		
		
		
	}
	
}

