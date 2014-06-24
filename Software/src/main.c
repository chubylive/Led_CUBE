/*
 ===============================================================================
 Name        : main.c
 Author      :
 Version     :
 Description : main definition
 ===============================================================================
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

#include "main.h"
#include "UMDLPC/system/clocking.h"

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP;
void delay_call(int dl){
  volatile int delay, i;

  delay = dl *100000;
  for (i = 0; i < delay; )
  {
    i++;
  }
}

int main(void) {
  
  // Select 12MHz crystal oscillator
  //LPC_SC ->CLKSRCSEL = 0;

  // Bypass PLL 0
  //PLL_bypass();

  //Peripheral power
  //LPC_SC->PCONP = 0;

  // Peripheral clocks
  // LPC_SC->PCLKSEL0 = 0;
  // LPC_SC->PCLKSEL1 = 0;

  //Setup GPIO pins
  LPC_GPIO0->FIODIR |= (1<<22);
  LPC_GPIO0->FIOSET |= (1<<22);

  // Select pin modes
  // LPC_PINCON->PINSEL1 = 0;

  while (1) {
    int idx;
      for(idx =0 ; idx < 5; idx++){

        LPC_GPIO0->FIOSET |= (1<<22);
        delay_call(100);
        LPC_GPIO0->FIOCLR |= (1<<22);
        delay_call(100);
        LPC_GPIO0->FIOSET |= (1<<22);

      }

      for ( idx = 0; idx < 2; idx++)
      {
        LPC_GPIO0->FIOSET |= (1<<22);
        delay_call(250);
        LPC_GPIO0->FIOCLR |= (1<<22);
        delay_call(250);
        LPC_GPIO0->FIOSET |= (1<<22);
      }
  }
  return 0;
}
