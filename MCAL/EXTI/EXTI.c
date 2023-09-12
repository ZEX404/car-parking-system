#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI.h"
#include<avr/io.h>

void EXTI_void_INT0(void)
{
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);
  
	SET_BIT(GICR, GICR_INT0);
}
