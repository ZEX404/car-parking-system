
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO.h"
#include "../MCAL/timer.h"
#include "../MCAL/UART_TX.h"
#include "CLCD.h"
#include "../APP/TimeCalc.h"
#include "../APP/Global.h"

u8 Local_u8Key, array_places[4], flag = 0, SpotsNum = 4, spot_index;
spotInfo SpotsArr[5];
timestamp CurrentTime;

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
	delay(2);
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
	delay(2);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_PIN_LOW);
}

void CLCD_voidInit(void){
	/* Delay more that 30 seconds*/
	delay(40);
	/* Command for font size 5*8 */
	CLCD_voidSendCommand(0b00111000);
	/* Display On or Off*/
	CLCD_voidSendCommand(0b00001100);
	/* Clear Display */
	CLCD_voidSendCommand(1);

}

/* Send String */
//void CLCD_voidSendString(const char*Copy_pcString);
void CLCD_voidSendString(const char* Copy_pcString) {
	u8 i = 0;
	while (Copy_pcString[i] != '\0') {
		CLCD_voidSendData(Copy_pcString[i]);
		i++;

		// Delay between characters (adjust as needed)
		delay(10);
	}
}


/* Go to position (x , y)*/
void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos) {
    u8 Local_u8Address;
    if (Copy_u8XPos == 0) {
        Local_u8Address = Copy_u8YPos;
    } else if (Copy_u8XPos == 1) {
        Local_u8Address = Copy_u8YPos + 0x40;
    } else if (Copy_u8XPos == 2) {
        Local_u8Address = Copy_u8YPos + 0x10;
    } else if (Copy_u8XPos == 3) {
        Local_u8Address = Copy_u8YPos + 0x50;
    }
    CLCD_voidSendCommand(Local_u8Address + 128);
}


/* LCD Clear */
void CLCD_voidLCDClear(void){
	CLCD_voidSendCommand(1);
}

void reserve(void){
	CLCD_voidLCDClear();

	u8 reserved = 0;
	while (reserved == 0 && Emergency != 1) {
		available_places();
		delay(1500);
		CLCD_voidLCDClear();
		CLCD_voidSendString(" Choose a slot ");
		CLCD_voidGoToXY(3,0);
		CLCD_voidSendString("C: go to options");

		do {
			Local_u8Key = KPD_GetPressedKey();
		} while (Local_u8Key == 0xFF && Emergency != 1);

		//exit if the input is 'Clear'
		if (Local_u8Key == 'C'){
			break;
		}
		// Check if the spot is available
		spot_index = Local_u8Key - '0';
		if (array_places[spot_index - 1] == 0) {
			switch(Local_u8Key){
			case '1':
			case '2':
			case '3':
			case '4':{
				CLCD_voidLCDClear();
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendString("  Slot Number ");
				CLCD_voidSendData(Local_u8Key);
				CLCD_voidGoToXY(2,0);
				CLCD_voidSendString("   is reserved  ");
				reserved = 1;
				SpotEnteringTime(&SpotsArr[spot_index], &CurrentTime); // Timer
				array_places[spot_index - 1] = spot_index;
				delay(1000);
				CLCD_voidLCDClear();

				CLCD_voidSendString("  Opening Gate  ");
				UART_voidSendData_TX(SIGNAL_OPENGATE);
				delay(500);
				break;
			}
			default:{
				CLCD_voidLCDClear();
				CLCD_voidSendString(" Invalid Key ! ");
				delay(500);
			}
			}
		}
		else {
			// The spot is reserved, display an error message
			CLCD_voidLCDClear();
			CLCD_voidSendString(" Spot not available");
			delay(1000);
		}
	}
}

void reserved_places(void){
	CLCD_voidLCDClear();
	CLCD_voidSendString(" Reserved Spots");
	u8 place_str[2];  // Assuming a place number is a single digit
	for (u8 i = 0; i < 4; i++) {
		if (array_places[i] == i + 1) {
			sprintf(place_str, "%d", array_places[i]);
			CLCD_voidGoToXY(2, 2*i+3);
			CLCD_voidSendString(place_str);
		}
	}
}

void available_places(void){
	CLCD_voidLCDClear();
	CLCD_voidSendString("Available places");
	u8 place_str[2];  // Assuming a place number is a single digit
	for (u8 i = 0; i < 4; i++) {
		if (array_places[i] != i + 1) {
			sprintf(place_str, "%d", i+1);
			CLCD_voidGoToXY(2, 2*i+3);
			CLCD_voidSendString(place_str);
		}
	}
}

void Checkout(void) {
	u8 PricePerHour = 10;
	u8 InitialPrice = 10;
	u8 ParkingHours;
	u8 TotalPrice;
	while (Emergency != 1) {
		CLCD_voidLCDClear();
		CLCD_voidSendString("   Enter Slot  ");
		CLCD_voidGoToXY(1, 0);
		CLCD_voidSendString("     Number");
		CLCD_voidGoToXY(3,0);
		CLCD_voidSendString("C: go to options");

		do {
			Local_u8Key = KPD_GetPressedKey();
		} while (Local_u8Key == 0xFF && Emergency != 1);

		//exit if the input is 'Clear'
		if (Local_u8Key == 'C'){
			break;
		}
		switch (Local_u8Key) {
		case '1':
		case '2':
		case '3':
		case '4': {
			spot_index = Local_u8Key - '0';  // Convert character to integer

			// Check if the spot is reserved
			if (array_places[spot_index - 1] == spot_index) {
				flag = 1;
				SpotLeavingTime(&SpotsArr[spot_index], &CurrentTime);	// Timer
				CalcParkingDuration(&SpotsArr[spot_index]);				// Timer

				ParkingHours = SpotsArr[spot_index].ParkingDuration.hours;
				TotalPrice = InitialPrice + PricePerHour * ParkingHours;

				// Remove the spot from the array_places array
				array_places[spot_index - 1] = 0;

			} else {
				// The spot is not reserved, display an error message
				CLCD_voidLCDClear();
				CLCD_voidSendString(" Spot not reserved");
				delay(1000);
			}
			break;
		}
		default: {
			// Invalid key entered, display an error message
			CLCD_voidLCDClear();
			CLCD_voidSendString(" Invalid Key ! ");
			delay(1000);
		}
		}

		// Exit the loop if the flag is set
		if (flag == 1) {
			break;
		}
	}

	if (flag == 1){
		flag = 0;
		// convert money value from int to string by sprintf
		CLCD_voidLCDClear();
		CLCD_voidSendString("Checkout: ");
		u8 total[5];
		sprintf(total, "%d", TotalPrice);
		CLCD_voidSendString(total);

		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString(" H:");
		u8 hours_string[5];
		sprintf(hours_string, "%d", (SpotsArr[spot_index].ParkingDuration.hours));
		CLCD_voidSendString(hours_string);

		CLCD_voidSendString(" M:");
		u8 min_string[5];
		sprintf(min_string, "%d", (SpotsArr[spot_index].ParkingDuration.minutes));
		CLCD_voidSendString(min_string);

		CLCD_voidSendString(" S:");
		u8 sec_string[5];
		sprintf(sec_string, "%d", (SpotsArr[spot_index].ParkingDuration.seconds));
		CLCD_voidSendString(sec_string);
		delay(500);
	}
}


