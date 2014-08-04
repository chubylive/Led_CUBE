#include "LPC17xx.h"

#define _BV(n) (1 << (n))
#ifndef FASTPWM_H
#define FASTPWM_H
//extern double dticks, dticks_us;

    
	void pwm_init(void);
	uint32_t setPrescaler( uint32_t reqScale );
	int calcPrescaler(uint64_t clocks);
	uint32_t getPeriod( void );
	void updateTicks( uint32_t prescaler );
	void period_us_double(double us);
	void write(double duty);
	void start_pwm();
	double get_dticks_us();

#endif