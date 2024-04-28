#include <msp430.h>
#include "stateMachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "switches.h"

enum State current_state = INTRO;
int update_sec = 0;
int sec_flag = 0;
short columnCenter = screenWidth >> 1;
short rowCenter = screenHeight >> 1;
//short background_color = BLACK;
short redrawScreen = 0;

/* Number of interrupts/sec */
void update_timer()
{
  update_sec++;
  if(update_sec == 125) {
    update_sec = 0;
    sec();
  }
}

// Toggle the sec_flag when update_sec is equal to whatever interrupts/sec is
void sec()
{
  sec_flag = sec_flag == 0 ? 1 : 0;
}

int i = 45;

/* Game title and back ground*/
void intro_state()
{
  clearScreen(COLOR_BLACK);
  drawString11x16(columnCenter-24, rowCenter-50, "PONG", COLOR_WHITE, COLOR_BLACK);
  current_state = MENU;
}

/* Game menu state*/
void main_menu_state()
{
  if(sec_flag) {
    drawString5x7(columnCenter-i, rowCenter+30, "PRESS ANY BUTTON", COLOR_BLACK, COLOR_BLACK);
  }
  else{
    drawString5x7(columnCenter-i, rowCenter+30, "PRESS ANY BUTTON", COLOR_WHITE, COLOR_BLACK);
  }
}

/* Explains the controls for the game */
void controls_state()
{
  clearScreen(COLOR_GREEN);
  drawString11x16(columnCenter, rowCenter, "PONG", COLOR_WHITE, COLOR_BLACK);
}
