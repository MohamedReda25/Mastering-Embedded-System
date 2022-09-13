/*
 * Section_1.c
 *
 * Created: 9/11/2022 7:58:05 PM
 * Author : Mohamed Reda
 */ 


#include "mem_map.h"
#include <util/delay.h>
#include "utils.h"

#define F_CPU 8000000UL
int main(void)
{
	DDRA = 0xFF;
	ClearBit(DDRC,0);
	SetBit(PORTC,0);
	unsigned char count =0;
  
    while (1) 
    {
		if(ReadBit(PINC,0) == 0){
			if(count == 8){
				PORTA =0;
				count = 0;
				
			}
			SetBit(PORTA,count);
			count++;
			
			_delay_ms(250);
		}
		
	}
}

