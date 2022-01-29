#ifndef HELPER__H__
#define HELPER__H__

#include <stdio.h>      
#define MAX_YEARS 100   

typedef struct {
  double inv0;                   
  double growth;                  
  int years;                      
  double invarray[MAX_YEARS+1];  
} Investment;  

void calculateGrowth(Investment *invp);
int getUserInput(Investment *invp);
void sendOutput(double *arr, int yrs);

#endif //HELPER__H__