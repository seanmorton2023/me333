#include <xc.h>          // Load the proper header for the processor

#define MAX_CYCLES 1000000
#define DELTA_CYCLES 100000

void delay(int);

int main(void) {
  TRISF = 0xFFFC;        // Pins 0 and 1 of Port F are LED1 and LED2.  Clear
                         // bits 0 and 1 to zero, for output.  Others are inputs.
  LATFbits.LATF0 = 1;    // Turn LED1 on and LED2 on.  These pins sink current
  LATFbits.LATF1 = 1;    // on the NU32, so "high" (1) = "off" and "low" (0) = "on"

  int cycles = MAX_CYCLES;

  while(1) {
    delay(cycles);
    LATFINV = 0x0003;    // toggle LED1 and LED2; same as LATFINV = 0x3;
	
	//reduce time of delay until 0, then reset
	cycles -= DELTA_CYCLES;
	if (cycles < 0) {
		cycles = MAX_CYCLES;
	}
	
  }
  return 0;
}

void delay(int cycles) {
  int j;
  for (j = 0; j < cycles; j++) { // number is 1 million
    while(!PORTDbits.RD7) {
        ;   // Pin D7 is the USER switch, low (FALSE) if pressed.
    }
  }
}
