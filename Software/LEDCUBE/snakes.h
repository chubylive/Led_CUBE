#ifndef _SNAKES_h_
#define _SNAKES_h_

#include "ledcube.h"
#define NORTH 0
#define SOUTH 1
#define EAST 2
#define WEST 3


typedef struct snake_node {
	uint8_t is_head;
	uint8_t x;	
	uint8_t y;
	uint8_t z;
	uint8_t direction;
	struct snake_node *next_ptr;
}s_node;
