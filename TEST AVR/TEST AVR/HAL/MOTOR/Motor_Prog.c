/*
 * Motor_Prog.c
 *
 * Created: 3/30/2023 12:45:26 PM
 *  Author: imahm
 */ 

#include "../../SERVICE/Std_types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "Motor_Interface.h"


Error_t Motor_Init(MOTOR_type motor)
{
	if ((motor >=TOTAL_MOTORS)||(motor<M1))return OUT_OF_RANGE;
	
	DIO_WritePin(MotorsPinsArr[motor][2],HIGH);
	return OK;
}


void Motor_CW(MOTOR_type motor)
{
	DIO_WritePin(MotorsPinsArr[motor][0],HIGH);
	DIO_WritePin(MotorsPinsArr[motor][1],LOW);	
}


void Motor_CCW(MOTOR_type motor)
{
	DIO_WritePin(MotorsPinsArr[motor][0],LOW);
	DIO_WritePin(MotorsPinsArr[motor][1],HIGH);	
}

void Motor_Stop(MOTOR_type motor)
{
	DIO_WritePin(MotorsPinsArr[motor][0],LOW);
	DIO_WritePin(MotorsPinsArr[motor][1],LOW);
}

void MotorS_Init(void)
{
	for (u8 i=0;i<TOTAL_MOTORS;i++)
	{
		Motor_Init(i);
	}
}
