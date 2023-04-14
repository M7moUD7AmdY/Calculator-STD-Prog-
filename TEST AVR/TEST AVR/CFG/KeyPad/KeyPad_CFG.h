/*
 * KeyPad_CFG.h
 *
 * Created: 4/6/2023 12:06:03 PM
 *  Author: imahm
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_


#define NO_KEY 'x'

#define ROWS  4
#define COLS  4

const u8 RowsPinsArr[ROWS]={PINB4,PINB5,PINB6,PINB7};
const u8 ColsPinsArr[ROWS]={PIND2,PIND3,PIND4,PIND5};

const u8 KeysArr[ROWS][COLS]={
	
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'c','0','=','+'},
	
	};



#endif /* KEYPAD_CFG_H_ */