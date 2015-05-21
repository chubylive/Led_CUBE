#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <NXP/crp.h>

#include "main.h"
#include "TLC5940.h"
#include "ledcube.h"
#include "sinWave.h"
#include "spiral.h"
#include "csumd.h"
#include "ColourWheel.h"
#include "animate.h"


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
   // printf("Red: %d Green: %d Blue: %d\n", cl.r, cl.g, cl.b);

  }
}

int level= 0xFFF;

int con = 0;
int up = 0;
volatile uint_fast8_t row_index = 0;
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
int anim_index =0;
volatile uint_fast8_t chg_buff = 0 ;

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
  cl.r = 255;//green
  cl.g = 255; //blue
  cl.b = 255; //red 
 
  PULSE_XLAT_PIN;
  PULSE_SCLK_PIN;
  VPRG_PIN_CLR;
  //switch ssp to send 16bit frames   
  LPC_SSP0->CR0 |= 0xF;
  
  
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
   //sinWave();
   //Spiral();
   // gsUpdateFlag = 1;
  struct animation cube_animation;
  cube_animation.animate = Spiral_animate;
  cube_animation.bottom = 0;
  cube_animation.top = 8; 
  cube_animation.narrow = 0;
  cube_animation.speed =1 ;
  cube_animation.phase = 0;
  cube_animation.X = 0;
  cube_animation.Y = 0;
  cube_animation.Z = 0;
  cube_animation.random_colour =1 ;
  cube_animation.overlay = 1;

  cube_animation.clr.r = 255;//green
  cube_animation.clr.g = 255; //blue
  cube_animation.clr.b = 255; //red 
  struct animation cube_animation1;
  cube_animation1.animate = Spiral_animate;
  cube_animation1.bottom = 0;
  cube_animation1.top = 8; 
  cube_animation1.narrow = 1;
  cube_animation1.speed =0.5 ;
  cube_animation1.phase = 0;
  cube_animation1.Y = 0;
  cube_animation1.Z = 0;  
  cube_animation1.overlay =1;
   cube_animation1.clr.r = 255;//red
  cube_animation1.clr.g = 255; //blue
  cube_animation1.clr.b = 255; // gree
  TLC5940_ClearGsData_buff(cube_animation1.overlay_buff);


  struct animation cube_animation2;
  cube_animation2.animate = Spiral_animate;
  cube_animation2.bottom = 0;
  cube_animation2.top = 8; 
  cube_animation2.narrow = 2;
  cube_animation2.speed =0.25 ;
  cube_animation2.phase = 0;
  cube_animation2.Y = 0;
  cube_animation2.Z = 0;  
  cube_animation2.random_colour =0;
  cube_animation2.overlay =1;
   cube_animation2.clr.r = 255;//green
  cube_animation2.clr.g = 255; //blue
  cube_animation2.clr.b = 255;
  TLC5940_ClearGsData_buff(cube_animation2.overlay_buff);
  TLC5940_ClearGsData();
  //csumd();
  NVIC_EnableIRQ(RIT_IRQn);
 // csumd();
  while(1){
    //Spiral();
    // if (row_index)
    // {
    //   /* code */
    // }
   // chg_buff = 1;
    cube_animation.animate(&cube_animation);
  //  cube_animation1.animate(&cube_animation1);
    cube_animation2.animate(&cube_animation2);
    //switch back to buffer 0
    
   // chg_buff = 0;

    delay_call(5000);

  //   switch (cube_animation[anim_index].animate(&(cube_animation[anim_index]))){
  //     case 0:
  //       continue;
  //       break;
  //     case 1:
  //       anim_index++; 
  //       break;
  //     default:
  //       break;
  //   }
   }
    return 0;
}

void RIT_IRQHandler(){
  //clear interrupt
  LPC_RIT->RICTRL |= _BV(0);

  BLANK_PIN_SET;
  BLANK_PIN_CLR;

  
  LPC_GPIO1->FIOPIN = _BV(GPIO1_1_18 + row_index);

  // if (!chg_buff) //Switch buffers
  // {
    spi_txrx((uint16_t*) gsData[row_index], NULL, gsDataSize);
    
  // }else{
  //   spi_txrx((uint16_t*) gsData1[row_index], NULL, gsDataSize);
  // }
  PULSE_XLAT_PIN; 

  row_index = (row_index + 1) % SIZE;

}

