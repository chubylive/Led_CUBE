#include "spiral.h"


float X, Y, Z, phase;
uint8_t bottom = 0, top = 8; 
		float narrow = 0;
		float speed =1 ;

void Spiral(){
	
	TLC5940_ClearGsData();
	COLOUR cl1 ;
  	cl1.r = 255; 
  	cl1.g = 255; 
  	cl1.b = 0; 
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
}
