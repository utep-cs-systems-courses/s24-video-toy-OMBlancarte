#include <msp430.h>
#include "switches.h"
#include "stateMachines.h"

// Initialize switches
void switch_init()
{
  P2REN |= SWITCHES;    // enables resistors for switches
  P2IE |= SWITCHES;     // enables interrupts from switches
  P2OUT |= SWITCHES;    // pull-ups for switches
  P2DIR &= ~SWITCHES;   // set switches bits for input
}


// Update switch interrupt to detect changes from current buttons
static char switch_update_interrupt_sense()
{
  char p2val = P2IN;               // Read input bits from p2
  P2IES |= (p2val & SWITCHES);     // If switches are up, sense down
  return p2val;
}


// Handler for switch interrupts
void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  // Check which button is pressed. 0 when NOT pressed, 1 when pressed
  char button1 = (p2val & SW1) ? 0 : 1;
  char button2 = (p2val & SW2) ? 0 : 1;
  char button3 = (p2val & SW3) ? 0 : 1;
  char button4 = (p2val & SW4) ? 0 : 1;
  
  if(button1){
    //current_state = SIREN;
  }
  else if(button2){
    // current_state = SONG3;
  }
  else if(button3){
    //current_state = SONG1;
  }
  else if(button4){
    //current_state = SONG2;
  }
}
