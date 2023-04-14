/*
 * ADC_Interface.h
 *
 * Created: 4/9/2023 11:39:46 AM
 *  Author: imahm
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADJUSTMENT   L
typedef enum{
	VREF_AREF=0,
	VREF_VCC=1,
	VREF_256=3
}ADC_VREF_type;

typedef enum{
	SCALER_2=1,
	SCALER_4,
	SCALER_8,
	SCALER_16,
	SCALER_32,
	SCALER_64,
	SCALER_128
}ADC_SCALER_type;

typedef enum{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	}ADC_CHANNEL_type;


void ADC_Init(ADC_VREF_type vref,ADC_SCALER_type scaler);
u16 ADC_Read(ADC_CHANNEL_type channel);
u16 ADC_ReadVolt(ADC_CHANNEL_type channel);



#endif /* ADC_INTERFACE_H_ */