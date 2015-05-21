#include "csumd.h"

COLOUR c;
COLOUR s;
COLOUR clear1;
void csumd(){

	//TLC5940_ClearGsData();
  	c.r = 0; 
  	c.g = 255; 
  	c.b = 255;
  	clear1.r = 0;
  	clear1.g = 0;
  	clear1.b = 0;
  	s.r = 255;
  	s.g = 0;
  	s.b = 0;  
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
				SetColour3D_16(x, y, z, clear1);
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
	
	for (int x = 2; x < SIZE; x++)
	{
		for (int y = 3; y < 5; y++)
		{
			for (int z = 0; z < 2; z++)
			{
				SetColour3D_16(x, y, z, clear1);
			}
		}
	}

for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 2; ++y)
		{
			for (int z = 0; z < 2 ; ++z)
				/*for (int z = 2; z < 4 ; ++z)
					for (znt z = 2; z < 3 ; ++z)
						for (znt z = 1; z < 3 ; ++z)
							for (znt z = 1; z < 2 ; ++z)*/
			{
				SetColour3D_16(x, y, z, clear1);
			}
		}
	}
	
		TLC5940_CopyGsData();

}

