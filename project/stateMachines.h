#ifndef stateMachines_included
#define stateMachines_included

// supported states
enum State{
  INTRO = 0,
  MENU = 1,
  CONTROLS = 2
};


// external variables
extern enum State current_state;
extern int sec_count;
extern int sec_flag;
extern short redrawScreen;
extern short background_color;

void intro_state();
void main_menu_state();
void controls_state();
void update_timer();
void sec();

#endif // included
