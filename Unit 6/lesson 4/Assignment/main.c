/*
 * main.c
 *
 * Created: 9/6/2022 5:17:58 AM
 *  Author: Mohamed Reda
 */ 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 8000000UL
#define IO_BASE	0x20
#define IO_PORTD	*(volatile int*) (IO_BASE+0x12)
#define IO_DDRD		*(volatile int*) (IO_BASE+0x11)
#define INT_MCUCR	*(volatile int*) (IO_BASE+0x35)
#define INT_MCUCSR	*(volatile int*) (IO_BASE+0x34)
#define INT_GICR	*(volatile int*) (IO_BASE+0x3B)





int main(void)
{
	//set intr0 to logical
	INT_MCUCR |= (1<<0);
	INT_MCUCR &= ~(1<<1);
	
	//set intr1 to rising
	INT_MCUCR |= (1<<2);
	INT_MCUCR |= (1<<3);
	
	//set intr2 to falling 
	INT_MCUCSR &= ~(1<<6);
	
	//enable interrupts 0,1,2
	INT_GICR |= (1<<5);
	INT_GICR |= (1<<6);
	INT_GICR |= (1<<7);
	//directions of the leds as outputs
	DDRD |=(1<<5);
	DDRD |=(1<<6);
	DDRD |=(1<<7);
	
	sei();
    while(1)
    {
		IO_PORTD &= ~(1<<5);
		IO_PORTD &= ~(1<<6);
		IO_PORTD &= ~(1<<7);
        //TODO:: Please write your application code 
    }
	

}

ISR(INT0_vect){
	IO_PORTD |= (1<<5);
	_delay_ms(1000);
}
ISR(INT1_vect){
	IO_PORTD |= (1<<6);
	_delay_ms(1000);
}

ISR(INT2_vect){
	IO_PORTD |= (1<<7);
	_delay_ms(1000);
}