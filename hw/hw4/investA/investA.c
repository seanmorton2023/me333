
#include <stdio.h>
#include "NU32.h"
      
#define MAX_YEARS 100   
#define MAX_MSG_LENGTH 100

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
  char write_msg[MAX_MSG_LENGTH];
  char read_msg[MAX_MSG_LENGTH];
  
  //make our string to send to the UART
  //MODIFIED: substituted printf() and scanf() with NU32 write/read functions
  sprintf(write_msg, "Enter investment, growth rate, number of yrs (up to %d): ",MAX_YEARS);
  NU32_WriteUART3(write_msg);
  NU32_ReadUART3(read_msg, MAX_MSG_LENGTH);
  
  //MODIFIED: sscanf instead of scanf
  sscanf(read_msg, "%lf %lf %d", &(invp->inv0), &(invp->growth), &(invp->years));

  valid = (invp->inv0 > 0) && (invp->growth > 0) &&
    (invp->years > 0) && (invp->years <= MAX_YEARS);
	
  //MODIFIED: NU32_write instead of printf
  sprintf(write_msg, "Valid input?  %d\r\n",valid);
  NU32_WriteUART3(write_msg);
   if (!valid) { 
	NU32_WriteUART3("Invalid input; exiting.\r\n");
  }
  return(valid);
} 


void sendOutput(double *arr, int yrs) {

  int i;
  char outstring[MAX_MSG_LENGTH];     

  //MODIFIED: NU32 write and sprintf instead of printf
  NU32_WriteUART3("\r\nRESULTS:\r\n\n");
  for (i=0; i<=yrs; i++) { 
    sprintf(outstring,"Year %3d:  %10.2f\r\n",i,arr[i]); 
    NU32_WriteUART3(outstring);
  }
  NU32_WriteUART3("\r\n");
} 
