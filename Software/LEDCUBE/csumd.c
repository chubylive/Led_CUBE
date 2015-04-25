#include "csumd.h"

COLOUR c;
COLOUR s;
COLOUR clear;
void csumd(){

	TLC5940_ClearGsData();
  	c.r = 255; 
  	c.g = 0; 
  	c.b = 0;
  	clear.r = 0;
  	clear.g = 0;
  	clear.b = 0;
  	s.r = 204;
  	s.g = 204;
  	s.b = 204;  
//C
  	for (int z = 2; z < SIZE; z++)
  	{
		for (uint8_t x = 0; x < 4; x++)
		{
			for (uint8_t y = 0; y < SIZE; y++)
			{
			 	SetColour3D_16(x, y, z, c);
			}
		}
	}

	for (int z = 4; z < 6; z++)
	{
		for (int x = 0; x < 4; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				SetColour3D_16(x, y, z, clear);
			}
		}
	}


//S
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < 2; y++)
		{
			for (int z = 0; z < SIZE; z++)
			{
				SetColour3D_16(x, y, z, s);
			}
		}
	}

	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{
			for (int z = 0; z < 2; z++)
			{
				SetColour3D_16(x, y, z, s);
			}
		}
	}
	
	for (int x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int z = 0; z < 2; z++)
			{
				SetColour3D_16(x, y, z, clear);
			}
		}
	}

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 2; ++y)
		{
			for (int i = 0; i < 2 ; ++i)
				/*for (int i = 2; i < 4 ; ++i)
					for (int i = 2; i < 3 ; ++i)
						for (int i = 1; i < 3 ; ++i)
							for (int i = 1; i < 2 ; ++i)*/
			{
				SetColour3D_16(x, y, z, clear);
			}
		}
	}
