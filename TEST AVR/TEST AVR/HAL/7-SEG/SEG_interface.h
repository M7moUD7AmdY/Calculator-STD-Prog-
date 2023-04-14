/*
 * _7_SEG_interface.h
 *
 * Created: 27/03/2023 23:36:30
 *  Author: imahm
 */ 


#ifndef SEG_INTERFACE_H_
#define SEG_INTERFACE_H_

typedef enum{
COMMON_ANOD=0,
COMMON_CATHOD=1		
}Seg_type;

//Initialize the two 7-segment ports
#define SEG1_PORT PORTA
#define SEG2_PORT PORTA
//Initialize the two 7-segment(USE BCD) port
#define BCD_SEG_PORT PORTA
//Initialize the MLX 7-segment port
#define MLX_SEG_PORT PORTA
//Initialize control PORT & PINS for MLX 7-segment
#define CONTROL_SEG_PORT PORTC
#define FIRST_SEG_PIN   6
#define SECOND_SEG_PIN  7
//****************************************


//Display decimal number at two 7 segment
void segment_display_DEC(u8 n,Seg_type seg);
//Display HEX number at two 7 segment
void segment_display_HEX(u8 n,Seg_type seg);
//Display the two 7-segment(USE BCD)
void segment_display_BCD(u8 n);
//Display the two 7-segment multiplexed
void segment_display_MLX(u8 n);

 








#endif /* 7-SEG_INTERFACE_H_ */