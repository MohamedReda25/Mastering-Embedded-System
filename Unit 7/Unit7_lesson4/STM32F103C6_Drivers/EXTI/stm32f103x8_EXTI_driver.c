//Eng. Mohamed Gamal

#include "stm32f103x8_EXTI_driver.h"
#include "stm32f103x8_GPIO_driver.h"
#include "STM32F103x8.h"


/*
 * ------------------------------------------------
 * 				  Generic Variables
 *-------------------------------------------------
 */

void(* GP_IRQ_Callback[15])(void);






/*
 * ------------------------------------------------
 * 				  Generic Macros
 *-------------------------------------------------
 */
#define AFIO_GPIO_EXTI_Mapping(x)		( (x==GPIOA)?0:\
		(x==GPIOB)?1:\
				(x==GPIOC)?2:\
						(x==GPIOD)?3:0  )





/*
 * ------------------------------------------------
 * 				  Generic Functions
 *-------------------------------------------------
 */

void Enable_NVIC(uint16_t IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_Enable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Enable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Enable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Enable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Enable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Enable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Enable;
		break;
	}


}
void Disable_NVIC(uint16_t IRQ){
	switch(IRQ){
	case 0:
		NVIC_IRQ6_EXTI0_Disable;
		break;
	case 1:
		NVIC_IRQ7_EXTI1_Disable;
		break;
	case 2:
		NVIC_IRQ8_EXTI2_Disable;
		break;
	case 3:
		NVIC_IRQ9_EXTI3_Disable;
		break;
	case 4:
		NVIC_IRQ10_EXTI4_Disable;
		break;
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		NVIC_IRQ23_EXTI5_9_Disable;
		break;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		NVIC_IRQ40_EXTI10_15_Disable;
		break;
	}


}











void UPDATE_EXTI(EXTI_Pinconfig_t* EXTI_config){

	//1- Configure GPIO to be AF input-> Floating input
	GPIO_Pinconfig_t PinCfg;
	PinCfg.Pin_number =EXTI_config->EXTI_PIN.GPIO_PIN;
	PinCfg.Mode = GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_INIT(EXTI_config->EXTI_PIN.GPIO_PORT, &PinCfg);



	//2- UPDATE AFIO to Route between EXTI lines with Ports A,B,C,D
	uint8_t AFIO_EXTICR_index = EXTI_config->EXTI_PIN.ETI_InputLineNumber / 4;
	uint8_t AFIO_EXTICR_position = (EXTI_config->EXTI_PIN.ETI_InputLineNumber % 4) *4;

	//Clear the four bit
	AFIO->EXTICR[AFIO_EXTICR_index] &= ~(0xF << AFIO_EXTICR_position) ;
	AFIO->EXTICR[AFIO_EXTICR_index] |= ((AFIO_GPIO_EXTI_Mapping(EXTI_config->EXTI_PIN.GPIO_PORT) &0xF) << AFIO_EXTICR_position );

	//3- Update Rising or Falling Register
	EXTI->RTSR &= ~(1<< EXTI_config->EXTI_PIN.ETI_InputLineNumber);
	EXTI->FTSR &= ~(1<< EXTI_config->EXTI_PIN.ETI_InputLineNumber);

	if(EXTI_config->Trigger_case == EXTI_Trigger_Rising){
		EXTI->RTSR |= (1<< EXTI_config->EXTI_PIN.ETI_InputLineNumber);
	}
	else if(EXTI_config->Trigger_case == EXTI_Trigger_Falling){
		EXTI->FTSR |= (1<< EXTI_config->EXTI_PIN.ETI_InputLineNumber);
	}
	else{
		EXTI->RTSR |= (1<< EXTI_config->EXTI_PIN.ETI_InputLineNumber);
		EXTI->FTSR |= (1<< EXTI_config->EXTI_PIN.ETI_InputLineNumber);
	}

	//4- Update IRQ Handling callback
	GP_IRQ_Callback[EXTI_config->EXTI_PIN.ETI_InputLineNumber] = EXTI_config->P_IRQ_Callback;

	//5- Enable/Disable IRQ EXTI and NVIC
	if(EXTI_config->IRQ_EN == EXTI_IRQ_Enable){
		EXTI->IMR |= (1<<EXTI_config->EXTI_PIN.ETI_InputLineNumber);
		Enable_NVIC(EXTI_config->EXTI_PIN.ETI_InputLineNumber);

	}
	else{
		EXTI->IMR &= ~(1<<EXTI_config->EXTI_PIN.ETI_InputLineNumber);
		Disable_NVIC(EXTI_config->EXTI_PIN.ETI_InputLineNumber);
	}


}





/*
 * ------------------------------------------------
 * 				APIs Functions Definitions
 *-------------------------------------------------
 */




/**================================================================
 * @Fn              - MCAL_EXTI_GPIO_DEINIT
 * @brief           - Reset External interrupt registers and NVIC coresponding IRQ mask
 * @retval          - none
 *================================================================ */
void MCAL_EXTI_GPIO_DEINIT(void){
	EXTI->IMR = 0x00000000;
	EXTI->EMR = 0x00000000;
	EXTI->RTSR = 0x00000000;
	EXTI->FTSR = 0x00000000;
	EXTI->SWIER = 0x00000000;
	EXTI->PR = 0xFFFFFFFF;



	NVIC_IRQ6_EXTI0_Disable;
	NVIC_IRQ7_EXTI1_Disable;
	NVIC_IRQ8_EXTI2_Disable;
	NVIC_IRQ9_EXTI3_Disable;
	NVIC_IRQ10_EXTI4_Disable;
	NVIC_IRQ23_EXTI5_9_Disable;
	NVIC_IRQ40_EXTI10_15_Disable;

}







/**================================================================
 * @Fn              - MCAL_EXTI_GPIO_INIT
 * @brief           - Initialize EXTI from specific GPIO Pin and specify the mask\trigger condition and IRQ callback
 * @param [in]      - EXTI_config: set bt @ref : EXTI_define , EXTI_Trigger_define , EXTI_IRQ_define
 * @retval          - none
 * Note             -
 *================================================================ */

void MCAL_EXTI_GPIO_INIT(EXTI_Pinconfig_t* EXTI_config){

	UPDATE_EXTI(EXTI_config);
}











/**================================================================
 * @Fn              - MCAL_EXTI_GPIO_INIT
 * @brief           - Initialize EXTI from specific GPIO Pin and specify the mask\trigger condition and IRQ callback
 * @param [in]      - EXTI_config: set bt @ref : EXTI_define , EXTI_Trigger_define , EXTI_IRQ_define
 * @retval          - none
 * Note             -
 *================================================================ */
void MCAL_EXTI_GPIO_UPDATE(EXTI_Pinconfig_t* EXTI_config){
	UPDATE_EXTI(EXTI_config);
}





//IRQ_Handler

void EXTI0_IRQHandler(void){
	// clear bit in pending register (EXTI_PR)
	EXTI->PR |= (1<<0);
	GP_IRQ_Callback[0]();
}

void EXTI1_IRQHandler(void){
	EXTI->PR |= (1<<1);
	GP_IRQ_Callback[1]();

}

void EXTI2_IRQHandler(void){
	EXTI->PR |= (1<<2);
	GP_IRQ_Callback[2]();
}

void EXTI3_IRQHandler(void){
	EXTI->PR |= (1<<3);
	GP_IRQ_Callback[3]();
}

void EXTI4_IRQHandler(void){
	EXTI->PR |= (1<<4);
	GP_IRQ_Callback[4]();
}

void EXTI9_5_IRQHandler(void){
	if(EXTI->PR & (1<<5)) {EXTI->PR |= (1<<5); GP_IRQ_Callback[5]();  }
	if(EXTI->PR & (1<<6)) {EXTI->PR |= (1<<6); GP_IRQ_Callback[6]();  }
	if(EXTI->PR & (1<<7)) {EXTI->PR |= (1<<7); GP_IRQ_Callback[7]();  }
	if(EXTI->PR & (1<<8)) {EXTI->PR |= (1<<8); GP_IRQ_Callback[8]();  }
	if(EXTI->PR & (1<<9)) {EXTI->PR |= (1<<9); GP_IRQ_Callback[9]();  }
}

void EXTI15_10_IRQHandler(void){
	if(EXTI->PR & (1<<10)) {EXTI->PR |= (1<<10); GP_IRQ_Callback[10]();  }
	if(EXTI->PR & (1<<11)) {EXTI->PR |= (1<<11); GP_IRQ_Callback[11]();  }
	if(EXTI->PR & (1<<12)) {EXTI->PR |= (1<<12); GP_IRQ_Callback[12]();  }
	if(EXTI->PR & (1<<13)) {EXTI->PR |= (1<<13); GP_IRQ_Callback[13]();  }
	if(EXTI->PR & (1<<14)) {EXTI->PR |= (1<<14); GP_IRQ_Callback[14]();  }
	if(EXTI->PR & (1<<15)) {EXTI->PR |= (1<<15); GP_IRQ_Callback[15]();  }

}
