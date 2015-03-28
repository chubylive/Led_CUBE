
#include "ColourWheel.h"
#include "utils.h"

COLOUR array[COLOUR_WHEEL_LENGTH];
int pos;

void fill_colour_wheel(void){
	//float red, green, blue;
	float c, s;
	int32_t phase = 0;
	int16_t I = 0;

	while(phase < COLOUR_WHEEL_LENGTH){
		s = MAX_8*mySin(myPI*(3*phase-I*COLOUR_WHEEL_LENGTH)/(2*COLOUR_WHEEL_LENGTH));
		c = MAX_8*myCos(myPI*(3*phase-I*COLOUR_WHEEL_LENGTH)/(2*COLOUR_WHEEL_LENGTH));
		COLOUR cl;
		cl.r = (I==0?1:0)*s + (I==1?1:0)*c;
		cl.g = (I==1?1:0)*s + (I==2?1:0)*c;
		cl.b = (I==2?1:0)*s + (I==0?1:0)*c;
		
		array[phase] = cl;
		if(++phase >= (1+I)*COLOUR_WHEEL_LENGTH/3){
			I++;
		}
	}
}

COLOUR get_colour(int16_t p){
	if(p >= COLOUR_WHEEL_LENGTH){
		p -= COLOUR_WHEEL_LENGTH;
	}	
	
	return array[p];
}

COLOUR get_next_colour(void){
	if(++pos >= COLOUR_WHEEL_LENGTH){
		pos -= COLOUR_WHEEL_LENGTH;
	}
	
	return array[pos];
}