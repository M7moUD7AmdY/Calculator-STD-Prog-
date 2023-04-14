/*
 * taskes_lcd.c
 *
 * Created: 4/3/2023 5:32:24 PM
 *  Author: imahm
 */ 
/*

int main()
{
	DIO_Init();
	LCD_Init();
	
	u8 i,j,x=0,arr[]="M7moud_7amdi",flag=1,flag2=0;
	
	while (1)
	{
		
		while (flag)
		{
			if (flag2)
			{
				LCD_SetCursor(2,2+j);
				LCD_WriteString(arr);
			}
			
			LCD_SetCursor(1,1);
			for(i=12-x;i<12;i++)
			{
				LCD_WriteChar(arr[i]);
			}
			x++;
			j++;
			if(x==12)
			{
				x=0;
				flag=0;
			}
			_delay_ms(300);
			LCD_Clear();
			

		}
		flag=1;
		
		
		
		for ( j=0;j<22;j++)
		{
			LCD_SetCursor(1,2+j);
			LCD_WriteString(arr);
			
			if (j>=3)
			{
				LCD_SetCursor(2,1);
				for(i=12-x;i<12;i++)
				{
					LCD_WriteChar(arr[i]);
				}
				x++;
				if(x==14)
				{
					x=0;
					break;
				}
			}
			_delay_ms(300);
			LCD_Clear();
			
		}
		
		for (j=2;j<7;j++)
		{
			LCD_SetCursor(2,j);
			LCD_WriteString(arr);
			_delay_ms(300);
			LCD_Clear();
			flag2=1;
		}
		

		
		
		
		
		
		
		
		
		
		
		
		
		
		
	}
}
*/

/*
void LCD_shift(u8*str,u8 str_length)
{
	static u8 line=1;
	static u8 cell=1;
	u8 i=1,l=1;
	
	LCD_SetCursor(line,cell);
	LCD_WriteString(str);
	_delay_ms(500);
	LCD_Clear();
	if(cell==16-str_length+1)
	{
		if(line==1)
		{
			l=2;
		}
		else
		{
			l=1;
		}
		for(i=1;str[i];i++)
		{
			cell++;
			LCD_SetCursor(line,cell);
			LCD_WriteString(str);
			LCD_SetCursor(l,1);
			LCD_WriteString(&str[str_length-i]);
			_delay_ms(500);
			LCD_Clear();
		}
	}
	if(cell==NomberOfCell)
	{
		if(line==1)
		{
			line=2;
		}
		else
		{
			line=1;
		}
		
		cell=0;
	}
	cell++;
}
*/