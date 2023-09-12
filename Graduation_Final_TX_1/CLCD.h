#ifndef CLCD_H_
#define CLCD_H_

/* Configuration Pins */
#define CLCD_DATA_PORT DIO_PORTA
#define CLCD_CTRL_PORT DIO_PORTC

#define CLCD_RS_PIN    DIO_PIN0
#define CLCD_RW_PIN    DIO_PIN1
#define CLCD_E_PIN     DIO_PIN2

/* Prototype Functions */
void CLCD_voidSendCommand (u8 Copy_u8Command);
void CLCD_voidSendData (u8 Copy_u8Data);
void CLCD_voidInit(void);

/* Send String */
void CLCD_voidSendString(const char*Copy_pcString);

/* Go to position (x , y)*/
void CLCD_voidGoToXY(u8 Copy_u8XPos,u8 Copy_u8YPos);

/* LCD Clear */
void CLCD_voidLCDClear(void);

#endif /* CLCD_H_ */
