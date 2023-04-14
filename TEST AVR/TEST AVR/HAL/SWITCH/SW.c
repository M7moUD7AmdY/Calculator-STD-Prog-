/*
 * SW.c
 *
 * Created: 3/30/2023 2:18:27 PM
 *  Author: imahm
 */ 
#define F_CPU 8000000
#include <util/delay.h>
#include "../../SERVICE/Std_types.h"
#include "../../SERVICE/BIT_OP.h"
#include "../../SERVICE/MemMap.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SW.h"
void SW_init()
{
	
}
DIO_PinVoltage_type SW_Read(DIO_Pin_type pin)
{
	u8 volt=0;
	_delay_ms(10);
	 DIO_ReadPin(pin,&volt);
	return volt;
}