/*
 * calc.c
 *
 * Created: 9/15/2022 7:29:00 AM
 *  Author: redam
 */ 
#include "calc.h"
#include "LCD/lcd.h"
#include "string.h"
#include "stdlib.h"



void calculate(char op1[],char op2[],char process){
	LCD_GOTO_XY(2,0);
	if(process == '+'){
		int num = atoi(op1) + atoi(op2);
		lcd_dipaly_number(num);
	}
	if(process == '-'){
		int num = atoi(op1) - atoi(op2);
		lcd_dipaly_number(num);
	}
	if(process == '*'){
		int num = atoi(op1) * atoi(op2);
		lcd_dipaly_number(num);
	}
	if(process == '/'){
		float num = atof(op1) / atof(op2);
		lcd_dipaly_real_number(num);
	}
	
}