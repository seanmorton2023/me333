
#ifndef POSN__H__
#define POSN__H__

#include <xc.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "encoder.h"
#include "picmodes.h"

extern volatile float e, eint, edot;
extern volatile float Kp, Ki, Kd;
extern volatile float u, u_old;
extern volatile float u_out; //torque/current command passed to current controller

extern volatile float ref_curr;
extern volatile float ref_posn;


//ISR defined in posn.c only


#endif //__POSN__H_