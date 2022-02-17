#include "helper.h"

void calculateGrowth(Investment *invp) {

  int i;
  for (i = 1; i <= invp->years; i= i + 1) {
    invp->invarray[i] = invp->growth * invp->invarray[i-1]; 
  }
}

int getUserInput(Investment *invp) {

  int valid;
  printf("Enter investment, growth rate, number of yrs (up to %d): ",MAX_YEARS);
  scanf("%lf %lf %d", &(invp->inv0), &(invp->growth), &(invp->years));

  valid = (invp->inv0 > 0) && (invp->growth > 0) &&
    (invp->years > 0) && (invp->years <= MAX_YEARS);
  printf("Valid input?  %d\n",valid);

   if (!valid) { 
    printf("Invalid input; exiting.\n");
  }
  return(valid);
} 

void sendOutput(double *arr, int yrs) {

  int i;
  char outstring[100];     

  printf("\nRESULTS:\n\n");
  for (i=0; i<=yrs; i++) { 
    sprintf(outstring,"Year %3d:  %10.2f\n",i,arr[i]); 
    printf("%s",outstring);
  }
  printf("\n");
} 
