#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include "ADC.h"
#include <avr/io.h>
#include <util/delay.h>


void LDR() {
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN4, DIO_PIN_INPUT); // INPUT pin
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN3, DIO_PIN_OUTPUT); // Output pin (LED)
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN2, DIO_PIN_OUTPUT); // Output pin (LED)
	     f32 LDR;
	     LCD_voidClear();
	     LDR = ADC_u16ReadChannelSyn(0);
	     LDR = (LDR / 1023.0) * 100;
	     LCD_voidSendNumber(LDR);
	     if (LDR <= 40) {
	         // Turn off LEDs on pins D3 and D2
	         DIO_SetPinValue(DIO_PORTD, DIO_PIN3, DIO_PIN_LOW);
	         DIO_SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PIN_LOW);
	     } else {
	         // Turn on LEDs on pins D3 and D2
	         DIO_SetPinValue(DIO_PORTD, DIO_PIN3, DIO_PIN_HIGH);
	         DIO_SetPinValue(DIO_PORTD, DIO_PIN2, DIO_PIN_HIGH);
	     }

	     _delay_ms(100); // Delay for a moment before reading LDR again

}
