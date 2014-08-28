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
  uint16_t red : 12;
  
}px;

typedef struct {
  px buf[SIZE *2];
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
    for(jdx = 0; (jdx < SIZE *2); jdx++){

      if (jdx%2)
      {
        /* code */
      lys[idx].buf[13].red = level1;
      }
    }
  }
}

int level= 0xFFF;

int con = 0;
int up = 0;
int main(void) {
 
  uint8_t layer ;  // //Setup GPIO pins
  LPC_GPIO0->FIODIR |= (1<<22);
  LPC_GPIO0->FIOSET |= (1<<22);

  set_all(level);
  tlcMuxInit();

  while (1) {

	layer= layers[rowSelect].gpio_shift;
      if(rowSelect ==  SIZE || rowSelect > SIZE){
        //set row 
        LPC_GPIO1->FIOPIN = _BV(layer);
        //reset row select
        rowSelect = 0;
    }

    else{
       
    	LPC_GPIO1->FIOPIN = _BV(layer);
      rowSelect++;
    }
     
    //delay_call(1);
  }

  return 0;
}
void RIT_IRQHandler(){
    //clear interrupt
    LPC_RIT->RICTRL |= _BV(0);

    // write(0.0);

    LPC_GPIO0->FIOCLR |= _BV(22);
    LPC_GPIO0->FIOSET |= _BV(22);
    LPC_GPIO0->FIOCLR |= _BV(22);

    //select Row to be one
    spi_txrx((uint16_t* )&lys[rowSelect].buf,NULL, 16);


}