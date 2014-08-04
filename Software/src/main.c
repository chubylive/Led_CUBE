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




int main(void) {
  
  
  // //Setup GPIO pins
  LPC_GPIO0->FIODIR |= (1<<22);
  LPC_GPIO0->FIOSET |= (1<<22);

  tlc_init();

  while (1) {
    
  }
  return 0;
}

// void PWM1_IRQHandler (void) 
// {

//     LPC_PWM1->IR |= 0xFF; // Clear the interrupt flag

//   LPC_GPIO0->FIOSET |= _BV(22);
//   LPC_GPIO0->FIOCLR |= _BV(22);

// }