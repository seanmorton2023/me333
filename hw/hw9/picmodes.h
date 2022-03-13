
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


int get_mode() {
	return mode;
}

void set_mode(int newmode) {
	mode = newmode;
}

#endif