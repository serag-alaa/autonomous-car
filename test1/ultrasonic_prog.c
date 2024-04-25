#include "STD_types.h"
#include "BIT_math.h"
#include "EXTI_int.h"
#include "DIO_int.h"
#include "Timer0_int.h"
#include "ultrasonic_int.h"
#include "ultrasonic_config.h"




void ultrasonic_init(void) {
	EXTI0_voidInit();
	EXTI0_voidEnable();
	DIO_voidSetPinDir(Trigger_port, Trigger_pin, DIO_U8_OUTPUT);
	DIO_voidSetPinDir(echo_port, echo_pin, DIO_U8_INPUT);
	//DIO_voidSetPinValue(echo_port, echo_pin, DIO_U8_HIGH);
	TIMER0_void_Init();
	TIMER0_void_EnableOVInt();
}