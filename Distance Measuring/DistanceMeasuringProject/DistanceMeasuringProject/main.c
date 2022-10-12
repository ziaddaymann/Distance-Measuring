 /******************************************************************************
 *
 * [FILE NAME]: <main.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <08/10/2022>
 *
 * [DESCRIPTION]: <Main file>
 *
 *******************************************************************************/

#include "icu.h"
#include "ultrasonic.h"
#include "lcd.h"
#include <util/delay.h>
#include <avr/io.h>

int main()
{
	SREG |= (1<<7);
	uint16 DISTANCE;

	LCD_init();
	Ultrasonic_init();

	LCD_displayString ("DISTANCE =   cm");

	while(1)
	{
		DISTANCE = Ultrasonic_readDistance();

		LCD_moveCursor(0,11);

		LCD_intgerToString(DISTANCE);

		if(DISTANCE<100)
		{
				LCD_displayCharacter(' ');
		}
	}
}
