
#include "posn.h"

//200Hz ISR to control torque/motor commands
void __ISR(_TIMER_4_VECTOR, IPL4SOFT) PositionControl(void) {

	//TODO
	
	//takes position data from the encoder via SPI



	//clear interrupt flag
	IFS0bits.T4IF = 0;

}