#ifndef SPI_H
#define SPI_H

#include "LPC17xx.h"

#include <stdlib.h>


#define SSPSR_TFE		(1 << 0)
#define SSPSR_TNF		(1 << 1)
#define SSPSR_RNE		(1 << 2)
#define SSPSR_RFF		(1 << 3)
#define SSPSR_BSY		(1 << 4)

void spi_init();
void spi_txrx(uint16_t* tx, uint16_t* rx, uint16_t len);
uint16_t spi_tx(uint16_t tx);

#endif
