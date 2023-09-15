/*
 * GIE.c
 *
 *  Created on: Aug 23, 2023
 *      Author: M
 */

#include "../LIB/BIT_MATH.h"
#include "GIE.h"
#include <avr/io.h>

void GIE_void_Enabled(void){
	SET_BIT(SREG, SREG_GIE);
}
void GIE_void_Disabled(void){
	CLR_BIT(SREG, SREG_GIE);
}
