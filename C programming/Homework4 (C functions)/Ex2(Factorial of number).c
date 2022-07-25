/*
 * main.c
 *
 *  Created on: Jul 25, 2022
 *      Author: redam
 */


#include "stdio.h"

int factorial(int n){
	if(n==0){
		return 1;
	}
	return n * factorial(n-1);
}




void main(){
int n;
printf("Enter an positive number: ");
fflush(stdin); fflush(stdout);
scanf("%d",&n);
fflush(stdin); fflush(stdout);
printf("Factorial of %d = %d ",n,factorial(n));


}
