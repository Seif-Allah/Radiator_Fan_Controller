/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: gpio.h
 *
 * Description: Header file for the AVR GPIO driver
 *
 * Author: Seif-Allah Magdy
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PWM_PORT_ID                 PORTB_ID
#define PWM_PIN_ID                  PIN3_ID

/*******************************************************************************
 *                      Functions Prototypes                                   *
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
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
