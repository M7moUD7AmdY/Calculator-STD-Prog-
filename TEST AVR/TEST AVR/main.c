/*
 * TEST AVR.c
 *
 * Created: 3/1/2023 3:15:33 PM
 * Author : imahm
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "SERVICE/MemMap.h"
#include "SERVICE/BIT_OP.h"
#include "SERVICE/Std_types.h"
#include "MCAL/DIO/DIO_interface.h"
#include "HAL/7-SEG/SEG_interface.h"
#include "HAL/SWITCH/SW.h"
#include "CFG/SW/SW_CFG.h"
#include "HAL/MOTOR/Motor_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KeyPad/KeyPad_interface.h"
#include "APP/KEYPAD/CALC_Convert.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "APP/Controle light/control_light.h"
#include "HAL/LM35_TempSensor/LM35_Interface.h"

int main()
{
	
	app_init_CALC();
	while (1)
	{
		
		
	}
	return 0;
}
