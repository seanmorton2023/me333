
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 50

int main(void) {

	char word[MAX_SIZE];
	char new_word[MAX_SIZE];
	short shift_value;
	
	printf("Enter a word to shift: ");
	scanf("%s", word);
	printf("Original word: %s \n",word);
	
	while (1) {
		printf("\nEnter a shift value between 1 and 8: ");
		scanf("%d", &shift_value);
		
		if (shift_value < 1 || shift_value > 8) {
			printf("Try again - invalid number\n");
		} else {
			break;
		}
			
	}

	short i = 0;
	while (word[i] != '\0') {
		new_word[i] = word[i] + shift_value;
		i++;
	}
	new_word[i] = '\0';
	
	
	printf("\nNew word: \n%s", new_word);
}