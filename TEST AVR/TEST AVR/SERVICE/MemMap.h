


#ifndef MEMMAP_H_
#define MEMMAP_H_
/***************(DIO_MEMORY_MAP)****************/
//************************************************
//PORT>>A
#define DDRA    (*(volatile unsigned char *)0x3A)
#define PORTA   (*(volatile unsigned char *)0x3B)
#define PINA    (*(volatile unsigned char *)0x39)
//PORT>>B
#define DDRB    (*(volatile unsigned char *)0x37)
#define PORTB   (*(volatile unsigned char *)0x38)
#define PINB    (*(volatile unsigned char *)0x36)
//PORT>>C
#define DDRC    (*(volatile unsigned char *)0x34)
#define PORTC   (*(volatile unsigned char *)0x35)
#define PINC    (*(volatile unsigned char *)0x33)
//PORT>>D
#define   DDRD    (*(volatile unsigned char *)0x31)
#define   PORTD   (*(volatile unsigned char *)0x32)
#define   PIND    (*(volatile unsigned char *)0x30)
//************************************************
/***************(ADC_MEMORY_MAP)*****************/
//***********************************************
//ADMUX to select Vref  and reading pin and reading register 
#define   ADMUX   (*(unsigned volatile char *)0x27)
#define   REFS1   7 //select Vref
#define   REFS0   6 //select Vref
#define   ADLAR   5 //read lift or right
#define   MUX4    4 //select pin
#define   MUX3    3 //select pin
#define   MUX2    2 //select pin
#define   MUX1    1 //select pin
#define   MUX0    0 //select pin
//ADCSRA
#define   ADCSRA  (*(unsigned volatile char*)0x26) 
#define   ADEN    7//enable ADC
#define   ADSC    6
#define   ADATE   5
#define   ADIF    4
#define   ADIE    3
#define   ADPS2   2//Select Scaler
#define   ADPS1   1//Select Scaler
#define   ADPS0   0//Select Scaler

#define  ADCH    (*(unsigned volatile char*)0x25)
#define  ADCL    (*(unsigned volatile char*)0x24) 


#endif /* MEMORYMAP_H_ */