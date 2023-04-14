/*
 * Motor_Interface.h
 *
 * Created: 3/30/2023 12:45:52 PM
 *  Author: imahm
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_



extern DIO_Pin_type MotorsPinsArr[][3];
typedef enum
{
	M1=0,
	M2=1,
	M3=2,
	M4=3,
	TOTAL_MOTORS//should be the last element	
	}MOTOR_type;
void MotorS_Init(void);
Error_t Motor_Init(MOTOR_type motor);
void Motor_CW(MOTOR_type motor);
void Motor_CCW(MOTOR_type motor);
void Motor_Stop(MOTOR_type motor);



#endif /* MOTOR_INTERFACE_H_ */