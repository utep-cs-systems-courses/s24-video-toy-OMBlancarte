#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port_2()
{
  if(P2IFG & SWITCHES) {            // Check if buttons caused an interrupt
    P2IFG &= ~SWITCHES;             // Clear pending switch interrupts
    switch_interrupt_handler();     // Handler for switches
  }
}
