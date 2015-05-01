#ifndef ANIMATE_H
#define	ANIMATE_H
#include <stdint.h>
#include "ledcube.h"
#define SIZE 8
// typedef ;

struct animation
{
	uint8_t framerate;
	uint8_t random_colour;
	uint8_t number;
	uint8_t fade;
	uint8_t overlay ;
	float X;
	float Y;
	float Z;
	float phase;
	float speed;
	COLOUR clr;
	//uint8_t cube_buff [SIZE][SIZE][SIZE];
	int (*animate)(struct animation *in);

	/*Spiral animation specific*/
	uint8_t bottom;
	uint8_t top;
	float narrow;

	uint16_t overlay_buff[SIZE][gsDataSize];

};

#endif