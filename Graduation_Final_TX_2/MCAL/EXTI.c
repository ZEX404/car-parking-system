#include <avr/io.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "EXTI.h"

void EXTI_void_INT0(void)
{
	SET_BIT(MCUCR, MCUCR_ISC01);
	CLR_BIT(MCUCR, MCUCR_ISC00);
  
	SET_BIT(GICR, GICR_INT0);
}
