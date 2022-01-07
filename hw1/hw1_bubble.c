/* HW1: Bubble Sort Exercise
 * ME 333
 * Sean Morton
 * 
 * Purpose: sort a string using a simple algorithm
 * Usage: compile and run, then input a string: ex. aslkdkasl
 */

#include <stdio.h>
#define MAX_LEN 50

//function prototypes
void getString(char*); //allocate a string and modify by reference
void printResult(char*);
short greaterThan(char, char);
void swap(char*, short, short);

int main(void) {
	
	//make a string
	char str[MAX_LEN];
	char m, n;
	
	/*
	//testing
	
	getString(str);
	printf("Test\n");
	printf("String: %s\n", str);
	m = 'c';
	n = 'f';
	printf("Is %d greater than %d: %d\n",m,n, greaterThan(m,n));

	//str = "aabb";
	swap(str, 2, 1);
	printResult(str);

	return 0;
	*/
}

void getString(char *strp) {
	printf("Please enter a string (max len: %d)  ",MAX_LEN);
	scanf("%s", strp);
}

void printResult(char *strp) {
	printf("Sorted string: %s\n", strp);
}

short greaterThan(char a, char b) {
	return (a > b);
}

void swap(char *strp, short index1, short index2) {
	char temp = strp[index1];
	strp[index1] = strp[index2];
	strp[index2] = temp;
}