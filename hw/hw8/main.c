#include "NU32.h"          // config bits, constants, funcs for startup and UART
#include <stdio.h>
#include "encoder.h"

#define BUF_SIZE 200


//200Hz ISR to control torque/motor commands
void __ISR(_TIMER_4_VECTOR, IPL4SRS) PositionControl(void) {

	//TODO

}

//5KHz ISR to control current going to motor
void __ISR(_TIMER_3_VECTOR, IPL5SRS) CurrentControl(void) {

}




//for initializing modules + SFRS on the PIC all at once
void initialize_sfrs(void);	
unsigned int adc_sample_convert(int pin);

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
		  //TODO
		  break;
	  }
	  
	  case 'f':
	  {
		  //Set PWM (-100 to 100)
		  //TODO
		  break;
	  }
	  
	  case 'r':
	  {
		  //read what mode the motor is in
		  //TODO
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
	
	//Digital output for H-bridge control: D4
	TRISDbits.TRISD4 = 0;
	
	//Timer initialization (3 timers)
	T2CONbits.ON = 1; //for 20KHz OC PWM
	T2CONbits.SIDL = 1;
	T2CONbits.TCKPS = 0b100; //prescaler of 16, use PR = 125
	T2CONbits.T32 = 0;
	T2CONbits.TCS = 0; //internal peripheral clock
	PR2 = 125;

	T3CONbits.ON = 1; //for 5KHz current control ISR
	T3CONbits.SIDL = 1;
	T3CONbits.TCKPS = 0b110; //prescaler of 64, use PR = 125
	T3CONbits.T32 = 0;
	T3CONbits.TCS = 0;
	PR3 = 125;
	
	T4CONbits.ON = 1; //for 200Hz position control ISR
	T4CONbits.SIDL = 1;
	T4CONbits.TCKPS = 0b110; //prescaler of 64, use PR = 3125
	T4CONbits.T32 = 0;
	T3CONbits.TCS = 0;
	PR4 = 3125;
	
	//OC PWM for H-bridge operation
	OC3CONbits.ON = 1;
	OC3CONbits.SIDL = 1;
	OC3CONbits.OCTSEL = 0;
	OC3CONbits.OCM = 0b110; //PWM mode; fault pin disabled
	OC3CONbits.OC32 = 0; //16 bit mode

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