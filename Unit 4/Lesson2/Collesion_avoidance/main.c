/*
 * main.c
 *
 *  Created on: Aug 15, 2022
 *      Author: redam
 */


#include "CA.h"
#include "DC.h"
#include "US.h"

void setup(){
	//init all drivers
	//init IRQ
	//init blocks
	US_init();
	DC_init();
	CA_State = STATE(CA_waiting);
	US_State = STATE(US_busy);
	DC_State = STATE(DC_idle);

}

void main(){
	volatile int i;
	setup();
	while(1)
	{
		//call state for each block
		US_State();
		CA_State();
		DC_State();
		//delay
		for(i=0; i< 1000; i++);
	}
}
