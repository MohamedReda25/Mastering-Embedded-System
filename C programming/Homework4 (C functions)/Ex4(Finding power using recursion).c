#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int power (int base, int exp);

int main(int argc, char *argv[]) {

	int base, exp;
	printf("Enter base number: ");
	fflush(stdout);
	scanf("%d",&base);
	fflush(stdout);
	printf("Enter power number(positive integer): ");
	fflush(stdout);
	scanf("%d",&exp);
	fflush(stdout);
	printf("%d^%d = %d",base,exp,power(base,exp));
	return 0;

}
int power(int base, int exp){
	if(exp != 0){
		return(base*power(base,exp-1));
	}
	else{
		return 1;
	}
}


