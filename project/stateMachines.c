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

/* Number of interrupts/sec */
void update_timer()
{
  update_sec++;
  if(update_sec == 125) {
    update_sec = 0;
  }
}


/* Game menu state*/
void main_menu_state()
{
  clearScreen(COLOR_BLACK);
  drawString8x12(columnCenter, rowCenter, "A", WHITE, BLACK);
}