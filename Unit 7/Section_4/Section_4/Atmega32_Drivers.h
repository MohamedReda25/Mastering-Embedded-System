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


//GPIOA
#define PORTA *(unsigned volatile char* )(0x3B)
#define DDRA  *(unsigned volatile char* )(0x3A)
#define PINA  *(unsigned volatile char* )(0x39)

//GPIOB
#define PORTB *(unsigned volatile char* )(0x38)
#define DDRB  *(unsigned volatile char* )(0x37)
#define PINB  *(unsigned volatile char* )(0x36)

//GPIOC
#define PORTC *(unsigned volatile char* )(0x35)
#define DDRC  *(unsigned volatile char* )(0x34)
#define PINC  *(unsigned volatile char* )(0x33)

//GPIOD
#define PORTD *(unsigned volatile char* )(0x32)
#define DDRD  *(unsigned volatile char* )(0x31)
#define PIND  *(unsigned volatile char* )(0x30)



//Addresses of GPIO_ Prephirals

#define portA (uint8_t* )(0x3B)
#define portB (uint8_t* )(0x38)
#define portC (uint8_t* )(0x35)
#define portD (uint8_t* )(0x32)












#endif /* ATMEGA32_DRIVERS_H_ */