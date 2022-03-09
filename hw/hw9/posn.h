
#ifndef POSN__H__
#define POSN__H__

#include <xc.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro

extern volatile float e, eint, edot;
extern volatile float Kp, Ki, Kd;
extern volatile float u, unew;
extern volatile float u_out; //torque/current command passed to current controller

//ISR defined in posn.c only


#endif //__POSN__H_