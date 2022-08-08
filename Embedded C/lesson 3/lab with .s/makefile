CC =arm-none-eabi-
CCFLAG=-mcpu=cortex-m3 -gdwarf-2
INCS=-I .
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
OBJS=$(AS:.s=.o)
PROJECT_NAME=learn_in_depth_cortex_m3






all: $(PROJECT_NAME).bin
	@echo "-------Build is done--------"
%.o: %.c
	$(CC)gcc.exe -c $(CCFLAG) $(INCS) $< -o $@
startup.o: startup.s
	$(CC)as.exe -c $(CCFLAG) $< -o $@

$(PROJECT_NAME).elf: $(OBJ) $(OBJS)
	$(CC)ld.exe -T linker_script.ld -Map=map_file.map $(OBJ) $(OBJS) -o $@

$(PROJECT_NAME).bin: $(PROJECT_NAME).elf
	$(CC)objcopy.exe -O binary $(PROJECT_NAME).elf $(PROJECT_NAME).bin

clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.elf *.bin