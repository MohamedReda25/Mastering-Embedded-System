/*learn_in_depth

by Mohamed Reda*/


#include "Platform_Types.h"


extern int main(void);

void reset_Handler(void);

void Default_Handler(){

	reset_Handler();
}

void NMI_Handler(void)__attribute__((weak,alias ("Default_Handler")));;
void H_fault_Handler(void)__attribute__((weak,alias ("Default_Handler")));;

static uint32_t stack_top[256];


void (*const g_p_fn_vectors[])()__attribute__((section(".vectors")))  = {
(void(*)()) ((uint32_t)stack_top+sizeof(stack_top)),
(uint32_t) &reset_Handler,
(uint32_t) &NMI_Handler,
(uint32_t) &H_fault_Handler,

};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_Handler(){

	// Copy data from ROM to RAM;
	
	unsigned int size_data =  (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* src_data   =  (unsigned char*)&_E_text;
	unsigned char* dst_data   =  (unsigned char*)&_S_data;
	for(int i =0 ; i < size_data ; i++){
		*((unsigned char*)dst_data++) = *((unsigned char*)src_data++);
	}

	// Initialize bss in RAM with zeros;
	unsigned int size_bss =  (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	dst_data =  (unsigned char*)&_S_bss;
	for(int i =0 ; i < size_bss ; i++){
		*((unsigned char*)dst_data++) = (unsigned char) 0;
	}

	// Jump to main
	main();
}