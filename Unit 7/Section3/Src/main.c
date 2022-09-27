/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "lcd.h"
#include "Keypad.h"
#include "stm32f103x8_GPIO_driver.h"
#include "STM32F103x8.h"

#define ZERO 0x01
#define ONE 0x79
#define TWO 0x24
#define THREE 0x30
#define FOUR 0x4C
#define FIVE 0x12
#define SIX 0x02
#define SEVEN 0x19
#define EIGHT 0x00
#define NINE 0x10




void wait_ms(int time){
	for(int i=0; i<time; i++){
		for(int j=0; j<255; j++);
	}
}


void seg7_init(){
	GPIO_Pinconfig_t config;
	config.Pin_number = GPIOx_PIN9;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &config);

	config.Pin_number = GPIOx_PIN10;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &config);

	config.Pin_number = GPIOx_PIN11;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &config);

	config.Pin_number = GPIOx_PIN12;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &config);

	config.Pin_number = GPIOx_PIN13;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &config);

	config.Pin_number = GPIOx_PIN14;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &config);

	config.Pin_number = GPIOx_PIN15;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(GPIOB, &config);

}


int main(void)
{
	GPIOA_Clock_Enable();
	GPIOB_Clock_Enable();
	LCD_INIT();
	seg7_init();
	unsigned char key_pressd;
	LCD_WRITE_STRING("Hey There");
	wait_ms(500);
	LCD_clear_screen();
	unsigned char seg[] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE,ZERO};
	unsigned char lcd[] = {'0','1','2','3','4','5','6','7','8','9','0'};
	for(int i=0; i<11; i++){
		MCAL_GPIO_WRITE_PORT(GPIOB, seg[i]<<9);
		LCD_WRITE_CHAR(lcd[i]);
		wait_ms(600);
	}
	LCD_clear_screen();
	Keypad_init();
	LCD_WRITE_STRING("Keypad is ready");
	wait_ms(500);
	LCD_clear_screen();

	/* Loop forever */
	while(1){
		key_pressd = Keypad_getkey();
		switch(key_pressd){
		case 'A':
			break;
		case '?':
			LCD_clear_screen();
			break;
		default:
			LCD_WRITE_CHAR(key_pressd);
			break;
		}
	}
}