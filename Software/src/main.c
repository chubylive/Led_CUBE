#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

#include "main.h"
#include "TLC5940.h"
#include "ledcube.h"


// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP;
 
  int8_t rowSelect = GPIO1_1_18;
typedef struct 
{
  uint16_t red ;
  
}px;

typedef struct {
  uint16_t buf[SIZE *2];
}ly;
int count = 0;

ly lys [SIZE];

void delay_call(int dl){
  volatile int delay, i;

  delay = dl *100;
  for (i = 0; i < delay; )
  {
    i++;
  }
}

uint16_t temp[gsDataSize/2];

void print_buff_binary_16(uint16_t *buff, size_t length){
  printf("$*********** Start of Frame **************$\n");
  uint16_t byte;

  for(int idx = 0; idx < length; idx++){

    for(int b_idx = 0; b_idx < 16; b_idx++){
      byte = buff[idx] & (1 << b_idx);
      byte  = byte >> b_idx;

        printf("%u ", byte);
      
    }
    printf("\n");
  }
  printf("$*********** End of Frame **************$\n");

}

void print_buff_binary_8(uint8_t *buff, size_t length){
  printf("$*********** Start of Frame **************$\n");
  uint16_t byte;

  for(int idx = 0; idx < length; idx++){

    for(int b_idx = 0; b_idx < 8; b_idx++){
      byte = buff[idx] & (1 << b_idx);
      byte  = byte >> b_idx;

        printf("%u ", byte);
      
    }
    printf("\n");
  }
  printf("$*********** End of Frame **************$\n");

}
#if !USE_16_BIT && !MUX
void print_buff_temp(){
  int j= 0;
  for (int i = 0; i < gsDataSize; i+=2)
  {
    temp[j++] = ((uint16_t)gsData[i] << 8) | gsData[i+1];
  }
  print_buff_binary_16(temp, gsDataSize/2);

}
#endif
void set_all(int level1){
  int idx, jdx;
  for (idx = 0; idx < SIZE; ++idx)
  {
    
        lys[idx].buf[15]= level1;
        lys[idx].buf[14]= level1;
        lys[idx].buf[0] = level1;
      
    
  }
}

int level= 0xFFF;

int con = 0;
int up = 0;
int idx = 0;
int vprg_pin =0;
#define R1 1
#define G1 2
#define B1 3
#define R2 16
#define G2 17
#define B2 18
#define R3 32
#define G3 33
#define B3 34

int main(void) {

   
   /* uint8_t layer ;  // //Setup GPIO pins
    LPC_GPIO0->FIODIR |= (1<<22);
    LPC_GPIO0->FIOSET |= (1<<22);
  */
  /*  
    set_all(level);
    tlcMuxInit();
    
  spi_txrx((uint16_t* )lys[rowSelect].buf,NULL, 16);*/
  TLC5940_Init();
  TLC5940_SetAllDC(0);
  TLC5940_ClockInDC();
  vprg_pin = 1;




  TLC5940_SetAllGS(0x00);

  COLOUR cl ;
  cl.r = 255; //green
  cl.g = 0; //blue
  cl.b = 0; //red 
  #if USE_16_BIT
  SetColour3D_16(0,0,0,cl);
  SetColour3D_16(2,0,0,cl);
  SetColour3D_16(4,0,0,cl);
  SetColour3D_16(6,0,0,cl);
  SetColour3D_16(8,0,0,cl);
  SetColour3D_16(10,0,0,cl);
  SetColour3D_16(12,0,0,cl);
  SetColour3D_16(14,0,0,cl);
  SetColour3D_16(0 + 1,0,0,cl);
  SetColour3D_16(2 + 1,0,0,cl);
  SetColour3D_16(4 + 1,0,0,cl);
  SetColour3D_16(6 + 1,0,0,cl);
  SetColour3D_16(8 + 1,0,0,cl);
  SetColour3D_16(10 + 1,0,0,cl);
  SetColour3D_16(12 + 1,0,0,cl);
  SetColour3D_16(14 + 1,0,0,cl);

  print_buff_binary_16(gsData[0], gsDataSize);
  #else
  SetColour3D(0,0,0,cl);
  SetColour3D(2,0,0,cl);
  SetColour3D(4,0,0,cl);
  SetColour3D(6,0,0,cl);
  SetColour3D(8,0,0,cl);
  SetColour3D(10,0,0,cl);
  SetColour3D(12,0,0,cl);
  SetColour3D(14,0,0,cl);
  SetColour3D(0 + 1,0,0,cl);
  SetColour3D(2 + 1,0,0,cl);
  SetColour3D(4 + 1,0,0,cl);
  SetColour3D(6 + 1,0,0,cl);
  SetColour3D(8 + 1,0,0,cl);
  SetColour3D(10 + 1,0,0,cl);
  SetColour3D(12 + 1,0,0,cl);
  SetColour3D(14 + 1,0,0,cl);
  print_buff_binary_8(gsData, gsDataSize);
  print_buff_temp();
  #endif
  // SetColour3D_16(2,0,0,cl);
  // SetColour3D_16(4,0,0,cl);
  // SetColour3D_16(6,0,0,cl);
  // SetColour3D_16(8,0,0,cl);
  // SetColour3D_16(10,0,0,cl);
  // SetColour3D_16(12,0,0,cl);
  // SetColour3D_16(14,0,0,cl);

  // SetColour3D_16(0 + 1,0,0,cl);
  // SetColour3D_16(2 + 1,0,0,cl);
  // SetColour3D_16(4 + 1,0,0,cl);
  // SetColour3D_16(6 + 1,0,0,cl);
  // SetColour3D_16(8 + 1,0,0,cl);
  // SetColour3D_16(10 + 1,0,0,cl);
  // SetColour3D_16(12 + 1,0,0,cl);
  // SetColour3D_16(14 + 1,0,0,cl);

  //SetColour3D_16(0,0,2,cl);

  exit(0);
  // print_buff_binary(gsData[1], gsDataSize);
  // print_buff_binary(gsData[2], gsDataSize);
  // TLC5940_SetGS(R1, 0,0xFFF);
  // TLC5940_SetGS(G1,0, 0xFFF);
  // TLC5940_SetGS(B1, 0, 0xFFF);
  /*
  TLC5940_SetGS(0, 0,0xFFF);
  TLC5940_SetGS(16,0, 0xFFF);
  TLC5940_SetGS(32, 0, 0xFFF);*/







  PULSE_XLAT_PIN;
  PULSE_SCLK_PIN;
  VPRG_PIN_CLR;
  #if USE_16_BIT 
      LPC_SSP0->CR0 |= 0xF;
  #else
       LPC_SSP0->CR0 |= 0x7;
  #endif   
   NVIC_EnableIRQ(RIT_IRQn);

  while(1){
   

     
    

  }
    return 0;
}

void RIT_IRQHandler(){
    //clear interrupt
    LPC_RIT->RICTRL |= _BV(0);

 
    
    static uint8_t xlatNeedsPulse = 0;

    BLANK_PIN_SET;
    if (vprg_pin){
      
      if (xlatNeedsPulse){
        PULSE_XLAT_PIN;
        xlatNeedsPulse = 0;
      }
      PULSE_SCLK_PIN;
      vprg_pin =0;

    }else if (xlatNeedsPulse)
    {
      
      xlatNeedsPulse = 0;
    }
    BLANK_PIN_CLR;

    #if MUX 
      #if USE_16_BIT 
        spi_txrx((uint16_t*) gsData[0], NULL, gsDataSize);
      #else
        dcspi_txrx((uint8_t*) gsData[0], NULL, gsDataSize);
      #endif
    #else
      #ifdef USE_16_BIT
        spi_txrx((uint16_t*) gsData, NULL, gsDataSize);
      #else
        dcspi_txrx((uint8_t*) gsData, NULL, gsDataSize);
      #endif



       if(rowSelect > GPIO1_1_25){
            //set row 
            rowSelect = GPIO1_1_18;
            LPC_GPIO1->FIOPIN = _BV(rowSelect++);
            //reset row select
            
        }else{
           
            LPC_GPIO1->FIOPIN = _BV(rowSelect++);
         
        }
       
    #endif
    PULSE_XLAT_PIN;
    
  //   // write(0.0);
  
  // BLANK_PIN_SET;
  // if (t)
  // {
  // VPRG_PIN_CLR;
  // PULSE_XLAT_PIN;
  // t = 0;
  //   /* code */
  // }

  // BLANK_PIN_CLR;

    //select Row to be one
    
   //delay_call(10000);
    
    

}

