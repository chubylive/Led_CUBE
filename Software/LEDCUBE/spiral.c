#include "spiral.h"
#include <stdio.h>

float X, Y, Z, phase;
uint8_t bottom = 0, top = 8; 
		float narrow = 0;
		float speed =1 ;
COLOUR cl1 ;
/*  	cl1.r = 255; 
  	cl1.g = 255; 
  	cl1.b = 255;*/
void Spiral(){
	
	TLC5940_ClearGsData();

	//Calculate frame
	for(uint8_t z = bottom; z < top; z++){
		for(uint8_t i = 0; i < 4; i++){
			Y = myCos(phase + myMap(z, 0, SIZE-1, 0, 2*myPI) + i*myPI/8);
			X = mySin(phase + myMap(z, 0, SIZE-1, 0, 2*myPI) + i*myPI/8);
			Y = myMap(Y, -1.1, 0.9, narrow, (float)SIZE-1-narrow);
			X = myMap(X, -1.1, 0.9, narrow, (float)SIZE-1-narrow);

			SetColour3D_16((uint8_t)X,(uint8_t)Y, z, cl1);
		}
	}
	
	//Count periods
	phase += myPI/5*speed;
	if(phase >= 2*myPI){
		phase -= 2*myPI;
		
	}
	cl1 = get_next_colour();

}


int Spiral_animate(struct animation *in){
	if (in->overlay )
	{
		//			TLC5940_ClearGsData();
		xorBuff(in->overlay_buff);
		TLC5940_ClearGsData_buff(in->overlay_buff);
	}else{
		TLC5940_ClearGsData();
	}
	//printf(" top %d, X %d, Y %d, Z%d\n", in->top ,(int)in->X, (int)in->Y, (int)in->Z);

	//Calculate frame
	for(uint8_t z = in->bottom; z < in->top; z++){
		for(uint8_t i = 0; i < 4; i++){

			in->Y = myCos(in->phase + myMap(z, 0, SIZE-1, 0, 2*myPI) + i*myPI/8);
			in->X = mySin(in->phase + myMap(z, 0, SIZE-1, 0, 2*myPI) + i*myPI/8);
			in->Y = myMap(in->Y, -1.1, 0.9, in->narrow, (float)SIZE - 1 - (in->narrow));
			in->X = myMap(in->X, -1.1, 0.9, in->narrow, (float)SIZE - 1 - (in->narrow));

			SetColour3D_16((uint8_t)(in->X),(uint8_t)(in->Y), z, in->clr);
			SetColour3D_16_buff((uint8_t)(in->X),(uint8_t)(in->Y), z, in->clr, in->overlay_buff);
		}
	}
	
	//Count periods
	in->phase += myPI/5*in->speed;
	if(in->phase >= 2*myPI){
		in->phase -= 2*myPI;
		
	}
	//printf("X %d, Y %d, Z%d\n", (int)in->X, (int)in->Y, (int)in->Z);
	//in->clr = get_next_colour();

return 1;
}
