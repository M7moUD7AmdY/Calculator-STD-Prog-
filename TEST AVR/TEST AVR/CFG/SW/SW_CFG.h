/*
 * SW_CFG.h
 *
 * Created: 3/30/2023 4:04:53 PM
 *  Author: imahm
 */ 


#ifndef SW_CFG_H_
#define SW_CFG_H_


typedef enum{
	SW1=0,
	SW2=1,
	SW3=2,
	SW4=3,
	TOTAL_SW
}SW_type;

DIO_Pin_type SW_PinsArr[TOTAL_SW]={PIND2,PIND3,PIND4,PINB3};


#endif /* SW_CFG_H_ */