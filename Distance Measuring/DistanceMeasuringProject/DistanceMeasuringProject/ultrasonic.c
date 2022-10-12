 /******************************************************************************
 *
 * [FILE NAME]: <ultrasonic.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <05/10/2022>
 *
 * [DESCRIPTION]: <source file for ultrasonic Driver>
 *
 *******************************************************************************/


#include "ultrasonic.h"
#include "gpio.h"
#include "icu.h"
#include <util/delay.h>



/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/
static volatile uint8 counter=0;
static volatile uint16 highCounter=0;





/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * [NAME]: Ultrasonic_init
 *
 * [Description] :  Function to initialise the Ultrasonic driver.
 *
 * [Returns]: void
 */
void Ultrasonic_init(void)
{
	GPIO_setupPinDirection (TRIGGER_PORT , TRIGGER_PIN , PIN_OUTPUT);
	Icu_ConfigType config = {F_CPU_8 , RISING};
	Icu_init (&config);
	Icu_setCallBack (Ultrasonic_edgeProcessing);
	GPIO_writePin (TRIGGER_PORT , TRIGGER_PIN , PIN_OUTPUT);
}


/*
 * [NAME]: Ultrasonic_Trigger
 *
 * [Description] : Function to trigger the Ultrasonic sensor.
 *
 * [Returns]: void
 */
void Ultrasonic_Trigger(void)
{
	GPIO_writePin (TRIGGER_PORT , TRIGGER_PIN , LOGIC_HIGH);
	_delay_ms(10);
	GPIO_writePin (TRIGGER_PORT , TRIGGER_PIN , LOGIC_LOW);
}



/*
 * [NAME]: Ultrasonic_readDistance
 *
 * [Description] : Function to measure the distance using Ultrasonic sensor.
 *
 * [Returns]: void
 */
uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_Trigger();
	uint16 distance;
	distance = (uint16) (highCounter/FACTOR);

	return distance;

}



/*
 * [NAME]: Ultrasonic_edgeProcessing
 *
 * [Description] : It's the callback function used to measure the pulse width time.
 *
 * [Returns]: void
 */
void Ultrasonic_edgeProcessing(void)
{
	counter++;

	if (counter == 1)
	{
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType (FALLING);
	}

	else if (counter ==2)
	{
		highCounter = Icu_getInputCaptureValue();
		Icu_clearTimerValue();
		Icu_setEdgeDetectionType (RISING);
		counter = 0;
	}
}
