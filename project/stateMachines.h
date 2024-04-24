#ifndef stateMachine_included
#define stateMachine_included

// supported states
enum State{
  MENU = 0,
  SIREN = 1,
  SONG1 = 2,
  SONG2 = 3,
  SONG3 = 4
};


// external variables
extern enum State current_state;
extern int sec_count;
extern int sec_flag;
extern short redrawScreen;

void main_menu_state();
void update_timer();
void sec();

#endif // included
