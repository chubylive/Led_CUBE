#include "FastPWM.h"


    uint32_t bits;
    double _duty;
    double dticks, dticks_us;
    int iticks_ms, iticks_us;
    bool dynamicPrescaler;

    void initPWM(){

    	LPC_SC->PCLKSEL0 |= _BV(12);
    	bits = 32;
    	//set pinsel registers

    }

    void period_ticks(uint32_t ticks){
    	LPC_PWM1->MR0 = ticks;
    	LPC_PWM1->LER |= _BV(0);
    }


uint32_t getPeriod( void ) {
    return LPC_PWM1->MR0;
}

void updateTicks( uint32_t prescaler ) {
    dticks = SystemCoreClock / (double)prescaler;
    dticks_us = SystemCoreClock / (double)prescaler / 1000000.0f;
    iticks_ms = SystemCoreClock / prescaler / 1000;
    iticks_us = SystemCoreClock / prescaler / 1000000;
}

int calcPrescaler(uint64_t clocks) {
    uint32_t scale = (clocks >> bits) + 1;
    uint32_t retval = setPrescaler(scale);
    updateTicks(retval);
    return retval;
}     


void period(double seconds) {
    if (dynamicPrescaler)
        calcPrescaler((uint64_t)(seconds * (double) SystemCoreClock));

     period_ticks(seconds * dticks + 0.5);
}

void period_ms(int ms) {
    if (dynamicPrescaler)
        calcPrescaler(ms * (SystemCoreClock / 1000));
        
    period_ticks(ms * iticks_ms);
}

void period_us(int us) {
    if (dynamicPrescaler)
        calcPrescaler(us * (SystemCoreClock / 1000000));
    
    period_ticks(us * iticks_us);
}

void period_us(double us) {
    if (dynamicPrescaler)
        calcPrescaler((uint64_t)(us * (double)(SystemCoreClock / 1000000)));
        
    period_ticks(us * dticks_us + 0.5);
}

void pulsewidth(double seconds) {
    pulsewidth_ticks(seconds * dticks + 0.5);
}

void pulsewidth_ms(int ms) {
    pulsewidth_ticks(ms * iticks_ms);
}

void pulsewidth_us(int us) {
    pulsewidth_ticks(us * iticks_us);
}

void pulsewidth_us(double us) {
    pulsewidth_ticks(us * dticks_us + 0.5);
}

void write(double duty) {
    _duty=duty;
    pulsewidth_ticks(duty*getPeriod());
}

double read( void ) {
    return _duty;
    }
    
 
int prescaler(int value) {
    int retval;
    if (value == -1) {
        dynamicPrescaler = true;
        value = 0;
    }
    else
        dynamicPrescaler = false;
    
    retval = setPrescaler(value);
    updateTicks(retval);
    return retval;
}