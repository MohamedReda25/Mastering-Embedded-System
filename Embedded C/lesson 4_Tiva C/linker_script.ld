/* learn-in-depth 

by Mohamed Reda*/ 

MEMORY
{
	flash(RX) : ORIGIN = 0X00000000, LENGTH = 512m
	sram(RWX) : ORIGIN = 0X20000000, LENGTH = 512m
}

SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_text = .;
	} > flash
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
		_E_bss = .;

	} > sram
	 
}