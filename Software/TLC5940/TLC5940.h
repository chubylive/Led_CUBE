#ifndef TLC5940_H
#define TLC5940_H

#include "FastPWM.h"
#include "lpc17xx_ssp.h"
#include "lpc17xx_gpdma.h"

#define SPI_SPEED 30000000
#define GSCLK_SPEED 2500000
#define SIZE 8
#define BLANK_PIN 

#define BLANK_HIGH  LPC_GIO0->FIOSET |= (1<<BLANK_PIN)
typedef struct 
{
	uint16_t red : 12;
	uint16_t green: 12;
	uint16_t blue:	12;

}Pixel;

typedef struct {
	Pixel buf[SIZE * SIZE];

}Layer;

extern Layer layers [SIZE];

//ie layer[i].buff[j].red

void tlc_init();
void clear();
void update();


#endif