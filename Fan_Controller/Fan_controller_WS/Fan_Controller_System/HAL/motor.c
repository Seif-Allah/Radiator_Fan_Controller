/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: motor.c
 *
 * Description: source file for the DC Motor driver
 *
 * Author:  Seif-Allah Magdy
 *
 *******************************************************************************/

#include"..\MCAL\gpio.h" /*calling the gpio module from MCAL Layer*/
#include"motor.h" /*include the header file of module*/
#include"..\MCAL\pwm.h" /*Callin the PWM (Timer) Driver From MCAL Layer*/
#include<avr/io.h>
/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * Initialize the MOTOR:
 * 1. Setup the Motor pins directions by use the GPIO driver.
 * 2. Initialize the Motor Pins of Motor by zero.
 */

void DcMotor_Init(void){
	/* Configure the direction Motor pins as output pins */
	GPIO_setupPinDirection(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID,PIN_OUTPUT);
	/*Initialize the Motor Pins of Motor by zero.*/
	GPIO_writePin(MOTOR_IN1_PORT_ID, MOTOR_IN1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(MOTOR_IN2_PORT_ID, MOTOR_IN2_PIN_ID,LOGIC_LOW);
}

/*
 * Description :
 * Rotate the MOTOR:
 * 1. Setup the Motor the state of motor from its Pins to be either (CW , A_CW , Stop).
 * 2. Call PWM_Timer0_Start Function to control the motor speed.
 *
 * Arguments:
 * a_state (its from type DcMotor_State which is enum contain direction and state of motor)
 * a_speed (the speed of motor )
 */

void DcMotor_Rotate(DcMotor_State a_state,uint8 a_speed){

	PORTB= (PORTB&0XFC) | a_state;

	PWM_Timer0_Start(a_speed);
}