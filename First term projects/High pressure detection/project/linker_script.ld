/* learn-in-depth 

by Mohamed Reda*/ 

MEMORY
{
	flash(RX) : ORIGIN = 0X08000000, LENGTH = 128k
	sram(RWX) : ORIGIN = 0X20000000, LENGTH = 20k
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	}> flash
	.data :
	{	
		_S_data = .;
		*(.data)
		. = ALIGN(4);
		_E_data = .;
	}> sram AT> flash
	.bss :
	{
		_S_bss = .;
		*(.bss*)
		. = ALIGN(4);
		_E_bss = .;

		. = ALIGN(4);
		. = . + 0x1000 ;
		_stack_top = .;

	}> sram
	.comment :
	{
	 	*(.comment) *(COMMON)
	}> flash
	 
}