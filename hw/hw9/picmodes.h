
#ifndef PICMODES__H__
#define PICMODES__H__

//operating modes for PIC
enum picMode {
	IDLE,
	PWM,
	ITEST,
	HOLD,
	TRACK
} mode; //variable to set mode with

int get_mode(void);
void set_mode(int);

#endif