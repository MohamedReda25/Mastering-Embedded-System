#include "uart.h"
unsigned char str[100] = "Learn-in-depth: Mohamed Reda";
void main(void){

uart_send_string(str);


}