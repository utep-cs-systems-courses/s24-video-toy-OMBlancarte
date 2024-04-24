#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"


enum State current_state = MENU;
int update_sec = 0;
int sec_flag = 0;
u_char width = screenWidth;
u_char height = screenHeight;
short columnCenter = width >> 1;
short rowCenter = height >> 1;
u_int background_color = BLACK;
short redrawScreen = 0;

/* Number of interrupts/sec */
void update_timer()
{
  update_sec++;
  if(update_sec == 125) {
    update_sec = 0;
  }
}

// Toggle the sec_flag when update_sec is equal to whatever interrupts/sec is
void sec()
{
  sec_flag = sec_flag == 0 ? 1 : 0;
}

/* Game menu state*/
void main_menu_state()
{
  if(sec_flag) {
    clearScreen(background_color);
  }
  else{
    drawString8x12(columnCenter, rowCenter, "A", WHITE, background_color);
  }
}
