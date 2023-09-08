#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_PRIVATE.h"
#include "Dio_Interface.h"


/*Setting Pin Direction*/
void DIO_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction)
{
	if(Copy_u8Direction==Input)
	{
		switch(Copy_u8Port)
		{
		case PORT_A: clear_bit(DDRA,Copy_u8Pin);
		break;
		case PORT_B: clear_bit(DDRB,Copy_u8Pin);
		break;
		case PORT_C: clear_bit(DDRC,Copy_u8Pin);
		break;
		case PORT_D: clear_bit(DDRD,Copy_u8Pin);
		break;


		}
	}
	else if(Copy_u8Direction==Output)
	{
		switch(Copy_u8Port)
				{
				case PORT_A: set_bit(DDRA,Copy_u8Pin);
				break;
				case PORT_B: set_bit(DDRB,Copy_u8Pin);
				break;
				case PORT_C: set_bit(DDRC,Copy_u8Pin);
				break;
				case PORT_D: set_bit(DDRD,Copy_u8Pin);
				break;


				}
	}
}

/*setting Pin value*/
void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value)
{
	if(Copy_u8Value==PinHigh)
	{
		switch(Copy_u8Port)
		{
		case PORT_A: set_bit(PORTA,Copy_u8Pin);
		break;
		case PORT_B: set_bit(PORTB,Copy_u8Pin);
		break;
		case PORT_C: set_bit(PORTC,Copy_u8Pin);
		break;
		case PORT_D: set_bit(PORTD,Copy_u8Pin);
		break;


		}
	}
	else if(Copy_u8Value==Pinlow)
	{
		switch(Copy_u8Port)
				{
				case PORT_A: clear_bit(PORTA,Copy_u8Pin);
				break;
				case PORT_B: clear_bit(PORTB,Copy_u8Pin);
				break;
				case PORT_C: clear_bit(PORTC,Copy_u8Pin);
				break;
				case PORT_D: clear_bit(PORTD,Copy_u8Pin);
				break;


				}
	}
}

/* Getting Pin Value */
void DIO_VidGetPinValue(u8 u8_port, u8 u8_pin, u8 *p_u8_data) {
	switch (u8_port) {
	case PORT_A:
		*p_u8_data = get_bit(PINA, u8_pin);
		break;
	case PORT_B:
		*p_u8_data = get_bit(PINB, u8_pin);
		break;
	case PORT_C:
		*p_u8_data = get_bit(PINC, u8_pin);
		break;
	case PORT_D:
		*p_u8_data = get_bit(PIND, u8_pin);
		break;
	}
}

/*Getting Pin Direction*/
void DIO_VidGetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *pu8Data){

			switch(Copy_u8Port)
			{
			case PORT_A: *pu8Data=get_bit(PINA,Copy_u8Pin);
			break;
			case PORT_B: *pu8Data=get_bit(PINB,Copy_u8Pin);
			break;
			case PORT_C: *pu8Data=get_bit(PINC,Copy_u8Pin);
			break;
			case PORT_D: *pu8Data=get_bit(PIND,Copy_u8Pin);
			break;


			}



}

/*Setting Pin Direction*/
void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction)
{
	if(Copy_u8Direction==Input)
	{
		switch(Copy_u8Port)
		{
		case PORT_A: DDRA=0x00;
		break;
		case PORT_B: DDRB=0x00;
		break;
		case PORT_C: DDRC=0x00;
		break;
		case PORT_D: DDRD=0x00;
		break;


		}
	}
	else if(Copy_u8Direction==Output)
	{
		switch(Copy_u8Port)
				{
				case PORT_A: DDRA=0xFF;
				break;
				case PORT_B: DDRB=0xFF;
				break;
				case PORT_C: DDRC=0xFF;
				break;
				case PORT_D: DDRD=0xFF;
				break;


				}
	}
}

/*setting Pin value*/
void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
		switch(Copy_u8Port)
		{
		case PORT_A: PORTA=Copy_u8Value;
		break;
		case PORT_B: PORTB=Copy_u8Value;
		break;
		case PORT_C: PORTC=Copy_u8Value;
		break;
		case PORT_D: PORTD=Copy_u8Value;
		break;


		}
	}

/*Getting Port Direction*/
void DIO_VidGetPortDirection(u8 Copy_u8Port,u8 *pu8Data){

			switch(Copy_u8Port)
			{
			case PORT_A: *pu8Data=PINA;
			break;
			case PORT_B: *pu8Data=PINB;
			break;
			case PORT_C: *pu8Data=PINC;
			break;
			case PORT_D: *pu8Data=PIND;
			break;


			}



}
