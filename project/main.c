#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "stateMachines.h"
#include "switches.h"
#include "buzzer.h"

// WARNING: LCD DISPLAY USES P1.0.  Do not touch!!!
//#define LED BIT6   /* note that bit zero req'd for display */


void main()
{
  P1DIR |= 64;         /**< Green led on when CPU on */
  P1OUT |= 64;

  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();      /**< enable periodic interrupt */
  or_sr(0x8);              /**< GIE (enable interrupts) */
  
  while (1) {                 /* forever */
    if (redrawScreen) {
      redrawScreen = 0;
      //update_shape();
    }
    P1OUT &= ~64;        /* led off */
    or_sr(0x10);          /**< CPU OFF */
    P1OUT |= 64;         /* led on */
  }
}
