#include <msp430.h>
#include <libTimer.h>
#include "stateMachines.h"



void wdt_c_handler()
{
  update_timer();
  
  switch (current_state) {
    case INTRO:
      intro_state();
      break;
    case MENU:               
      main_menu_state();
      break;
    case CONTROLS:
      controls_state();
      break;
  } 
  
}
