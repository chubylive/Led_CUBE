#ifndef __LEDCUBE_H_
#define __LEDCUBE_H_
<<<<<<< HEAD
=======
#include "TLC5940.h"
#include "utils.h"
#define myPI  3.14159265358979323846
#define MAX_8 255
#define MAX_12 4095
>>>>>>> 23c7eb9597e776124ed79c12fc95c9d47e93587f


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
