/*
 * ADC_Prog.c
 *
 * Created: 4/9/2023 11:39:29 AM
 *  Author: imahm
 */ 
#define F_CPU 8000000UL
#include <util/delay.h>
#include "../../SERVICE/BIT_OP.h"
#include "../../SERVICE/Std_types.h"
#include "../../SERVICE/MemMap.h"
#include "ADC_Interface.h"


void ADC_Init(ADC_VREF_type vref,ADC_SCALER_type scaler)
{
	/***VREF***/
	vref<<=6;//shifting
	vref|=0x3F;//masking
	ADMUX&=vref;//selecting
	//MORE OPTMIZATION
	//***********************************************
	/*
	switch (vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		break;
		case VREF_VCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		case VREF_256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;	
	}*/
	//*********************************************
	/***Select Adjustment***/
	/*get reading from 2 registers*/
	#if ADJUSTMENT==R
	CLR_BIT(ADMUX,ADLAR );
	#else
	SET_BIT(ADMUX,ADLAR );
	#endif
	/***CLk***/
	ADCSRA&=0xF8;//0b11111000 masking to make sure that last 3 bit =0
	scaler&=0x07;//0b00000111 masking to make sure that scaler not more than 7
	ADCSRA=ADCSRA|scaler;
	/**ADC_Enable**/
	SET_BIT(ADCSRA,ADEN);
	
}
u16 ADC_Read(ADC_CHANNEL_type channel)
{
	u16 adc=0;
	/*Select channel*/
	ADMUX&=0xE0;//E for single conversion
	//channel&=0x0E;
	ADMUX|=channel;
	/*start conversion*/
	SET_BIT(ADCSRA,ADSC);
	/*wait until end*/
	while(READ_BIT(ADCSRA,ADSC));
	//_delay_ms(1);
	CLR_BIT(ADCSRA,ADSC);
	/*get reading from 2 registers*/ 
 	#if ADJUSTMENT==R
 	 adc=(u16)ADCL+((u16)ADCH<<8);
 	#else
	 adc=((u16)ADCL>>6)+((u16)ADCH<<2);
	#endif
	return  adc;
	
}

u16 ADC_ReadVolt(ADC_CHANNEL_type channel)
{
	u16 adc=ADC_Read(channel);
	u16 volt=(adc*(u32)5000)/1023;
	return volt;
}
