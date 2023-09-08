#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}et_Port;

typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}et_Pin;

typedef enum{
	Input,
	Output
}et_Dirction;

typedef enum{
	Pinlow,
	PinHigh
}et_Status;

/*setting pin direction*/
void DIO_VidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Direction);

/*setting pin*/
void DIO_VidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value);

/*getting Pin value*/
void DIO_VidGetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 *pu8Data);

/*setting Port direction*/
void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction);

/*setting Port*/
void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value);

/*getting Port value*/
void DIO_VidGetPortValue(u8 Copy_u8Port,u8 *pu8Data);

#endif
