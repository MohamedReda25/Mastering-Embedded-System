/*
 * stm32f103x8_GPIO_driver.h
 *
 *  Created on: Sep 17, 2022
 *      Author: redam
 */

#ifndef INC_STM32F103X8_GPIO_DRIVER_H_
#define INC_STM32F103X8_GPIO_DRIVER_H_

//---------------------------
//INCLUDES
#include "STM32F103x8.h"

//***************************


//---------------------------
//User type definitions (Structures)

typedef struct{
	volatile uint16_t Pin_number;
	volatile uint8_t Mode;
	volatile uint8_t Output_speed;

}GPIO_Pinconfig_t;

//****************************




//-----------------------------
//Macros configuration references

// @ref   GPIO_Pinconfig_t->>Pin_number
#define GPIOx_PIN0		((uint16_t)(1<<0))
#define GPIOx_PIN1		((uint16_t)(1<<1))
#define GPIOx_PIN2		((uint16_t)(1<<2))
#define GPIOx_PIN3		((uint16_t)(1<<3))
#define GPIOx_PIN4		((uint16_t)(1<<4))
#define GPIOx_PIN5		((uint16_t)(1<<5))
#define GPIOx_PIN6		((uint16_t)(1<<6))
#define GPIOx_PIN7		((uint16_t)(1<<7))
#define GPIOx_PIN8		((uint16_t)(1<<8))
#define GPIOx_PIN9		((uint16_t)(1<<9))
#define GPIOx_PIN10		((uint16_t)(1<<10))
#define GPIOx_PIN11		((uint16_t)(1<<11))
#define GPIOx_PIN12		((uint16_t)(1<<12))
#define GPIOx_PIN13		((uint16_t)(1<<13))
#define GPIOx_PIN14		((uint16_t)(1<<14))
#define GPIOx_PIN15		((uint16_t)(1<<15))

//******

// @ref   GPIO_Pinconfig_t->>Mode
#define GPIO_MODE_ANALOG			0x00000000U
#define GPIO_MODE_INPUT_FLO			0x00000001U
#define GPIO_MODE_INPUT_PU			0x00000002U
#define GPIO_MODE_INPUT_PD			0x00000003U
#define GPIO_MODE_OUTPUT_PP			0x00000004U
#define GPIO_MODE_OUTPUT_OD			0x00000005U
#define GPIO_MODE_OUTPUT_AF_PP		0x00000006U
#define GPIO_MODE_OUTPUT_AF_OD		0x00000007U
#define GPIO_MODE_INTPUT_AF			0x00000008U

//******



// @ref   GPIO_Pinconfig_t->>Output_speed
#define GPIO_OUT_SPEED_10M		0x00000001U
#define GPIO_OUT_SPEED_2M		0x00000002U
#define GPIO_OUT_SPEED_50M		0x00000003U

//******


// @ref GPIO_PIN_State
#define GPIO_Pin_set                1
#define GPIO_Pin_reset              0


// @ref GPIO_Lock_State
#define GPIO_Pin_Locked             1
#define GPIO_Pin_unlocked           0


//******************************

void MCAL_GPIO_INIT(GPIO_Typedef* GPIOx, GPIO_Pinconfig_t* pin_config);
void MCAL_GPIO_DEINIT(GPIO_Typedef* GPIOx);
void MCAL_GPIO_WRITE_PIN(GPIO_Typedef* GPIOx, uint16_t pin_number , uint8_t value);
void MCAL_GPIO_WRITE_PORT(GPIO_Typedef* GPIOx,uint16_t value);
uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef* GPIOx, uint16_t pin_number);
uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef* GPIOx);
void MCAL_GPIO_TogglePin(GPIO_Typedef* GPIOx, uint16_t pin_number);
uint8_t MCAL_GPIO_LockPin(GPIO_Typedef* GPIOx, uint16_t pin_number);





#endif /* INC_STM32F103X8_GPIO_DRIVER_H_ */
