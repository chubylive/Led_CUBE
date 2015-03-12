#include "sineWave.h"

float X, Y, Z, phase;

uint8_t animate(void *arrayP){

	TLC5940_ClearGsData();
	
	COLOUR cl1 ;
  	cl1.r = 0; 
  	cl1.g = 0; 
  	cl1.b = 0;  
	for (uint8_t x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{

			X = myMap(x, 0, SIZE - 1, -2, 2);
			Y = myMap(y, 0, SIZE - 1, -2, 2);
			Z = mySin(phase - myPI/8 + mySqrt(X*X + Y*Y));
			Z = myRound(myMap(Z,-1,1,0,SIZE-1));

			Z= mySin(phase + mySqrt(X*X + Y*Y));
			Z = myRound(myMap(Z,-1,1,0,SIZE-1));

			SetColour3D_16(1, 0, 0, cl1);
		}
	}

}
