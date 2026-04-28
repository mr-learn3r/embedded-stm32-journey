CC = arm-none-eabi-gcc
CFLAGS = -mcpu=cortex-m0 -mthumb -nostdlib -nostartfiles -g -Wall

all: blinky.elf

blinky.elf:	main.c startup.c
	$(CC) $(CFLAGS) -T linker_script.ld main.c startup.c -o blinky.elf

flash:	blinky.elf
	openocd -f interface/stlink.cfg -f target/stm32f0x.cfg \
	-c "program blinky.elf verify reset exit"

clean:
	rm -f *.elf *.o
