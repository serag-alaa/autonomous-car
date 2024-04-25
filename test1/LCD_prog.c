#include "STD_types.h"
#include "LCD_int.h"
#include "DIO_int.h"
#include "LCD_config.h"
#define F_CPU 16000000UL
#include <util/delay.h>


void LCD_voidInit(void)
{
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN4 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN5 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN6 ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_DATA_PORT, DIO_U8_PIN7 ,DIO_U8_OUTPUT);
	
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_OUTPUT);
	DIO_voidSetPinDir(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_OUTPUT);
	
	_delay_ms(35);
	LCD_voidSendCommand(0x33);
	_delay_ms(2);
	LCD_voidSendCommand(0x32);
	_delay_ms(2);
	LCD_voidSendCommand(0x28);
	_delay_ms(2);
	LCD_voidSendCommand(0x0c);
	_delay_ms(2);
	LCD_voidSendCommand(0x06);
	_delay_ms(2);
	LCD_voidSendCommand(0x01);
	_delay_ms(2);
}
void LCD_voidSendChar(u8 LCD_u8_Data)
{
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_HIGH);
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Data);
	
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Data << 4);
	
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}

void LCD_voidSendCommand(u8 LCD_u8_Command)
{
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_RS ,DIO_U8_LOW);
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_RW ,DIO_U8_LOW);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Command);
	
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
	
	DIO_voidSetPortValue(LCD_U8_DATA_PORT , LCD_u8_Command << 4);
	
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_U8_CONTROL_PORT, LCD_U8_EN ,DIO_U8_LOW);
	_delay_ms(1);
}
void LCD_goto_xy (u8 line,u8 pos)				//line = 0 or 1
{
	LCD_voidSendCommand((0x80|(line<<6))+pos);
	_delay_us (50);
}
void LCD_Write_Word(u16 word[20])
{
	u16 i=0;
	while(word[i]!='\0')
	{
		LCD_voidSendChar(word[i]);
		i++;
	}
}