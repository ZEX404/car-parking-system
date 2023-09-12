#define  F_CPU 8000000UL
#include "STD_TYPES.h"
#include "CLCD.h"
#include "DIO.h"
#include "UART_TX.h"

u8 Local_u8Key, array_places[4], flag = 0;
/* Prototype Functions */
void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	// Set Low to set command
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_PIN_LOW);

	// Write (send command) --> 0 , Read --> 1
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPortValue(CLCD_DATA_PORT, Copy_u8Command);

	// E pulse high for 2ms then low pulse
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_PIN_LOW);
}

/* Print char by char */
void CLCD_voidSendData (u8 Copy_u8Data){
	// Set High to set data
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_PIN_HIGH);

	// Write (send command) --> 0 , Read --> 1
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_PIN_LOW);
	DIO_SetPortValue(CLCD_DATA_PORT, Copy_u8Data);

	// E pulse high for 2ms then low pulse
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_PIN_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_PIN_LOW);
}

void CLCD_voidInit(void){
	/* Delay more that 30 seconds*/
	_delay_ms(40);
	/* Command for font size 5*8 */
	CLCD_voidSendCommand(0b00111000);
	/* Display On or Off*/
	CLCD_voidSendCommand(0b00001100);
	/* Clear Display */
	CLCD_voidSendCommand(1);

}

/* Send String */
void CLCD_voidSendString(const char* Copy_pcString) {
	u8 i = 0;
	while (Copy_pcString[i] != '\0') {
		CLCD_voidSendData(Copy_pcString[i]);
		i++;

		// Delay between characters (adjust as needed)
		_delay_ms(10);
	}
}


/* Go to position (x , y)*/
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos){

	u8 Local_u8Address;
	if (Copy_u8XPos == 0){
		Local_u8Address = Copy_u8YPos;
	}
	else if (Copy_u8XPos == 1){
		Local_u8Address = Copy_u8YPos + 0x40;
	}
	CLCD_voidSendCommand(Local_u8Address + 128);
}

/* LCD Clear */
void CLCD_voidLCDClear(void){
	CLCD_voidSendCommand(1);
}

void reserve(void){
	CLCD_voidLCDClear();
	CLCD_voidSendString("You can choose");
	CLCD_voidGoToXY(1,0);
	CLCD_voidSendString("from these slots");
	CLCD_voidGoToXY(0,13);
	_delay_ms(1000);

	int reserved = 0;
	while (reserved == 0) {
		CLCD_voidLCDClear();
		available_places();
		_delay_ms(1000);
		CLCD_voidLCDClear();
		CLCD_voidSendString(" Choose a slot ");

		do {
			Local_u8Key = KPD_GetPressedKey();
		} while (Local_u8Key == 0xFF);

		switch(Local_u8Key){
		case '1':
			CLCD_voidLCDClear();
			CLCD_voidSendString("  Slot Number 1 ");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("   is reserved  ");
			reserved = 1;
			array_places[0] = 1;
			_delay_ms(1000);
			CLCD_voidLCDClear();

			CLCD_voidSendString("  Opening Gate  ");
			UART_voidSendData_TX(SIGNAL_OPENGATE);
			_delay_ms(1000);
			break;
		case '2':
			CLCD_voidLCDClear();
			CLCD_voidSendString("  Slot Number 2 ");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("   is reserved  ");
			reserved = 1;
			array_places[1] = 2;
			_delay_ms(1000);
			CLCD_voidLCDClear();

			CLCD_voidSendString("  Opening Gate  ");
			UART_voidSendData_TX(SIGNAL_OPENGATE);
			_delay_ms(1000);
			break;
		case '3':
			CLCD_voidLCDClear();
			CLCD_voidSendString("  Slot Number 3 ");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("   is reserved  ");
			reserved = 1;
			array_places[2] = 3;
			_delay_ms(1000);

			CLCD_voidLCDClear();
			CLCD_voidSendString("  Opening Gate  ");
			UART_voidSendData_TX(SIGNAL_OPENGATE);
			_delay_ms(1000);
			break;
		case '4':
			CLCD_voidLCDClear();
			CLCD_voidSendString("  Slot Number 4 ");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("   is reserved  ");
			reserved = 1;
			array_places[3] = 4;
			_delay_ms(1000);
			CLCD_voidLCDClear();

			CLCD_voidSendString("  Opening Gate  ");
			UART_voidSendData_TX(SIGNAL_OPENGATE);
			_delay_ms(1000);
			break;

		default:{
			CLCD_voidLCDClear();
			CLCD_voidSendString(" Invalid Key ! ");
			_delay_ms(500);

		}
		}

	}


}

void reserved_places(void){
	CLCD_voidLCDClear();
	CLCD_voidSendString("Reserved places");
	char place_str[2];  // Assuming a place number is a single digit
	for (int i = 0; i < 4; i++) {
		if (array_places[i] == i + 1) {
			sprintf(place_str, "%d", array_places[i]);
			CLCD_voidGoToXY(1, 2*i+3);
			CLCD_voidSendString(place_str);
		}
	}
}

void available_places(void){
	CLCD_voidLCDClear();
	CLCD_voidSendString("Available places");
	char place_str[2];  // Assuming a place number is a single digit
	for (int i = 0; i < 4; i++) {
		if (array_places[i] != i + 1) {
			sprintf(place_str, "%d", i+1);
			CLCD_voidGoToXY(1, 2*i+3);
			CLCD_voidSendString(place_str);
		}
	}
}

void Checkout(void){
	while(flag != 1){
		CLCD_voidLCDClear();
		CLCD_voidSendString("Enter Slot Number");

		do {
			Local_u8Key = KPD_GetPressedKey();
		} while (Local_u8Key == 0xFF);

		switch(Local_u8Key){
		case '1':
		case '2':
		case '3':
		case '4':{
			flag = 1;
			break;
		}
		default:{
			CLCD_voidLCDClear();
			CLCD_voidSendString(" Invalid Key ! ");
			_delay_ms(500);

		}
		}
	}

	/*
	  	  Timer calculations (money)
	 */

	for (int i = 0; i < 4; i++) {
		if (array_places[i] == atoi(Local_u8Key)) {
			array_places[i] = 0;
		}
	}






}
