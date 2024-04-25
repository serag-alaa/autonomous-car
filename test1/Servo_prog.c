#define F_CPU 16000000UL
#include <util\delay.h>
#include "BIT_math.h"
#include "STD_types.h"
#include "DIO_Reg.h"
#include "DIO_int.h"
#include "Timer1_cong.h"
#include "Timer1_priv.h"
#include "Timer1_int.h"

#include "Servo_config.h"




void Servo_0_Degree()
{
	OCR1A=	249;
}



void Servo_90_Degree()
{
	OCR1A=374;
}




void Servo_180_Degree()
{
	OCR1A=499;
}


void Servo_init()
{
	DIO_voidSetPinDir(Servo_Control_Port,Servo_Control_Pin,DIO_U8_OUTPUT);
	TIMER1_void_Init();
	Servo_90_Degree();
}
