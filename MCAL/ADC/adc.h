/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.h
 *
 * Description: header file for the ATmega16 ADC driver
 *
 * Author: Muhammad Salah Ahmed Hefny
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include <stdio.h>
#include "../std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023			/* 10 bits */
#define ADC_REF_VOLT_VALUE   2.56			/* INTERNAL */

typedef enum{
	PRE_SCALER2, PRE__SCALER2, PRE_SCALER4, PRE_SCALER8, PRE_SCALER16, PRE_SCALER32, PRE_SCALER64,PRE_SCALER128
}ADC_Prescaler;

typedef enum{
	AREF, AVCC, RESERVED, INTERNAL
}ADC_ReferenceVoltage;

typedef struct{
	ADC_ReferenceVoltage ref_volt;
	ADC_Prescaler prescaler;
} ADC_ConfigType;



/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
