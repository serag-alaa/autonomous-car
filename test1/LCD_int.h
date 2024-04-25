#ifndef LCD_INT_H
#define LCD_INT_H

void LCD_voidInit(void);
void LCD_voidSendChar(u8 LCD_u8_Data);
void LCD_voidSendCommand(u8 LCD_u8_Command);
void LCD_goto_xy (u8 line,u8 pos);
void LCD_Write_Word(u16 word[20]);

#endif