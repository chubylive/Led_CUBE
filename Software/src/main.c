#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

#include "main.h"
#include "TLC5940.h"
#include "ledcube.h"
#include "sinWave.h"
#include "ColourWheel.h"


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

void print_array(){
  for (int i = 0; i < 512; ++i)
  {
    COLOUR cl = get_next_colour();
    printf("Red: %d Green: %d Blue: %d\n", cl.r, cl.g, cl.b);

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

  fill_colour_wheel();
  //print_array();
  //exit(0);

  COLOUR cl ;
  cl.r = 0; //green
  cl.g = 255; //blue
  cl.b = 0; //red 
 
  PULSE_XLAT_PIN;
  PULSE_SCLK_PIN;
  VPRG_PIN_CLR;
  //switch ssp to send 16bit frames   
  LPC_SSP0->CR0 |= 0xF;
  
  NVIC_EnableIRQ(RIT_IRQn);
  int tdx = 0;
  for (int x = 0; x < 8; ++x)
    {
      for (int y = 0; y < 8; ++y)
      {
        for (int z = 0; z < 8; ++z)
        {
          SetColour3D_16(x,y,z, cl);
        }
      }
  }

  //gsUpdateFlag = 0;
    // TLC5940_ClearGsData();    
    // SetColour3D_16(3, 0,tdx, cl);
    // SetColour3D_16(3, 1,tdx, cl);
    // SetColour3D_16(3, 2,tdx, cl);
    // SetColour3D_16(3, 3,tdx, cl);
    // SetColour3D_16(3, 4,tdx, cl);
    // SetColour3D_16(3, 5,tdx, cl);
    // SetColour3D_16(tdx, 6,0, cl);
    // SetColour3D_16(tdx, tdx,tdx, cl);
    // tdx = (tdx + 1) % SIZE;
  struct animate cube_animation[4];

  while(1){

    
    sinWave();
    //Spiral();
   // gsUpdateFlag = 1;

    //delay_call(5000);

    switch (cube_animation[index].animate(&(cube_animation[index])){
      case 0:
        continue;
        break;
      case 1:
        index++; 
        break;
      default:
        break;
    }
  }
    return 0;
}

void RIT_IRQHandler(){
  //clear interrupt
  LPC_RIT->RICTRL |= _BV(0);

  BLANK_PIN_SET;
  BLANK_PIN_CLR;

  
  LPC_GPIO1->FIOPIN = _BV(GPIO1_1_18 + idx);

  if (gsUpdateFlag) //framerate of cube ie on cube image
  {


    spi_txrx((uint16_t*) gsData[idx], NULL, gsDataSize);
    

    PULSE_XLAT_PIN; 
    //gsUpdateFlag = 0; 
  }

  idx = (idx + 1) % SIZE;

}

