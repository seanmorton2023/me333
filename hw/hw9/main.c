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

//control variables for position control
volatile float e, eint = 0, edot;
volatile float Kp = 0, Ki = 0, Kd = 0;
volatile float u, unew;
volatile float u_out = 0; //torque/current command passed to current controller

//control variables for current control
volatile float Jp = 0, Ji = 0;
volatile float f, fint = 0;
volatile float  v;

//reference position/velocity, controlled by user input
int client_input;
static volatile int adcval;

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
			//sprintf(buffer, "Current value in mA: %.2f \r\n", ma);
			sprintf(buffer, "%f \r\n", ma);
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
			sprintf(m, "%d \r\n", p);
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
			sprintf(m, "%.1f \r\n", p * 360 /4/334 );
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
			mode = PWM;

			NU32_WriteUART3("\nSet PWM (-100 to 100): ");
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer,"%d", &client_input);
			sprintf(buffer, "\r\nPWM set as: %d \r\n", client_input);
			NU32_WriteUART3(buffer);
			break;
		}
  
		case 'g':
		{
			//set current gains
			NU32_WriteUART3("r\nEnter new current gain Kp: ");
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Jp);
			
			NU32_WriteUART3("\r\nEnter new current gain Ki: ");
			NU32_ReadUART3(buffer, BUF_SIZE);
			sscanf(buffer, "%f", &Ji);			
			
			sprintf(buffer, "\r\nNew P + I gains: %.3f, %.3f \r\n\n", Jp, Ji);
			NU32_WriteUART3(buffer);
			
			break;
		}
		
		case 'h':
		{
			//get current gains
			sprintf(buffer, "Current gains (Kp, Ki): %.3f %.3f \r\n\n", Jp, Ji);
			NU32_WriteUART3(buffer);
			
			break;
		}
  
  
		case 'p':
		{
			//unpower the motor
			NU32_WriteUART3("\nMotor set to IDLE mode.\r\n\n");
			mode = IDLE;
			break;
		}
	  
		case 'q':
		{
			// handle q for quit. Later you may want to return to IDLE mode here.
			mode = IDLE;

			//delay a short amount of time to make sure ISR hits
			for (int i = 0; i < 4000000; ++i){
				//nothing
			}
			
			NU32_WriteUART3("Exiting. Goodbye!");

			return 0;
		}
	  
		case 'r':
		{
			//read what mode the motor is in
			sprintf(buffer, "\nCurrent mode of program: %d \r\n", mode);
			NU32_WriteUART3(buffer);

			sprintf(buffer,
			"\nGuide to program modes: \r\n"
			"IDLE Mode: %d \r\n" 
			"PWM Mode: %d \r\n"
			"ITEST Mode: %d \r\n"
			"HOLD Mode: %d \r\n"
			"TRACK Mode: %d \r\n\n",
			IDLE, PWM, ITEST, HOLD, TRACK
			);
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

