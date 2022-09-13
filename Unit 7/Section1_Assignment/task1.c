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
  
    while (1) 
    {
		for(int i=0; i<8; i++){
			SetBit(PORTA,i);
			_delay_ms(1200);
		}
		for(int i=7; i>=0; i--){
			ClearBit(PORTA,i);
			_delay_ms(1200);
		}
		
    }
	
}

