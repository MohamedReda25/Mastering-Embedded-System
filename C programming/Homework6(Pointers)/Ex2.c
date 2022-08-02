/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "string.h"



int main(int argc, char *argv[]) {

char c=65;
char* pc =&c;
for(int i=0; i<26; i++){
	printf("%c  ",*pc+i);
}


}
