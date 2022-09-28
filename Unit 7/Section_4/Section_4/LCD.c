/*
 * LCDc.c
 *
 * Created: 9/28/2022 2:37:24 AM
 *  Author: redam
 */ 

#include "LCD.h"

GPIO_Pinconfig_t config;

void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_lcd_kick(){
	//LCD_CTRL |= (1 << EN_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,EN_SWITCH,GPIO_PIN_SET);
	
	_delay_ms(50);
	
	//LCD_CTRL &= ~(1 << EN_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,EN_SWITCH,GPIO_PIN_RESET);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position){
	if (line == 1)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}
	}
	if (line == 2)
	{
		if (position < 16 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}

void LCD_INIT(){
	_delay_ms(20);
	//DataDir_LCD_CTRL |= (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	config.Pin_number = EN_SWITCH;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portB,&config);
	
	config.Pin_number = RS_SWITCH;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portB,&config);
	
	config.Pin_number = RW_SWITCH;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portB,&config);
	
	
	
	//LCD_CTRL &= ~ (1<<EN_SWITCH | 1<<RS_SWITCH | 1<<RW_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,EN_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	
	//DataDir_LCD_PORT = 0xFF;
	config.Pin_number = GPIO_PIN0;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN1;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN2;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN3;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	
	config.Pin_number = GPIO_PIN4;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN5;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN6;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN7;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	
	_delay_ms(15);
	LCD_clear_screen();
	#ifdef EIGHT_BIT_MODE
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
	#endif
	#ifdef FOUR_BIT_MODE
	//LCD_WRITE_COMMAND(0x02);		/* send for 4 bit initialization of LCD  */
	//LCD_WRITE_COMMAND(0x28);              /* 2 line, 5*7 matrix in 4-bit mode */
	//LCD_WRITE_COMMAND(0x0c);              /* Display on cursor off*/
	//LCD_WRITE_COMMAND(0x06);              /* Increment cursor (shift cursor to right)*/
	//LCD_WRITE_COMMAND(0x01);
	LCD_WRITE_COMMAND(0x02);
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
}

void LCD_check_lcd_isbusy(){
	//DataDir_LCD_PORT &= ~(0xFF<<DATA_shift);
	#ifdef EIGHT_BIT_MODE
	config.Pin_number = GPIO_PIN0;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN1;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN2;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN3;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN4;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN5;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN6;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN7;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	#endif
	
	
	
	#ifdef FOUR_BIT_MODE
	config.Pin_number = GPIO_PIN4;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN5;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN6;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN7;
	config.Mode = GPIO_Input;
	MCAL_GPIO_INIT(portA,&config);
	#endif
	
	
	
	
	
	//LCD_CTRL |= (1 << RW_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_SET);
	
	//LCD_CTRL &= ~(1 << RS_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_SET);
	
	LCD_lcd_kick();
	
	//DataDir_LCD_PORT |= (0xFF<<DATA_shift);
	#ifdef EIGHT_BIT_MODE
	config.Pin_number = GPIO_PIN0;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN1;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN2;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN3;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN4;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN5;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN6;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN7;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	#endif
	
	#ifdef FOUR_BIT_MODE
	
	config.Pin_number = GPIO_PIN4;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN5;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN6;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	
	config.Pin_number = GPIO_PIN7;
	config.Mode = GPIO_Output;
	MCAL_GPIO_INIT(portA,&config);
	#endif
	
	
	//LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	
}


void LCD_WRITE_COMMAND(unsigned char command){
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	//LCD_PORT = command;
	MCAL_GPIO_WRITE_PORT(LCD_PORT,command);
	
	//LCD_CTRL &= ~((1 << RS_SWITCH) | (1<<RW_SWITCH));
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	
	
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	*(LCD_PORT) = (*(LCD_PORT) & 0x0F) | (command & 0xF0);
	//LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_RESET);
	
	LCD_lcd_kick ();
	*(LCD_PORT) = (*(LCD_PORT) & 0x0F) | (command << 4);
	//LCD_CTRL &= ~ ((1<<RW_SWITCH)|(1<<RS_SWITCH));
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_RESET);
	
	LCD_lcd_kick();
	#endif
}

void LCD_WRITE_CHAR(unsigned char character){
	#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	
	//LCD_PORT = character;
	MCAL_GPIO_WRITE_PORT(LCD_PORT,character);
	
	//LCD_CTRL &= ~(1 << RW_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	
	//LCD_CTRL |= (1 << RS_SWITCH);
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_SET);
	_delay_ms(1);
	LCD_lcd_kick();
	#endif
	#ifdef FOUR_BIT_MODE
	//LCD_check_lcd_isbusy();
	*(LCD_PORT) = (*(LCD_PORT) & 0x0F) | (character & 0xF0);
	
	//LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_SET);
	
	//LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	
	
	LCD_lcd_kick();
	
	*(LCD_PORT) = (*(LCD_PORT) & 0x0F) | (character << 4);
	
	//LCD_CTRL |= 1<<RS_SWITCH; //turn RS ON for Data mode.
	MCAL_GPIO_WRITE_PIN(portB,RS_SWITCH,GPIO_PIN_SET);
	
	//LCD_CTRL &= ~ (1<<RW_SWITCH);//turn RW off so you can write.
	MCAL_GPIO_WRITE_PIN(portB,RW_SWITCH,GPIO_PIN_RESET);
	
	LCD_lcd_kick ();
	#endif
}

void LCD_WRITE_STRING(char* string){
	int count = 0;
	while (*string > 0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}
void lcd_dipaly_number(int number){
	char str[16];
	sprintf(str,"%d",number);
	LCD_WRITE_STRING(str);
}

void lcd_dipaly_real_number(float number){
	char strr[16];
	
	char *tmpsign = (number < 0) ? "-" : "";
	float tmpval = (number < 0) ? -number : number;
	
	int tmpint1 = tmpval;
	float tmpfrac = tmpval - tmpint1;
	int tmpint2 = tmpfrac * 1000;
	
	sprintf(strr,"%s%d.%03d",tmpsign,tmpint1,tmpint2);
	
	LCD_WRITE_STRING(strr);
}