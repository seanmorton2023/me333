
#include "posn.h"

float Kp = 0, Ki = 0, Kd = 0;

//control variables for position control
volatile float e, e_old = 0;
volatile float eint = 0, edot = 0;
volatile float u; //torque/current command sent to the current ISR

volatile int posn_count = 0;
volatile float ref_posn;
extern volatile float ref_curr;

//for executing trajectories in l/m/n/o
float traj_array[TRAJ_BUF];
float posn_array[TRAJ_BUF];
char m[BUF_SIZE];

float traj;
int traj_length;

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
			
			posn_PID();	
			
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

			break;
		}
		
		case TRACK:
		{
			
			posn_PID();			
			
			//end condition: we get to the end of the 
			//reference array
			if (posn_count > traj_length) {
				set_mode(IDLE);
				break;
			}
			
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



void send_posn_arrays(void) {
	
	sprintf(m,"");
	
	//send number of datapoints to client
	sprintf(m, "%d\r\n", traj_length);
	NU32_WriteUART3(m);
	
	for (int ii = 0; ii < traj_length; ++ii) {
		// sprintf(m, "%f %f\r\n", traj_array[i], posn_array[i]);
		// NU32_WriteUART3(m);	
		sprintf(m, "%f\r\n", traj_array[ii]);
		NU32_WriteUART3(m);	
		sprintf(m, "%f\r\n", posn_array[ii]);
		NU32_WriteUART3(m);	
	}	
}

void read_posn_arrays(void) {
				
	//get the length of the array
	NU32_ReadUART3(m, BUF_SIZE);
	sscanf(m, "%d", &traj_length);
	
	//read each individual trajectory command
	for (int j = 0; j < traj_length; j++) {
		NU32_ReadUART3(m, BUF_SIZE);
		// sscanf(m, "%f", &traj);
		// traj_array[i] = traj;
		sscanf(m, "%f", traj_array + j); //pointer to the i'th element of t_a
	}
}


void posn_PID(void) {
	
	//read encoder value in degrees
	WriteUART2("a");
	
	while (!get_encoder_flag()) {
		//delay until encoder/PICO are done sending insructions
	}
	
	set_encoder_flag(0); //prepare for new instructions
	float posn = get_encoder_count();
	posn = posn * 360/4/334;
	
	ref_posn = traj_array[posn_count];
	
	//PID control: calculate errors and calculate next ref val
	//of current/PWM output
	e = ref_posn - posn;
	
	//integrator anti windup
	if (eint > POSN_EINT_MAX) {
		eint = POSN_EINT_MAX;
	} else if (eint < -POSN_EINT_MAX) {
		eint = -POSN_EINT_MAX;
	}

	u = Kp * e + Ki * eint + Kd * edot;
	
	//bounds on current reference. current can take in
	//a refval of like 200 for the ITEST, so I'm assuming
	//it can take even more than that
	if (u > POSN_OUT_MAX) {
		u = POSN_OUT_MAX;
	} else if (u < -POSN_OUT_MAX) {
		u = -POSN_OUT_MAX;
	}
	
	//store value of position in array
	posn_array[posn_count] = posn;			
	
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
	
}