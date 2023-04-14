/*
 * MOTOR_CFG.c
 *
 * Created: 3/30/2023 1:23:04 PM
 *  Author: imahm
 */ 


#include "../../SERVICE/Std_types.h"
#include "../../MCAL/DIO/DIO_interface.h"

#define MOTOR_PIN_NUMBERS  3
#define MOTOR_NUMS         4

DIO_Pin_type MotorsPinsArr[MOTOR_NUMS][MOTOR_PIN_NUMBERS]={
  /*{ IN1 , IN2 ,  E }*/
	{PIND0,PIND1,PINA0},//Motor 1
	{PIND2,PIND3,PINA1},//Motor 2
	{PIND4,PIND5,PINA2},//Motor 3
	{PIND6,PIND7,PINA3}//Motor 4
	
	
};