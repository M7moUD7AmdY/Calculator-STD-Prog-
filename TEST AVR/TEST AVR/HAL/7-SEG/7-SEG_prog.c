#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../SERVICE/Std_types.h"
#include "../../SERVICE/MemMap.h"
#include "../../SERVICE/BIT_OP.h"
#include "SEG_interface.h"
#include "SEG_Privet.h"

//display for two 7-seg by decimal
void segment_display_DEC(u8 n ,Seg_type seg)
{
	u8 d0,d1, seg_arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	//if i want to display num from 2 digits
	d0=n%10;
	d1=n/10;
	//shift if i use pin 1 as a first
   switch (seg)
   {
	   case COMMON_ANOD:
	   SEG1_PORT=~seg_arr[d0];
	   SEG2_PORT=~seg_arr[d1];
	   break;
	   case COMMON_CATHOD:
	   SEG1_PORT=seg_arr[d0];
	   SEG2_PORT=seg_arr[d1];
	   break;
   }
	
	
	
}

//display for two 7-seg by hex

void segment_display_HEX(u8 n,Seg_type seg)
{
	u8 d0,d1, seg_arr[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0xF7,0xFC,0x39,0x5E,0x79,0x71};
	d1=n>>4;
	d0=n&0x0F;
	 switch (seg)
	 {
		 case COMMON_ANOD:
		 SEG1_PORT=~seg_arr[d0];
		 SEG2_PORT=~seg_arr[d1];
		 break;
		 case COMMON_CATHOD:
		 SEG1_PORT=seg_arr[d0];
		 SEG2_PORT=seg_arr[d1];
		 break;
	 }
}

//display for two 7-seg use bcd

void segment_display_BCD(u8 n)
{
	u8 d0,d1;
	d0=n%10;
	d1=n/10;
	BCD_SEG_PORT&=0x00;//masking to make sure that the register is 0
	BCD_SEG_PORT=(d0)|(d1<<4);
	
}


//display for two 7-seg mlx

void segment_display_MLX(u8 n)
{
	unsigned char d0,d1, seg_arr[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
	d0=n%10;
	d1=n/10;

	SET_BIT(CONTROL_SEG_PORT,FIRST_SEG_PIN);
	SEG1_PORT=(seg_arr[d0]<<1);
	CLR_BIT(CONTROL_SEG_PORT,SECOND_SEG_PIN);
	_delay_ms(1);
	SET_BIT(CONTROL_SEG_PORT,SECOND_SEG_PIN);
	SEG2_PORT=(seg_arr[d1]<<1);
	CLR_BIT(CONTROL_SEG_PORT,FIRST_SEG_PIN);
	_delay_ms(1);
	
	
}