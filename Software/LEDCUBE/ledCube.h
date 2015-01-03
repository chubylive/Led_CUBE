#ifndef __LEDCUBE_H_
#define __LEDCUBE_H_


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