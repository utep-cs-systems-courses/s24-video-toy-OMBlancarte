# makfile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as


all: musicMachine.elf


#additional rules for files
musicMachine.elf: ${COMMON_OBJECTS} buzzer.o led.o main.o wdInterruptHandler.o stateMachines.o switches.o p2_interrupt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} -o $@ $^


load: musicMachine.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf *~


buzzer.o: buzzer.h
main.o: buzzer.h led.h 
led.o: led.c led.h
stateMachines.o: stateMachines.c stateMachines.h led.h
wdInterruptHandler.o: stateMachines.h
switches.o: switches.c stateMachines.h
