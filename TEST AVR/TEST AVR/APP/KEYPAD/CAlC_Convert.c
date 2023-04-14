/*
 * CAlC_Convert.c
 *
 * Created: 4/6/2023 3:26:54 PM
 *  Author: imahm
 */ 
/*
int main()
{
	DIO_Init();
	LCD_Init();
	KeyPad_Init();
	u8 flag=0,k,sum=0;
	while(1)
	{
		k=KeyPad_GetKey();
		if (k!='x')
		{
			if (flag)
			{
				LCD_SetCursor(1,1);
				LCD_WriteString("          ");
				LCD_SetCursor(1,1);
				flag=0;
			}
			
			if (k>='0'&&k<='9')
			{
				LCD_WriteChar(k);
				sum=sum*10+k-'0';
			}
			else if (k=='=')
			{
				flag=1;
				LCD_SetCursor(2,1);
				LCD_WriteBinary(sum);
				sum=0;
				LCD_SetCursor(1,1);

			}
			else if (k=='c')
			{
				LCD_Clear();
			}		
		}
	}
	return 0;
}

*/
//**********************************************************
// 
/*
#define F_CPU 8000000UL
#include <util/delay.h>
 #include "../../SERVICE/Std_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../HAL/LCD/LCD_Interface.h"
 #include "../../HAL/KeyPad/KeyPad_interface.h"
#include "CALC_Convert.h"



void WelcomMassage()
{
	LCD_Clear();
	LCD_SetCursor(1,1);
	LCD_WriteString("   Calculator");
	_delay_ms(500);
	LCD_SetCursor(2,1);
	LCD_WriteString("BY Mahmoud Hamdi");
	_delay_ms(2000);
	LCD_Clear();
    LCD_SetCursor(2,1);
	LCD_WriteString("1-STD   2-Prog");
     LCD_SetCursor(1,1);
	 LCD_WriteString("Enter UR CALC:");
	 return;
}

 void app_init_calc(void)
 {
	 DIO_Init();
	 LCD_Init();
	 KeyPad_Init();
	  
 
 }
 
 void app_start_STD_Calc(void)
 {
	 s16 arr[2]={0},res=0;
	u8 op,flag=0,key,c=0;
	 while (1)
	 {
		 key=KeyPad_GetKey();
		 if (key!='x')
		 {
			 
			 if (key>='0'&&key<='9')
			 {
				 c=0;
				 if(flag)
				 {
					 arr[1]=arr[1]*10+key-'0';
				 }
				 else
				 {
					 arr[0]=arr[0]*10+key-'0';
				 }
				 LCD_WriteChar(key);
			 }
			 else if (key=='+'|| key=='-'|| key=='*'|| key=='/')
			 {
				 c=0;
				 if (res)
				 {
					 LCD_SetCursor(1,1);
					 LCD_WriteString("           ");
					 LCD_SetCursor(1,1);
					 flag=0;
					 arr[0]=0;
				 }
				 else
				 {
					 flag=1;
				 }
				 op=key;
				 LCD_WriteChar(key);
			 }
			 else if (key =='c')
			 {
				 c++;
				 LCD_Clear();
				 arr[0]=0;
				 arr[1]=0;
				 res=0;
				 flag=0;
				 if(c==2)return;
					 
			 }
			 else if (key=='=')
			 {
				 c=0;
				 if (flag)
				 {
					 switch(op)
					 {
						 case '+':
						 res=arr[0]+arr[1];
						 break;
						 case '-':
						 res=arr[0]-arr[1];
						 break;
						 case '*':
						 res=arr[0]*arr[1];
						 break;
						 case '/':
						 res=arr[0]/arr[1];
						 break;
					 }
				 }
				 else 
				 {
					 c=0;
					 switch(op)
					 {
						 case '+':
						 res+=arr[0];
						 break;
						 case '-':
						 res-=arr[0];
						 break;
						 case '*':
						 res*=arr[0];
						 break;
						 case '/':
						 res/=arr[0];
						 break;
					 }
					 
				 }
				  
				  LCD_SetCursor(2,1);
				  LCD_WriteString("           ");
				  LCD_SetCursor(2,1);
				  //if (res<0)LCD_WriteChar('-'); 
				  LCD_WriteNumber(res);	  
			 }		 
		 }
	 }
 }



void app_start_prog_Calc(void)
{
	void (*arr[3][3])(void)={{BTB,BTH,BTD},{HTB,HTH,HTD},{DTB,DTH,DTD}};
		u8 from,to,key,flag=1;
	while(1)
	{
	LCD_SetCursor(2,1);
	LCD_WriteString("1-B 2-H 3-D");
	LCD_SetCursor(1,1);
	LCD_WriteString("Convert from :");
	while (flag)
	{
		key=KeyPad_GetKey();
		
		if (key=='c')return;
		
		if (key=='1'||key=='2'||key=='3')
		{
			LCD_WriteChar(key);
			if (flag==1)
			{
		     	from=key;
				 flag=2;
				 LCD_Clear();
				LCD_SetCursor(2,1);
				LCD_WriteString("1-B 2-H 3-D");
				LCD_SetCursor(1,1);
				LCD_WriteString("Convert to :");
			}
			else if(flag==2)
			{
				to=key;
				if (to=='1'||to=='2'||to=='3')flag=0;	
			}
		}
		
	}
	
	from=from-'0'-1;
	to=to-'0'-1;
	arr[from][to]();
	flag=1;
	
	}
}
//BIN T
void BTB()
{
	u8 key,num=0,c=0,i=0;
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("BIN:");
	LCD_SetCursor(1,1);
	LCD_WriteString("BIN:");
	while(1)
	{
		key=KeyPad_GetKey();
		if (key=='1'||key=='0')
		{
			
			LCD_WriteChar(key);
			num=num|((key-'0')<<i);
			i++;
			if(i>=8)key='=';
		}
		else if (key=='c')
		{
			
			LCD_Clear();
			LCD_SetCursor(2,1);
			LCD_WriteString("BIN:");
			LCD_SetCursor(1,1);
			LCD_WriteString("BIN:");
			c++;
			num=0;
			i=0;
			if(c==2)return;
		}
		else if (key=='=')
		{
			c=0;
			i=0;
			LCD_SetCursor(2,1);
			LCD_WriteString("BIN:");
			LCD_WriteBinary(num);
			num=0;
		}
		
	}

}
void BTH()
{
	u8 key,num=0,c=0,i=0;
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("HEX:");
	LCD_SetCursor(1,1);
	LCD_WriteString("BIN:");
	while(1)
	{
		key=KeyPad_GetKey();
		if (key=='1'||key=='0')
		{
			
			LCD_WriteChar(key);
			num=num|((key-'0')<<i);
			i++;
			if(i>=8)key='=';
		}
		else if (key=='c')
		{
			LCD_Clear();
			LCD_SetCursor(2,1);
			LCD_WriteString("HEX:");
			LCD_SetCursor(1,1);
			LCD_WriteString("BIN:");
			c++;
			num=0;
			i=0;
			if(c==2)return;
		}
		else if (key=='=')
		{
			c=0;
			i=0;
			LCD_SetCursor(2,1);
			LCD_WriteString("HEX:");
			LCD_WriteHex(num);
			num=0;
		}
		
	}
	
	
}
void BTD()
{
	u8 key,num=0,c=0,i=0;
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("DEC:");
	LCD_SetCursor(1,1);
	LCD_WriteString("BIN:");
	while(1)
	{
	key=KeyPad_GetKey();
	if (key=='1'||key=='0')
	{
		LCD_WriteChar(key);
		num=num|((key-'0')<<i);
		i++;
		if(i>=8)key='=';
	}
	else if (key=='c')
	{
		LCD_Clear();
		LCD_SetCursor(2,1);
		LCD_WriteString("DEC:");
		LCD_SetCursor(1,1);
		LCD_WriteString("BIN:");
		c++;
		num=0;
		i=0;
		if(c==2)return;
	}
	else if (key=='=')
	{
		i=0;
		c=0;
		LCD_SetCursor(2,1);
		LCD_WriteString("DEC:");
		LCD_WriteNumber(num);
		num=0;
	}
	
	}
	
}

//DEC to
void DTB()
{
	u8 key,num=0,c=0;
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("BIN:");
	LCD_SetCursor(1,1);
	LCD_WriteString("DEC:");
	while (1)
	{
		key=KeyPad_GetKey();
		if (key>='0'&&key<='9')
		{
			c=0;
			num=num*10+key-'0';
			LCD_WriteChar(key);
		}
		else if(key =='=')
		{
			c=0;
			LCD_SetCursor(2,5);
			LCD_WriteBinary(num);
			
		}
		else if(key =='c')
		{
			num=0;
			c++;
			LCD_Clear();
			if(c==2)return;
			LCD_SetCursor(2,1);
			LCD_WriteString("BIN:");
			LCD_SetCursor(1,1);
			LCD_WriteString("DEC:");
			
		}
		
	}
	
}	 
void DTH()
{	
	u8 key,num=0,c=0;
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("HEX:");
	LCD_SetCursor(1,1);
	LCD_WriteString("DEC:");
	while (1)
	{
		key=KeyPad_GetKey();
		if (key>='0'&&key<='9')
		{
			c=0;
			num=num*10+key-'0';
			LCD_WriteChar(key);
		}
		else if(key =='=')
		{
			c=0;
			LCD_SetCursor(2,5);
			LCD_WriteHex(num);
			
		}
		else if(key =='c')
		{
			num=0;
			c++;
			LCD_Clear();
			if(c==2)return;
			LCD_SetCursor(2,1);
			LCD_WriteString("HEX:");
			LCD_SetCursor(1,1);
			LCD_WriteString("DEC:");
			
		}
		
	} 
}
void DTD()
{
	u8 key,num=0,c=0;
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("DEC:");
	LCD_SetCursor(1,1);
	LCD_WriteString("DEC:");
	while (1)
	{
		key=KeyPad_GetKey();
		if (key>='0'&&key<='9')
		{
			c=0;
			num=num*10+key-'0';
			LCD_WriteChar(key);
		}
		else if(key =='=')
		{
			c=0;
			LCD_SetCursor(2,5);
			LCD_WriteNumber(num);
			
		}
		else if(key =='c')
		{
			num=0;
			c++;
			LCD_Clear();
			if(c==2)return;
			LCD_SetCursor(2,1);
			LCD_WriteString("DEC:");
			LCD_SetCursor(1,1);
			LCD_WriteString("DEC:");
			
		}
		
	}
	
}

//HEX to
void HTB()
{
	u8 key,num=0,c=0;
	u8 arr[4]={'A','B','C','D'};
	u8 arr2[4]={10,11,12,13};
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("BIN:");
	LCD_SetCursor(1,1);
	LCD_WriteString("HEX:0X");
	while (1)
	{
		key=KeyPad_GetKey();
		if (key>='0'&&key<='9')
		{
			c=0;
			LCD_WriteChar(key);
			if(num)
			{
			 num|=(key-'0');
			}
			else
			{
				num|=(key-'0')<<4;
			}
		}
		else if (key=='+'|| key=='-'|| key=='*'|| key=='/')
		{
			c=0;
			switch (key)
			{
				case '+':
				LCD_WriteChar(arr[3]);
				if(num)
				{
					
					num|=arr2[3];
				}
				else
				{
					
					num|=(arr2[3]<<4);
				}
				
				break;
				case '-':
				LCD_WriteChar(arr[2]);
				if(num)
				{
					
					num|=arr2[2];
				}
				else
				{
					
					num|=(arr2[2]<<4);
				}
				break;
				case '*':
				LCD_WriteChar(arr[1]);
				if(num)
				{
					
					num|=arr2[1];
				}
				else
				{
					
					num|=(arr2[1]<<4);
				}
				break;
				case '/':
				LCD_WriteChar(arr[0]);
				if(num)
				{
					
					num|=arr2[0];
				}
				else
				{
					
					num|=(arr2[0]<<4);
				}
				break;
			}
		}
		else if(key=='=')
		{
			c=0;
			LCD_SetCursor(2,1);
			LCD_WriteString("BIN:");
			LCD_WriteBinary(num);
			num=0;
			
		}
		else if(key=='c')
		{
			c++;
			LCD_Clear();
			if(c==2)return;
			LCD_SetCursor(2,1);
			LCD_WriteString("BIN:");
			LCD_SetCursor(1,1);
			LCD_WriteString("HEX:0X");
			
			num=0;
		}
		
	}

}
void HTH()
{
	u8 key,num=0,c=0;
	u8 arr[4]={'A','B','C','D'};
	u8 arr2[4]={10,11,12,13};
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("HEX:");
	LCD_SetCursor(1,1);
	LCD_WriteString("HEX:0X");
	while (1)
	{
		key=KeyPad_GetKey();
		if (key>='0'&&key<='9')
		{
			c=0;
			LCD_WriteChar(key);
			if(num)
			{
				num|=(key-'0');
			}
			else
			{
				num|=(key-'0')<<4;
			}
		}
		else if (key=='+'|| key=='-'|| key=='*'|| key=='/')
		{
			c=0;
			switch (key)
			{
				case '+':
				LCD_WriteChar(arr[3]);
				if(num)
				{
					
					num|=arr2[3];
				}
				else
				{
					
					num|=(arr2[3]<<4);
				}
				
				break;
				case '-':
				LCD_WriteChar(arr[2]);
				if(num)
				{
					
					num|=arr2[2];
				}
				else
				{
					
					num|=(arr2[2]<<4);
				}
				break;
				case '*':
				LCD_WriteChar(arr[1]);
				if(num)
				{
					
					num|=arr2[1];
				}
				else
				{
					
					num|=(arr2[1]<<4);
				}
				break;
				case '/':
				LCD_WriteChar(arr[0]);
				if(num)
				{
					
					num|=arr2[0];
				}
				else
				{
					
					num|=(arr2[0]<<4);
				}
				break;
			}
		}
		else if(key=='=')
		{
			c=0;
			LCD_SetCursor(2,1);
			LCD_WriteString("HEX:");
			LCD_WriteHex(num);
			num=0;
			
		}
		else if(key=='c')
		{
			c++;
			LCD_Clear();
			if(c==2)return;
			LCD_SetCursor(2,1);
			LCD_WriteString("HEX:");
			LCD_SetCursor(1,1);
			LCD_WriteString("HEX:0X");
			
			num=0;
		}
		
	}
	
}
void HTD()
{
	u8 key,num=0,c=0;
	u8 arr[4]={'A','B','C','D'};
	u8 arr2[4]={10,11,12,13};
	LCD_Clear();
	LCD_SetCursor(2,1);
	LCD_WriteString("DEC:");
	LCD_SetCursor(1,1);
	LCD_WriteString("HEX:0X");
	while (1)
	{
		key=KeyPad_GetKey();
		if (key>='0'&&key<='9')
		{
			c=0;
			LCD_WriteChar(key);
			if(num)
			{
				num|=(key-'0');
			}
			else
			{
				num|=(key-'0')<<4;
			}
		}
		else if (key=='+'|| key=='-'|| key=='*'|| key=='/')
		{
			c=0;
			switch (key)
			{
				case '+':
				LCD_WriteChar(arr[3]);
				if(num)
				{
					
					num|=arr2[3];
				}
				else
				{
					
					num|=(arr2[3]<<4);
				}
				
				break;
				case '-':
				LCD_WriteChar(arr[2]);
				if(num)
				{
					
					num|=arr2[2];
				}
				else
				{
					
					num|=(arr2[2]<<4);
				}
				break;
				case '*':
				LCD_WriteChar(arr[1]);
				if(num)
				{
					
					num|=arr2[1];
				}
				else
				{
					
					num|=(arr2[1]<<4);
				}
				break;
				case '/':
				LCD_WriteChar(arr[0]);
				if(num)
				{
					
					num|=arr2[0];
				}
				else
				{
					
					num|=(arr2[0]<<4);
				}
				break;
			}
		}
		else if(key=='=')
		{
			c=0;
			LCD_SetCursor(2,1);
			LCD_WriteString("DEC:");
			LCD_WriteNumber(num);
			num=0;
			
		}
		else if(key=='c')
		{
			c++;
			LCD_Clear();
			if(c==2)return;
			LCD_SetCursor(2,1);
			LCD_WriteString("DEC:");
			LCD_SetCursor(1,1);
			LCD_WriteString("HEX:0X");
			
			num=0;
		}
		
	}
	
}




*/