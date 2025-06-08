/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.h
 *
 * Description: header file for the LED driver
 *
 * Author: kerollos Wagih
 *
 *******************************************************************************/

#ifndef LED_H_
#define LED_H_

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

/* Configure led connection (by default positive logic connection )*/

#define POSITIVE_LOGIC
/* #define NEGATIVE_LOGIC */

/* Configure red led (port and pin) */
#define RED_LED_PORT_ID		PORTC_ID
#define RED_LED_PIN_ID		PIN0_ID

/* Configure green led (port and pin) */
#define GREEN_LED_PORT_ID	PORTC_ID
#define GREEN_LED_PIN_ID	PIN1_ID

/* Configure blue led (port and pin) */
#define BLUE_LED_PORT_ID	PORTC_ID
#define BLUE_LED_PIN_ID		PIN2_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum
{
	RED,GREEN,BLUE
}LED_ID;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for:
 * 1. initializing all Leds (red, green, blue) pins direction.
 * 2. turning off all the Leds
 */
void LEDS_init(void);

/*
 * Description:
 * Function responsible for Turning on the specified LED.
 */
void LED_on(LED_ID id);

/*
 * Description:
 * Function responsible for Turning off the specified LED.
 */
void LED_off(LED_ID id);


#endif /* LED_H_ */
