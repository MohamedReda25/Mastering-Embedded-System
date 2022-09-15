/*
 * keypad.c
 *
 * Created: 9/15/2022 4:21:59 AM
 *  Author: redam
 */ 
#include "keypad.h"

int keypad_r[] = {R0,R1,R2,R3};
int keypad_c[] = {C0,C1,C2,C3};
	

void keypad_init(){
	keypad_PORT_dir &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));
	keypad_PORT_dir |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
	keypad_PORT = 0xFF;
}

char keypad_get_char(){
	int i,j;
	for(i=0; i<4; i++){
		keypad_PORT |= ((1<<keypad_c[0]) | (1<<keypad_c[1]) | (1<<keypad_c[2]) | (1<<keypad_c[3]));
		keypad_PORT &= ~(1<<keypad_c[i]);
		for(j=0; j<4; j++ ){
			if((keypad_PIN & (1<<keypad_r[j])) == 0){
				while((keypad_PIN & (1<<keypad_r[j])) == 0);
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
  return 'N';
}
	
	


