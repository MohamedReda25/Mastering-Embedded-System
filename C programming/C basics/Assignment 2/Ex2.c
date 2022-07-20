/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: redam
 */
#include "stdio.h"

void main(){
	char alphapet;

	printf("Enter an alphapet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&alphapet);
	fflush(stdin);
	fflush(stdout);


	switch(alphapet)
	{
	case 'i':
	case 'I':
	case 'a':
	case 'A':
	case 'e':
	case 'E':
	case 'o':
	case 'O':
		printf("%c is a vowel.",alphapet);
		break;
	default:
		printf("%c is a consonant.",alphapet);
	}


}
