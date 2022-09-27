/*
 * Keypad.h
 *
 *  Created on: Sep 21, 2022
 *      Author: redam
 */

#ifndef KEYPAD_KEYPAD_H_
#define KEYPAD_KEYPAD_H_


# define F_CPU 1000000UL
#include "stm32f103x8_GPIO_driver.h"
#include "STM32F103x8.h"

#define keypad_PORT GPIOB

#define R0 GPIOx_PIN0
#define R1 GPIOx_PIN1
#define R2 GPIOx_PIN3
#define R3 GPIOx_PIN4

#define C0 GPIOx_PIN5
#define C1 GPIOx_PIN6
#define C2 GPIOx_PIN7
#define C3 GPIOx_PIN8


#define KEYPAD_PORT   GPIOB

void Keypad_init();
char Keypad_getkey();




void keypad_init();
char keypad_get_char();




#endif /* KEYPAD_KEYPAD_H_ */
