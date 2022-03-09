#include "encoder.h"
#include <stdio.h>

#define UART2_DESIRED_BAUD 230400
#define MAX_RX_MESSAGE 100

volatile int rx_num_bytes = 0;
char rx_message[MAX_RX_MESSAGE];
volatile int pos = 0;
volatile int newPosFlag = 0;

int get_encoder_flag(){
    return newPosFlag;
}

void set_encoder_flag(int f){
    newPosFlag = f;
}

int get_encoder_count(){
    return pos;
}

void __ISR(_UART_2_VECTOR, IPL5SOFT) U2ISR(void) { 
  char data = U2RXREG; // read the data
  if (data == '\n') {
    rx_message[rx_num_bytes] = '\0';
    sscanf(rx_message,"%d",&pos);
    newPosFlag = 1;
    rx_num_bytes = 0;
  } 
  else {
    rx_message[rx_num_bytes] = data;
    ++rx_num_bytes;
    // roll over if the array is too small
    if (rx_num_bytes >= MAX_RX_MESSAGE) {
      rx_num_bytes = 0;
    }
  }
  IFS1bits.U2RXIF = 0;
}

// Write a character array using UART2
void WriteUART2(const char * string) {
  while (*string != '\0') {
    while (U2STAbits.UTXBF) {
      ; // wait until tx buffer isn't full
    }
    U2TXREG = *string;
    ++string;
  }
}

//  Initialize the serial port - UART2 
void UART2_Startup() {
  // disable interrupts
  __builtin_disable_interrupts();

  // turn on UART2 with interrupt on RX
  U2MODEbits.BRGH = 0; // set baud to NU32_DESIRED_BAUD
  U2BRG = ((NU32_SYS_FREQ / UART2_DESIRED_BAUD) / 16) - 1;

  // 8 bit, no parity bit, and 1 stop bit (8N1 setup)
  U2MODEbits.PDSEL = 0;
  U2MODEbits.STSEL = 0;

  // configure TX & RX pins as output & input pins
  U2STAbits.UTXEN = 1;
  U2STAbits.URXEN = 1;

  U2STAbits.URXISEL = 0; // interrupt when a char is rcvd
  IPC8bits.U2IP = 5;
  IPC8bits.U2IS = 0;
  IFS1bits.U2RXIF = 0;
  IEC1bits.U2RXIE = 1;

  // enable the uart
  U2MODEbits.ON = 1;

  __builtin_enable_interrupts();
}

