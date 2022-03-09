
#include "current.h"

//5KHz ISR to control current going to motor
void __ISR(_TIMER_3_VECTOR, IPL5SOFT) CurrentControl(void) {

	//TODO
	
	//takes current data from the ADC
	//adcval = adc_sample_convert(ADC_PIN);
	
	//PI controller for current
	
 	//set OC3RS at 25% of PR at first, modify later
	OC3RS = 500;
	
	//invert directional output of motor
	//LATDINV = 0b1 << 4; //invert digital output at pin 4
	
	
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