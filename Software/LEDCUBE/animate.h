#ifndef ANIMATE_H
#define	ANIMATE_H
#include <stdint.h>
#define SIZE 8
// typedef ;

struct animation
{
	uint8_t framerate;
	uint8_t random_colour;
	uint8_t number;
	uint8_t fade;
	uint8_t X;
	uint8_t Y;
	uint8_t Z;
	uint8_t cube_buff [SIZE][SIZE][SIZE];
	void (*animate)(struct animation *in);

};

#endif