/*
 * UART.c
 *
 * Created: 10/2/2022 4:15:26 AM
 *  Author: redam
 */ 
#include "UART.h"
#include "..\utils.h"

char arr[20];
void UART_INIT(void){
	
	// buad rate
	UBRRL =51;
	
	//normal mode
	ClearBit(UCSRA,U2X);
	
	
	//frame
	//no parity
	
	//8 bit data
	
	
	//Enable
	SetBit(UCSRB,TXEN);
	SetBit(UCSRB,RXEN);
		
	
	
}
void UART_SEND(uint8_t data){
	while(!ReadBit(UCSRA,UDRE));
	UDR = data;
	
	
}
uint8_t UART_RECIEVE(void){
	while(!ReadBit(UCSRA,RXC));
	return UDR;
	
}


void UART_SEND_U32NUM(uint32_t data){
	
	uint8_t* p = &data;
	UART_SEND(p[0]);
	UART_SEND(p[1]);
	UART_SEND(p[2]);
	UART_SEND(p[3]);
	
}


uint32_t UART_RECIEVE_U32NUM(void){
	uint32_t num;
	uint8_t* p =&num;
	p[0] = UART_RECIEVE();
	p[1] = UART_RECIEVE();
	p[2] = UART_RECIEVE();
	p[3] = UART_RECIEVE();
	return num;
	
	
}

void UART_SEND_STRING(unsigned char* str){
	unsigned char* temp =str;
	while(1){
		if(*(temp) == '\0'){
			UART_SEND(*(temp));
			break;
		}
		UART_SEND(*(temp));
		temp++;
	}
	
}

 char* UART_RECIEVE_STRING(void){
	 char* temp1 = arr;
	 
	while(1){
		*(temp1) = UART_RECIEVE();
		if(*(temp1) == '#'){
			break;
		}
		temp1++;
	}
	return arr;
	
	
}