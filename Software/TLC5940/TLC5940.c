#include "TLC5940.h"

#include "lpc17xx_ssp.h"

Layer layers[SIZE];

uint8_t rowSelect =0;
void rit_init(){
    LPC_SC->PCONP |= _BV(16);
    LPC_SC->PCLKSEL0 |= _BV(26);
    LPC_RIT->RICOUNTER = 0;
  
    NVIC_EnableIRQ(RIT_IRQn);

}

void attach_us(double us){
    LPC_RIT->RICOMPVAL = us * get_dticks_us() + 0.5;
    LPC_RIT->RICTRL |= _BV(1) | _BV(3);

}

void tlc_init(){
    pwm_init();
    rit_init();

    period_us_double(1000000.0/(GSCLK_SPEED * 1.05));
    write(0.5);
    start_pwm();

    attach_us((1000000.0/(GSCLK_SPEED * 1.05))* 4096);



}

void tlcMuxInit(){
    int idx, jdx ;
    //initialize the layer gpio shift values
    for (idx = GPIO1_1_18, jdx = 0 ; idx <= GPIO1_1_25; idx++)
    {
        layers[jdx++].gpio_shift = idx;
        LPC_GPIO1->FIODIR |= _BV(idx);
        LPC_GPIO1->FIOSET |= _BV(idx);

    }
    
    tlc_init();
}



void RIT_IRQHandler(){
    //clear interrupt
    LPC_RIT->RICTRL |= _BV(0);

    // write(0.0);

    LPC_GPIO0->FIOCLR |= _BV(22);
    LPC_GPIO0->FIOSET |= _BV(22);
    LPC_GPIO0->FIOCLR |= _BV(22);

    //select Row to be one
   

}










    
  //  write(0);

    // //set BLANK pin high

    // //select row
    // /*might just let spi do this*/
    // if(need_xlat){
    //     //pulse xlat
    //     need_xlat = 0;
    // }

    // //set BLANK low
    // write(0.5);

    // if(newGSData){
    //     for (int i = (16 *  ); i < ; ++i)
    //     {
    //         /* code */
    //     }
    // }