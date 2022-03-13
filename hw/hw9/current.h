
#ifndef CURRENT__H__
#define CURRENT__H__

#include <xc.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "picmodes.h"

#define EINT_MAX 100
#define EINT_MIN -100

extern volatile float f, fint;
extern volatile float  v;
extern volatile float Jp, Ji;
extern volatile int count; //for counting up in ITEST

extern int client_input;

//arrays for storing data
extern float curr_array;
extern float ref_array;

void send_current_arrays(void);

//ISR function is defined in the .c file only


#endif //__CURRENT__H_