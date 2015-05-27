#ifndef __LEDCUBE_H_
#define __LEDCUBE_H_

#include "TLC5940.h"
#include "utils.h"

#define myPI  3.14159265358979323846
#define MAX_8 255
#define MAX_12 4095

#define map12(x) (x)*(MAX_12)/(MAX_8)
typedef struct{
	uint8_t r;
	uint8_t g;
	uint8_t b;
}COLOUR;

 struct COLOUR_S{
	uint8_t r;
	uint8_t g;
	uint8_t b;
};
void SetAllColour(COLOUR colour);
void SetColour(channel_t channel, COLOUR colour);
void SetColour3D(uint8_t x, uint8_t y, uint8_t z, COLOUR colour);
void SetColour3D_16(uint8_t x, uint8_t y, uint8_t z, COLOUR colour);
void SetColour3D_16_buff(uint8_t x, uint8_t y, uint8_t z, COLOUR colour, uint16_t buff[SIZE][gsDataSize]);





#endif

/*

typedef struct {

	uint16_t red : 12;
 	uint16_t green : 12;
 	uint16_t blue : 12;

}MyVoxel;

typedef struct {
	MyVoxel vx_buffer[SIZE * SIZE];
}MyLayer;

typedef struct {
	MyLayer layer[SIZE];
}MyCube;




#endif
