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
volatile int idx = 0;
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

  SetColour3D(0,0,0,cl);
  SetColour3D(1,0,0,cl);
  SetColour3D(2,0,0,cl);
  SetColour3D(3,0,0,cl);
  SetColour3D(4,0,0,cl);
  SetColour3D(5,0,0,cl);
  SetColour3D(6,0,0,cl);
  SetColour3D(7,0,0,cl);

  SetColour3D(0,3,1,cl);
  SetColour3D(1,3,1,cl);
  SetColour3D(2,3,1,cl);
  SetColour3D(3,3,1,cl);
  SetColour3D(4,3,1,cl);
  SetColour3D(5,3,1,cl);
  SetColour3D(6,3,1,cl);
  SetColour3D(7,3,1,cl);
  
 // print_buff_binary_8(gsData, gsDataSize);


   print_buff_binary_8(gsData[0], gsDataSize);
   print_buff_binary_8(gsData[1], gsDataSize);
    print_buff_binary_8(gsData[2], gsDataSize);
  exit(0);
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


    dcspi_txrx((uint8_t*) gsData[idx], NULL, gsDataSize);
    
    LPC_GPIO1->FIOPIN = _BV(GPIO1_1_18 + idx);
    idx = (idx + 1) % SIZE;
    // if(rowSelect > GPIO1_1_25){
    //     //set row 
    //     rowSelect = GPIO1_1_18;
    //     LPC_GPIO1->FIOPIN = _BV(rowSelect++);
    //     //reset row select
        
    // }else{
       
    //     LPC_GPIO1->FIOPIN = _BV(rowSelect++);
     
    // }
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

