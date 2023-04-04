/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Seif-Allah Magdy
 *
 *******************************************************************************/

#include "lm35_sensor.h"


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 * Returns :
 * this function returns the temperature value in Celsius degree
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0; /*this variable will store the temperature */

	uint16 adc_value = 0; /*store the ADC value */

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));
	/*casting of uint32 prevent overflow in multiply */
	/*and second casting for final value to be uint8 */
	return temp_value;
}

