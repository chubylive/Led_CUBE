#ifndef _OBJ_HASH_h_
#define _OBJ_HASH_h_

#include "stdlib.h"
#include "stdint.h" 	

#define MAX_NODES 256
typedef enum Object_Type { FOOD, BOMB, EMPTY,} object_type;

typedef struct cord{
	uint8_t x;
	uint8_t y;
	uint8_t z;
}cord_t; 

//collision detection
typedef struct object
{
	object_type obj_t;
	cord_t curr_cord;
}object_t;

uint32_t object_count;
object_t object_list [MAX_NODES];

//only head can collide should be called in head updated
void init_hash_table();
void add_object(object_t obj);
uint8_t cord_hash(cord_t cord);
void detect_collision();
#endif