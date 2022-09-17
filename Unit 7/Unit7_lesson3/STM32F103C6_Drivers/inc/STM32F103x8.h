/*
 * STM32F103x8.h
 *
 *  Created on: Sep 17, 2022
 *      Author: redam
 */

#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_

///-----------------------------------
//INCLUDES

#include "stdlib.h"
#include "stdint.h"

///**********************************



///------------------------------------
//Base addresses for Memories

#define FLASH_MEMORY_BASE								0x08000000UL
#define SYSTEM_MEMORY_BASE								0x1FFFF000UL
#define PERIPHERALS_BASE								0x40000000UL
#define SRAM_BASE										0x20000000UL

#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE				0xE0000000UL

//*************************************



//-------------------------------------
//Base addresses for AHB Peripherals
#define RCC_BASE		0x40021000UL

//*****

///Base addresses for APB2 Peripherals

//GPIO

//GPIO A and GPIO B are totally included in LQFP48 package
#define GPIOA_BASE		0x40010800UL
#define GPIOB_BASE		0x40010C00UL

//GPIO C and GPIO D are partially included in LQFP48 package
#define GPIOC_BASE		0x40011000UL
#define GPIOD_BASE		0x40011400UL

//GPIO E are not included in LQFP48 package
#define GPIOE_BASE		0x40011800UL

//------

//AFIO
#define AFIO_BASE		0x40010000UL
//------


//EXTI
#define EXTI_BASE		0x40010400UL
//------

//----------------------------------


///---------------------------------
//Peripherals registers

//RCC registers
typedef struct
{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_Typedef;



//GPIO registers
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Typedef;


//AFIO registers
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	volatile uint32_t reserved;
	volatile uint32_t MAPR2;
}AFIO_Typedef;


//EXTI registers
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXTI_Typedef;


//*******************************


//-------------------------------
//Peripherals instants

//GPIO instants
#define GPIOA		(GPIO_Typedef*) GPIOA_BASE
#define GPIOB		(GPIO_Typedef*) GPIOB_BASE
#define GPIOC		(GPIO_Typedef*) GPIOC_BASE
#define GPIOD		(GPIO_Typedef*) GPIOD_BASE
#define GPIOE		(GPIO_Typedef*) GPIOE_BASE


//RCC instant
#define RCC			((RCC_Typedef*) RCC_BASE)


//AFIO instant
#define AFIO		(AFIO_Typedef*) AFIO_BASE

//********************************



//--------------------------------
//Clock enable MACROS

#define GPIOA_Clock_Enable()   (RCC->APB2ENR |= 1<<2)
#define GPIOB_Clock_Enable()   (RCC->APB2ENR |= 1<<3)
#define GPIOC_Clock_Enable()   (RCC->APB2ENR |= 1<<4)
#define GPIOD_Clock_Enable()   (RCC->APB2ENR |= 1<<5)
#define GPIOE_Clock_Enable()   (RCC->APB2ENR |= 1<<6)
#define AFIO_Clock_Enable()    (RCC->APB2ENR |= 1<<0)

//********************************



//--------------------------------
//Generic Macros





//*********************************


























#endif /* INC_STM32F103X8_H_ */
