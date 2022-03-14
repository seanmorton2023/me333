
#ifndef POSN__H__
#define POSN__H__

#include <xc.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "encoder.h"
#include "picmodes.h"

#define POSN_EINT_MAX 100
#define POSN_EINT_MIN -100
#define POSN_EDOT_THRES 0.1
#define POSN_E_THRES 0.1

#define POSN_DATASIZE 400 //for 2 seconds' worth of ISR executions
							//for a 200HZ ISR

extern volatile float e, e_old;
extern volatile float eint, edot;
extern volatile float Kp, Ki, Kd;
extern volatile float u; //torque/current command passed to current controller

extern volatile float ref_curr;
extern volatile float ref_posn;
extern volatile int posn_count;

//ISR defined in posn.c only


#endif //__POSN__H_