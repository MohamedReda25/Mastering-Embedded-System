/*
 * GPIO.h
 *
 * Created: 9/28/2022 1:47:08 AM
 *  Author: redam
 */ 


#ifndef GPIO_H_
#define GPIO_H_


//-----------------------------
//Includes
//-----------------------------
#include "Atmega32_Drivers.h"




//-----------------------------
//User type definitions (structures)
//-----------------------------
typedef struct
{
	volatile uint8_t Pin_number;    //@ref GPIO_PINs to select the pin
	volatile uint8_t Mode;			//@ref GPIO_MODE to select the mode	

}GPIO_Pinconfig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref GPIO_PINs
#define GPIO_PIN0		((uint8_t)(1<<0))
#define GPIO_PIN1		((uint8_t)(1<<1))
#define GPIO_PIN2		((uint8_t)(1<<2))
#define GPIO_PIN3		((uint8_t)(1<<3))
#define GPIO_PIN4		((uint8_t)(1<<4))
#define GPIO_PIN5		((uint8_t)(1<<5))
#define GPIO_PIN6		((uint8_t)(1<<6))
#define GPIO_PIN7		((uint8_t)(1<<7))





//@ref GPIO_MODE
#define GPIO_Input		0
#define GPIO_Output		1




#define GPIO_PIN_RESET		0
#define GPIO_PIN_SET		1



/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_GPIO_INIT( uint8_t* GPIOx, GPIO_Pinconfig_t* pin_config);
void MCAL_GPIO_DEINIT( uint8_t* GPIOx);
void MCAL_GPIO_WRITE_PIN(uint8_t* GPIOx, uint8_t pin_number , uint8_t value);
void MCAL_GPIO_WRITE_PORT(uint8_t* GPIOx,uint8_t value);
uint8_t MCAL_GPIO_READ_PIN(uint8_t* GPIOx, uint8_t pin_number);
uint8_t MCAL_GPIO_READ_PORT(uint8_t* GPIOx);
void MCAL_GPIO_TogglePin(uint8_t* GPIOx, uint8_t pin_number);





#endif /* GPIO_H_ */