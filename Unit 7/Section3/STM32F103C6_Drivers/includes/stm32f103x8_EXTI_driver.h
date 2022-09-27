/*
 * stm32f103x8_EXTI_driver.h
 *
 *  Created on: Sep 24, 2022
 *      Author: redam
 */

#ifndef INCLUDES_STM32F103X8_EXTI_DRIVER_H_
#define INCLUDES_STM32F103X8_EXTI_DRIVER_H_


//includes
#include "STM32F103x8.h"
#include "stm32f103x8_GPIO_driver.h"



typedef struct{

	uint16_t 			ETI_InputLineNumber;
	GPIO_Typedef* 		GPIO_PORT;
	uint16_t			GPIO_PIN;
	uint16_t			IVT_IRQ_Number;
}EXTI_GPIO_Mapping_t;


typedef struct{

	EXTI_GPIO_Mapping_t EXTI_PIN; 	//Specifies the external Interrupt GPIO Mapping
									//This parameter must be set base on @ref EXTI_define

	uint8_t Trigger_case;			//specifies rising or falling or both trigger
									//This parameter must be set base on @ref EXTI_Trigger_define

	uint8_t IRQ_EN;             	//Enable or disable the EXTI IRQ (will also enable the IRQ on the NVIC)
									//This parameter must be set base on @ref EXTI_IRQ_define


	void(* P_IRQ_Callback)(void);   //Set the C function() that will be called when the interrupt happen

}EXTI_Pinconfig_t;


#define EXTI0 		0
#define EXTI1 		1
#define EXTI2 		2
#define EXTI3 		3
#define EXTI4 		4
#define EXTI5 		5
#define EXTI6 		6
#define EXTI7 		7
#define EXTI8 		8
#define EXTI9 		9
#define EXTI10 		10
#define EXTI11 		11
#define EXTI12 		12
#define EXTI13 		13
#define EXTI14 		14
#define EXTI15 		15


//macros



//@ref EXTI_Trigger_define
#define EXTI_Trigger_Rising					0
#define EXTI_Trigger_Falling				1
#define EXTI_Trigger_RisingAndFalling		2




//@ref EXTI_IRQ_define
#define EXTI_IRQ_Enable		1
#define EXTI_IRQ_Disable	0




//EXT_define
//EXTI0
#define EXTI0A0		(EXTI_GPIO_Mapping_t){EXTI0 , GPIOA , GPIOx_PIN0 , EXTI0_IRQ}
#define EXTI0B0		(EXTI_GPIO_Mapping_t){EXTI0 , GPIOB , GPIOx_PIN0 , EXTI0_IRQ}
#define EXTI0C0		(EXTI_GPIO_Mapping_t){EXTI0 , GPIOC , GPIOx_PIN0 , EXTI0_IRQ}
#define EXTI0D0		(EXTI_GPIO_Mapping_t){EXTI0 , GPIOD , GPIOx_PIN0 , EXTI0_IRQ}


//EXTI1
#define EXTI1A1		(EXTI_GPIO_Mapping_t){EXTI1 , GPIOA , GPIOx_PIN1 , EXTI1_IRQ}
#define EXTI1B1		(EXTI_GPIO_Mapping_t){EXTI1 , GPIOB , GPIOx_PIN1 , EXTI1_IRQ}
#define EXTI1C1		(EXTI_GPIO_Mapping_t){EXTI1 , GPIOC , GPIOx_PIN1 , EXTI1_IRQ}
#define EXTI1D1		(EXTI_GPIO_Mapping_t){EXTI1 , GPIOD , GPIOx_PIN1 , EXTI1_IRQ}

//EXTI2
#define EXTI2A2		(EXTI_GPIO_Mapping_t){EXTI2 , GPIOA , GPIOx_PIN2 , EXTI2_IRQ}
#define EXTI2B2		(EXTI_GPIO_Mapping_t){EXTI2 , GPIOB , GPIOx_PIN2 , EXTI2_IRQ}
#define EXTI2C2		(EXTI_GPIO_Mapping_t){EXTI2 , GPIOC , GPIOx_PIN2 , EXTI2_IRQ}
#define EXTI2D2		(EXTI_GPIO_Mapping_t){EXTI2 , GPIOD , GPIOx_PIN2 , EXTI2_IRQ}

//EXTI3
#define EXTI3A3		(EXTI_GPIO_Mapping_t){EXTI3 , GPIOA , GPIOx_PIN3 , EXTI3_IRQ}
#define EXTI3B3		(EXTI_GPIO_Mapping_t){EXTI3 , GPIOB , GPIOx_PIN3 , EXTI3_IRQ}
#define EXTI3C3		(EXTI_GPIO_Mapping_t){EXTI3 , GPIOC , GPIOx_PIN3 , EXTI3_IRQ}
#define EXTI3D3		(EXTI_GPIO_Mapping_t){EXTI3 , GPIOD , GPIOx_PIN3 , EXTI3_IRQ}



//EXTI4
#define EXTI4A4		(EXTI_GPIO_Mapping_t){EXTI4 , GPIOA , GPIOx_PIN4 , EXTI4_IRQ}
#define EXTI4B4		(EXTI_GPIO_Mapping_t){EXTI4 , GPIOB , GPIOx_PIN4 , EXTI4_IRQ}
#define EXTI4C4		(EXTI_GPIO_Mapping_t){EXTI4 , GPIOC , GPIOx_PIN4 , EXTI4_IRQ}
#define EXTI4D4		(EXTI_GPIO_Mapping_t){EXTI4 , GPIOD , GPIOx_PIN4 , EXTI4_IRQ}



//EXTI5
#define EXTI5A5		(EXTI_GPIO_Mapping_t){EXTI5 , GPIOA , GPIOx_PIN5 , EXTI5_IRQ}
#define EXTI5B5		(EXTI_GPIO_Mapping_t){EXTI5 , GPIOB , GPIOx_PIN5 , EXTI5_IRQ}
#define EXTI5C5		(EXTI_GPIO_Mapping_t){EXTI5 , GPIOC , GPIOx_PIN5 , EXTI5_IRQ}
#define EXTI5D5		(EXTI_GPIO_Mapping_t){EXTI5 , GPIOD , GPIOx_PIN5 , EXTI5_IRQ}



//EXTI6
#define EXTI6A6		(EXTI_GPIO_Mapping_t){EXTI6 , GPIOA , GPIOx_PIN6 , EXTI6_IRQ}
#define EXTI6B6		(EXTI_GPIO_Mapping_t){EXTI6 , GPIOB , GPIOx_PIN6 , EXTI6_IRQ}
#define EXTI6C6		(EXTI_GPIO_Mapping_t){EXTI6 , GPIOC , GPIOx_PIN6 , EXTI6_IRQ}
#define EXTI6D6		(EXTI_GPIO_Mapping_t){EXTI6 , GPIOD , GPIOx_PIN6 , EXTI6_IRQ}



//EXTI7
#define EXTI7A7		(EXTI_GPIO_Mapping_t){EXTI7 , GPIOA , GPIOx_PIN7 , EXTI7_IRQ}
#define EXTI7B7		(EXTI_GPIO_Mapping_t){EXTI7 , GPIOB , GPIOx_PIN7 , EXTI7_IRQ}
#define EXTI7C7		(EXTI_GPIO_Mapping_t){EXTI7 , GPIOC , GPIOx_PIN7 , EXTI7_IRQ}
#define EXTI7D7		(EXTI_GPIO_Mapping_t){EXTI7 , GPIOD , GPIOx_PIN7 , EXTI7_IRQ}



//EXTI8
#define EXTI8A8		{EXTI8 , GPIOA , GPIOx_PIN8 , EXTI8_IRQ}
#define EXTI8B8		{EXTI8 , GPIOB , GPIOx_PIN8 , EXTI8_IRQ}
#define EXTI8C8		{EXTI8 , GPIOC , GPIOx_PIN8 , EXTI8_IRQ}
#define EXTI8D8		{EXTI8 , GPIOD , GPIOx_PIN8 , EXTI8_IRQ}



//EXTI9
#define EXTI9A9		(EXTI_GPIO_Mapping_t){EXTI9 , GPIOA , GPIOx_PIN9 , EXTI9_IRQ}
#define EXTI9B9		(EXTI_GPIO_Mapping_t){EXTI9 , GPIOB , GPIOx_PIN9 , EXTI9_IRQ}
#define EXTI9C9		(EXTI_GPIO_Mapping_t){EXTI9 , GPIOC , GPIOx_PIN9 , EXTI9_IRQ}
#define EXTI9D9		(EXTI_GPIO_Mapping_t){EXTI9 , GPIOD , GPIOx_PIN9 , EXTI9_IRQ}



//EXTI10
#define EXTI10A10		(EXTI_GPIO_Mapping_t){EXTI10 , GPIOA , GPIOx_PIN10 , EXTI10_IRQ}
#define EXTI10B10		(EXTI_GPIO_Mapping_t){EXTI10 , GPIOB , GPIOx_PIN10 , EXTI10_IRQ}
#define EXTI10C10		(EXTI_GPIO_Mapping_t){EXTI10 , GPIOC , GPIOx_PIN10 , EXTI10_IRQ}
#define EXTI10D10		(EXTI_GPIO_Mapping_t){EXTI10 , GPIOD , GPIOx_PIN10 , EXTI10_IRQ}



//EXTI11
#define EXTI11A11		(EXTI_GPIO_Mapping_t){EXTI11 , GPIOA , GPIOx_PIN11 , EXTI11_IRQ}
#define EXTI11B11		(EXTI_GPIO_Mapping_t){EXTI11 , GPIOB , GPIOx_PIN11 , EXTI11_IRQ}
#define EXTI11C11		(EXTI_GPIO_Mapping_t){EXTI11 , GPIOC , GPIOx_PIN11 , EXTI11_IRQ}
#define EXTI11D11		(EXTI_GPIO_Mapping_t){EXTI11 , GPIOD , GPIOx_PIN11 , EXTI11_IRQ}



//EXTI12
#define EXTI12A12		(EXTI_GPIO_Mapping_t){EXTI12 , GPIOA , GPIOx_PIN12 , EXTI12_IRQ}
#define EXTI12B12		(EXTI_GPIO_Mapping_t){EXTI12 , GPIOB , GPIOx_PIN12 , EXTI12_IRQ}
#define EXTI12C12		(EXTI_GPIO_Mapping_t){EXTI12 , GPIOC , GPIOx_PIN12 , EXTI12_IRQ}
#define EXTI12D12		(EXTI_GPIO_Mapping_t){EXTI12 , GPIOD , GPIOx_PIN12 , EXTI12_IRQ}



//EXTI13
#define EXTI13A13		(EXTI_GPIO_Mapping_t){EXTI13 , GPIOA , GPIOx_PIN13 , EXTI13_IRQ}
#define EXTI13B13		(EXTI_GPIO_Mapping_t){EXTI13 , GPIOB , GPIOx_PIN13 , EXTI13_IRQ}
#define EXTI13C13		(EXTI_GPIO_Mapping_t){EXTI13 , GPIOC , GPIOx_PIN13 , EXTI13_IRQ}
#define EXTI13D13		(EXTI_GPIO_Mapping_t){EXTI13 , GPIOD , GPIOx_PIN13 , EXTI13_IRQ}



//EXTI14
#define EXTI14A14		(EXTI_GPIO_Mapping_t){EXTI14 , GPIOA , GPIOx_PIN14 , EXTI14_IRQ}
#define EXTI14B14		(EXTI_GPIO_Mapping_t){EXTI14 , GPIOB , GPIOx_PIN14 , EXTI14_IRQ}
#define EXTI14C14		(EXTI_GPIO_Mapping_t){EXTI14 , GPIOC , GPIOx_PIN14 , EXTI14_IRQ}
#define EXTI14D14		(EXTI_GPIO_Mapping_t){EXTI14 , GPIOD , GPIOx_PIN14 , EXTI14_IRQ}



//EXTI15
#define EXTI15A15		(EXTI_GPIO_Mapping_t){EXTI15 , GPIOA , GPIOx_PIN15 , EXTI15_IRQ}
#define EXTI15B15		(EXTI_GPIO_Mapping_t){EXTI15 , GPIOB , GPIOx_PIN15 , EXTI15_IRQ}
#define EXTI15C15		(EXTI_GPIO_Mapping_t){EXTI15 , GPIOC , GPIOx_PIN15 , EXTI15_IRQ}
#define EXTI15D15		(EXTI_GPIO_Mapping_t){EXTI15 , GPIOD , GPIOx_PIN15 , EXTI15_IRQ}





/*-*-*-*-*-*-*-*-*-*-*-*/
/*--------------------------APIs------------------------------*/
void MCAL_EXTI_GPIO_INIT(EXTI_Pinconfig_t* EXTI_config);
void MCAL_EXTI_GPIO_DEINIT(void);
void MCAL_EXTI_GPIO_UPDATE(EXTI_Pinconfig_t* EXTI_config);

















#endif /* INCLUDES_STM32F103X8_EXTI_DRIVER_H_ */
