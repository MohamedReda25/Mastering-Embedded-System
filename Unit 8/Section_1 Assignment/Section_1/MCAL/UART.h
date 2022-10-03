/*
 * UART.h
 *
 * Created: 10/2/2022 4:15:14 AM
 *  Author: redam
 */ 


#ifndef UART_H_
#define UART_H_

#include "..\Atmega32_Drivers.h"
#include "avr\io.h"





void UART_INIT(void);
void UART_SEND(uint8_t data);
uint8_t UART_RECIEVE(void);
uint32_t UART_RECIEVE_U32NUM(void);
void UART_SEND_U32NUM(uint32_t data);
void UART_SEND_STRING(unsigned char* str);
char* UART_RECIEVE_STRING(void);






#endif /* UART_H_ */