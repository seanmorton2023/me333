#include "NU32.h"          // config bits, constants, funcs for startup and UART
#include <stdio.h>
#include "encoder.h"
#include "ina219.h"

//user-added header files for different functionalities
#include "sfr.h"
#include "posn.h"
#include "current.h"

#define ADC_PIN 5           // pin 5 on the PIC/NU32
#define BUF_SIZE 200
#define conversion 360/344/4 //convert from counts to angles
#define NUM_SAMPS 100
#define TRAJ_BUF 3000

//control variables for position control
volatile float e, e_old = 0;
volatile float eint = 0, edot = 0;
volatile float Kp = 0, Ki = 0, Kd = 0;
volatile float u; //torque/current command sent to the current ISR

//control variables for current control
volatile float f, f_old = 0;
volatile float fint = 0, fdot = 0;
volatile float Jp = 0, Ji = 0, Jd = 0;
volatile float  v;

//for sending data in ITEST
volatile int curr_count = 0;
volatile int posn_count = 0;
volatile float curr_array[NUM_SAMPS];
volatile float ref_array[NUM_SAMPS];

//reference position/velocity, controlled by user input
int client_input; //for PWM percentage
volatile float ref_curr = 0;
volatile float ref_posn = 0;

//for executing trajectories in l/m/n/o
volatile float traj_array[TRAJ_BUF];
volatile float posn_array[TRAJ_BUF];
volatile float traj;
volatile int traj_length;

int main() 
{
  char buffer[BUF_SIZE];
  NU32_Startup(); // cache on, min flash wait, interrupts on, LED/button init, UART init
  
  NU32_LED1 = 1;  // turn off the LEDs
  NU32_LED2 = 1; 
  
  __builtin_disable_interrupts();
  // in future, initialize modules or peripherals here
  initialize_sfrs();
  UART2_Startup();
  INA219_Startup();
  __builtin_enable_interrupts();

  while(1)
  {
    NU32_ReadUART3(buffer,BUF_SIZE); // we expect the next character to be a menu command
    NU32_LED2 = 1;                   // clear the error LED
    switch (buffer[0]) {

		case 'b':
		{
			//read current sensor in milli-amps
			float ma = INA219_read_current();
			sprintf(buffer, "%f\r\n", ma);
			NU32_WriteUART3(buffer);
			break;
		}

		case 'c':
		{
			//read encoder value in counts
			WriteUART2("a");

			while (!get_encoder_flag()) {
				//delay until encoder/PICO are done sending insructions
			}
			
			set_encoder_flag(0); //prepare for new instructions
			char m[50];
			int p = get_encoder_count();
			sprintf(m, "%d\r\n", p);
			NU32_WriteUART3(m);
			break;
		}

		case 'd':
		{
			//read encoder value in degrees
			WriteUART2("a");
			
			while (!get_encoder_flag()) {
				//delay until encoder/PICO are done sending insructions
			}
			
			set_encoder_flag(0); //prepare for new instructions
			char m[50];
			float p = get_encoder_count();
			sprintf(m, "%f\r\n", p * 360 /4/334 );
			NU32_WriteUART3(m);
			break;
		}
		
		case 'e':
		{
			//reset encoder count
			WriteUART2("b");
			break;
		}

		case 'f':
		{
			//Set PWM (-100 to 100)
			set_mode(PWM);

			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer,"%d", &client_input);
			break;
		}
  
		case 'g':
		{
			//set current gains
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Jp);
			
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Ji);		

			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Jd);			
			break;
		}
		
		case 'h':
		{
			//get current gains
			sprintf(buffer, "%f\r\n",Jp);
			NU32_WriteUART3(buffer);
			
			sprintf(buffer, "%f\r\n", Ji);
			NU32_WriteUART3(buffer);
			
			sprintf(buffer, "%f\r\n", Jd);
			NU32_WriteUART3(buffer);
			
			break;
		}
		
		case 'i':
		{
			//set position gains
			
			//set position Kp
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Kp);
			
			//set position Ki
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Ki);		
			
			//set position Kd
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Kd);			
			break;
		}
		
		case 'j':
		{
			//get position gains
			sprintf(buffer, "%f\r\n", Kp);
			NU32_WriteUART3(buffer);
			
			sprintf(buffer, "%f\r\n", Ki);
			NU32_WriteUART3(buffer);			

			sprintf(buffer, "%f\r\n", Kd);
			NU32_WriteUART3(buffer);			
			
			break;
		}
		
		case 'k':
		{
			//go into ITEST mode for gain testing
			curr_count = 0;		
			eint = 0;
			fint = 0;
			set_mode(ITEST);
			
			//current control ISR at 5KHz times 200 samples
			//should take 0.04 seconds. wait til done
			while (get_mode() == ITEST) {
				//nothing
			}
			
			sprintf(buffer, "%d\r\n", NUM_SAMPS); 
			NU32_WriteUART3(buffer);
			
			send_current_arrays();		
			break;
		}
		
		case 'l':
		{
			/*
			//go to a position
			posn_count = 0;
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", ref_posn);
			
			set_mode(HOLD);
			
			//wait for HOLD mode to be done, i.e. to settle
			//at a position
			while (get_mode() == HOLD){
				//nothing
				//NU32_WriteUART3("Inside loop for HOLD mode\r\n");

			}
			
			//send a basic signal saying "HOLD mode is done"
			//NU32_WriteUART3("1\r\n");
				
				*/
				
			break;
		}
		
		case 'm':
		{
			//load step trajectory

			//get the length of the array
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%d", &traj_length);
			
			//read each individual trajectory command
			for (int i = 0; i < traj_length; ++i) {
				NU32_ReadUART3(buffer, BUF_SIZE);
				sscanf(buffer, "%f", &traj);
				traj_array[i] = traj;
			}
			
			break;
		}
		
		case 'n':
		{
			//get the length of the array
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%d", &traj_length);
			
			//read each individual trajectory command
			for (int i = 0; i < traj_length; ++i) {
				NU32_ReadUART3(buffer, BUF_SIZE);
				sscanf(buffer, "%f", &traj);
				traj_array[i] = traj;
			}
					
			break;
		}
  
		case 'o':
		{
			//execute trajectory set by m or n
			posn_count = 0;
			eint = 0;
			fint = 0;
			set_mode(TRACK);

			//wait for the mode to change
			while (get_mode() == TRACK) {
				//nothing	
			}
			
			//send number of datapoints to client
			sprintf(buffer, "%d\r\n", traj_length);
			NU32_WriteUART3(buffer);
			
			//send data to client
			send_posn_arrays();
			break;
		}
		
		case 'p':
		{
			//unpower the motor
			set_mode(IDLE);
			break;
		}
	  
		case 'q':
		{
			// handle q for quit. Later you may want to return to IDLE mode here.
			set_mode(IDLE);

			//delay a short amount of time to make sure ISR hits
			for (int i = 0; i < 4000000; ++i){
				//nothing
			}

			return 0;
		}
	  
		case 'r':
		{
			//read what mode the motor is in
			sprintf(buffer, "%d\r\n", mode);
			NU32_WriteUART3(buffer);
			break;
		}

		case 'x':                      // dummy command for demonstration purposes
		{
			int n = 0;
			NU32_ReadUART3(buffer,BUF_SIZE);
			sscanf(buffer, "%d", &n);
			sprintf(buffer,"%d\r\n", n + 1); // return the number + 1
			NU32_WriteUART3(buffer);
			break;
		}
	  

		default:
		{
			NU32_LED2 = 0;  // turn on LED2 to indicate an error
			break;
		}
	  
    }
	
  }
  
  
  return 0;
}

