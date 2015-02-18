#include "TLC5940.h"

Layer layers[SIZE];


void rit_init(){
    LPC_SC->PCONP |= _BV(16);
    LPC_SC->PCLKSEL0 |= _BV(26);
    LPC_RIT->RICOUNTER = 0;
  
   

}

void attach_us(double us){
    LPC_RIT->RICOMPVAL = us * get_dticks_us() + 0.5;
    LPC_RIT->RICTRL |= _BV(1) | _BV(3);

}

void tlc_init(){
    pwm_init();
    rit_init();
    spi_init();

    period_us_double(1000000.0/(GSCLK_SPEED *2));
    write(0.5);
    start_pwm();

    attach_us((1000000.0/(GSCLK_SPEED *2))* 4096);



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
    
    //tlc_init();
}

void TLC5940_Init(void) {
    //set XLAT_PIN to output
    LPC_GPIO0->FIODIR |= _BV(XLAT_PIN);
    //set DCPRG_PIN to output
    LPC_GPIO0->FIODIR |= _BV(DCPRG_PIN);
    //set VPRG_PIN to output
    LPC_GPIO0->FIODIR |= _BV(VPRG_PIN);
    //set BLANK_PIN to output
    LPC_GPIO0->FIODIR |= _BV(BLANK_PIN);
    //set SCLK_PIN to output
    LPC_GPIO0->FIODIR |= _BV(SCLK_PIN);


    tlcMuxInit();
    //set XLAT_PIN low
    XLAT_PIN_CLR;
    //set DCPRG_PIN low
    DCPRG_PIN_CLR;
    //set VPRG_PIN high
    VPRG_PIN_SET;
    //set SCLK_PIN
    SCLK_PIN_CLR;
    //set BLANK_PIN high
    BLANK_PIN_SET;

    gsUpdateFlag = 1;

    pwm_init();
    rit_init();
    spi_init();

    period_us_double(1000000.0/(GSCLK_SPEED *2));
    write(0.5);
    start_pwm();

    attach_us((1000000.0/(GSCLK_SPEED *1.7))* 4096);




}
void TLC5940_SetAllDC(uint8_t value){
    uint8_t tmp1 = (uint8_t)(value << 2);
    uint8_t tmp2 = (uint8_t)(tmp1 << 2);
    uint8_t tmp3 = (uint8_t)(tmp2 << 2);
    tmp1 |= (value >> 4);
    tmp2 |= (value >> 2);
    tmp3 |= value;
    dcData_t i = 0;
    do {
        dcData[i++] = tmp1; // bits: 05 04 03 02 01 00 05 04
        dcData[i++] = tmp2; // bits: 03 02 01 00 05 04 03 02
        dcData[i++] = tmp3; // bits: 01 00 05 04 03 02 01 00
    } while (i < dcDataSize);

}
void TLC5940_SetDC(channel_t channel, uint8_t value){
    channel = numChannels - 1 - channel;
    channel_t i = (channel3_t)channel * 3 / 4;
    switch (channel % 4) {
        case 0:
            dcData[i] = (dcData[i] & 0x03) | (uint8_t)(value << 2);
            break;
        case 1:
            dcData[i] = (dcData[i] & 0xFC) | (value >> 4);
            i++;
            dcData[i] = (dcData[i] & 0x0F) | (uint8_t)(value << 4);
            break;
        case 2:
            dcData[i] = (dcData[i] & 0xF0) | (value >> 2);
            i++;
            dcData[i] = (dcData[i] & 0x3F) | (uint8_t)(value << 6);
            break;
        default: // case 3:
            dcData[i] = (dcData[i] & 0xC0) | (value);
            break;
    }
}

uint8_t dc_spi_tx(uint8_t tx){
   uint8_t dummy;
    while ( (LPC_SSP0->SR & (SSPSR_TNF|SSPSR_BSY)) != SSPSR_TNF );
                LPC_SSP0->DR = tx ;
     while ( (LPC_SSP0->SR & (SSPSR_BSY|SSPSR_RNE)) != SSPSR_RNE );
     /* Whenever a byte is written, MISO FIFO counter increments, Clear FIFO
        on MISO. Otherwise, when SSP0Receive() is called, previous data byte
        is left in the FIFO. */
    dummy = LPC_SSP0->DR;
    return dummy;

}

void dcspi_txrx(uint8_t* tx, uint8_t* rx, uint16_t len)
{
    /* Embed: transmit and receive len bytes
     * Remember:
     *   SPI transmits and receives at the same time
     *   If tx == NULL and you are only receiving then transmit all 0xFF
     *   If rx == NULL and you are only transmitting then dump all recieved bytes
     */
     uint8_t dummy, idx ;
     for( idx = 0; idx < len; idx++){
        if(tx == NULL && rx == NULL){
            //while not busy
             while ( LPC_SSP0->SR & SSPSR_BSY );
            dummy = LPC_SSP0->DR;
             while ( LPC_SSP0->SR & SSPSR_BSY );
             LPC_SSP0->DR = 0xFF;


        }
        else if(tx != NULL && rx == NULL){
            /*according to manual (software can write data to be sent in a future frame to this
            register whenever the TNF bit in the Status register is 1)*/
            while ( (LPC_SSP0->SR & (SSPSR_TNF|SSPSR_BSY)) != SSPSR_TNF );
            LPC_SSP0->DR = *tx & 0xFF;
            tx++;
             while ( (LPC_SSP0->SR & (SSPSR_BSY|SSPSR_RNE)) != SSPSR_RNE );
                  /* Whenever a byte is written, MISO FIFO counter increments, Clear FIFO
                  on MISO. Otherwise, when SSP0Receive() is called, previous data byte
                  is left in the FIFO. */
                  dummy = LPC_SSP0->DR;
        }
        else if(tx == NULL && rx != NULL){
            LPC_SSP0->DR = 0xFF;
            /* Wait until the Busy bit is cleared */
            while ( (LPC_SSP0->SR & (SSPSR_BSY|SSPSR_RNE)) != SSPSR_RNE );
            /*according to manual (software can read data from this register whenever the RNE bit
            in the Status register is 1, indicating that the Rx FIFO is not empty.)*/

            *rx++ =LPC_SSP0->DR;
        }
    }
}

void TLC5940_ClockInDC(void){
    DCPRG_PIN_SET;
    VPRG_PIN_SET;
    dcspi_txrx((uint8_t*) &dcData, NULL, dcDataSize);
    PULSE_XLAT_PIN;
    
}



//This is not working at the moment need to be reviced for 16bit
void TLC5940_SetAllGS(uint16_t value){
    uint8_t tmp1 = (value >> 4);
    uint8_t tmp2 = (uint8_t)(value << 4) | (tmp1 >> 4);
    gsData_t i = 0;
    do {
        #if MUX 
        for(int level = 0; level < SIZE; level++){
            gsData[level][i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
            gsData[level][i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
            gsData[level][i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00
            
        }
        #else
            gsData[i++] = tmp1; // bits: 11 10 09 08 07 06 05 04
            gsData[i++] = tmp2; // bits: 03 02 01 00 11 10 09 08
            gsData[i++] = (uint8_t)value; // bits: 07 06 05 04 03 02 01 00
        #endif
    } while (i < gsDataSize);

}

void TLC5940_SetGS(channel_t channel,uint8_t level,  uint16_t value) {
    channel = numChannels - 1 - channel;
    channel3_t i = (channel3_t)channel * 3 / 2;
    switch (channel % 2) {
        case 0:    
            gsData[level][i] = (value >> 4);
            i++;
            gsData[level][i] = (gsData[level][i] & 0x0F) | (uint8_t)(value << 4);
            break;
        default: // case 1:
            gsData[level][i] = (gsData[level][i] & 0xF0) | (value >> 8);
            i++;
            gsData[level][i] = (uint8_t)value;
            break;
    }
}


void TLC5940_SetGS_16(channel_t channel, uint8_t level, uint16_t value){
    printf("channel before: %d", channel );
    channel = numChannels - 1 - channel; 
    channel3_t  i = (channel3_t) channel * 3/4;
    printf("channel_after: %d    index: %d\n",channel, i + 1);
    switch((i + 1 ) % 3) {
       case 0:
            gsData[i][level] = (gsData[i][level] & 0xF000) | ((value) & 0x0FFF);
            break;

       case 1:
            switch(channel % 2){
                case 0:
                    gsData[i][level] = (gsData[i][level] & 0x000F) | (value << 4);
                default:
                    gsData[i][level] = (gsData[i][level] & 0xFFF0) | (value  >> 8);
                    i++;
                    gsData[i][level] = (gsData[i][level] & 0x00FF) | ((value & 0x00FF) << 8);
            }
            break;

       case 2:
            gsData[i][level] = (gsData[i][level] & 0xFF00) | ((value & 0x0FF0) >> 4);
            i++;
            gsData[i][level] = (gsData[i][level] & 0x0FFF) | ((value & 0x000F) << 12);     
            break;

    }
}
