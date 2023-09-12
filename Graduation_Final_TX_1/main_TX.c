#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include "Keypad.h"
#include <util/delay.h>
#include <avr/io.h>
u8 Local_u8Key=0;

int main(void){
	DIO_SetPortDirection(DIO_PORTA, DIO_PORT_OUTPUT);

	DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN2, DIO_PIN_OUTPUT);

	UART_voidINIT_TX();
	KPD_INIT();
	CLCD_voidInit();

	UART_voidSendData_TX(1);
	UART_voidSendData_TX(0);

	while(1){
		CLCD_voidLCDClear();
		CLCD_voidSendString("Welcome to our");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("Parking Garage");
		_delay_ms(500);
		CLCD_voidLCDClear();

		CLCD_voidSendString("1.Reserve 2.Ava-");
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("3.Reserved lable");

		do {
			Local_u8Key = KPD_GetPressedKey();
		} while (Local_u8Key == 0xFF);

		switch(Local_u8Key){
		case '1':{
			reserve();
			_delay_ms(2000);
			break;
		}
		case '2':{
			available_places();
			_delay_ms(2000);
			break;
		}
		case '3':{
			reserved_places();
			_delay_ms(2000);
			break;
		}
		case '4':{
			Checkout();
			_delay_ms(2000);
			break;
		}
		default:{
			CLCD_voidLCDClear();
			CLCD_voidSendString(" Invalid Key ! ");
			_delay_ms(500);
		}
		}

	}



	return 0;
}

