//Eng. Mohamed Gamal

#ifndef MCU_DEVICE_HEADER_STM32F103X6_H_
#define MCU_DEVICE_HEADER_STM32F103X6_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdlib.h>
#include <stdint.h>


//-----------------------------
//Base addresses for Memories
//-----------------------------
#define FLASH_MEMORY_BASE  							 0x08000000UL
#define SYSTEM_MEMORY_BASE 							 0x1FFFF000UL
#define PERIPHERALS_BASE    						 0x40000000UL
#define SRAM_BASE            						 0x20000000UL

#define CORTEX_M3_INTERNAL_PERIPHERALS_BASE       	 0xE0000000UL


//NVIC register MAP
#define NVIC_BASE								     0xE000E100UL
#define NVIC_ISER0									 *(volatile uint32_t *)(NVIC_BASE + 0x00)
#define NVIC_ISER1									 *(volatile uint32_t *)(NVIC_BASE + 0x04)
#define NVIC_ISER2									 *(volatile uint32_t *)(NVIC_BASE + 0x08)
#define NVIC_ICER0									 *(volatile uint32_t *)(NVIC_BASE + 0x80)
#define NVIC_ICER1									 *(volatile uint32_t *)(NVIC_BASE + 0x84)
#define NVIC_ICER2									 *(volatile uint32_t *)(NVIC_BASE + 0x88)






//-----------------------------
//Base addresses for AHB Peripherals
//-----------------------------
#define RCC_BASE  0x40021000


//-----------------------------
//Base addresses for APB2 Peripherals
//-----------------------------
#define GPIOA_BASE	  0x40010800UL
#define GPIOB_BASE	  0x40010C00UL
#define GPIOC_BASE	  0x40011000UL
#define GPIOD_BASE	  0x40011400UL
#define GPIOE_BASE	  0x40011800UL


//EXTI
#define EXIT_BASE	  0x40010400UL


//AFIO
#define AFIO_BASE     0x40010000UL

//=================================================================//


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
typedef struct
{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_Typedef;




//EXTI registers
typedef struct
{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;
}EXIT_Typedef;




//AFIO registers
typedef struct
{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
	uint32_t Reserved;
	volatile uint32_t MAPR2;
}AFIO_Typedef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: GPIOx
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA   ((GPIO_Typedef*) GPIOA_BASE)
#define GPIOB   ((GPIO_Typedef*) GPIOB_BASE)
#define GPIOC   ((GPIO_Typedef*) GPIOC_BASE)
#define GPIOD   ((GPIO_Typedef*) GPIOD_BASE)
#define GPIOE   ((GPIO_Typedef*) GPIOE_BASE)

//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: RCC
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC    ((RCC_Typedef*) RCC_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: EXIT
//-*-*-*-*-*-*-*-*-*-*-*
#define EXTI   ((EXIT_Typedef*) EXIT_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants: AFIO
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO   ((AFIO_Typedef*) AFIO_BASE)

//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define AFIO_Clock_Enable()    (RCC->APB2ENR |= 1<<0)
#define GPIOA_Clock_Enable()   (RCC->APB2ENR |= 1<<2)
#define GPIOB_Clock_Enable()   (RCC->APB2ENR |= 1<<3)
#define GPIOC_Clock_Enable()   (RCC->APB2ENR |= 1<<4)
#define GPIOD_Clock_Enable()   (RCC->APB2ENR |= 1<<5)
#define GPIOE_Clock_Enable()   (RCC->APB2ENR |= 1<<6)

//=================================================================//

//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*-

//IVT
//------------------------

//EXTI
#define EXTI0_IRQ		6
#define EXTI1_IRQ		7
#define EXTI2_IRQ		8
#define EXTI3_IRQ		9
#define EXTI4_IRQ		10
#define EXTI5_IRQ		23
#define EXTI6_IRQ		23
#define EXTI7_IRQ		23
#define EXTI8_IRQ		23
#define EXTI9_IRQ		23
#define EXTI10_IRQ		40
#define EXTI11_IRQ		40
#define EXTI12_IRQ		40
#define EXTI13_IRQ		40
#define EXTI14_IRQ		40
#define EXTI15_IRQ		40


/*------------------------------
 * NVIC IRQ enable/disable Macros
 */
#define NVIC_IRQ6_EXTI0_Enable 				(NVIC_ISER0	|= 1<<6)
#define NVIC_IRQ7_EXTI1_Enable 				(NVIC_ISER0	|= 1<<7)
#define NVIC_IRQ8_EXTI2_Enable 				(NVIC_ISER0	|= 1<<8)
#define NVIC_IRQ9_EXTI3_Enable 				(NVIC_ISER0	|= 1<<9)
#define NVIC_IRQ10_EXTI4_Enable 			(NVIC_ISER0	|= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Enable 			(NVIC_ISER0	|= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Enable 		(NVIC_ISER1	|= 1<<8)


#define NVIC_IRQ6_EXTI0_Disable 			(NVIC_ICER0	|= 1<<6)
#define NVIC_IRQ7_EXTI1_Disable 			(NVIC_ICER0	|= 1<<7)
#define NVIC_IRQ8_EXTI2_Disable 			(NVIC_ICER0	|= 1<<8)
#define NVIC_IRQ9_EXTI3_Disable 			(NVIC_ICER0	|= 1<<9)
#define NVIC_IRQ10_EXTI4_Disable 			(NVIC_ICER0	|= 1<<10)
#define NVIC_IRQ23_EXTI5_9_Disable 			(NVIC_ICER0	|= 1<<23)
#define NVIC_IRQ40_EXTI10_15_Disable 		(NVIC_ICER1	|= 1<<8)





#endif /* MCU_DEVICE_HEADER_STM32F103X6_H_ */
