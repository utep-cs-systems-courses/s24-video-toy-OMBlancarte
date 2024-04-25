# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/ 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c


all: game.elf


#additional rules for files
game.elf: ${COMMON_OBJECTS} buzzer.o main.o wdt_c_handler.o stateMachines.o switches.o p2_interrupt_handler.o wdt_handler.o
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd


load: game.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf *~
