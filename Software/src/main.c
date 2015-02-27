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
volatile uint_fast8_t idx = 0;
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
  //vprg_pin = 1;
  TLC5940_SetAllGS(0x00);




  COLOUR cl ;
  cl.r = 255; //green
  cl.g = 0; //blue
  cl.b = 0; //red 
 
  SetColour3D_16(0,0,0,cl);
  SetColour3D_16(1,0,0,cl);
  SetColour3D_16(2,0,1,cl);
  SetColour3D_16(3,0,0,cl);
  SetColour3D_16(5,0,1,cl);
  SetColour3D_16(4,0,0,cl);
  SetColour3D_16(6,0,0,cl);
  SetColour3D_16(7,0,1,cl);

  SetColour3D_16(0,2,1,cl);
  SetColour3D_16(1,2,0,cl);
  SetColour3D_16(2,2,0,cl);
  SetColour3D_16(3,2,0,cl);
  SetColour3D_16(5,2,1,cl);
  SetColour3D_16(4,2,1,cl);
  SetColour3D_16(6,2,1,cl);
  SetColour3D_16(7,2,1,cl);
 
  

  //print_buff_binary_16(gsData[0], gsDataSize);
  
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

  //exit(0);
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
  //switch ssp to send 16bit frames   
  LPC_SSP0->CR0 |= 0xF;
  
   NVIC_EnableIRQ(RIT_IRQn);

  while(1){
   

     
    //TLC5940_SetGSUpdateFlag;

  }
    return 0;
}

void RIT_IRQHandler(){
  //clear interrupt
  LPC_RIT->RICTRL |= _BV(0);

  BLANK_PIN_SET;
  BLANK_PIN_CLR;

  
  LPC_GPIO1->FIOPIN = _BV(GPIO1_1_17 + idx);

 //if (gsUpdateFlag) //framerate of cube ie on cube image
 //{


  spi_txrx((uint16_t*) gsData[idx], NULL, gsDataSize);
  
/*  if(rowSelect > GPIO1_1_25){
    //set row 
    rowSelect = GPIO1_1_18;
    LPC_GPIO1->FIOPIN = _BV(rowSelect++);
    //reset row select
    
  }else{
    LPC_GPIO1->FIOPIN = _BV(rowSelect++);
   
  }*/
    // gsUpdateFlag = 0;
  PULSE_XLAT_PIN;  
 //}

  


idx = (idx + 1) % SIZE;

}

