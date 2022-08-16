/*
 * main.c
 *
 *  Created on: Aug 12, 2022
 *      Author: redam
 */
#include "Platform_Types.h"
#include "stdio.h"
#include "stdlib.h"
#include "lifo.h"

uint32 buffer1[5];

int main(){
	uint32 i;
	uint32 temp=0;
	LIFO_BUFF_t uart_lifo, I2C_lifo;
	LIFO_INIT(&uart_lifo,buffer1,5);
	uint32* buffer2 = malloc(5*sizeof(uint32));
	LIFO_INIT(&I2C_lifo,buffer2,5);

	for(int i=0; i<5; i++){
		if(LIFO_PUSH(&uart_lifo,i) == LIFO_NO_ERROR){
			printf("UART_LIFO_push : %d\n",i);
		}
	}
	for(i=0; i<5; i++){
		if(LIFO_POP(&uart_lifo ,&temp) == LIFO_NO_ERROR)
		{
			printf("UART_LIFO_pop : %d\n",temp);
		}
	}



}
