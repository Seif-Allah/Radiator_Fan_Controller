/******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.c
 *
 * Description: Source file for the AVR GPIO driver
 *
 * Author: Seif-Allah Magdy
 *
 *******************************************************************************/

#include"gpio.h"
#include"pwm.h"
#include<avr/io.h>

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Set up Timer0 to produce PWM signal :
 * 1. Initialize timer 0 by initial value = 0.
 * 2. Set compare register value depend on the duty cycle want to produce.
 * 3. configure pin want to produce signal on it as an output pin.
 * 4. setup the setting of the timer ( Mode and Prescaler ).
 *
 * Arguments :
 * a_duty_cycle (the function take the duty cycle as a percentage you want from Volt)
 */
void PWM_Timer0_Start(uint8 a_duty_cycle)
{

	TCNT0 = 0; /* Set Timer Initial Value to 0*/

	OCR0  = (uint8)(((float)a_duty_cycle/100)*256); /* Set Compare Value by calculating the value from the input percentage*/

	/* Configure Pin of PWM as output pin --> pin where the PWM signal is generated from MC*/
	GPIO_setupPinDirection(PWM_PORT_ID, PWM_PIN_ID,PIN_OUTPUT);
	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}

