#ifndef INVESTMENT__H__
#define INVESTMENT__H__

#define MAX_YEARS 100   

typedef struct {
  double inv0;                   
  double growth;                  
  int years;                      
  double invarray[MAX_YEARS+1];  
} Investment;  

#endif //INVESTMENT__H__