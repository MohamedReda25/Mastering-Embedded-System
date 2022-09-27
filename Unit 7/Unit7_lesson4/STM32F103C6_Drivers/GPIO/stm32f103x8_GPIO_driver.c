//Eng. Mohamed Gamal

#include "STM32F103x8.h"
#include "stm32f103x8_GPIO_driver.h"

uint8_t getposition(uint16_t pin_num){
	uint8_t rval;
	if(pin_num == GPIOx_PIN0){
		rval =0;
	}
	if(pin_num == GPIOx_PIN1){
		rval =4;
	}
	if(pin_num == GPIOx_PIN2){
		rval =8;
	}
	if(pin_num == GPIOx_PIN3){
		rval =12;
	}
	if(pin_num == GPIOx_PIN4){
		rval =16;
	}
	if(pin_num == GPIOx_PIN5){
		rval =20;
	}
	if(pin_num == GPIOx_PIN6){
		rval =24;
	}
	if(pin_num == GPIOx_PIN7){
		rval =28;
	}
	if(pin_num == GPIOx_PIN8){
		rval =0;
	}
	if(pin_num == GPIOx_PIN9){
		rval =4;
	}
	if(pin_num == GPIOx_PIN10){
		rval =8;
	}
	if(pin_num == GPIOx_PIN11){
		rval =12;
	}
	if(pin_num == GPIOx_PIN12){
		rval =16;
	}
	if(pin_num == GPIOx_PIN13){
		rval =20;
	}
	if(pin_num == GPIOx_PIN14){
		rval =24;
	}
	if(pin_num == GPIOx_PIN15){
		rval =28;
	}
	return rval;


}




/**================================================================
 * @Fn              - MCAL_GPIO_Init
 * @brief           - initialized the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_config: pointer to  GPIOx_Config_t struct that contains
 * 					  the configuration information for specified GPIO PIN
 * @retval          - none
 * Note             - Stm32F103C6 MCU Has GPIO (A,B,C,D,E) modules
 * 					  But LQFP48 has only GPIO A,B,Part of C\D exported as external PINS from MCU
 *================================================================ */
void MCAL_GPIO_INIT(GPIO_Typedef* GPIOx , GPIO_Pinconfig_t* pin_config)
{
	volatile uint32_t* config = NULL;
	uint8_t PIN_Config = 0;

	config = (pin_config->Pin_number < GPIOx_PIN8 )? &GPIOx->CRL : &GPIOx->CRH;

	(*config) &= ~(0xf << getposition(pin_config->Pin_number) );

	if ( ((pin_config->Mode)== GPIO_MODE_OUTPUT_AF_OD) ||  ((pin_config->Mode)== GPIO_MODE_OUTPUT_AF_PP) || ((pin_config->Mode)== GPIO_MODE_OUTPUT_OD) || ( (pin_config->Mode)== GPIO_MODE_OUTPUT_PP) )
	{

		PIN_Config =  ( (((pin_config->Mode - 4)  << 2) | (pin_config->Output_speed)) & 0x0f);
	}
	else
	{
		if ( (pin_config->Mode == GPIO_MODE_ANALOG) || (pin_config->Mode == GPIO_MODE_INPUT_FLO) )
		{
			PIN_Config =  ( (((pin_config->Mode)  << 2) | 0x0 ) & 0x0f);
		}
		else if ( pin_config->Mode == GPIO_MODE_INTPUT_AF)
		{
			PIN_Config =  ( (((GPIO_MODE_INPUT_FLO)  << 2) | 0x0 ) & 0x0f);
		}
		else
		{
			PIN_Config =  ( (((GPIO_MODE_INPUT_PU)  << 2) | 0x0 ) & 0x0f);

			if ( pin_config->Mode == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR |= 1 << pin_config->Pin_number;
			}
			else
			{
				GPIOx->ODR &= ~(1 << pin_config->Pin_number);
			}
		}
	}
	(*config) |=  ( (PIN_Config) << getposition(pin_config->Pin_number) );
}




/**================================================================
 * @Fn              - MCAL_GPIO_DeInit
 * @brief           - Reset the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @retval          - none
 * Note             - Stm32F103C6 MCU Has GPIO (A,B,C,D,E) modules
 * 					  But LQFP48 has only GPIO A,B,Part of C\D exported as external PINS from MCU
 *================================================================ */
void MCAL_GPIO_DEINIT(GPIO_Typedef* GPIOx){

	/*
	// GPIOx->IDR (Read-Ony)
	GPIOx->GPIOx_BRR = 0x00000000;
	GPIOx->GPIOx_BSRR = 0x00000000;
	GPIOx->CRH = 0x44444444;
	GPIOx->CRL = 0x44444444;
	GPIOx->GPIOx_LCKR = 0x00000000;
	GPIOx->ODR = 0x00000000;
	 */
	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2);
		RCC->APB2RSTR &= ~(1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= (1<<3);
		RCC->APB2RSTR &= ~(1<3);
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR |= (1<<4);
		RCC->APB2RSTR &= ~(1<<4);
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR |= (1<<5);
		RCC->APB2RSTR &= ~(1<<5);
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR |= (1<<6);
		RCC->APB2RSTR &= ~(1<<6);
	}
}




/**================================================================
 * @Fn              - MCAL_GPIO_ReadPin
 * @brief           - Read the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @retval          - uint8_t -> @ref GPIO_PIN_State
 * Note             - none
 *================================================================ */
uint8_t MCAL_GPIO_READ_PIN(GPIO_Typedef* GPIOx, uint16_t pin_number){

	uint8_t tmp ;
	if ( ( GPIOx->IDR & (pin_number) ) != ((uint32_t)GPIO_Pin_reset) ){
		tmp = GPIO_Pin_set;
	}
	else
	{
		tmp = GPIO_Pin_reset;
	}
	return tmp;
}




/**================================================================
 * @Fn              - MCAL_GPIO_ReadPort
 * @brief           - Read the GPIOx according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @retval          - uint16_t
 * Note             - none
 *================================================================ */
uint16_t MCAL_GPIO_ReadPort (GPIO_Typedef* GPIOx){

	uint16_t tmp ;
	tmp = (uint16_t)(GPIOx->IDR);
	return tmp;
}




/**================================================================
 * @Fn              - MCAL_GPIO_WritePin
 * @brief           - Write the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @param [in]      - Value: The Input Value
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_GPIO_WRITE_PIN(GPIO_Typedef* GPIOx, uint16_t pin_number , uint8_t value) {

	if(value != GPIO_Pin_reset){
		//GPIOx->ODR |= Pin_No;

		/* GPIOx_BSRR:
		Bits 15:0 BSy: Port x Set bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Set the corresponding ODRx bit
		 */

		GPIOx->BSRR = (uint32_t)pin_number;
	}
	else
	{
		//GPIOx->ODR &= ~(Pin_No);

		/* GPIOx_BRR:
		Bits 15:0 BRy: Port x Reset bit y (y= 0 .. 15)
		These bits are write-only and can be accessed in Word mode only.
		0: No action on the corresponding ODRx bit
		1: Reset the corresponding ODRx bit
		 */

		GPIOx->BRR = (uint32_t)pin_number;
	}

}




/**================================================================
 * @Fn              - MCAL_GPIO_WritePort
 * @brief           - Write the GPIOx according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Value: The Input Value
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_GPIO_WRITE_PORT(GPIO_Typedef* GPIOx,uint16_t value) {

	GPIOx->ODR = (uint16_t)value;
}




/**================================================================
 * @Fn              - MCAL_GPIO_TogglePin
 * @brief           - Toggle the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @retval          - none
 * Note             - none
 *================================================================ */
void MCAL_GPIO_TogglePin(GPIO_Typedef* GPIOx, uint16_t pin_number) {

	GPIOx->ODR ^= pin_number;
}




/**================================================================
 * @Fn              - MCAL_GPIO_LockPin
 * @brief           - Lock the GPIOx PINy according to specified parameters in Pin_config
 * @param [in]      - GPIOx: where x can be (A...E Depending on device used) to select the GPIO Peripheral
 * @param [in]      - Pin_No: GPIOx PIN Number
 * @retval          - uint8_t -> @ref GPIO_Lock_State
 * Note             - none
 *================================================================ */
uint8_t MCAL_GPIO_LockPin(GPIO_Typedef* GPIOx, uint16_t pin_number) {

	/*
	 LOCK key writing sequence:
	Write 1
	Write 0
	Write 1
	Read 0
	Read 1 (this read is optional but confirms that the lock is active)
	 */

	uint32_t tmp = (1<<16);

	tmp |= pin_number;

	//Write 1
	GPIOx->LCKR = tmp;

	//Write 0
	GPIOx->LCKR = pin_number;

	//Write 1
	GPIOx->LCKR = tmp;

	//Read 0
	tmp = GPIOx->LCKR;

	//Read 1
	if( ((uint32_t)(GPIOx->LCKR & 1<<16)) ) {

		return GPIO_Pin_Locked;
	}
	else
	{

		return GPIO_Pin_unlocked;
	}



}

