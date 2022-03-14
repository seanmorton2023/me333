
#ifndef CURRENT__H__
#define CURRENT__H__

#include <xc.h>
#include <stdio.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "picmodes.h"
#include "ina219.h"

#define EINT_MAX 100
#define EINT_MIN -100
#define NUM_SAMPS 100
#define BUF_SIZE 200

extern volatile float f, fint, fdot;
extern volatile float  v, v_old;
extern volatile float Jp, Ji, Jd;
extern volatile int count; //for counting up in ITEST

extern int client_input;

//arrays for storing data
extern volatile float curr_array[NUM_SAMPS];
extern volatile float ref_array[NUM_SAMPS];
	
char m[BUF_SIZE];
void send_current_arrays(void);

extern volatile float ref_curr;
static volatile float current;

//ISR function is defined in the .c file only


#endif //__CURRENT__H_