/* HW1: Bubble Sort Exercise
 * Sean Morton
 * ME 333
 * 
 * Purpose: sort a string using a simple algorithm
 * Usage: compile and run, then input a string: ex. aslkdkasl
 */

#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

//function prototypes
void getString(char*);
void printResult(char*);
short greaterThan(char, char);
void swap(char*, short, short);

int main(void) {
	
	//initialize string of the max length b/c
	//we won't know actual length yet
	char str[MAX_LEN];
	char curr, next;
	
	getString(str);
	short len = strlen(str);
	
	//make n comparisons, where n = len of string
	for (short iter = 0; iter < len; ++iter) {
		
		//for each subsequent comparison, we can neglect the rightmost
		//character just studied b/c it's at max position
		for (int index = 0; index < (len - iter) -1; ++index) {
			curr = str[index];
			next = str[index + 1];
			if (greaterThan(curr, next) && next != '\0') {
				swap(str, index, index + 1);
			}
		
		}
		//printf("Curr string: %s\n", str);
	}
	
	printResult(str);	
	return 0;
	
	/*
	//testing
	char m, n;

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

//Takes in an existing string variable by reference, then uses
//user input to fill in the string
void getString(char *strp) {
	printf("Please enter a string (max len: %d)  ",MAX_LEN);
	scanf("%s", strp);
}

//Takes a string and prints it to the screen using custom formatting
void printResult(char *strp) {
	printf("Sorted string: %s\n", strp);
}

//Evaluates whether or not char a is greater in value than b
short greaterThan(char a, char b) {
	return (a > b);
}

//Given an existing string variable, takes in that string
//by reference, as well as two index numbers. Sets it so that
//str[index1] = str[index2] and vice versa, i.e. swaps their places
void swap(char *strp, short index1, short index2) {
	char temp = strp[index1];
	strp[index1] = strp[index2];
	strp[index2] = temp;
}