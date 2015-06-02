#include "snakes.h"

void animate(){
	for (int idx = 0; idx < MAX_SNAKES; idx++)
	{
		/* code */
		update_snake(s_array[idx]);
	}
}

void update_snake(s_node head){
	//bounds check
	s_node * curr_node = head;
	while(curr_node->next_ptr != NULL){
		if(curr_node->x > SIZE){
			return;
		}
		if(curr_node->y > SIZE){
			return;
		}
		if(curr_node->z > SIZE){
			return;
		}

		//clear old image

		//update image

		//update next image

		curr_node = curr_node->next_ptr;
	}
	
}
