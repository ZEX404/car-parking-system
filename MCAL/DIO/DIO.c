#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO.h"
#include <avr/io.h>
#include <util/delay.h>

void DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy)
{
	if (u8PortIdCopy <= DIO_PORTD){
		if (u8PinIdCopy <= DIO_PIN7){
			if (u8PinDirCopy == DIO_OUTPUT){
				switch(u8PortIdCopy)
				{
					case DIO_PORTA: SET_BIT(DDRA,u8PinIdCopy);break;
					case DIO_PORTB: SET_BIT(DDRB,u8PinIdCopy);break;
					case DIO_PORTC: SET_BIT(DDRC,u8PinIdCopy);break;
					case DIO_PORTD: SET_BIT(DDRD,u8PinIdCopy);break;

				}
			}
			else if (u8PinDirCopy == DIO_INPUT){
				switch(u8PortIdCopy)
				{
					case DIO_PORTA: CLR_BIT(DDRA,u8PinIdCopy);break;
					case DIO_PORTB: CLR_BIT(DDRB,u8PinIdCopy);break;
					case DIO_PORTC: CLR_BIT(DDRC,u8PinIdCopy);break;
					case DIO_PORTD: CLR_BIT(DDRD,u8PinIdCopy);break;

				}
			}

		}
	}
}


void DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PortDirCopy)
{
	if (u8PortIdCopy <= DIO_PORTD)
	{
		if (u8PortDirCopy == DIO_OUTPUT)
		{
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: DDRA = 0xFF; break; // Set all pins of Port A as OUTPUT
				case DIO_PORTB: DDRB = 0xFF; break; // Set all pins of Port B as OUTPUT
				case DIO_PORTC: DDRC = 0xFF; break; // Set all pins of Port C as OUTPUT
				case DIO_PORTD: DDRD = 0xFF; break; // Set all pins of Port D as OUTPUT
			}
		}
		else if (u8PortDirCopy == DIO_INPUT)
		{
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: DDRA = 0x00; break; // Set all pins of Port A as INPUT
				case DIO_PORTB: DDRB = 0x00; break; // Set all pins of Port B as INPUT
				case DIO_PORTC: DDRC = 0x00; break; // Set all pins of Port C as INPUT
				case DIO_PORTD: DDRD = 0x00; break; // Set all pins of Port D as INPUT
			}
		}

	}
}





void DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValueCopy)
{
	if (u8PortIdCopy <= DIO_PORTD && u8PinIdCopy <= DIO_PIN7)
	{
		if (u8PinValueCopy == DIO_HIGH)
		{
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: SET_BIT(PORTA, u8PinIdCopy); break;
				case DIO_PORTB: SET_BIT(PORTB, u8PinIdCopy); break;
				case DIO_PORTC: SET_BIT(PORTC, u8PinIdCopy); break;
				case DIO_PORTD: SET_BIT(PORTD, u8PinIdCopy); break;
			}
		}
		else if (u8PinValueCopy == DIO_LOW)
		{
			switch (u8PortIdCopy)
			{
				case DIO_PORTA: CLR_BIT(PORTA, u8PinIdCopy); break;
				case DIO_PORTB: CLR_BIT(PORTB, u8PinIdCopy); break;
				case DIO_PORTC: CLR_BIT(PORTC, u8PinIdCopy); break;
				case DIO_PORTD: CLR_BIT(PORTD, u8PinIdCopy); break;
			}
		}

	}
}


void DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PortValueCopy)
{
	if (u8PortIdCopy <= DIO_PORTD)
	{
		switch (u8PortIdCopy)
		{
			case DIO_PORTA: PORTA = u8PortValueCopy; break;
			case DIO_PORTB: PORTB = u8PortValueCopy; break;
			case DIO_PORTC: PORTC = u8PortValueCopy; break;
			case DIO_PORTD: PORTD = u8PortValueCopy; break;
		}
	}
}



u8 DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy)
{
	u8 u8Result = 0;
	
	if (u8PortIdCopy <= DIO_PORTD && u8PinIdCopy <= DIO_PIN7)
	{
		switch (u8PortIdCopy)
		{
			case DIO_PORTA: u8Result = GET_BIT(PINA, u8PinIdCopy); break;
			case DIO_PORTB: u8Result = GET_BIT(PINB, u8PinIdCopy); break;
			case DIO_PORTC: u8Result = GET_BIT(PINC, u8PinIdCopy); break;
			case DIO_PORTD: u8Result = GET_BIT(PIND, u8PinIdCopy); break;
		}
	}
	
	return u8Result;
}
