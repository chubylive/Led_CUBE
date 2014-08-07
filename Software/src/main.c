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

void delay_call(int dl){
  volatile int delay, i;

  delay = dl *10000;
  for (i = 0; i < delay; )
  {
    i++;
  }
}


int main(void) {
  
      uint8_t rowSelect = 0;
      uint8_t layer ;  // //Setup GPIO pins
  LPC_GPIO0->FIODIR |= (1<<22);
  LPC_GPIO0->FIOSET |= (1<<22);

  tlcMuxInit();

  while (1) {

	layer= layers[rowSelect].gpio_shift;

     if(rowSelect ==  SIZE || rowSelect > SIZE){
        //set row 
        //delay_call(5);
        LPC_GPIO1->FIOPIN = _BV(layer);
        //reset row select
        rowSelect = 0;
    }

    else{
        //delay_call(5);

       // LPC_GPIO1->FIOCLR |= _BV(layer - 1);
       // LPC_GPIO1->FIOSET |= _BV(layer);
    	LPC_GPIO1->FIOPIN = _BV(layer);


        rowSelect++;
    }

    delay_call(1);
  // 			            delay_call(5);

		// LPC_GPIO1->FIOPIN  = _BV(18);
		//             delay_call(5);

 	//     LPC_GPIO1->FIOPIN = ~_BV(18);
		//             delay_call(5);

 	//     		LPC_GPIO1->FIOPIN |= _BV(18);


  }
  return 0;
}

// void PWM1_IRQHandler (void) 
// {

//     LPC_PWM1->IR |= 0xFF; // Clear the interrupt flag

//   LPC_GPIO0->FIOSET |= _BV(22);
//   LPC_GPIO0->FIOCLR |= _BV(22);

// }