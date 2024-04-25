  #define  F_CPU 16000000UL
  #include <util\delay.h>
  #include "BIT_math.h"
  #include "STD_types.h"
  #include "DIO_Reg.h"
  #include "DIO_int.h"
  #include "Motors_config.h"

  
  

  
 
  
  
 void Motors_Init(void)
  {
	 
	  
	 
	  DIO_voidSetPinDir(Motor1_INT1_Port , Motor1_INT1_pin , DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(Motor1_INT2_Port , Motor1_INT2_pin , DIO_U8_OUTPUT);
	  
	   DIO_voidSetPinValue(Motor1_INT1_Port , Motor1_INT1_pin , DIO_U8_HIGH);
	   DIO_voidSetPinValue(Motor1_INT2_Port , Motor1_INT2_pin , DIO_U8_LOW);
	  /*---------------------------------------------------------------------*/
	  DIO_voidSetPinDir(Motor2_INT3_Port , Motor2_INT3_pin , DIO_U8_OUTPUT);
	  DIO_voidSetPinDir(Motor2_INT4_Port , Motor2_INT4_pin , DIO_U8_OUTPUT);
	  
	   DIO_voidSetPinValue(Motor2_INT3_Port , Motor2_INT3_pin , DIO_U8_HIGH);
	   DIO_voidSetPinValue(Motor2_INT4_Port , Motor2_INT4_pin , DIO_U8_LOW);

	  
  }
  
  
  
  void Motors_Stop ()
  {
	  DIO_voidSetPinValue(Motor1_INT1_Port , Motor1_INT1_pin , DIO_U8_LOW);
	  DIO_voidSetPinValue(Motor1_INT2_Port , Motor1_INT2_pin , DIO_U8_LOW);
	  
	  
	 DIO_voidSetPinValue(Motor2_INT3_Port , Motor2_INT3_pin , DIO_U8_LOW);
	 DIO_voidSetPinValue(Motor2_INT4_Port , Motor2_INT4_pin , DIO_U8_LOW);
  }
  
  
  
  

  
  void Motors_TOP_Speed()
  {
	  
	   DIO_voidSetPinValue(Motor1_INT1_Port , Motor1_INT1_pin , DIO_U8_HIGH);
	   DIO_voidSetPinValue(Motor1_INT2_Port , Motor1_INT2_pin , DIO_U8_LOW);
	  
	  
	  DIO_voidSetPinValue(Motor2_INT3_Port , Motor2_INT3_pin , DIO_U8_HIGH);
	  DIO_voidSetPinValue(Motor2_INT4_Port , Motor2_INT4_pin , DIO_U8_LOW);
  }
  
  

  
  void Motors_Left()
  {
	   DIO_voidSetPinValue(Motor1_INT1_Port , Motor1_INT1_pin , DIO_U8_LOW);
	   DIO_voidSetPinValue(Motor1_INT2_Port , Motor1_INT2_pin , DIO_U8_LOW);
	   
	   DIO_voidSetPinValue(Motor2_INT3_Port , Motor2_INT3_pin , DIO_U8_HIGH);
	   DIO_voidSetPinValue(Motor2_INT4_Port , Motor2_INT4_pin , DIO_U8_LOW); 
	  
	  	  
  }
  
  
  
  
  void Motors_Right()
  {
	  
	  DIO_voidSetPinValue(Motor1_INT1_Port , Motor1_INT1_pin , DIO_U8_HIGH);
	  DIO_voidSetPinValue(Motor1_INT2_Port , Motor1_INT2_pin , DIO_U8_LOW);
	  
	  
	  
	 DIO_voidSetPinValue(Motor2_INT3_Port , Motor2_INT3_pin , DIO_U8_LOW);
	 DIO_voidSetPinValue(Motor2_INT4_Port , Motor2_INT4_pin , DIO_U8_LOW);
	  
  }