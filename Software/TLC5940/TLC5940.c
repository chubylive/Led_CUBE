#include "TLC5940.h"
// #include "lpc17xx_pwm.h"
#include "lpc17xx_ssp.h"

// static PWM_TIMERCFG_Type pwm_cfg;
// static PWM_MATCHCFG_Type pwm_mat[7];
// static PWM_Match_T  mat_t[7];



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

void RIT_IRQHandler(){
    //clear interrupt
    LPC_RIT->RICTRL |= _BV(0);

    // write(0.0);

    LPC_GPIO0->FIOCLR |= _BV(22);
    LPC_GPIO0->FIOSET |= _BV(22);
    LPC_GPIO0->FIOCLR |= _BV(22);

    
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

}

void tlc_init(){
    pwm_init();
    rit_init();

    period_us_double(1000000.0/(GSCLK_SPEED * 1.05));
    write(0.5);
    start_pwm();

    attach_us((1000000.0/(GSCLK_SPEED * 1.05))* 4096);



}