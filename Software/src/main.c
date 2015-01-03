#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

#include "main.h"
#include "TLC5940.h"


// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP;
 
  int8_t rowSelect = 0;
typedef struct 
{
  uint16_t red ;
  
}px;

typedef struct {
  uint16_t buf[SIZE *2];
}ly;


ly lys [SIZE];

void delay_call(int dl){
  volatile int delay, i;

  delay = dl *100;
  for (i = 0; i < delay; )
  {
    i++;
  }
}

void set_all(int level1){
  int idx, jdx;
  for (idx = 0; idx < SIZE; ++idx)
  {
    
        lys[idx].buf[15]= level1;
        lys[idx].buf[14]= level1;
        lys[idx].buf[0] = level1;
      
    
  }
}

int level= 0xFFF;

int con = 0;
int up = 0;
int idx = 0;
int vprg_pin =0;
#define R1 1
#define G1 2
#define B1 3
#define R2 4
#define G2 5
#define B2 6

int main(void) {
 
 /* uint8_t layer ;  // //Setup GPIO pins
  LPC_GPIO0->FIODIR |= (1<<22);
  LPC_GPIO0->FIOSET |= (1<<22);
*/
/*  
  set_all(level);
  tlcMuxInit();
  
spi_txrx((uint16_t* )lys[rowSelect].buf,NULL, 16);*/
TLC5940_Init();
TLC5940_SetAllDC(0);
TLC5940_SetAllGS(0x0);
TLC5940_SetGS(G1, 0);
TLC5940_SetGS(R1, 0xFFF);
TLC5940_SetGS(G1, 2048);
TLC5940_SetGS(B1, 0x000);




TLC5940_ClockInDC();
vprg_pin = 1;

/*
PULSE_XLAT_PIN;
PULSE_SCLK_PIN;
*/
while(1){
 
	 /* layer= layers[rowSelect].gpio_shift;
    
    if(rowSelect ==  SIZE || rowSelect > SIZE){
        //set row 
        LPC_GPIO1->FIOPIN = _BV(layer);
        //reset row select
        rowSelect = 0;
    }

    else{
       
    	LPC_GPIO1->FIOPIN = _BV(layer);
     // rowSelect++;
    }
    */
   
    
    //
  
}

  return 0;
}

void RIT_IRQHandler(){
    //clear interrupt
    LPC_RIT->RICTRL |= _BV(0);

    static uint8_t xlatNeedsPulse = 0;

    BLANK_PIN_SET;
    if (vprg_pin){
      VPRG_PIN_CLR;
      if (xlatNeedsPulse){
        PULSE_XLAT_PIN;
        xlatNeedsPulse = 0;
      }
      PULSE_SCLK_PIN;
      vprg_pin =0;
    }else if (xlatNeedsPulse)
    {
      
      xlatNeedsPulse = 0;
    }
    BLANK_PIN_CLR;
    dcspi_txrx((uint8_t*) gsData, NULL, gsDataSize);
    PULSE_XLAT_PIN;
    
  //   // write(0.0);
  
  // BLANK_PIN_SET;
  // if (t)
  // {
  // VPRG_PIN_CLR;
  // PULSE_XLAT_PIN;
  // t = 0;
  //   /* code */
  // }

  // BLANK_PIN_CLR;

    //select Row to be one
   

}