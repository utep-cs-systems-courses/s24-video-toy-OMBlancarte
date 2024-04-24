#ifndef switches_included
#define switches_included

// Buttons on P2
#define SW1 BIT0
#define SW2 BIT1
#define SW3 BIT2
#define SW4 BIT3


/* 4 switches on this board */
#define SWITCHES (SW1|SW2|SW3|SW4)


void switch_init();
static char switch_update_interrupt_sense();
void switch_interrupt_handler();


#endif // included
