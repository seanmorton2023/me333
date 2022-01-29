#ifndef IO__H__
#define IO__H__

#include <stdio.h> 
#include "investment.h"

int getUserInput(Investment *invp);
void sendOutput(double *arr, int yrs);

#endif //IO__H__