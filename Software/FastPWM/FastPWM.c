#include "FastPWM.h"


uint32_t bits;
double _duty;
double dticks, dticks_us;
int iticks_ms, iticks_us;
uint8_t dynamicPrescaler;


   
void pwm_init(){
    
    LPC_SC->PCLKSEL0 |= _BV(12);

    LPC_PINCON->PINSEL4 |= (1<<0);    //2.0 is PWM 1.1
    LPC_PINCON->PINMODE4 |= _BV(1); // enable neither pull up nor pull down

    LPC_PWM1->PCR |= (1<<9);      //Turn on PWM 1.1 output
    LPC_PWM1->PR = 1;          //Prescale register value to get 
    updateTicks(1);

    //LPC_PWM1->MR0 = 100;       //Match0 register
    //LPC_PWM1->MR1 = 50;       //Match4 register, opposite because of hardware inverter.
    LPC_PWM1->MCR |= _BV(1); // Reset timer on Match0
    bits = 32;
   
}   

void start_pwm(){
    LPC_PWM1->TCR |= (1<<0)|(1<<3);   //Enable counter and PWM.

}

void pulsewidth_ticks(double ticks){
    LPC_PWM1->MR1 =  ticks;
    LPC_PWM1->LER |= _BV(1);
}

void period_ticks(double ticks){
    LPC_PWM1->MR0 =  ticks;
    LPC_PWM1->LER |= _BV(0);
}

double get_dticks_us(){
    return dticks_us;
}
void period_us_double(double us){
    if (dynamicPrescaler)
        calcPrescaler((uint64_t)(us * (double)(SystemCoreClock / 1000000)));
        
    period_ticks(us * dticks_us + 0.5);
}
   

void updateTicks( uint32_t prescaler ) {
    dticks = SystemCoreClock / (double)prescaler;
    dticks_us = SystemCoreClock / (double)prescaler / 1000000.0f;
    iticks_ms = SystemCoreClock / prescaler / 1000;
    iticks_us = SystemCoreClock / prescaler / 1000000;
}

uint32_t setPrescaler(uint32_t reqScale) {
    //Disable dynamic prescaling
    dynamicPrescaler = 0;
    
    return 1;
}


uint32_t getPeriod( void ) {
    return LPC_PWM1->MR0;
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

void period_us_int(int us) {
    if (dynamicPrescaler)
        calcPrescaler(us * (SystemCoreClock / 1000000));
    
    period_ticks(us * iticks_us);
}


void pulsewidth(double seconds) {
    pulsewidth_ticks(seconds * dticks + 0.5);
}

void pulsewidth_ms(int ms) {
    pulsewidth_ticks(ms * iticks_ms);
}

void pulsewidth_us_int(int us) {
    pulsewidth_ticks(us * iticks_us);
}

void pulsewidth_us_double(double us) {
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
        dynamicPrescaler = 1;
        value = 0;
    }
    else
        dynamicPrescaler = 0;
    
    retval = setPrescaler(value);
    updateTicks(retval);
    return retval;
}
