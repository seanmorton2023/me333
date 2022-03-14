
#include "posn.h"

//200Hz ISR to control torque/motor commands
void __ISR(_TIMER_4_VECTOR, IPL4SOFT) PositionControl(void) {

	//TODO
	switch(mode) {
		
		case HOLD:
		{
			//user inputs a position to main.c via ref_posn
			//and we have to navigate to that position
			
			//read encoder value in degrees
			WriteUART2("a");
			
			while (!get_encoder_flag()) {
				//delay until encoder/PICO are done sending insructions
			}
			
			set_encoder_flag(0); //prepare for new instructions
			float posn = get_encoder_count();
			posn = posn * 360/4/334;
			
			//PID control: calculate errors and calculate next ref val
			//of current/PWM output
			e = ref_posn - posn;
			
			//u = u + Kp * //I think I realized my mistake. 
			//the present value of u should be independent of the
			//past one, and instead be based on e, eint, edot only
			
			
			
			//send 
			
			
			
			break;
		}
		
		case TRACK:
		{
			
			
			
			break;
		}
		
		default:
		{
			break;
		}
		
		
		
		
		
	}


	//clear interrupt flag
	IFS0bits.T4IF = 0;

}