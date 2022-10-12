 /******************************************************************************
 *
 * [FILE NAME]: <ultrasonic.h>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <05/10/2022>
 *
 * [DESCRIPTION]: <Header file for ultrasonic Driver>
 *
 *******************************************************************************/

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define TRIGGER_PORT         PORTB_ID
#define TRIGGER_PIN          PIN5_ID

#define FACTOR                 55.8



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * [NAME]: Ultrasonic_init
 *
 * [Description] :  Function to initialise the Ultrasonic driver.
 *
 * [Returns]: void
 */
void Ultrasonic_init(void);


/*
 * [NAME]: Ultrasonic_Trigger
 *
 * [Description] : Function to trigger the Ultrasonic sensor.
 *
 * [Returns]: void
 */
void Ultrasonic_Trigger(void);


/*
 * [NAME]: Ultrasonic_readDistance
 *
 * [Description] : Function to measure the distance using Ultrasonic sensor.
 *
 * [Returns]: void
 */
uint16 Ultrasonic_readDistance (void);




/*
 * [NAME]: Ultrasonic_edgeProcessing
 *
 * [Description] : It's the callback function used to measure the pulse width time.
 *
 * [Returns]: void
 */
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
