/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dcmotor.c
 *
 * Description: Header file for the DC Motor driver
 *
 * Author: Muhammad Salah Ahmed Hefny
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "../../MCAL/GPIO/gpio.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define MOTOR1_INPUT_PORT 	 	PORTB_ID
#define MOTOR1_INPUT_PIN0	 	PIN0_ID
#define MOTOR1_INPUT_PIN1	 	PIN1_ID
#define MOTOR1_ENABLE        	PIN3_ID

typedef enum
{
	MOTOR_STOP,MOTO_ANTI_CW,MOTOR_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the Dc Motor.
 */
void DcMotor_Init(void);

/*
 * Description :
 * Function responsible to Control the motor speed and rotation direction .
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);



#endif /* DCMOTOR_H_ */
