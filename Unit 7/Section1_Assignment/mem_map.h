/*
 * mem_map.h
 *
 * Created: 9/11/2022 8:00:38 PM
 *  Author: Mohamed Reda 
 */ 


#ifndef MEM_MAP_H_
#define MEM_MAP_H_

#define PORTA *(unsigned volatile char* )(0x3B)
#define DDRA  *(unsigned volatile char* )(0x3A)
#define PINA  *(unsigned volatile char* )(0x39)


#define PORTC *(unsigned volatile char* )(0x35)
#define DDRC  *(unsigned volatile char* )(0x34)
#define PINC  *(unsigned volatile char* )(0x33)

#define PORTD *(unsigned volatile char* )(0x32)
#define DDRD  *(unsigned volatile char* )(0x31)
#define PIND  *(unsigned volatile char* )(0x30)





#endif /* MEM_MAP_H_ */