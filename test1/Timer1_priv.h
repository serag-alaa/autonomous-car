#ifndef _TIMRER1_priv_H
#define _TIMRER1_priv_H

#define TCCR1A (*(volatile u8 * )0x4F)
#define TCCR1B (*(volatile u8 * )0x4E)
#define OCR1A (*(volatile u16 * )0x4A)
#define ICR1 (*(volatile u16 * )0x46)
#define OCR1BL (*(volatile u8 * )0x48)
#define TCNT1 (*(volatile u8 * )0x4C)
#define TIMSK (*(volatile u8 * )0x59)
#define TIFR (*(volatile u8 * )0x58)

#define SFIOR (*(volatile u8 * )0x50)




#define TIMER1_FAST_PWM 	0

#define	TIMER1_FAST_PWM_ICR 3

#define	TIMER1_INVERTED		4

#define TIMER1_DIV_BY_64    1


#define TIMER1_NON_INVERTED  2



#endif