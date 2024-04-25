#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER1_int.h"
#include "TIMER1_priv.h"
#include "TIMER1_cong.h"
#include <avr/interrupt.h>



void TIMER1_void_Init(void)
{
	
	
	#if(TIMER1_MODE == TIMER1_FAST_PWM)
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
		
	#elif(TIMER1_MODE == TIMER1_FAST_PWM_ICR)
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
		
	#endif
	
	
	#if(TIMER1_PRESCALER == TIMER1_DIV_BY_64)
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		CLEAR_BIT(TCCR1B,2);
	#endif
	
	
	#if(TIMER1_COM_EVENT == TIMER1_INVERTED )
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,6);
		SET_BIT(TCCR1A,4);
	#elif(TIMER1_COM_EVENT ==  TIMER1_NON_INVERTED)
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,6);
		CLEAR_BIT(TCCR1A,4);
	#endif
	
	TCNT1 =0 ;
	OCR1A = 0;
	 ICR1 = 4999;
	
		
	
}
void TIMER1_void_SetCompareVal(u16 Copy_u8Val)
{
	OCR1A = Copy_u8Val ;
}
