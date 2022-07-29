/*
 * main.c
 *
 *  Created on: Jul 26, 2022
 *      Author: redam
 */

#include "stdio.h"
#include "string.h"


struct Scomplex{
	float real;
	float imj;
};

struct Scomplex add(struct Scomplex s1,struct Scomplex s2);

int main(int argc, char *argv[]) {

	struct Scomplex s1,s2,s3;
	printf("For 1st complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdout); fflush(stdin);
	scanf("%f%f",&s1.real,&s1.imj);
	printf("For 2nd complex number\n");
	printf("Enter real and imaginary respectively: ");
	fflush(stdout); fflush(stdin);
	scanf("%f%f",&s2.real,&s2.imj);
	s3=add(s1,s2);
	printf("Sum= %.2f + %.2fi",s3.real,s3.imj);

}

struct Scomplex add(struct Scomplex s1,struct Scomplex s2){
	struct Scomplex s;
	s.real = s1.real+s2.real;
	s.imj= s1.imj+s2.imj;
	return s;
}
