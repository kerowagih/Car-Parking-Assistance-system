/******************************************************************************
 *
 * Module: LED
 *
 * File Name: led.c
 *
 * Description: source file for the led driver
 *
 * Author: Kerollos Wagih
 *
 *******************************************************************************/

/*******************************************************************************
 *                                 INCLUDES                                    *
 *******************************************************************************/

#include "led.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                   *
 *******************************************************************************/

/*
 * Description:
 * Function responsible for:
 * 1. initializing all Leds (red, green, blue) pins direction.
 * 2. turning off all the Leds
 */
void LEDS_init(void)
{
	/* Initializes all Leds (red, green, blue) pins direction. */
	GPIO_setupPinDirection(RED_LED_PORT_ID, RED_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, PIN_OUTPUT);

	/* Turn off all the Leds */
#ifdef NEGATIVE_LOGIC
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
#else
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
#endif
}

/*
 * Description:
 * Function responsible for Turning on the specified LED.
 */
void LED_on(LED_ID id)
{
	switch (id)
	{
	case 0:
		/* Turn on the red led */
#ifdef NEGATIVE_LOGIC
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
#else
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
#endif
		break;
	case 1:
		/* Turn on the green led */
#ifdef NEGATIVE_LOGIC
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
#else
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
#endif
		break;
	case 2:
		/* Turn on the blue led */
#ifdef NEGATIVE_LOGIC
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
#else
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
#endif
		break;
	default:
		/*
		 * Wrong ID
		 * Do nothing
		 */
		break;
	}
}

/*
 * Description:
 * Function responsible for Turning off the specified LED.
 */
void LED_off(LED_ID id)
{
	switch (id)
	{
	case 0:
		/* Turn off the red led */
#ifdef NEGATIVE_LOGIC
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
#else
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
#endif
		break;
	case 1:
		/* Turn off the green led */
#ifdef NEGATIVE_LOGIC
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
#else
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
#endif
		break;
	case 2:
		/* Turn off the blue led */
#ifdef NEGATIVE_LOGIC
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
#else
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
#endif
		break;
	default:
		/*
		 * Wrong ID
		 * Do nothing
		 */
		break;
	}
}
