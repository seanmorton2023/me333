
#ifndef __CURRENT__H_
#define __CURRENT__H_


#include <xc.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "picmodes.h"

//control variables for current control
static volatile float Jp = 0, Ji = 0;
static volatile float f, fint = 0;
static volatile float  v;

extern int client_input;
//ISR function is defined in the .c file only


#endif //__CURRENT__H_