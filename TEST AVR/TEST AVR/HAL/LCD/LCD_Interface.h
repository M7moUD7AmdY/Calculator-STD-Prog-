/*
 * LCD_Prog.h
 *
 * Created: 4/1/2023 4:02:57 PM
 *  Author: imahm
 */ 


#ifndef LCD_PROG_H_
#define LCD_PROG_H_



void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8 *str);
void LCD_WriteNumber(s32 num);
void LCD_WriteBinary(s8 num);
void LCD_WriteHex(u8 num);
void LCD_SetCursor(u8 line,u8 cell);
void LCD_Clear(void);
void LCD_SpecialShape(u8 *shap,u8 CGRam_addres);
void LCD_ClearLOC(u8 line,u8 cell,u8 num);
void LCD_WriteNumber_recersive(s32 num);
void LCD_WriteNumber_4D(u16);


#endif /* LCD_PROG_H_ */