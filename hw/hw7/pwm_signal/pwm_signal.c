
#include "NU32.h"
#define NUMSAMPS 1000
#define PLOTPTS 200
#define DECIMATION 10

//arrays for storing + plotting wave data
static volatile int Waveform[NUMSAMPS];
static volatile int ADCarray[NUMSAMPS];
static volatile int REFarray[NUMPSAMPS];

static volatile int StoringData = 0;
static volatile float Kp = 0, Ki = 0;

void makeWaveform() {
	
	//waveform should be between 0 and PR--determines the 
	//PWM duty cycle at any given time to create an "analog" square
	//wave of variable peak/valley values
	
	int i = 0, center = 600, A = 300; // square wave, fill in center value and amplitude
	for (i = 0; i < NUMSAMPS; ++i) {
		if ( i < NUMSAMPS/2) {
			Waveform[i] = center + A;
		} else {
			Waveform[i] = center - A;
		}
	}

}

void _ _ISR(_TIMER_2_VECTOR, IPL5SOFT) Controller(void) {
	static int counter = 0; // initialize counter once
	static int plotind = 0; // index for data arrays; counts up to PLOTPTS
	static int decctr = 0; // counts to store data one every DECIMATION
	static int adcval = 0; //
	
	// insert line(s) to set OC1RS
	OC1RS = Waveform[counter]; //for now--later there will be PID control
	
	if (StoringData) {
		decctr++;
		if (decctr == DECIMATION) { // after DECIMATION control loops,
			decctr = 0; // reset decimation counter
			ADCarray[plotind] = adcval; // store data in global arrays
			REFarray[plotind] = Waveform[counter];
			plotind++; // increment plot data index
		}
		if (plotind == PLOTPTS) { // if max number of plot points plot is reached,
			plotind = 0; // reset the plot index
			StoringData = 0; // tell main data is ready to be sent to MATLAB
		}
	}
	counter++; // add one to counter every time ISR is entered
	if (counter == NUMSAMPS) {
		counter = 0; // rollover counter over when end of waveform reached
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
	
	//-----------//
	
	//setup pin RB5/AN5 as an analog input
	TRISBbits.TRISB5 = 1; //input
	AD1PCFGbits.PCFG5 = 0; //analog
	
	
	
	//turn it on and see what we get
	T2CONbits.ON = 1;
	T3CONbits.ON = 1;
	OC1CONbits.ON = 1;
	IEC0bits.T2IE = 1;

	__builtin_enable_interrupts();

	//75% duty cycle
	while (1) {
		NU32_ReadUART3(message, sizeof(message)); // wait for a message from MATLAB
		sscanf(message, "%f %f" , &kptemp, &kitemp);
		
		_ _builtin_disable_interrupts(); // keep ISR disabled as briefly as possible
		Kp = kptemp; // copy local variables to globals used by ISR
		Ki = kitemp;
		_ _builtin_enable_interrupts(); // only 2 simple C commands while ISRs disabled
		
		StoringData = 1; // message to ISR to start storing data
		while (StoringData) { // wait until ISR says data storing is done
		; // do nothing
		}
		for (i=0; i<PLOTPTS; i++) { // send plot data to MATLAB
			// when first number sent = 1, MATLAB knows we’re done
			sprintf(message, "%d %d %d\r\n", PLOTPTS-i, ADCarray[i], REFarray[i]);
			NU32_WriteUART3(message);
		}
	}


}