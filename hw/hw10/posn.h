
#ifndef POSN__H__
#define POSN__H__

#include <xc.h>
#include <stdio.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "encoder.h"
#include "picmodes.h"

#define POSN_EINT_MAX 50
#define POSN_EDOT_THRES 0.1
#define POSN_E_THRES 0.1
#define POSN_OUT_MAX 1000

#define POSN_DATASIZE 400 //for 2 seconds' worth of ISR executions
							//for a 200HZ ISR
#define BUF_SIZE 200
#define TRAJ_BUF 3000


//ISR defined in posn.c only

void posn_PID(void);
void send_posn_arrays(void);
void read_posn_arrays(void);

#endif //__POSN__H_