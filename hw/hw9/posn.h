
#ifndef __POSN__H_
#define __POSN__H_

#include <xc.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro


//control variables for position control
static volatile float Kp = 0, Ki = 0, Kd = 0;
static volatile float e, eint = 0, edot;
static volatile float u, unew;
static volatile float u_out = 0; //torque/current command passed to current controller

//ISR defined in posn.c only


#endif //__POSN__H_