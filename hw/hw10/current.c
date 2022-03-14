
#include "current.h"

//5KHz ISR to control current going to motor
void __ISR(_TIMER_3_VECTOR, IPL5SOFT) CurrentControl(void) {

	
	//set PWM and motor direction based on mode flag
	switch (mode) {
		
		case IDLE:
		{
			//the PWM duty cycle and direction bit
			//should put the H-bridge in brake mode.

			//set PWM duty cycle to 0 so the motor is always in brake mode
			OC3RS = 0;
			
			break;
		}
		
		case PWM:
		{
			//If the operating mode is PWM, the duty cycle and direction bit are set according to 
			//the value −100 to 100 specified by the user through the client
			
			//phase bit
			if (client_input < 0) {
				LATDbits.LATD4 = 0;
				OC3RS = (unsigned int) -client_input * PR2/100;			

			} else {
				LATDbits.LATD4 = 1;
				OC3RS = (unsigned int) client_input * PR2/100;			
			}
			
			//set PWM
			break;
		}
		
		case ITEST:
		{

			static int refval;
			static float current;
				
			//PI controller for current
			if (count < 25) {
				refval = 200;
			} else if (count < 50) {
				refval = -200;
			} else if (count < 75) {
				refval = 200;
			} else if (count < 100) {
				refval = -200;
			} else {
				set_mode(IDLE);
				break;
			}
					
			current = INA219_read_current();
			
			//integrator anti windup
			if (fint > EINT_MAX) {
				fint = EINT_MAX;
			} else if (fint < EINT_MIN) {
				fint = EINT_MIN;
			}
			
			
			//carry out PI controller for current
			f = refval - current;
			v = v + Jp * f + Ji * fint - Jd * fdot;
			
			//bounds on PI controller output
			if (v > 100.0) {
				v = 100.0; 
			} else if (v < -100.0) {
				v = -100.0;
			}
			
			//convert output of PI controller to PWM out - adjust the 
			//current through the system by adjusting voltages

			if (v < 0) {	
				//deal with "negative" direction
				LATDbits.LATD4 = 0;
				OC3RS = (unsigned int) -v * PR2/100;
			} else {
				LATDbits.LATD4 = 1;
				OC3RS = (unsigned int) v * PR2/100;		
			}
	
			//store values of current in arrays. send them in a separate
			//function because sprintf() takes a while
			curr_array[count] = current;
			ref_array[count] = refval;
	
			//setup calcs for next pass of ISR
			fdot = v - v_old;
			fint += f;
			v_old = v;
			count++;

			break;
		}
		
		case HOLD:
		{
			
			
			
			
			break;
		}
		
		case TRACK:
		{
			break;
		} 		
	}
	
	
	//clear interrupt flag
	IFS0bits.T3IF = 0;

}

//take every entry of current vs. expected val, and 
//send to client over UART
void send_current_arrays() {
		
	for (int i = 0; i < NUM_SAMPS; ++i) {
		sprintf(m, "%f %f\r\n", curr_array[i], ref_array[i]);
		NU32_WriteUART3(m);	
	}
}