#define F_CPU 16000000UL
#include <util\delay.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include "BIT_math.h"
#include "STD_types.h"
#include "DIO_int.h"
#include "LCD_int.h"
#include "ultrasonic_config.h"
#include "ultrasonic_int.h"
#include "GIE_int.h"
#include "EXTI_int.h"
#include "Motors_int.h"
#include "Servo_int.h"



//  Global variables
u8 sensor_working = 0;
u8 rising_edge = 0;
u32 timer_counter = 0;
u32 distance = 0;
u8 distance_str[10];

// Function prototypes
void ultrasonic_init(void);
void ultra_trigger(void);

 //Interrupt Service Routines
ISR(INT0_vect);
ISR(TIMER0_OVF_vect);

int main() {
	// Initialization
	u32 distance_right = 0;
	u32 distance_left = 0;
	Servo_init();
	Motors_Init();
	LCD_voidInit();
	ultrasonic_init();
	GIE_voidEnable();
	ultra_trigger();
	_delay_ms(100);
	
	while (1) {



			
		
			if (distance >= 51) {
			Motors_TOP_Speed();
			Servo_90_Degree();	
			
			
			}
			
	
		else if (distance<=50) {
			Motors_Stop();
			Servo_0_Degree();
			_delay_ms(2000);
			
			ultra_trigger();
			_delay_ms(15);
	
			distance_left=distance;
			
			Servo_180_Degree();
			_delay_ms(2000);
			ultra_trigger();
			_delay_ms(15);
			
			distance_right=distance;
			
			if (distance_right > distance_left) {
				Servo_90_Degree();
				_delay_ms(100);
				ultra_trigger();
				_delay_ms(15);
				
				
				
				while (distance <= distance_right)
				 {
					Motors_Left();
					
					ultra_trigger();
					_delay_ms(15);
					
				}
		
			} 
				
			if (distance_left>distance_right) {
					
					Servo_90_Degree();
					_delay_ms(100);	 
					ultra_trigger();	 
					_delay_ms(15); 
					
					while (distance <= distance_left){

					Motors_Right();
					
					ultra_trigger();
					_delay_ms(15);
					
					
				}

			}
	
	
		}
					ultra_trigger();
					_delay_ms(15);
	}            
                    	
	
}


// Trigger ultrasonic sensor
void ultra_trigger(void) {
	if (!sensor_working) {
		DIO_voidSetPinValue(Trigger_port, Trigger_pin, DIO_U8_HIGH);
		_delay_us(15);
		DIO_voidSetPinValue(Trigger_port, Trigger_pin, DIO_U8_LOW);
		sensor_working = 1;
	}
}

 //External Interrupt Service Routine
ISR(INT0_vect) {
	if (sensor_working == 1) {
		if (rising_edge == 0) {
			TCNT0 = 0x00;
			rising_edge = 1;
			timer_counter = 0;
			} else {	 
			distance = ((timer_counter * 256 )+ TCNT0) *0.0686;
			LCD_goto_xy (1, 0);
			itoa(distance, distance_str, 10);
			strcat(distance_str, " cm ");
			LCD_Write_Word(distance_str);
			timer_counter = 0;
			rising_edge = 0;
			sensor_working=0;
	
		}
	}
}

 //Timer0 Overflow Interrupt Service Routine
ISR(TIMER0_OVF_vect) {
	timer_counter++;
	if (timer_counter > 20) {
		TCNT0 = 0x00;
		sensor_working = 0;
		rising_edge = 0;
		timer_counter = 0;
	}
}
