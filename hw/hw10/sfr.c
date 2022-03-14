
#include "sfr.h"

void initialize_sfrs(void) {
	
	//Peripherals and stuff to initialize:
	
	//SPI communication
	//encoder_init(); //change this to new I2C communication
	
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