#include "NU32.h"          // constants, funcs for startup and UART
#define MAX_LEN 100;

//global variable to determine whether our button was pressed to start timing
static volatile int timing = 0;
static volatile float count;
static volatile char[MAX_LEN] writestring;

/* void __ISR(_EXTERNAL_0_VECTOR, IPL2SOFT) Ext0ISR(void) { // step 1: the ISR
  NU32_LED1 = 0;                  // LED1 and LED2 on
  NU32_LED2 = 0;
  _CP0_SET_COUNT(0);
  
  while(_CP0_GET_COUNT() < 400000) { ; } // delay for 400k core ticks, 10ms
  
  NU32_LED1 = 1;                  // LED1 and LED2 off
  NU32_LED2 = 1;
  IFS0bits.INT0IF = 0;            // clear interrupt flag IFS0<3>
} */

//ISR for taking an interrupt from the button press from INT2
void __ISR(_EXTERNAL_2_VECTOR, IPL6SRS) Ext2ISR(void) {
	
	//if button was pressed to start timing, clear core timer and start the count
	if (timing = 0) {
		_CP0_SET_COUNT(0);
		NU32_WriteUART3("Press USER button to stop timing.\r\n");
		timing = 1;
		
	//if button was pressed to access time, get the count and revert back
	} else {
		count = _CP0_GET_COUNT();
		sprintf(writestring, "Current count of the clock: %.3f \r\n\n",count);
		NU32_WriteUART3(writestring);
		timing = 0;
		NU32_WriteUART3("Press USER button to begin timing.\r\n");
		
	}
	
	//set the flag status back to 0
	IFS0bits.INT2IF = 0;
	
	//delay for debounce. wait for 10ms after the button press
	while (_CP0_GET_COUNT() < count + 400000) {;} 
}



int main(void) {
  NU32_Startup(); // cache on, min flash wait, interrupts on, LED/button init, UART init
  __builtin_disable_interrupts(); // step 2: disable interrupts
  
  
/*   INTCONbits.INT0EP = 0;          // step 3: INT0 triggers on falling edge
  IPC0bits.INT0IP = 2;            // step 4: interrupt priority 2
  IPC0bits.INT0IS = 1;            // step 4: interrupt priority 1
  IFS0bits.INT0IF = 0;            // step 5: clear the int flag
  IEC0bits.INT0IE = 1;            // step 6: enable INT0 by setting IEC0<3>
  __builtin_enable_interrupts();  // step 7: enable interrupts
                                  // Connect RD7 (USER button) to INT0 (RD0)
								   */
		
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