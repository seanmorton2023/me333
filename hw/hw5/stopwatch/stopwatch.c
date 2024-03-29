#include "NU32.h"          // constants, funcs for startup and UART
#include <stdio.h>
#define MAX_LEN 100

//global variable to determine whether our button was pressed to start timing
static volatile int timing = 0;
static volatile float count;
static char writestring[MAX_LEN];
int sec = 40000000; //in core timer counts


//ISR for taking an interrupt from the button press from INT2
void __ISR(_EXTERNAL_2_VECTOR, IPL6SRS) Ext2ISR(void) {
	
	//set the flag status back to 0
	IFS0bits.INT2IF = 0;
	
	//delay for debounce. wait for 10ms after the button press
	count = _CP0_GET_COUNT();
	while (_CP0_GET_COUNT() < count + 400000) {;} 
	
	//if the button isn't pressed after this time, then ISR was triggered by
	//switch bounce upon release
	if (NU32_USER) {
		return;
	}
	
	//if button was pressed to start timing, clear core timer and start the count
	if (timing == 0) {
		_CP0_SET_COUNT(0);
		NU32_WriteUART3("Press USER button to stop timing.\r\n");
		timing = 1;
		
	//if button was pressed to access time, get the count and revert back
	} else {
		count = _CP0_GET_COUNT();
		sprintf(writestring, "Current count of the clock: %.3f seconds \r\n\n",count/sec);
		NU32_WriteUART3(writestring);
		NU32_WriteUART3("Press USER button to begin timing.\r\n");
		timing = 0;
	}
}



int main(void) {
  NU32_Startup(); // cache on, min flash wait, interrupts on, LED/button init, UART init
  __builtin_disable_interrupts(); // step 2: disable interrupts
  
	INTCONbits.INT2EP = 0; //falling edge
	IEC0bits.INT2IE = 1; //enable external interrupt 2
	IFS0bits.INT2IF = 0; //clear the interrupt flag
	
	IPC2bits.INT2IP = 6; //priority level 6
	IPC2bits.INT2IS = 0; //subpriority 0
	
	__builtin_enable_interrupts();  // step 7: enable interrupts
				
	NU32_WriteUART3("Press USER button to begin timing.\r\n");

				
  while(1) {
	  ; // do nothing, loop forever
  }

  return 0;
}
