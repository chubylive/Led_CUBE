#include "ledcube.h"
#include "ColourWheel.h"
#include "animate.h"

#ifndef SPIRAL_H
#define SPIRAL_H
uint8_t bottom, top; 
		float narrow;
		float speed;

		void Spiral();
		int Spiral_animate(struct animation *in);
		void begin(void);
#endif
