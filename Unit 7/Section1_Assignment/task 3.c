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
	
	ClearBit(DDRD,0);
	ClearBit(PORTD,0);  
	SetBit(DDRD,4);
	
  
    while (1) 
    {
		if(ReadBit(PIND,0) == 1){
			SetBit(PORTD,4);
			_delay_ms(1000);
			ClearBit(PORTD,4);
		}
		
		
	}
	
}

