#include "snakes.h"

void animate(){
	for (int idx = 0; idx < MAX_SNAKES; idx++)
	{
		/* code */
		update_snake(snake_array[idx]);
	}
}

uint8_t read_direction(head){
	uint8_t x_cord = head
	if (/* condition */)
	{
		/* code */
	}
}



void update_head(s_node head){
	uint8_t h_dir = read_direction(head);
	switch(h_dir){
		case ZP:
			h_dir.curr_cord.z +=1;
			break;
		case ZN:
			h_dir.curr_cord.z -=1;
			break;
		case YP:
			h_dir.curr_cord.y +=1;
			break;
		case YN:
			h_dir.curr_cord.y -=1;
			break;
		case XP:
			h_dir.curr_cord.x +=1;
			break;
		case XN: 
			h_dir.curr_cord.x -=1;
		default:
			break;
	}


}

void update_snake(snake_t snake){
	//update_head(snake[0]);
	for (int i = 0; i < snake[0].length; ++i)
	{
		s_node curr = snake[i];
		if(curr.x > SIZE){
		return;
		}
		if(curr.y > SIZE){
			return;
		}
		if(curr.z > SIZE){
			return;
		}
		curr.old_cord = curr.curr_cord;

		//clear old image remeber to change clear to CLear
		clear3D(curr.old_cord.x, curr.old_cord.y,curr.old_cord.z);

		//update next image
		if(i == 0){
			update_head(curr);
		}else{
			curr.curr_cord = snake[i - 1].old_cord;
		}
		
		//update image
		SetColour3D_16(curr.old_cord.x, curr.old_cord.y,curr.old_cord.z, curr.clr);
	
		
	}
}

/*
void update_snake(s_node* head){
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

		curr_node->old_cord = curr_node->curr_cord;

		//clear old image remeber to change clear to CLear
		clear3D(curr_node->old_cord.x, curr_node->old_cord.y,curr_node->old_cord.z);

		//update next image
		if(curr_node->is_head){
			update_head(curr_node);
		}else{
			curr_node->curr_cord = curr_node->next_ptr->old_cord;
		}
		
		//update image
		SetColour3D_16(curr_node->old_cord.x, curr_node->old_cord.y,curr_node->old_cord.z, curr_node->clr);
		curr_node = curr_node->next_ptr;
		


	}
	
}
*/
//add collision detection 
// head is determine in creation on a new node. that is if not head there will be a second parameter (head) if head the second parameter will be null
