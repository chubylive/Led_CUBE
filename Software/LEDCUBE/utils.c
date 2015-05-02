#include "utils.h"

#include <stdio.h>
uint32_t x = 360, y=107, z = 13, w=77;
//FAST SINE APPROX
float mySin(float x){
	float sinr = 0;
	uint8_t g = 0;

	while(x > myPI){
		x -= 2*myPI; 
		g = 1;
	}

	while(!g&(x < -myPI)){
		x += 2*myPI;
	}

	sinr = myDPI*x - myDPI2*x*myAbs(x);
	sinr = 0.225*(sinr*myAbs(sinr)-sinr)+sinr;

	return sinr;
}

//FAST COSINE APPROX
float myCos(float x){
	return mySin(x+myPI/2);
}

float myTan(float x){
	return mySin(x)/myCos(x);
}

//SQUARE ROOT APPROX
float mySqrt(float in){
	int16_t d = 0;
	int16_t in_ = in;
	float result = 2;
	
	for(d = 0; in_ > 0; in_ >>= 1){
		d++;
	}
	
	for(int16_t i = 0; i < d/2; i++){
		result = result*2;
	}
	
	for(int16_t i = 0; i < 3; i++){
		result = 0.5*(in/result + result);
	}
	
	return result;
}

//MAP NUMBERS TO NEW RANGE
float myMap(float in, float inMin, float inMax, float outMin, float outMax){
	float out;
	out = (in-inMin)/(inMax-inMin)*(outMax-outMin) + outMin;
	return out;
}

//ROUND A NUMBER
int16_t myRound(float in){
	int8_t s = in/myAbs(in);
	return (int16_t)(s*(myAbs(in) + 0.5));
}

//ABSOLUTE VALUE
float myAbs(float in){
	return (in)>0?(in):-(in);
}


int myRand() {
    uint32_t t = x ^ (x << 11);
    x = y; y = z; z = w;
    return w = w ^ (w >> 19) ^ t ^ (t >> 8);
}

void xorBuff(uint16_t buff[SIZE][gsDataSize]){
	for (int idx = 0; idx < SIZE; ++idx)
	{
		for (int jdx = 0; jdx < gsDataSize; ++jdx)
		{
			//printf("b %d %d\n", gsData[idx][jdx], buff[idx][jdx]);
			gsData[idx][jdx] ^= buff[idx][jdx];
			//printf("a %d %d\n", gsData[idx][jdx], buff[idx][jdx]);
		}
	}
}