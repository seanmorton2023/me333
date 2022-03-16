
#ifndef CURRENT__H__
#define CURRENT__H__

#include <xc.h>
#include <stdio.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "picmodes.h"
#include "ina219.h"

#define EINT_MAX 50
#define NUM_SAMPS 100
#define BUF_SIZE 200


//ISR function is defined in the .c file only
void send_current_arrays(void);
void current_PID(void);


#endif //__CURRENT__H_