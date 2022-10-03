/*
 * Atmega32_Drivers.h
 *
 * Created: 9/28/2022 1:39:09 AM
 *  Author: redam
 */ 


#ifndef ATMEGA32_DRIVERS_H_
#define ATMEGA32_DRIVERS_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdlib.h>
#include <stdint.h>




//-----------------------------
//Base addresses
//-----------------------------


//GPIOA registers
#define PORTA *(unsigned volatile char* )(0x3B)
#define DDRA  *(unsigned volatile char* )(0x3A)
#define PINA  *(unsigned volatile char* )(0x39)

//GPIOB registers
#define PORTB *(unsigned volatile char* )(0x38)
#define DDRB  *(unsigned volatile char* )(0x37)
#define PINB  *(unsigned volatile char* )(0x36)

//GPIOC registers
#define PORTC *(unsigned volatile char* )(0x35)
#define DDRC  *(unsigned volatile char* )(0x34)
#define PINC  *(unsigned volatile char* )(0x33)

//GPIOD registers
#define PORTD *(unsigned volatile char* )(0x32)
#define DDRD  *(unsigned volatile char* )(0x31)
#define PIND  *(unsigned volatile char* )(0x30)



//Addresses of GPIO_ Prephirals

#define portA (uint8_t* )(0x3B)
#define portB (uint8_t* )(0x38)
#define portC (uint8_t* )(0x35)
#define portD (uint8_t* )(0x32)


//UART registers

/* USART Baud Rate Register Low */
#define UBRRL		*(volatile uint8_t*)(0x29)

/* USART Control and Status Register A */
#define UCSRA		*(volatile uint8_t*)(0x2B)

/* USART Control and Status Register B */
#define UCSRB		*(volatile uint8_t*)(0x2A)

/* USART I/O Data Register */
#define UDR			*(volatile uint8_t*)(0x2C)








#endif /* ATMEGA32_DRIVERS_H_ */