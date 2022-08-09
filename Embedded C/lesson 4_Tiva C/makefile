CC =arm-none-eabi-
CCFLAG=-mcpu=cortex-m4 -gdwarf-2 -g
INCS=-I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
OBJS=$(AS:.s=.o)
PROJECT_NAME=lab3_cortex_m4






all: $(PROJECT_NAME).bin
	@echo "-------Build is done--------"
%.o: %.c
	$(CC)gcc.exe -c $(CCFLAG) $(INCS) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(OBJS)
	$(CC)ld.exe -T linker_script.ld -Map=map_file.map $(OBJ) $(OBJS) -o $@
	cp $@ $(PROJECT_NAME).axf

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin
	

clean_all:
	rm *.o *.elf *.bin *.map

clean:
	rm *.elf *.bin 