/*/******************************************************************************
 *
 * Module: DC Motor
 *
 * File Name: dcmotor.c
 *
 * Description: Source file for DC Motor driver
 *
 * Author: Muhammad Salah Ahmed Hefny
 *
 *******************************************************************************/
#include "dcmotor.h"
#include "../../MCAL/common_macros.h"
#include "../../MCAL/std_types.h"
#include "../../MCAL/PWM/pwm.h"
void DcMotor_Init(void)
{

	GPIO_setupPinDirection(MOTOR1_INPUT_PORT, MOTOR1_INPUT_PIN0, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR1_INPUT_PORT, MOTOR1_INPUT_PIN1, PIN_OUTPUT);
	GPIO_writePin(MOTOR1_INPUT_PORT,MOTOR1_INPUT_PIN0,LOGIC_LOW);
	GPIO_writePin(MOTOR1_INPUT_PORT,MOTOR1_INPUT_PIN1,LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed)
{

	/*
	 * Description :
	 * Motor Stops when its two terminals are low (LOW,LOW)
	 * Motor Changes its direction by changing the voltage on its terminals (HIGH,LOW) -  (LOW,HIGH)
	 * .
	 */

	if (state == MOTOR_STOP)
	{
		GPIO_writePin(MOTOR1_INPUT_PORT, MOTOR1_INPUT_PIN0, LOGIC_LOW);
		GPIO_writePin(MOTOR1_INPUT_PORT, MOTOR1_INPUT_PIN1, LOGIC_LOW);
	}
	else if (state == MOTOR_CW)
	{
		GPIO_writePin(MOTOR1_INPUT_PORT, MOTOR1_INPUT_PIN0, LOGIC_LOW);
		GPIO_writePin(MOTOR1_INPUT_PORT, MOTOR1_INPUT_PIN1, LOGIC_HIGH);

	}
	else if (state == MOTO_ANTI_CW)
	{
		GPIO_writePin(MOTOR1_INPUT_PORT, MOTOR1_INPUT_PIN0, LOGIC_HIGH);
		GPIO_writePin(MOTOR1_INPUT_PORT ,MOTOR1_INPUT_PIN1, LOGIC_LOW);

	}

	PWM_generatePwm(speed);

}
