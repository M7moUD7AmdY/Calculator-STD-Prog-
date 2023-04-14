/*
 * DIO_interface.c
 *
 * Created: 3/24/2023 3:14:09 PM
 *  Author: imahm
 */ 

#include "../../SERVICE/Std_types.h"
#include "../../SERVICE/MemMap.h"
#include "../../SERVICE/BIT_OP.h"
#include "DIO_interface.h"
#include "DIO_Privet.h"
/**************************PIN_FUNCTIONS*********************************/
void DIO_Init(void)
{
	DIO_Pin_type i;
	for(i=PINA0;i<TOTAL_PINS;i++)
	{
		DIO_InitPin2(i,PinStatusArr[i]);
		
	}
	
}

Error_t DIO_InitPin(DIO_Pin_type pin,DIO_PinStatuse_type status)
{
	switch (status)
	{
		case OUTPUT:
		{
			if ((pin>=PINA0) && (pin<=PINA7))
			{
				SET_BIT(DDRA,pin);
			}
			else if((pin>=PINB0) && (pin<=PINB7))
			{
				pin=pin-PINB0;
				SET_BIT(DDRB,pin);
			}
			else if((pin>=PINC0) && (pin<=PINC7))
			{
				pin=pin-PINC0;
				SET_BIT(DDRC,pin);
			}
			else if((pin>=PIND0) && (pin<=PIND7))
			{
				pin=pin-PIND0;
				SET_BIT(DDRD,pin);
			}
			else
			{
				return NOK;
			}
		}
		break;
		
		case INFREE:
		{
			if ((pin>=PINA0) && (pin<=PINA7))
			{
				CLR_BIT(DDRA,pin);
			}
			else if((pin>=PINB0) && (pin<=PINB7))
			{
				pin=pin-PINB0;
				CLR_BIT(DDRB,pin);
			}
			else if((pin>=PINC0) && (pin<=PINC7))
			{
				pin=pin-PINC0;
				CLR_BIT(DDRC,pin);
			}
			else if((pin>=PIND0) && (pin<=PIND7))
			{
				pin=pin-PIND0;
				CLR_BIT(DDRD,pin);
			}
			else
			{
				return NOK;
			}
			
		}
		break;
		case INPULL:
		{
			if ((pin>=PINA0) && (pin<=PINA7))
			{
				CLR_BIT(DDRA,pin);
				SET_BIT(PORTA,pin);
			}
			else if((pin>=PINB0) && (pin<=PINB7))
			{
				pin=pin-PINB0;
				CLR_BIT(DDRB,pin);
				SET_BIT(PORTB,pin);
			}
			else if((pin>=PINC0) && (pin<=PINC7))
			{
				pin=pin-PINC0;
				CLR_BIT(DDRC,pin);
				SET_BIT(PORTC,pin);
			}
			else if((pin>=PIND0) && (pin<=PIND7))
			{
				pin=pin-PIND0;
				CLR_BIT(DDRD,pin);
				SET_BIT(PORTD,pin);
			}
			else
			{
				return NOK;
			}
			
		}
		break;
		default:
		{
			return NOK;
		}
		break;
		
	}
	return OK;
	
}

Error_t DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt)
{
	switch(volt)
	{
		case LOW:
		{
			if ((pin>=PINA0) && (pin<=PINA7))
			{
				CLR_BIT(PORTA,pin);
			}
			else if((pin>=PINB0) && (pin<=PINB7))
			{
				pin=pin-PINB0;
				CLR_BIT(PORTB,pin);
			}
			else if((pin>=PINC0) && (pin<=PINC7))
			{
				pin=pin-PINC0;
				CLR_BIT(PORTC,pin);
			}
			else if((pin>=PIND0) && (pin<=PIND7))
			{
				pin=pin-PIND0;
				CLR_BIT(PORTD,pin);
			}
			else
			{
				return NOK;
		    }
	     }
		break;
		
		case HIGH:
		{
			if ((pin>=PINA0) && (pin<=PINA7))
			{
				SET_BIT(PORTA,pin);
			}
			else if((pin>=PINB0) && (pin<=PINB7))
			{
				pin=pin-PINB0;
				SET_BIT(PORTB,pin);
			}
			else if((pin>=PINC0) && (pin<=PINC7))
			{
				pin=pin-PINC0;
				SET_BIT(PORTC,pin);
			}
			else if((pin>=PIND0) && (pin<=PIND7))
			{
				pin=pin-PIND0;
				SET_BIT(PORTD,pin);
			}
			else
			{
				return NOK;
			}
		}
		break;
		default:
		{
			return NOK;
		}
		break;
		
		}
		return OK;
		
	}
		
Error_t DIO_ReadPin(DIO_Pin_type pin,DIO_PinVoltage_type *pvolt)
{
	if(pvolt==NULLPTR)return NULL_PTR_ERROR;
	
	
	if ((pin>=PINA0) && (pin<=PINA7))
	{
		pin=pin-PINA0;
		*pvolt=READ_BIT(PORTA,pin);
	}
	else if((pin>=PINB0) && (pin<=PINB7))
	{
		pin=pin-PINB0;
		*pvolt=READ_BIT(PINB,pin);
	}
	else if((pin>=PINC0) && (pin<=PINC7))
	{
		pin=pin-PINC0;
		*pvolt=READ_BIT(PINC,pin);
	}
	else if((pin>=PIND0) && (pin<=PIND7))
	{
		pin=pin-PIND0;
		*pvolt=READ_BIT(PIND,pin);
	}
	else
	{
		return NOK;
	}
	
	return OK;
}

Error_t DIO_ToggelPin(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	switch (port)
	{
		
			case PA:
			TOG_BIT(PORTA,pin_num);
			break;
			case PB:
			TOG_BIT(PORTB,pin_num);
			break;
			case PC:
			TOG_BIT(PORTC,pin_num);
			break;
			case PD:
			TOG_BIT(PORTD,pin_num);
			break;
			default:
			return NOK;
			break;
	}
	return OK;
}

/***********************************PORT_FUNCTIONS*************************/
Error_t DIO_InitPort(DIO_Port_type port,DIO_PinStatuse_type status)
{
			switch(status)
			{
				case OUTPUT:
				switch (port)
				{
					case PA:
					DDRA=0XFF;
					break;
					case PB:
					DDRB=0XFF;
					break;
					case PC:
					DDRC=0XFF;
					break;
					case PD:
					DDRD=0XFF;
					break;
					default:
					return NOK;
					break;
				}
				break;
				case INFREE:
				switch (port)
				{
					case PA:
					DDRA=0X00;
					break;
					case PB:
					DDRB=0X00;
					break;
					case PC:
					DDRC=0X00;
					break;
					case PD:
					DDRD=0X00;
					break;
					default:
					return NOK;
					break;
				}
				break;
				case INPULL:
				switch (port)
				{
					case PA:
					DDRA=0X00;
					PORTA=0xFF;
					break;
					case PB:
					DDRB=0X00;
					PORTB=0xFF;
					break;
					case PC:
					DDRC=0X00;
					PORTC=0xFF;
					break;
					case PD:
					DDRD=0X00;
					PORTD=0xFF;
					break;
					default:
					return NOK;
					break;
				}
				break;
				default:
				return NOK;
				break;
				
			}
			return OK;
}

Error_t DIO_WritePort(DIO_Port_type port,u8 value)
{
	switch (port)
	{
		case PA:
		{
			PORTA=value;
		}
		break;
		case PB:
		{
			PORTB=value;
		}
		break;
		case PC:
		{
			PORTC=value;
		}
		break;
		case PD:
		{
		 PORTD=value;	
		}
		break;
		default:
		{
			return NOK;
		}
		break;
	}
	return OK;
	
}
	
Error_t DIO_ReadPort(DIO_Port_type port,u8 *pvalue)
{ 
	if (pvalue ==NULLPTR)
	{return NULL_PTR_ERROR;
	}
	
	switch (port)
	{
		case PA:
		{
			*pvalue=PINA;	
		}
		break;
		case PB:
		{
		    *pvalue=PINB;
		}
		break;
		case PC:
		{
			*pvalue=PINC;
		}
		break;
		case PD:
		{
			*pvalue=PIND;
		}
		break;
		default:
		{
			return NOK;
		}
		break;
		
		
	}
	return OK;
	
	
}

//*****************************************************************
//DIO PIN INIT WITH IDEA AND STATIC
static Error_t DIO_InitPin2(DIO_Pin_type pin,DIO_PinStatuse_type status)
{
	DIO_Port_type PORT=pin/8;
	u8 pin_num=pin%8;
	switch(status)
	{
		case OUTPUT:
		{
			switch (PORT)
			{
				case PA:
				SET_BIT(DDRA,pin_num);
				break;
				case PB:
				SET_BIT(DDRB,pin_num);
				break;
				case PC:
				SET_BIT(DDRC,pin_num);
				break;
				case PD:
				SET_BIT(DDRD,pin_num);
				break;
				default:
				return NOK;
				break;
			}
		}
		break;
		case INFREE:
		{
			switch (PORT)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				break;
				default:
				return NOK;
				break;
			}
		}
		break;
		case INPULL:
		{
			switch (PORT)
			{
				case PA:
				CLR_BIT(DDRA,pin_num);
				SET_BIT(PORTA,pin_num);
				break;
				case PB:
				CLR_BIT(DDRB,pin_num);
				SET_BIT(PORTB,pin_num);
				break;
				case PC:
				CLR_BIT(DDRC,pin_num);
				SET_BIT(PORTC,pin_num);
				break;
				case PD:
				CLR_BIT(DDRD,pin_num);
				SET_BIT(PORTD,pin_num);
				break;
				default:
				return NOK;
				break;
			}
		}
		break;
		
	}
	
	return OK;
}