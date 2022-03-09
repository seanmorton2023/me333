
#ifndef CURRENT__H__
#define CURRENT__H__

#include <xc.h>
#include "NU32.h"
#include <sys/attribs.h> // __ISR macro
#include "picmodes.h"

extern volatile float f, fint;
extern volatile float  v;
extern volatile float Jp, Ji;

extern int client_input;
//ISR function is defined in the .c file only


#endif //__CURRENT__H_