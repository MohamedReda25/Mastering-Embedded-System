/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "string.h"


#define PI 3.1415
#define Area(r) (r)*(r)*(PI)

int main(int argc, char *argv[]) {

	float r;
	printf("Enter Radius: ");
	fflush(stdin); fflush(stdout);
	scanf("%f" , &r);

	printf("Area = %.2f" , Area(r));

	return 0;

}
