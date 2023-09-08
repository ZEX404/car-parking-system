#include<avr/io.h>
#include"BIT_MATH.h"
#include"STD_TYPES.h"
#include"Dio_Interface.h"
#include"LCD_INTERFACE.h"
#include"ADC_INTERFACE.h"
#include<util/delay.h>


int main(){

	CLCD_voidInit();
	ADC_vidInit();
	LCD_voidClear();
	 f32 LDR;
	while(1)
	{
		LCD_voidClear();
		LDR = ADC_u16ReadChannelSyn(0);
		LDR = (LDR / 1023.0) * 100;
		LCD_voidSendNumber(LDR);
		_delay_ms(200);

	}


}
