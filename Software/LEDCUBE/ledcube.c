#include "ledcube.h"

/*
void SetAllColour(COLOUR colour){
  for(int idx = 0; idx < SIZE; idx++){
  	uint16_t value = map12(colour.r);
  	uint8_t tmp1 = (value >> 4);
      uint8_t tmp2 = (uint8_t)(value << 4) | (tmp1 >> 4);
      gsData_t i = 0;
      do {
        #if MUX
          gsData[idx][i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
          gsData[idx][i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
          gsData[idx][i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00

        #else
          gsData[i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
          gsData[i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
          gsData[i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00
        #endif
      } while (i < gsDataSize/3);

     	value = map12(colour.g);
     	tmp1 = (value >> 4);
     	tmp2 =  (uint8_t)(value << 4) | (tmp1 >> 4);
     	
     	do{
        #if MUX
          gsData[idx][i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
          gsData[idx][i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
          gsData[idx][i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00
        #else
          gsData[i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
          gsData[i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
          gsData[i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00
        #endif  
      } while (i < gsDataSize*2/3);

      value = map12(colour.b);
     	tmp1 = (value >> 4);
     	tmp2 =  (uint8_t)(value << 4) | (tmp1 >> 4);
     	
     	do{
        #if MUX
     		  gsData[idx][i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
          gsData[idx][i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
          gsData[idx][i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00
        #else
          gsData[i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
          gsData[i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
          gsData[i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00
        #endif
      } while (i < gsDataSize);
    }

}
*/
void SetColour3D(uint8_t x, uint8_t y, uint8_t z, COLOUR colour){
	/*  0 1 2 3 
		4 5 6 7
		8 9 10 11
		12 13 14 15*/

    uint16_t  idx = x + y * SIZE;
    uint16_t scale = numChannels/3;
    TLC5940_SetGS(idx , z, map12(colour.r));
    TLC5940_SetGS(idx + scale, z, map12(colour.g));
    TLC5940_SetGS(idx + (scale * 2),z, map12(colour.b));


		
}

void SetColour3D_16(uint8_t x, uint8_t y, uint8_t z, COLOUR colour){
  /*  0 1 2 3 
    4 5 6 7
    8 9 10 11
    12 13 14 15*/
    if (y % 2 ){
     if (x % 2 == 0)
     {
       x++;
     }else{
      x--;
     }
    }

    uint16_t  idx = x + y * SIZE;
    uint16_t scale = numChannels/3;
    TLC5940_SetGS_16(idx , z, map12(colour.r));
    TLC5940_SetGS_16(idx + scale, z, map12(colour.g));
    TLC5940_SetGS_16(idx + (scale * 2),z, map12(colour.b));


    
}

void SetColour3D_16_buff(uint8_t x, uint8_t y, uint8_t z, COLOUR colour, uint16_t buff[SIZE][gsDataSize]){
  /*  0 1 2 3 
    4 5 6 7
    8 9 10 11
    12 13 14 15*/
    if (y % 2 ){
     if (x % 2 == 0)
     {
       x++;
     }else{
      x--;
     }
    }

    uint16_t  idx = x + y * SIZE;
    uint16_t scale = numChannels/3;
    TLC5940_SetGS_16_buff(idx , z, map12(colour.r), buff);
    TLC5940_SetGS_16_buff(idx + scale, z, map12(colour.g), buff);
    TLC5940_SetGS_16_buff(idx + (scale * 2),z, map12(colour.b), buff);


    
}