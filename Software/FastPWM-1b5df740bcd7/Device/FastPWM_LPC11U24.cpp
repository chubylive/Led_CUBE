#ifdef TARGET_LPC11U24

#include "FastPWM.h"


volatile uint32_t *PWM_MR;
LPC_CTxxBx_Type *pwm_obj;

typedef struct {
    uint8_t timer;
    uint8_t mr;
} timer_mr;
 
static timer_mr pwm_timer_map[11] = {
    {0, 0}, {0, 1}, {0, 2},
    {1, 0}, {1, 1},
    {2, 0}, {2, 1}, {2, 2},
    {3, 0}, {3, 1}, {3, 2},
};
 
static LPC_CTxxBx_Type *Timers[4] = {
    LPC_CT16B0, LPC_CT16B1,
    LPC_CT32B0, LPC_CT32B1
};


void FastPWM::initFastPWM( void ) {
    //Sadly the 11u24 pwm object does not store match register/pwm object for some reason
    //It recalculates it everytime, we just do it once because we are awesome
    timer_mr tid = pwm_timer_map[_pwm.pwm];
    pwm_obj = Timers[tid.timer];
    PWM_MR = &pwm_obj->MR[tid.mr];
    
    if (tid.timer < 2)
        //16-bit timer
        bits = 16;
    else
        //32-bit timer
        bits = 32;  
}

void FastPWM::pulsewidth_ticks( uint32_t ticks ) {
    if (ticks)
        *PWM_MR = pwm_obj->MR3 - ticks;  //They inverted PWM on the 11u24
    else
        *PWM_MR = 0xFFFFFFFF;           //If MR3 = ticks 1 clock cycle wide errors appear, this prevents that (unless MR3 = max).
}

void FastPWM::period_ticks( uint32_t ticks ) {
    pwm_obj->TCR = 0x02;
    pwm_obj->MR3 = ticks;
    pwm_obj->TCR = 0x01;   
}

uint32_t FastPWM::getPeriod( void ) {
    return pwm_obj->MR3;
}

uint32_t FastPWM::setPrescaler(uint32_t reqScale) {
    //If 32-bit, disable auto-scaling, return 1
    if (bits == 32) {
        dynamicPrescaler = false;
        return 1;
    }
    
    //Else 16-bit timer:
    if (reqScale == 0)
        //Return prescaler
        return pwm_obj->PR + 1;
    if (reqScale > (uint32_t)(1<<16))
        reqScale = 1<<16;
    //Else set prescaler, we have to substract one from reqScale since a 0 in PCVAL is prescaler of 1
    pwm_obj->PR = reqScale - 1;

    return reqScale;
}

#endif