/*
 * GPIO.c
 *
 * Created: 9/28/2022 2:03:05 AM
 *  Author: redam
 */ 
#include "..\Atmega32_Drivers.h"
#include "GPIO.h"


void MCAL_GPIO_INIT( uint8_t* GPIOx, GPIO_Pinconfig_t* pin_config){
	if(pin_config->Mode == GPIO_Output){
		*(volatile uint8_t*)(GPIOx -1) |= pin_config->Pin_number;
	}
	else{
		*(volatile uint8_t*)(GPIOx -1) &= ~(pin_config->Pin_number);
	}
	
}




void MCAL_GPIO_DEINIT( uint8_t* GPIOx){
*(GPIOx)  = (uint8_t)0x00;
*(GPIOx-1) = (uint8_t)0x00;
}



void MCAL_GPIO_WRITE_PIN(uint8_t* GPIOx, uint8_t pin_number , uint8_t value){
	if(value == GPIO_PIN_SET){
		*(GPIOx) |= pin_number;
	}
	else{
		*(GPIOx) &= ~(pin_number);
	}
}


void MCAL_GPIO_WRITE_PORT(uint8_t* GPIOx,uint8_t value){
	*(GPIOx) = value;
}

uint8_t MCAL_GPIO_READ_PIN(uint8_t* GPIOx, uint8_t pin_number){
	uint8_t temp;
	if((*(GPIOx-2) & pin_number) != GPIO_PIN_RESET){
		temp = GPIO_PIN_SET;
	}
	else{
		temp = GPIO_PIN_RESET;	
	}
	return temp;
}


uint8_t MCAL_GPIO_READ_PORT(uint8_t* GPIOx){
		uint8_t temp = *(GPIOx-2);
		return temp;	
}


void MCAL_GPIO_TogglePin(uint8_t* GPIOx, uint8_t pin_number){
	*(GPIOx) ^= pin_number;
}