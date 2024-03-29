
#include "NU32.h"
#define NUMSAMPS 1000
static volatile int Waveform[NUMSAMPS];


void makeWaveform() {
	
	int i = 0, center = 2000, A = 2000; // square wave, fill in center value and amplitude
	for (i = 0; i < NUMSAMPS; ++i) {
		if ( i < NUMSAMPS/2) {
			Waveform[i] = center + A;
		} else {
			Waveform[i] = center - A;
		}
	}

}

void __ISR(_TIMER_2_VECTOR, IPL5SOFT) Controller(void) { // _TIMER_2_VECTOR = 8
	static int counter = 0; // initialize counter once
	
	// insert line(s) to set OC1RS
	OC1RS = Waveform[counter];
	
	counter++; // add one to counter every time ISR is entered
	if (counter == NUMSAMPS) {
		counter = 0; // roll the counter over when needed
	}
	
	// insert line to clear interrupt flag
	IFS0bits.T2IF = 0;

	
}

int main(void) {

	NU32_Startup();
	__builtin_disable_interrupts();
	
	makeWaveform();
	
	//setup timer2 interrupt
	IFS0bits.T2IF = 0;
	IPC2bits.T2IP = 5;
	IPC2bits.T2IS = 0;
	
	//configure timer2 for the waveform ISR
	T2CONbits.TCKPS = 0b110; //prescaler of 64
	PR2 = 1249; //to get ISR frequency of 1kHz
	TMR2 = 0;
	
	//setup timer 3 prescaler and period
	T3CONbits.TCKPS = 000; //prescaler of 1
	PR3 = 3999;
	TMR3 = 0; //initialize count
	
	//setup OC1 as a PWM output on timer 3
	OC1CONbits.OCM = 0b110; //PWM mode w/o fault pin
	OC1CONbits.OCTSEL = 1; //timer 3
	OC1CONbits.OC32 = 0; //32 bit timer off
	
	//set OC1R and OC1RS to create periodic signal
	OC1R = 3000;
	OC1RS = 3000; //75% of (PR = 1500)
	
	//turn it on and see what we get
	T2CONbits.ON = 1;
	T3CONbits.ON = 1;
	OC1CONbits.ON = 1;
	IEC0bits.T2IE = 1;

	__builtin_enable_interrupts();

	//75% duty cycle
	while (1) {
		//loop forever
	}


}