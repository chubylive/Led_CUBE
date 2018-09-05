
#ifndef SPHERE_h
#define SPHERE_h
#include "ColourWheel.h"
#include "animate.h"

uint8_t bottom, top; 
		float narrow;
		float speed;

		void sphere();
		int sphere_animate(struct animation *in);
		void begin(void);
#endif