#ifndef __UTILS_H_
#define __UTILS_H_
#include "ledcube.h"
#define myPI  3.14159265358979323846
#define myDPI 1.2732395
#define myDPI2 0.40528473
#define MY_C_RES 8


float mySin(float x);
float myCos(float x);
float myTan(float x);
float mySqrt(float x);
float myMap(float in, float inMin, float inMax, float outMin, float outMax);
int16_t myRound(float x);
float myAbs(float x);
int myRand();
void xor_buff(uint16_t **buff);


#endif