//Eng. Mohamed Gamal

#ifndef GPIO_DRIVER_STM32F_103C6_GPIO_DRIVER_H_
#define GPIO_DRIVER_STM32F_103C6_GPIO_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	volatile uint16_t Pin_number;    //@ref GPIO_PINs to select the pin
	volatile uint8_t Mode;			//@ref GPIO_MODE to select the mode
	volatile uint8_t Output_speed;	//@ref GPIO_OutPut_Speed to select the output speed

}GPIO_Pinconfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINs
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
#define GPIOx_Full   ((uint16_t)0xFFFF)

//@ref GPIO_MODE
#define GPIO_MODE_ANALOG  			 0x00000000u
#define GPIO_MODE_INPUT_FLO   	 	 0x00000001u
#define GPIO_MODE_INPUT_PU 	 		 0x00000002u
#define GPIO_MODE_INPUT_PD 	 		 0x00000003u
#define GPIO_MODE_OUTPUT_PP  		 0x00000004u
#define GPIO_MODE_OUTPUT_OD          0x00000005u
#define GPIO_MODE_OUTPUT_AF_PP       0x00000006u
#define GPIO_MODE_OUTPUT_AF_OD       0x00000007u
#define GPIO_MODE_INTPUT_AF          0x00000008u

//@ref GPIO_OutPut_Speed
#define GPIO_OUT_SPEED_10M    	0x00000001u
#define GPIO_OUT_SPEED_2M 		0x00000002u
#define GPIO_OUT_SPEED_50M 	    0x00000003u

//@ref GPIO_PIN_State
#define GPIO_Pin_set                1
#define GPIO_Pin_reset              0


//@ref GPIO_Lock_State
#define GPIO_Pin_Locked             1
#define GPIO_Pin_unlocked           0

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_INIT(GPIO_Typedef* GPIOx, GPIO_Pinconfig_t* pin_config);
void MCAL_GPIO_DEINIT(GPIO_Typedef* GPIOx);
void MCAL_GPIO_WRITE_PIN(GPIO_Typedef* GPIOx, uint16_t pin_number , uint8_t value);
void MCAL_GPIO_WRITE_PORT(GPIO_Typedef* GPIOx,uint16_t value);
uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef* GPIOx, uint16_t pin_number);
uint16_t MCAL_GPIO_READ_PORT(GPIO_Typedef* GPIOx);
void MCAL_GPIO_TogglePin(GPIO_Typedef* GPIOx, uint16_t pin_number);
uint8_t MCAL_GPIO_LockPin(GPIO_Typedef* GPIOx, uint16_t pin_number);

#endif /* GPIO_DRIVER_STM32F_103C6_GPIO_DRIVER_H_ */
