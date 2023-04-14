/*
 * DIO_interface.h
 *
 * Created: 3/25/2023 2:12:09 PM
 *  Author: imahm
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


typedef enum{
	PA,
	PB,
	PC,
	PD
}DIO_Port_type;

typedef enum{
	OUTPUT,
	INFREE,
	INPULL
	}DIO_PinStatuse_type;
	
typedef enum{
	LOW=0,
	HIGH=1		
}DIO_PinVoltage_type;



typedef enum{
	PINA0=0,
	PINA1,
	PINA2,
	PINA3,
	PINA4,
	PINA5,
	PINA6,
	PINA7,
	PINB0=8,
	PINB1,
	PINB2,
	PINB3,
	PINB4,
	PINB5,
	PINB6,
	PINB7,
	PINC0=16,
	PINC1,
	PINC2,
	PINC3,
	PINC4,
	PINC5,
	PINC6,
	PINC7,
	PIND0=24,
	PIND1,
	PIND2,
	PIND3,
	PIND4,
	PIND5,
	PIND6,
	PIND7,
	TOTAL_PINS	
}DIO_Pin_type;
void DIO_Init(void);
//PIN FUNCTIONS
Error_t DIO_InitPin(DIO_Pin_type pin,DIO_PinStatuse_type status);
Error_t DIO_WritePin(DIO_Pin_type pin,DIO_PinVoltage_type volt);
Error_t DIO_ReadPin(DIO_Pin_type pin,DIO_PinVoltage_type *volt);
Error_t DIO_ToggelPin(DIO_Pin_type pin);
//PORT FUNCTIONS
Error_t DIO_InitPort(DIO_Port_type port,DIO_PinStatuse_type status);
Error_t DIO_WritePort(DIO_Port_type port,u8 value);
Error_t DIO_ReadPort(DIO_Port_type port,u8 *pvalue);



#endif /* DIO_INTERFACE_H_ */