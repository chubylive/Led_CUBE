#ifndef COLOURWHEEL_H
#define COLOURWHEEL_H
#include "ledcube.h"
#define COLOUR_WHEEL_LENGTH 1024
	void fill_colour_wheel(void);
	COLOUR get_colour(int16_t p);
	COLOUR get_next_colour(void);
	COLOUR get_random_colour(void);


#endif