#ifndef _SNAKES_h_
#define _SNAKES_h_

#include "ledcube.h"
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3
#define MAX_SNAKES 10
typedef struct cord{
	uint8_t x;
	uint8_t y;
	uint8_t z;
}cord_t; 

typedef struct snake_node {
	uint8_t is_head;
	cord_t old_cord;
	cord_t new_cord;
	uint8_t direction;
	uint8_t speed;
	COLOUR clr;
	struct snake_node *next_ptr;
}s_node_;

s_node_t s_array[MAX_SNAKES]; 
