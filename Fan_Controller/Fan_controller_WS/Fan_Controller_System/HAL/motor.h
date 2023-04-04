/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: motor.h
 *
 * Description: Header file for the DC Motor driver
 *
 * Author:  Seif-Allah Magdy
 *
 *******************************************************************************/

#ifndef MOTOR_H_
#define MOTOR_H_
#include"..\MCAL\std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR_IN1_PORT_ID                 PORTB_ID
#define MOTOR_IN1_PIN_ID                  PIN0_ID

#define MOTOR_IN2_PORT_ID                 PORTB_ID
#define MOTOR_IN2_PIN_ID                  PIN1_ID

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

typedef enum {
	stop,A_CW,CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Initialize the MOTOR:
 * 1. Setup the Motor pins directions by use the GPIO driver.
 * 2. Initialize the Motor Pins of Motor by zero.
 */
void DcMotor_Init(void);
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
void DcMotor_Rotate(DcMotor_State state,uint8 speed);


#endif /* MOTOR_H_ */
