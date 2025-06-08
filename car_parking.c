/*
 ================================================================================================
 Name        : car_parking.c
 Author      : Kerollos Wagih
 ================================================================================================
 */

/*----------------------------------------- INCLUDES ------------------------------------------*/

#include "lcd.h"
#include "buzzer.h"
#include "led.h"
#include "ultrasonic_sensor.h"

#include <avr/io.h> 			/* To use the SREG register */
#include <util\delay.h>			/* Delay for flashing Leds and buzzer*/


int main(void)
{
	/*-------------------------------- Application Initialization -----------------------------*/

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/*-------------------------------- Modules initializations --------------------------------*/

	/* Initialize the LCD driver */
	LCD_init();

	/* Initialize the Buzzer driver */
	Buzzer_init();

	/* Initialize the LED driver */
	LEDS_init();

	/* Initialize the LED driver */
	Ultrasonic_init();

	/* variable definition */
	uint16 distance = Ultrasonic_readDistance();

	/* Display on LCD */
	LCD_displayString("distance =    cm");

	while(1)	/*------------------------- Infinite loop --------------------------------*/
	{
		/*--------------------------------- Application Code ----------------------------------*/

		/* Read distance value from ultrasonic sensor */
		distance = Ultrasonic_readDistance();

		/* Move cursor to display the distance on a specific position in LCD */
		LCD_moveCursor(0,11);

		/* Display the distance on LCD */
		if (distance >= 100)
		{
			LCD_intgerToString(distance);
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayString(" ");
		}


		/*-------------------------- Distance to LED and Buzzer Mapping -----------------------*/

		if (distance <= 5)
		{
			/*
			 * (Distance <= 5 cm)
			 * All LEDs are flashing (Red, Green, Blue), Buzzer sounds, LCD shows "Stop."
			 */
			LCD_clearScreen();
			LCD_displayString("Stop.");

			while (distance <= 5)
			{
				LED_on(RED);
				LED_on(GREEN);
				LED_on(BLUE);
				Buzzer_on();
				_delay_ms(500);
				LED_off(RED);
				LED_off(GREEN);
				LED_off(BLUE);
				Buzzer_off();
				_delay_ms(500);

				/* Update the distance value */
				distance = Ultrasonic_readDistance();
			}

			/* Distance is updated and become greater than 5 cm */
			Buzzer_off();
			LCD_clearScreen();
			LCD_displayString("distance =    cm");
		}
		else if (distance <= 10)
		{
			/*
			 * (6 cm <= Distance <= 10 cm)
			 * All LEDs ON (Red, Green, Blue), No buzzer.
			 */
			LED_on(RED);
			LED_on(GREEN);
			LED_on(BLUE);
		}
		else if (distance <= 15)
		{
			/*
			 * (11 cm <= Distance <= 15 cm)
			 * Red and Green LEDs ON, Blue LED OFF.
			 */
			LED_on(RED);
			LED_on(GREEN);
			LED_off(BLUE);
		}
		else if (distance <= 20)
		{
			/*
			 * (16 cm <= Distance <= 20 cm)
			 * Only Red LED ON, others OFF.
			 */
			LED_on(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}
		else
		{
			/*
			 * (Distance > 20 cm)
			 * All LEDs OFF, Buzzer OFF.
			 */
			LED_off(RED);
			LED_off(GREEN);
			LED_off(BLUE);
		}

	}
	/*----------------------------- End of Application Code ------------------------------*/
	return LOGIC_LOW;
}
/*----------------------------- End of main function ------------------------------*/
