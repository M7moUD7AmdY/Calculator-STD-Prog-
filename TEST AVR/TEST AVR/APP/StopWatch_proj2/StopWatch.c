/*
 * StopWatch.c
 *
 * Created: 3/31/2023 9:55:14 PM
 *  Author: imahm
 */ 
/*
u8 CounterDawn(u8 num)
{
	u8 counter=num;
	for (u8 i=0;i<num;i++)
	{
		if (!(SW_Read(SW_PinsArr[SW3])))
		{
			return counter;
		}
		for(int i=0;i<500;i++)
		{
			segment_display_MLX(counter);
		}
		counter--;
		if(counter==0)
		{
			for (u8 i=0;i<5;i++)
			{
				DIO_WritePin(PINC6,HIGH);
				DIO_WritePin(PINC7,HIGH);
				DIO_WritePin(PINC5,HIGH);
				DIO_WritePort(PA,(0x3f<<1));
				_delay_ms(200);
				DIO_WritePin(PINC5,LOW);
				DIO_WritePin(PINC6,LOW);
				DIO_WritePin(PINC7,LOW);
				_delay_ms(200);
			}
		}
	}
	return counter;
}



u8 setcounter(u8 counter)
{
	
	while (1)
	{
		if(!(SW_Read(SW_PinsArr[SW1])))
		{
			counter+=10;
			if( (counter/10) > 9)
			{
				counter-=90;
			}
			
		}
		else if (!(SW_Read(SW_PinsArr[SW2])))
		{
			counter++;
			if( (counter%10) > 9)
			{
				counter-=9;
			}
		}
		else if (!(SW_Read(SW_PinsArr[SW3])))
		{
			return counter;
		}
		for(int i=0;i<100;i++)
		{
			segment_display_MLX(counter);
		}
	}
}

int main(void)
{
	DIO_Init();
	u8 counter=0;
	counter=setcounter(counter);
	while(1)
	{
		
		if(!(SW_Read(SW_PinsArr[SW3])))
		{
			counter=setcounter(counter);
		}
		else
		{
			counter = CounterDawn(counter);
		}
		
		
		
		
	}
	
	return 0;

}
*/
