#include <msp430.h>
#include <libTimer.h>
#include "stateMachines.h"



void wdt_c_handler()
{
  update_timer();
  switch (current_state) {
    case MENU:               
      main_menu_state();
      break;
  } 
}
