#include "animate.h"
#include "stdio.h"
void process(struct animation *in){
	

	printf("%d %d %d \n", in->X++, in->Y++, in->Z++);
}
void process1(struct animation *in){
	

	printf("second: %d %d %d \n", in->X, in->Y, in->Z++);
}
//create animation struct 

//set fuction that takes struct pass reference to struct into function print out changing state


int main(void){
	struct animation comeon;
	comeon.animate = process;
	comeon.X =0;
	comeon.Y =0;
	comeon.Z = 0;
	int i =0;
	for (i = 0; i < 8; ++i)
	{
		comeon.animate(&comeon);
		comeon.animate = process1;
		comeon.animate(&comeon);
		comeon.animate = process;
	}

}