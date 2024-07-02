/*
 * app.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Ahmed
 */


#include "ultra.h"
#include "lcd.h"
#include "std_types.h"
#include <avr/io.h> /* To use the SREG register */

#include <util/delay.h>

int main(void)
{
	uint16 Distance  ;

	Ultrasonic_init();
	LCD_init();
	SREG |= (1<<7);

	LCD_displayString("Distance= ");
	while (1)
	{
		LCD_moveCursor(0,10);
		Distance = Ultrasonic_readDistance();
		if (Distance > 99){
			LCD_intgerToString(Distance);
		}
		else{
			LCD_intgerToString(Distance);
			LCD_displayCharacter(' ');
		}

		LCD_displayString("cm");

	}

	return 0;
}
