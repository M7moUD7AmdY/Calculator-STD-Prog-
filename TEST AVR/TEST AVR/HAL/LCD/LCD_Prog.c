/*
 * LCD_Prog.c
 *
 * Created: 4/1/2023 4:03:28 PM
 *  Author: imahm
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../SERVICE/Std_types.h"
#include "../../SERVICE/BIT_OP.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_Interface.h"
#include "../../CFG/LCD/LCD_CFG.h"


#if LCD_MODE==_8_BIT
static void WriteIns(u8 ins)
{
	
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_PORT,ins);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}

static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_PORT,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}



void LCD_Init(void)
{
	_delay_ms(50);
	
	WriteIns(0x38);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift
	
}

#elif LCD_MODE ==_4_BIT
static void WriteIns(u8 ins)
{
	
	
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,READ_BIT(ins,7));
	DIO_WritePin(D6,READ_BIT(ins,6));
	DIO_WritePin(D5,READ_BIT(ins,5));
	DIO_WritePin(D4,READ_BIT(ins,4));
	
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(ins,3));
	DIO_WritePin(D6,READ_BIT(ins,2));
	DIO_WritePin(D5,READ_BIT(ins,1));
	DIO_WritePin(D4,READ_BIT(ins,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}

static void WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));

	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}



void LCD_Init(void)
{
	_delay_ms(50);
	WriteIns(0x02);
	WriteIns(0x28);//5*7 2 lines
	WriteIns(0x0c);//0x0c,0x0e,0x0f cursor
	WriteIns(0x01);//clear screen
	_delay_ms(1);
	WriteIns(0x06);// increment DDRAM address, no shift
	
}

#endif

//****************************************

void LCD_WriteChar(u8 ch)
{
	WriteData(ch);
}


void LCD_WriteString(u8*str)
{
	u8 i;
	for (i=0;str[i];i++)
	{
		LCD_WriteChar(str[i]);
	}
	
}


void LCD_WriteNumber(s32 num)
{
	u8 i=0,arr[10];
	if (num==0)
	{
		LCD_WriteChar('0');
		return;
	}
		if (num<0)
		{
			num*=-1;
			LCD_WriteChar('-');
		}
		while (num)
		{
			arr[i]=num%10+'0';
			num/=10;
			i++;
		}
		for (;i>0;i--)
		{
			LCD_WriteChar(arr[i-1]);
		}
			
}


void LCD_WriteBinary(s8 num)
{
	s8 i;
	for (i=7;i>=0;i--)
	{
		LCD_WriteChar(READ_BIT(num,i)+'0');
	}	
}


void LCD_WriteHex(u8 num)
{
	s8 i;
LCD_WriteChar('0');
LCD_WriteChar('X');
u8 hex_num[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	u8 bits_arr[2];
	for(i=0;i<2;i++)
	{
		bits_arr[i]=hex_num[num%16];	
		num/=16;
		
	}
	LCD_WriteChar(bits_arr[1]);
	LCD_WriteChar(bits_arr[0]);
	
}


//***************************************
//CGRam_addres from 0 to 63
void LCD_SpecialShape(u8 *shap,u8 CGRam_addres)
{
	u8 i,instruction;
	instruction=CGRam_addres*8;
	SET_BIT(instruction,6);
	WriteIns(instruction);
	for(i=0;i<8;i++)
	{
		WriteData(shap[i]);
	}
	WriteIns(0x80);//to go back to DDRam
	
}


//**************************************
void LCD_SetCursor(u8 line,u8 cell)
{
	if (line==1)
	{
		WriteIns(0x80|(cell-1));
	}
	else if (line ==2)
	{
		WriteIns(0x80+0x40+(cell-1));
	}
	
}

void LCD_Clear(void)
{
	WriteIns(0x01);
	_delay_ms(1);
}

void LCD_ClearLOC(u8 line,u8 cell,u8 num)
{
	s8 i;
	LCD_SetCursor(line ,cell);
	for (i=0;i<num;i++)
	{
		LCD_WriteChar(' ');
	}
	
}


//*******************************
void LCD_WriteNumber_recersive(s32 num)
{
	if (num<0)
	{
		num*=-1;
		LCD_WriteChar('-');
	}
	if ((num/10)!=0)
	{
		num/=10;
		LCD_WriteNumber(num);
	}
	num%=10;
	LCD_WriteChar((num+'0'));

}

void LCD_WriteNumber_4D(u16 num)
{
	LCD_WriteChar(((num%10000)/1000+'0'));
	LCD_WriteChar(((num%1000)/100+'0'));
	LCD_WriteChar(((num%100)/10+'0'));
	LCD_WriteChar(((num%10)/1+'0'));
}
//**************
