/* THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * THE AUTHORS SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER. USE IT AT YOUR OWN RISK */

#include "LPC17xx.h"

void PWMInit();


int main (void) 
{

	PWMInit();
	
	while(1)
	{
	}
	return 0;
  
}

void PWM1_IRQHandler (void) 
{
	if((LPC_PWM1->IR & 0x04) == 0x04) // Check whether it is an interrupt from match compare 2
	{
		LPC_PWM1->IR |= 0x04; // Clear the interrupt flag
		
		// Write the interrupt routine here.
	}
	
	return;
}


void PWMInit()
{
	
	LPC_SC->PCONP |= 1 << 6; // enable power for PWM1
	LPC_SC->PCLKSEL0 |= 1 << 12; // PCLK_PWM1 = CCLK
	LPC_PINCON->PINSEL4 |= 1 << 8; // P2.4 works as PWM1 output
	LPC_PINCON->PINMODE4 |= 1 << 9; // enable neither pull up nor pull down

	LPC_PWM1->MR0 = 16; // PWM freq = CCLK/16
	LPC_PWM1->MCR |= 1 << 1; // Reset timer on Match0
	
	LPC_PWM1->MR5 = 8;  // PWM DC = 0.5
	
	LPC_PWM1->MR3 = 4;
	LPC_PWM1->MR4 = 8;
	
	// Setup up an interrupt on Match compare 2
	LPC_PWM1->MR2 = 5;
	LPC_PWM1->MCR |= 1 << 6; // Interrupt on Match compare 2
	
	NVIC_EnableIRQ(PWM1_IRQn);

	LPC_PWM1->TCR |= (1 << 0) | (1 << 3); // enable timer counter and PWM
	
	LPC_PWM1->PCR |= 1 << 4; // Configure channel 4 as double edge controlled PWM
	LPC_PWM1->PCR |= 1 << 12; // Enable PWM channel 4 output
	LPC_PWM1->PCR |= 1 << 13; //Enable PWM channel 5 output
	
	
}

