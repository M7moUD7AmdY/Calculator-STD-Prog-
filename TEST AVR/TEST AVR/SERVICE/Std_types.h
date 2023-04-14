/*
 * Std_types.h
 *
 * Created: 3/22/2023 6:29:56 PM
 *  Author: imahm
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef   signed char s8;

typedef unsigned short u16;
typedef   signed short s16;

typedef unsigned long u32;
typedef   signed long s32;

#define MAX_U8  ((u8)255)
#define MIN_U8  ((u8)0)

#define MAX_S8  ((s8)127)
#define MIN_S8  ((s8)-128)


#define MAX_U16  ((u16)65535)
#define MIN_U16  ((u16)0)

#define MAX_S16  ((s16)32767)
#define MIN_S16  ((s16)-32768)

#define MAX_U32  ((u32)4294967295)
#define MIN_U32  ((u32)0)

#define MAX_S32  ((s32)2147483647)
#define MIN_S32  ((s32)-2147483648)

#define NULLPTR   ((void *)0)

typedef enum{
FALSE=0x55,
TRUE=0x80	
}Bool_t;

typedef enum{
OK=0,
NOK,
OUT_OF_RANGE,
NULL_PTR_ERROR		
}Error_t;







#endif /* STD_TYPES_H_ */