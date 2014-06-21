#include "LPC17xx.h"

#ifndef FASTPWM_H
#define FASTPWM_H


    
	void initPWM(void);
	uint32_t setPrescaler( uint32_t reqScale );
	int calcPrescaler(uint64_t clocks);
	uint32_t getPeriod( void );
	void updateTicks( uint32_t prescaler );