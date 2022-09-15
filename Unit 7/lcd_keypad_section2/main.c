/*
 * lcd_keypad_section2.c
 *
 * Created: 9/15/2022 2:03:36 AM
 * Author : Mohamed Reda
 */ 

#include <avr/io.h>
#include "LCD/lcd.h"
#include "Keypad/keypad.h"
#include <string.h>
#include "stdlib.h"
#include "calc.h"
char operand1[16]={};
char operand2[16] ={};
int count1 =0;
int count2 =0;
char process;
int flag=0;


int main(void)
{
   LCD_INIT();
    _delay_ms(50);
   keypad_init();
 
   char pressed_char;
    while (1) 
    {
		pressed_char = keypad_get_char();
		if(pressed_char == '?'){
			LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
			LCD_GOTO_XY(1,0);
			for(int i=0; i<16; i++){
				operand1[i] ='\0';
				operand2[i] ='\0';
			}
			count1=0;
			count2=0;
			flag=0;
    }
	else if(pressed_char == 'N'){
		
	}
	
   else if((pressed_char == '+') | (pressed_char == '-')| (pressed_char == '*')|(pressed_char == '/')){
	LCD_WRITE_CHAR(pressed_char);
	_delay_ms(1);
	flag =1;
	process = pressed_char;
	}
	else if(pressed_char == '='){
		LCD_WRITE_CHAR(pressed_char);
		_delay_ms(1);
		calculate(operand1,operand2,process);
		count1 =0;
		count2=0;
		flag=0;
	}
	else{
		if(flag == 0){
			LCD_WRITE_CHAR(pressed_char);
			_delay_ms(1);
			operand1[count1] = pressed_char;
			count1++;
		}
		else if(flag == 1){
			LCD_WRITE_CHAR(pressed_char);
			_delay_ms(1);
			operand2[count2] = pressed_char;
			count2++;
		}
	}
}
	}


