/* HW1: Print an ASCII table
 * Sean Morton
 * ME333
 * 
 * Purpose: prints out ASCII characters 33 - 127, the legible 
 * text characters
 * Usage: compile and run from cmd
 */


#include <stdio.h>

int main(void) {
	
	char init = 33, fin = 127, val;
	char len = fin - init;
	
	//print 33, 34, 35, ..., 126, 127 in int and char form
	for (unsigned char i = 0; i <= len; ++i) {
		val = init + i;
		printf("Num: %3d  |  ASCII char: %2c\n",val,val);
	}
	
	//I'm not sure the 127 value makes any sense printed out,
	//since ASCII 127 = "DEL", but I'll leave it in
	return 0;
}