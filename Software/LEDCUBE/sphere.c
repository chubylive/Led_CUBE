#include "sphere.h"

static float X, Y, Z, phase;
COLOUR cl1;
void sphere(){

	TLC5940_ClearGsData();
	
	// COLOUR cl1 ;
 //  	cl1.r = 255; 
 //  	cl1.g = 200; 
 //  	cl1.b = 0;  
	for (uint8_t x = 0; x < SIZE; x++)
	{
		for (int y = 0; y < SIZE; y++)
		{

			X = myMap(x, 0, SIZE - 1, -2, 2);
			Y = myMap(y, 0, SIZE - 1, -2, 2);
			Z = mySin(phase - myPI/8 + mySqrt(X*X + Y*Y));
			Z = myRound(myMap(Z,-1,1,0,SIZE-1));

			Z= mySin(phase + mySqrt(X*X + Y*Y));
			Z = myRound(myMap(Z,-1,1,0,SIZE-1));

			SetColour3D_16(x, y, Z,cl1 );
		}
	}

	phase += myPI/8;
	if(phase >= 2*myPI){
		phase -= 2*myPI;
	}
cl1 = get_next_colour();
}

int sphere_animate(struct animation *in){
	
			//NVIC_DisableIRQ(RIT_IRQn);

		
		if (in->overlay )
		{
			//switch to buff 1
			
			xorBuff(in->overlay_buff);
		}else{
			// switch to buff 1
			TLC5940_ClearGsData_buff(gsData1);

		//	TLC5940_ClearGsData();
		}
		//printf(" top %d, X %d, Y %d, Z%d\n", in->top ,(int)in->X, (int)in->Y, (int)in->Z);

		// //Calculate frame and edit buff 0
		// for(uint8_t z = in->bottom; z < in->top; z++){
		// 	for(uint8_t i = 0; i < 4; i++){

		// 		in->Y = myCos(in->phase + myMap(z, 0, SIZE-1, 0, 2*myPI) + i*myPI/8);
		// 		in->X = mySin(in->phase + myMap(z, 0, SIZE-1, 0, 2*myPI) + i*myPI/8);
		// 		in->Y = myMap(in->Y, -1.1, 0.9, in->narrow, (float)SIZE - 1 - (in->narrow));
		// 		in->X = myMap(in->X, -1.1, 0.9, in->narrow, (float)SIZE - 1 - (in->narrow));

		// 		//SetColour3D_16((uint8_t)(in->X),(uint8_t)(in->Y), z, in->clr);
		// 		SetColour3D_16_buff((uint8_t)(in->X),(uint8_t)(in->Y), z, in->clr, in->overlay_buff);
		// 		SetColour3D_16_buff((uint8_t)(in->X),(uint8_t)(in->Y), z, in->clr, gsData1);

		// 	}
		// }
		
		   

    int x,y,z,xa,ya,za,xb,yb,zb,xr,yr,zr,xx,yy,zz,rr=in->r*in->r;
    // bounding box
    xa=in->X-in->r; if (xa<0) xa=0; xb=in->X+in->r; if (xb>SIZE) xb=SIZE;
    ya=in->Y-in->r; if (ya<0) ya=0; yb=in->Y+in->r; if (yb>SIZE) yb=SIZE;
    za=in->Z-in->r; if (za<0) za=0; zb=in->Z+in->r; if (zb>SIZE) zb=SIZE;
    // project xy plane
    for (x=xa,xr=x-in->X,xx=xr*xr;x<xb;x++,xr++,xx=xr*xr)
     for (y=ya,yr=y-in->Y,yy=yr*yr;y<yb;y++,yr++,yy=yr*yr)
        {
        zz=rr-xx-yy; if (zz<0) continue; zr=mySqrt(zz);
        z=in->Z-zr; if ((z>0)&&(z<SIZE)) 
        {
        	SetColour3D_16(x, y, z,in->clr );
        			// printf("X %d, Y %d, Z %d\n", (int)x, (int)y, (int)z);

        }
        z=in->Z+zr; if ((z>0)&&(z<SIZE)) 
        {
        	SetColour3D_16(x, y, z,in->clr );
        			// printf("X %d, Y %d, Z %d\n", (int)x, (int)y, (int)z);

        }
        }
    // project xz plane
    for (x=xa,xr=x-in->X,xx=xr*xr;x<xb;x++,xr++,xx=xr*xr)
     for (z=za,zr=z-in->Z,zz=zr*zr;z<zb;z++,zr++,zz=zr*zr)
        {
        yy=rr-xx-zz; if (yy<0) continue; yr=mySqrt(yy);
        y=in->Y-yr; if ((y>0)&&(y<SIZE)) 
        {
        	SetColour3D_16(x, y, z,in->clr );
        			// printf("X %d, Y %d, Z %d\n", (int)x, (int)y, (int)z);

        }
        y=in->Y+yr; if ((y>0)&&(y<SIZE)) 
        {
        	SetColour3D_16(x, y, z,in->clr );
        			// printf("X %d, Y %d, Z %d\n", (int)x, (int)y, (int)z);

        }
        }
    // project yz plane
    for (y=ya,yr=y-in->Y,yy=yr*yr;y<yb;y++,yr++,yy=yr*yr)
     for (z=za,zr=z-in->Z,zz=zr*zr;z<zb;z++,zr++,zz=zr*zr)
        {
        xx=rr-zz-yy; if (xx<0) continue; xr=mySqrt(xx);
        x=in->X-xr; if ((x>0)&&(x<SIZE)) 
        {
        	SetColour3D_16(x, y, z,in->clr );
        			// printf("X %d, Y %d, Z %d\n", (int)x, (int)y, (int)z);

        }
        x=in->X+xr; if ((x>0)&&(x<SIZE)) 
        {
        	SetColour3D_16(x, y, z,in->clr );
        			// printf("X %d, Y %d, Z %d\n", (int)x, (int)y, (int)z);

        }
        }
    




		//NVIC_EnableIRQ(RIT_IRQn);
		//copy data to buff 1 
		TLC5940_CopyGsData();
	
		if (in->random_colour == 1)
		{
			in->clr = get_next_colour();
			/* code */
		}else if (in->random_colour == 2)
		{
			/* code */
			in->clr = get_random_colour();
		}else if (in->random_colour == 3){
			in->clr = get_next_colourNeg();
		}
		if(in->bounce == 0 ){
			in->r += 0.25;
			if (in->r > SIZE )
			{
				in->r = 1;		
			}
		}else{
			if (in->phase == 0)
			{
				/* code */
				in->r += 0.25;
			if (in->r > SIZE )
			{
				in->r = SIZE;	
				in->phase	= 1;
			}
			}else{
/* code */
				in->r -= 0.25;
			if (in->r < 1 )
			{
				in->r = 1;	
				in->phase	= 0;
			}
			}
		}
		return 1;
	
return 0;
}

