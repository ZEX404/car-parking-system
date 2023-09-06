#define F_CPU 8000000UL
#include "../../LIB/STD_TYPES.h"
#include "CLCD.h"
#include "../../MCAL/DIO/DIO.h"

void CLCD_voidSendCommand (u8 Copy_u8Command)
{
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_LOW);

	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_LOW);
	DIO_SetPortValue(CLCD_DATA_PORT, Copy_u8Command);

	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_LOW);
}

void CLCD_voidSendData (u8 Copy_u8Data){
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_HIGH);

	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_LOW);
	DIO_SetPortValue(CLCD_DATA_PORT, Copy_u8Data);

	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_LOW);
}

void CLCD_voidInit(void){
	_delay_ms(40);
	CLCD_voidSendCommand(0b00111000);
	CLCD_voidSendCommand(0b00001100);
	CLCD_voidSendCommand(1);

}

void CLCD_voidSendString(const char* Copy_pcString) {
	u8 i = 0;
	while (Copy_pcString[i] != '\0') {
		CLCD_voidSendData(Copy_pcString[i]);
		i++;

		_delay_ms(10);
	}
}


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

void CLCD_voidLCDClear(void){
	CLCD_voidSendCommand(1);
}
