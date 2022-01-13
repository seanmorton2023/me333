
#include <stdio.h>

int main() {

	float arr[10] = {};
	char ii = 0;
	float num;
	
	printf("Enter numbers from 1 to 5:\n");
	while (ii < 10) {
		scanf("%f", &num);
		if (num < 1 || num > 5) {
			printf("Num not stored, try another\n");
		} else {
			arr[ii] = num;
			++ii;
		}
	}

	printf("\nThe array you entered is: \n");
	for (short i = 0; i < 10; ++i) {
		printf("%.3f\n",arr[i]);
	}
}