#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO.h"
#include "../MCAL/timer.h"
#include "CLCD.h"
#include "Keypad.h"
#include "../APP/Global.h"
#include <avr/io.h>

void KPD_INIT(void){
	/* Configure Rows Directions --> Internal Pullup --> Input --> Value = Low */
	DIO_SetPinDirection(KPD_R0_PORT, KPD_R0_PIN, DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_R1_PORT, KPD_R1_PIN, DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_R2_PORT, KPD_R2_PIN, DIO_PIN_INPUT);
	DIO_SetPinDirection(KPD_R3_PORT, KPD_R3_PIN, DIO_PIN_INPUT);

	DIO_SetPinValue(KPD_R0_PORT, KPD_R0_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(KPD_R1_PORT, KPD_R1_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(KPD_R2_PORT, KPD_R2_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(KPD_R3_PORT, KPD_R3_PIN, DIO_PIN_HIGH);

	/* Configure Columns Directions --> Output --> Value = High */
	DIO_SetPinDirection(KPD_C0_PORT, KPD_C0_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_C1_PORT, KPD_C1_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_C2_PORT, KPD_C2_PIN, DIO_PIN_OUTPUT);
	DIO_SetPinDirection(KPD_C3_PORT, KPD_C3_PIN, DIO_PIN_OUTPUT);

	DIO_SetPinValue(KPD_C0_PORT, KPD_C0_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(KPD_C1_PORT, KPD_C1_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(KPD_C2_PORT, KPD_C2_PIN, DIO_PIN_HIGH);
	DIO_SetPinValue(KPD_C3_PORT, KPD_C3_PIN, DIO_PIN_HIGH);
}

u8 KPD_GetPressedKey(void){
	u8 u8RowLocal = 0;
	u8 u8ColLocal = 0;
	u8 KPD_u8Value [ROW_NUMBER][COL_NUMBER] = KPD_VALUES;
	u8 KPD_u8ROWPORTArr[ROW_NUMBER] = {KPD_R0_PORT, KPD_R1_PORT, KPD_R2_PORT, KPD_R3_PORT};
	u8 KPD_u8ROWPINArr [ROW_NUMBER] = {KPD_R0_PIN, KPD_R1_PIN, KPD_R2_PIN, KPD_R3_PIN};

	u8 KPD_u8COLPORTArr[COL_NUMBER] = {KPD_C0_PORT, KPD_C1_PORT, KPD_C2_PORT, KPD_C3_PORT};
	u8 KPD_u8COLPINArr [COL_NUMBER] = {KPD_C0_PIN, KPD_C1_PIN, KPD_C2_PIN, KPD_C3_PIN};

	for(u8ColLocal = 0 ; u8ColLocal < COL_NUMBER ; u8ColLocal++){
		DIO_SetPinValue(KPD_u8COLPORTArr[u8ColLocal], KPD_u8COLPINArr[u8ColLocal], DIO_PIN_LOW);
		for(u8RowLocal = 0 ; u8RowLocal < ROW_NUMBER ; u8RowLocal++){
			u8 u8PinValueLocal = DIO_GetPinValue(KPD_u8ROWPORTArr[u8RowLocal], KPD_u8ROWPINArr[u8RowLocal]);
			if (u8PinValueLocal == KPD_PRESSED_KEY){

				delay(50);
				u8PinValueLocal = DIO_GetPinValue(KPD_u8ROWPORTArr[u8RowLocal], KPD_u8ROWPINArr[u8RowLocal]);
				if (u8PinValueLocal == KPD_PRESSED_KEY){

					while ((u8PinValueLocal == KPD_PRESSED_KEY) && Emergency != 1){
						u8PinValueLocal = DIO_GetPinValue(KPD_u8ROWPORTArr[u8RowLocal], KPD_u8ROWPINArr[u8RowLocal]);
					}
					return KPD_u8Value [u8RowLocal][u8ColLocal];
				}
			}
		}
		/* Deactivate Column */
		DIO_SetPinValue(KPD_u8COLPORTArr[u8ColLocal],KPD_u8COLPINArr[u8ColLocal], DIO_PIN_HIGH);

	}

	return KPD_NOTPRESSED_KEY;
}
