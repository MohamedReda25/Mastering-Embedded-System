/*
 * main.c
 *
 *  Created on: Jul 20, 2022
 *      Author: redam
 */


#include "stdio.h"
#include "string.h"

void main(){


	float a[2][2];
	float b[2][2];
	float sum[2][2];
	printf("Enter the elements of 1st matrix\r\n");
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("Enter a%d%d: ",i+1,j+1);
			fflush(stdin);
			fflush(stdout);
			scanf("%f",&a[i][j]);

		}


	}

	printf("Enter the elements of 2nd matrix\r\n");
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("Enter b%d%d: ",i+1,j+1);
			fflush(stdin);
			fflush(stdout);
			scanf("%f",&b[i][j]);

		}


	}

	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			sum[i][j]=a[i][j]+b[i][j];
		}
	}
	printf("Sum of matrix:\r\n");
	for(int i=0; i<2; i++){
		for(int j=0; j<2; j++){
			printf("%.2f",sum[i][j]);
			printf("   ");
		}
		printf("\r\n");
	}


}
