
/*
discussed in class exam practice
structs
compilation processes
strings in C
arrays in C
pointer notation
user i/o
integer overflow
memory allocation of variables in the stack

things to practice
array notation - declaring
how to pass array to function
size of an array
how to initialize an array

*/

#define MAX_SIZE 100
#include <stdio.h>

float avg_array(float *arr, short size);

int main(void) {
	float arr[4] = {1.2,5,7,88};
	short size = sizeof arr / sizeof *arr;
	float avg = avg_array(arr, size);
	printf("The average of the array is %.3f\n",avg);
}


float avg_array(float *arr, short size) {
	
	float sum = 0;
	
	for (short i = 0; i < size; ++i) {
		sum += arr[i];
	}
	
	float avg = sum/size;
	return avg;
}