#ifndef KEYPAD_H_
#define KEYPAD_H_

/* Configuration Pins & Ports */
/*Rows*/
#define KPD_R0_PORT DIO_PORTB
#define KPD_R0_PIN  DIO_PIN0

#define KPD_R1_PORT DIO_PORTB
#define KPD_R1_PIN  DIO_PIN1

#define KPD_R2_PORT DIO_PORTB
#define KPD_R2_PIN  DIO_PIN2

#define KPD_R3_PORT DIO_PORTB
#define KPD_R3_PIN  DIO_PIN3

/*Columns*/
#define KPD_C0_PORT DIO_PORTB
#define KPD_C0_PIN  DIO_PIN4

#define KPD_C1_PORT DIO_PORTB
#define KPD_C1_PIN  DIO_PIN5

#define KPD_C2_PORT DIO_PORTB
#define KPD_C2_PIN  DIO_PIN6

#define KPD_C3_PORT DIO_PORTB
#define KPD_C3_PIN  DIO_PIN7

/**/
#define KPD_PRESSED_KEY 0
#define KPD_NOTPRESSED_KEY 0xFF

/* To Avoid Magic Numbers*/
#define ROW_NUMBER       4
#define COL_NUMBER       4

#define KPD_VALUES {{'7', '8', '9', '/'}, {'4', '5', '6', '*'}, {'1', '2', '3', '-'}, {'C', '0', '=', '+'}}

/* Prototypes */
void KPD_INIT(void);
u8 KPD_GetPressedKey(void);


#endif /* KEYPAD_H_ */
