/*
 * keypad.h
 *
 * Created: 9/15/2022 4:21:48 AM
 *  Author: redam
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL
#include "avr/io.h"
#include "avr/delay.h" 

# define F_CPU 1000000UL
#define keypad_PORT PORTD
#define keypad_PORT_dir DDRD
#define keypad_PIN PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7





void keypad_init();
char keypad_get_char();




#endif /* KEYPAD_H_ */