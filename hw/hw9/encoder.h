#ifndef __ENCODER_H__
#define __ENCODER_H__

static int encoder_command(int read); // send a command to the encoder chip
int encoder_counts(void); //returns count of the encoder
void encoder_init(void); //SPI initialization


#endif