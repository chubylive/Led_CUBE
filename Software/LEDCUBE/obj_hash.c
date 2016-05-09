#include "obj_hash.h"
#include "ledcube.h"

void init_hash_table(){
	for (int i = 0; i < MAX_NODES; ++i)
	{
		object_list[i].obj_t = EMPTY;
	}
}

//this function adds an object of type food, bomb or empty to the object hash table
void add_object(object_t obj){
	object_list[cord_hash(obj.curr_cord)] = obj;

}

uint8_t cord_hash(cord_t cord){
	return cord.x + (cord.y * SIZE) + (cord.z * SIZE * SIZE);
}

//add collision detection 
void detect_collision(){


}