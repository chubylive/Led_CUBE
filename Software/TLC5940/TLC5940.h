#ifndef TLC5940_H
#define TLC5940_H

#include "FastPWM.h"
#include "lpc17xx_gpdma.h"
#include "spi.h"
#include <string.h>

#define SPI_SPEED 30000000
#define GSCLK_SPEED 12000000
#define SIZE 8
#define TLC5940_N 12
#define MUX 1
#define USE_16_BIT 1

//+---+
//|   |
//|   |
//+---+

//this are the layer pins a better system is needed 
#define GPIO1_1_17 17
#define GPIO1_1_18 18
#define GPIO1_1_25 25
//XLAT pin this should be 
#define XLAT_PIN 21
#define XLAT_PIN_CLR ((LPC_GPIO0->FIOCLR) |= (1 << XLAT_PIN))
#define XLAT_PIN_SET ((LPC_GPIO0->FIOSET) |= (1 << XLAT_PIN))
#define PULSE_XLAT_PIN do {\
							XLAT_PIN_SET;\
							XLAT_PIN_CLR;\							
						} while (0)


//BLANK pin this should be pusle after each count 4096 to refresh the display. this is currently beign down with a RIT.
//another way of doing send clock signal and trigger an interrupt after a mat register counts 4096 
//this is on pin GPIO0_22 
#define BLANK_PIN 22
#define BLANK_PIN_CLR ((LPC_GPIO0->FIOCLR) |= (1 << BLANK_PIN))
#define BLANK_PIN_SET ((LPC_GPIO0->FIOSET) |= (1 << BLANK_PIN))
#define PULSE_BLANK_PIN do {\
							BLANK_PIN_SET;\
							BLANK_PIN_CLR;\
						} while (0)



//SCLK this the clock pin and is only need for after setting dc data
//this on pin GPIO0_03						
#define SCLK_PIN 3
#define SCLK_PIN_CLR ((LPC_GPIO0->FIOCLR) |= (1 << SCLK_PIN))
#define SCLK_PIN_SET ((LPC_GPIO0->FIOSET) |= (1 << SCLK_PIN))
#define PULSE_SCLK_PIN do{\
							SCLK_PIN_SET;\
							SCLK_PIN_CLR;\
						} while(0)


//VPRG pin: this should be high when sending DC data
//			this should be low when sending Grey scale data
//			this is on pin GPIO0_27 a pin below blank pin
#define VPRG_PIN 27
#define VPRG_PIN_CLR ((LPC_GPIO0->FIOCLR) |= (1 << VPRG_PIN))
#define VPRG_PIN_SET ((LPC_GPIO0->FIOSET) |= (1 << VPRG_PIN))


//DCPRG pin: this should be high when sending DC data
//			 this should be low when sending GS data
//			 this is on pin GPIO0_28 a pin below vpgr pin

#define DCPRG_PIN 28 
#define DCPRG_PIN_CLR ((LPC_GPIO0->FIOCLR) |= (1 << DCPRG_PIN))
#define DCPRG_PIN_SET ((LPC_GPIO0->FIOSET) |= (1 << DCPRG_PIN))


#if (12 * TLC5940_N > 255)
	#define dcData_t uint16_t
#else
	#define dcData_t uint8_t
#endif

#if (24 * TLC5940_N > 255)
	#define gsData_t uint16_t
#else
	#define gsData_t uint8_t
#endif

#if (16 * TLC5940_N > 255)
	#define channel_t uint16_t
#else	
	#define channel_t uint8_t
#endif

#if (3 * 16 * TLC5940_N > 255)
#define channel3_t uint16_t
#else
#define channel3_t uint8_t
#endif

#define dcDataSize ((dcData_t)12 * TLC5940_N)
#define gsDataSize ((gsData_t)12 * TLC5940_N)
#define numChannels ((channel_t)16 * TLC5940_N)
uint8_t dcData[dcDataSize];
uint16_t gsData[SIZE][gsDataSize];
	


volatile uint8_t gsUpdateFlag;

static inline void TLC5940_SetGSUpdateFlag(void) {
__asm__ volatile ("" ::: "memory");
gsUpdateFlag = 1;
}

void TLC5940_Init(void);
void TLC5940_SetAllDC(uint8_t value);
void TLC5940_SetDC(channel_t channel, uint8_t vaule);
void TLC5940_ClockInDC(void);
void TLC5940_ClearGsData();
void TLC5940_SetAllGS(uint16_t value);
void TLC5940_SetGS(channel_t channel, uint8_t, uint16_t);
void TLC5940_SetGS_16(channel_t channel, uint8_t, uint16_t);
uint8_t dc_spi_tx(uint8_t tx);
void dcspi_txrx(uint8_t* tx, uint8_t* rx, uint16_t len);




typedef struct 
{
	uint16_t red;
	uint16_t green;
	uint16_t blue;

}Voxel;

typedef struct {
	Voxel buf[SIZE * SIZE];
	uint8_t gpio_shift;
	//essentially initialized this to a set of gpios in init and assign
	//gpio shift to the BV(n) shift value

}Layer;

extern Layer layers [SIZE];



void tlc_init();
void tlcMuxInit();

void clear();
void update();


#endif