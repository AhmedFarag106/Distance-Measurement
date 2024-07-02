/*
 * ultra.c
 *
 *  Created on: Oct 19, 2023
 *      Author: Ahmed
 */


#include "ultra.h"
#include "icu.h"
#include "gpio.h"
#include <util/delay.h>

#include "lcd.h"

static uint8 turns =0;

void Ultrasonic_edgeProcessing(void)
{
	turns ++;

	if (turns == 1)
	{
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);

	}

}


void Ultrasonic_init(void)
{
	ICU_ConfigType my_ICU = {F_CPU_8,RAISING};
	ICU_init(&my_ICU);

	ICU_setCallBack(Ultrasonic_edgeProcessing);

	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);

}

void Ultrasonic_Trigger(void)
{
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(PORTB_ID,PIN5_ID,LOGIC_LOW);

}


uint16 Ultrasonic_readDistance(void)
{
	uint16 distance ;

	Ultrasonic_Trigger();

	ICU_setEdgeDetectionType(RAISING);

	while (turns != 2) ;

	turns = 0;

	distance =  1 + ICU_getInputCaptureValue() /58 ;

	return distance;
}
