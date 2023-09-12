#include <avr/io.h>
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/GIE/GIE.h"

void GIE_Enabled(void)
{
	SET_BIT(SREG, SREG_I);
}

void GIE_Disabled(void)
{
	CLR_BIT(SREG, SREG_I);
}
