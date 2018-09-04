
#ifndef SINEWAVE_h
#define SINEWAVE_h
#include "ledcube.h"
#include "ColourWheel.h"

uint8_t bottom, top; 
		float narrow;
		float speed;

		void sphere();
		int sphere_animate(struct animation *in);
		void begin(void);
#endif