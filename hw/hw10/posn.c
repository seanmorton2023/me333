
#include "posn.h"

//200Hz ISR to control torque/motor commands
void __ISR(_TIMER_4_VECTOR, IPL4SOFT) PositionControl(void) {

	//TODO
	switch(mode) {
		
		case HOLD:
		{
			//user inputs a position to main.c via ref_posn
			//and we have to navigate to that position
			
			//check: do we enter the ISR?
			//NU32_WriteUART3("Entered HOLD mode in posn.c\r\n");
			
			
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
			
			//integrator anti windup
			if (eint > POSN_EINT_MAX) {
				eint = POSN_EINT_MAX;
			} else if (eint < POSN_EINT_MIN) {
				eint = POSN_EINT_MIN;
			}
	
			u = Kp * e + Ki * eint + Kd * edot;
			
			//bounds on PWM
			if (u > 100) {
				u = 100;
			} else if (u < -100) {
				u = -100;
			}
			
			//end condition: maybe when edot goes to zero?
			//do "if end_condition -> set_mode(IDLE" so this
			//doesn't go forever
			if (-POSN_EDOT_THRES < edot < POSN_EDOT_THRES) {
				if (-POSN_E_THRES < e < POSN_E_THRES) {	
					set_mode(IDLE);
					break;
				}
			} else if (posn_count > POSN_DATASIZE) {
				set_mode(IDLE);
				break;
			}
			
			//send this new value of position PID control
			//output to the current PID controller. we don't
			//want to set refval before this b/c the current
			//ISR can interrupt this one and grab refval too early
			ref_curr = u;
			
			//setup next iteration of PID
			edot =  e - e_old;
			eint += e;
			e_old = e;
			posn_count++;

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