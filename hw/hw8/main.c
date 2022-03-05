#include "NU32.h"          // config bits, constants, funcs for startup and UART
#include <stdio.h>
#include "encoder.h"

#define ADC_PIN 5           // pin 5 on the PIC/NU32
#define BUF_SIZE 200
#define SAMPLE_TIME 10       // 10 core timer ticks = 250 ns

//operating modes for PIC
enum picMode {
	IDLE,
	PWM,
	ITEST,
	HOLD,
	TRACK
} mode; //variable to set mode with

//for initializing modules + SFRS on the PIC all at once
void initialize_sfrs(void);	
unsigned int adc_sample_convert(int pin);


//control variables for position control
static volatile float Kp = 0, Ki = 0, Kd = 0;
static volatile float e, eint = 0, edot;
static volatile float u, unew;
static volatile float u_out = 0; //torque/current command passed to current controller

//control variables for current control
static volatile float Jp = 0, Ji = 0;
static volatile float f, fint = 0;
static volatile float  v;

//reference position/velocity, controlled by user input
int client_input;
static volatile int adcval;


//200Hz ISR to control torque/motor commands
void __ISR(_TIMER_4_VECTOR, IPL4SOFT) PositionControl(void) {

	//TODO
	
	//takes position data from the encoder via SPI



	//clear interrupt flag
	IFS0bits.T4IF = 0;

}

//5KHz ISR to control current going to motor
void __ISR(_TIMER_3_VECTOR, IPL5SOFT) CurrentControl(void) {

	//TODO
	
	//takes current data from the ADC
	adcval = adc_sample_convert(ADC_PIN);
	
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


int main() 
{
  char buffer[BUF_SIZE];
  NU32_Startup(); // cache on, min flash wait, interrupts on, LED/button init, UART init
  NU32_LED1 = 1;  // turn off the LEDs
  NU32_LED2 = 1;        
  __builtin_disable_interrupts();
  // in future, initialize modules or peripherals here
  initialize_sfrs();
  __builtin_enable_interrupts();

  while(1)
  {
    NU32_ReadUART3(buffer,BUF_SIZE); // we expect the next character to be a menu command
    NU32_LED2 = 1;                   // clear the error LED
    switch (buffer[0]) {
      case 'd':                      // dummy command for demonstration purposes
      {
        int n = 0;
        NU32_ReadUART3(buffer,BUF_SIZE);
        sscanf(buffer, "%d", &n);
        sprintf(buffer,"%d\r\n", n + 1); // return the number + 1
        NU32_WriteUART3(buffer);
        break;
      }
	  
	  case 'p':
	  {
		  //unpower the motor
		  NU32_WriteUART3("\Motor set to IDLE mode.\r\n\n");
		  mode = IDLE;
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
	  }
	  
      case 'q':
      {
        // handle q for quit. Later you may want to return to IDLE mode here. 
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


void initialize_sfrs(void) {
	
	//Peripherals and stuff to initialize:
	
	//SPI communication
	encoder_init(); //SPI comms enabled in external function
	
	//ADC input for current sensor: AN5
 	AD1CON1bits.ON = 1;
	AD1CON1bits.SIDL = 1;
	AD1PCFGbits.PCFG5 = 0; //pin 5 analog
	TRISDbits.TRISD5 = 1; //pin 5 input
	
 	//Digital output for H-bridge control: D4
	TRISDbits.TRISD4 = 0;
	LATDbits.LATD4 = 0; //direction of motor 
	
	//Timer initialization (3 timers)
	
	T2CONbits.TCKPS = 0b001; //prescaler of 2, use PR = 2000
	T2CONbits.T32 = 0;
	PR2 = 2000;

	T3CONbits.TCKPS = 0b011; //prescaler of 8, use PR = 2000
	PR3 = 2000;
	
	T4CONbits.TCKPS = 0b100; //prescaler of 16, use PR = 25000
	T4CONbits.T32 = 0;
	PR4 = 25000;
	
 	//OC PWM for H-bridge operation
	OC3CONbits.SIDL = 1;
	OC3CONbits.OCTSEL = 0; //timer2
	OC3CONbits.OCM = 0b110; //PWM mode; fault pin disabled
	OC3CONbits.OC32 = 0; //16 bit mode
	OC3R = 0; //initialize at 25% PR2 
	
	//Interrupt setup for ISRs on timers 3 and 4
	IPC3bits.T3IP = 5;
	IPC3bits.T3IS = 0;
		
	IPC4bits.T4IP = 4;
	IPC4bits.T4IS = 0;
	
	OC3CONbits.ON = 1;
	T2CONbits.ON = 1; //for 20KHz OC PWM
	T3CONbits.ON = 1; //for 5KHz current control ISR
	T4CONbits.ON = 1; //for 200Hz position control ISR

	
	IEC0bits.T3IE = 1;
	IEC0bits.T4IE = 1;

}

unsigned int adc_sample_convert(int pin) { // sample & convert the value on the given 
                                           // adc pin the pin should be configured as an 
                                           // analog input in AD1PCFG
    unsigned int elapsed = 0, finish_time = 0;
    AD1CHSbits.CH0SA = pin;                // connect chosen pin to MUXA for sampling
    AD1CON1bits.SAMP = 1;                  // start sampling
    elapsed = _CP0_GET_COUNT();
    finish_time = elapsed + SAMPLE_TIME;
    while (_CP0_GET_COUNT() < finish_time) { 
      ;                                   // sample for more than 250 ns
    }
    AD1CON1bits.SAMP = 0;                 // stop sampling and start converting
    while (!AD1CON1bits.DONE) {
      ;                                   // wait for the conversion process to finish
    }
    return ADC1BUF0;                      // read the buffer with the result
}