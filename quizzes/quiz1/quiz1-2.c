
#include <stdio.h>

typedef struct {
	int id;
	char brand[50];
	float miles[10];
} Car;

void calc_miles(Car*);

Car calc_miles_copy(Car);


int main(void) {

	//------question 6------------
	Car mycar;
	Car* carp = &mycar;
	mycar.id = 1;
	sprintf(carp->brand, '\0');
	
	for (int i = 0; i < 10; ++i) {
		mycar.miles[i] = 0;
	}

	printf("The car's id and brand are: \nid: %d \nbrand: %s \n",
			mycar.id, mycar.brand);
			
	printf("\nThe car's miles array is:\n");
	for (int j = 0; j < 10; ++j) {
		printf("%.1f ", mycar.brand[j]);
	}
	
	
	//-----question 7-----------
	Car hiscar;
	printf("\n\nEnter the brand name of the car: ");
	scanf("%s", hiscar.brand);
	
	printf("The car's brand is: %s\n", hiscar.brand);
	
	//------question 8--------
	Car toyota;
	Car *tp;
	tp = &toyota;
	
	toyota.miles[0] = 2.2;
	calc_miles(tp);
	printf("\nThe miles of the car are now:");
	for (int j = 0; j < 10; ++j) {
		printf("%.3f ", toyota.miles[j]);
	}
	
	Car toyota_new;
	toyota_new.miles[0] = 1.5;
	toyota_new = calc_miles_copy(toyota_new);
	printf("\nThe miles of the car are now:");
	for (int jj = 0; jj < 10; ++jj) {
		printf("%.3f ", toyota_new.miles[jj]);
	}
	
	
}

void calc_miles(Car *carp) {
	
	float prev = carp->miles[0];
	for (int i = 1; i < 10; ++i) {
		carp->miles[i] = prev * 2;
		prev = carp->miles[i];
	}
}

Car calc_miles_copy(Car car) {
	
	float prev = car.miles[0];
	for (int i = 1; i < 10; ++i) {
		car.miles[i] = prev * 2;
		prev = car.miles[i];
	}
	
	return car;
}