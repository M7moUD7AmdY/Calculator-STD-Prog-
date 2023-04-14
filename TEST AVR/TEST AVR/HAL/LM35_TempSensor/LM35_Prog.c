/*
 * LM35.c
 *
 * Created: 4/13/2023 10:39:37 PM
 *  Author: imahm
 */ 


#include "../../SERVICE/Std_types.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "LM35_Interface.h"

u16 Temp_Read(void)
{
	u16 volt=ADC_ReadVolt(LM35_CH);
	
	return volt;
}
