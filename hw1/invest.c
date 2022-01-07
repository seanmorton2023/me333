
#include <stdio.h>      
#define MAX_YEARS 100   

typedef struct {
  double inv0;                   
  double growth;                  
  int years;                      
  double invarray[MAX_YEARS+1];  
} Investment;                    


int getUserInput(Investment *invp);     
void calculateGrowth(Investment *invp); 
void sendOutput(double *arr, int years);

int main(void) {

  Investment inv;                

  while(getUserInput(&inv)) {    
    inv.invarray[0] = inv.inv0; 
    calculateGrowth(&inv);       
    sendOutput(inv.invarray,     
               inv.years);      
  }
  return 0;                      
} 

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

   if (!valid) { // ! is logical NOT ==SecA.4.11== 
    printf("Invalid input; exiting.\n");
  }
  return(valid);
} 


void sendOutput(double *arr, int yrs) {

  int i;
  char outstring[100];     

  printf("\nRESULTS:\n\n");
  for (i=0; i<=yrs; i++) {  // ++, +=, math in ==SecA.4.7==
    sprintf(outstring,"Year %3d:  %10.2f\n",i,arr[i]); 
    printf("%s",outstring);
  }
  printf("\n");
} 
