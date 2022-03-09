
#ifndef __SFR__H_
#define __SFR__H_


#include <xc.h>
#include "NU32.h"

#define SAMPLE_TIME 10       // 10 core timer ticks = 250 ns

//for initializing modules + SFRS on the PIC all at once
void initialize_sfrs(void);	
unsigned int adc_sample_convert(int pin);

#endif //__SFR__H_