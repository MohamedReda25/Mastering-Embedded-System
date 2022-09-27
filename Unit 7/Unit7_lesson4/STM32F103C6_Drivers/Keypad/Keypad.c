/*
 * Keypad.c
 *
 *  Created on: Sep 21, 2022
 *      Author: redam
 */

#include "Keypad.h"

int Key_padRow[] = {R0, R1, R2, R3}; //rows of the keypad
int Key_padCol[] = {C0, C1, C2, C3};//columns



void Keypad_init(){

	GPIO_Pinconfig_t config;

	config.Pin_number = R0;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	config.Pin_number = R1;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed =  GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	config.Pin_number = R2;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed =  GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	config.Pin_number = R3;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed =  GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	config.Pin_number = C0;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed =  GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	config.Pin_number = C1;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed =  GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	config.Pin_number = C2;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed =  GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	config.Pin_number = C3;
	config.Mode =  GPIO_MODE_OUTPUT_PP;
	config.Output_speed = GPIO_OUT_SPEED_10M;
	MCAL_GPIO_INIT(keypad_PORT, &config);

	MCAL_GPIO_WRITE_PORT(keypad_PORT, 0xFF);

}

char Keypad_getkey(){
	int i,j;
	for (i = 0; i < 4; i++){
		MCAL_GPIO_WRITE_PIN(keypad_PORT, Key_padCol[0], 1);
		MCAL_GPIO_WRITE_PIN(keypad_PORT, Key_padCol[1], 1);
		MCAL_GPIO_WRITE_PIN(keypad_PORT, Key_padCol[2], 1);
		MCAL_GPIO_WRITE_PIN(keypad_PORT, Key_padCol[3], 1);

		MCAL_GPIO_WRITE_PIN(keypad_PORT, Key_padCol[i], 0);


		for(j = 0; j < 4; j++){
			if ( MCAL_GPIO_READ_PIN(keypad_PORT, Key_padRow[j]) == 0)
			{
				while( MCAL_GPIO_READ_PIN(keypad_PORT, Key_padRow[j]) == 0);
				switch(i){
					case (0):
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					case (1):
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					case (2):
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					case (3):
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '-';
						else if (j == 3) return '+';
						break;
				}
			}
		}
	}
	return 'A';
}
