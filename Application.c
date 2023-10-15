/******************************************************************************
 *
 * Module: Main Application
 *
 * File Name: main.c
 *
 * Description: Main Application for the Fan Controller System
 *
 * Author: Muhammad Salah Ahmed Hefny
 *
 *******************************************************************************/

#include "HAL/LM35/lm35_sensor.h"
#include "HAL/DCMOTOR/dcmotor.h"
#include "HAL/LCD/lcd.h"
#include "MCAL/std_types.h"

/*
 * Description:
 * Function responsible to adjust the cursor , print the main messages.
 */
void app_Welcome()
{
	LCD_moveCursor(0, 0);
	LCD_displayString("Welcome         ");
	LCD_moveCursor(1,0);
	LCD_displayString("Temp =    C");

}
/*
 * Description:
 * Function responsible to print the current temperature.
 */
void lcd_Temprint(uint8 temperature)
{

	if(temperature >= 100)
	{
		LCD_moveCursor(1,7);
		LCD_intgerToString(temperature);
		LCD_moveCursor(0,0);
		LCD_displayString("Fan Is ON         ");

	}
	else
	{
		LCD_moveCursor(1,7);
		LCD_intgerToString(temperature);
		/* In case the digital value is two or one digits print space in the next digit place */
		LCD_displayCharacter(' ');
		LCD_moveCursor(0,0);
		if (temperature<30) LCD_displayString("Fan is OFF         ");
		else 		 		LCD_displayString("Fan Is ON          ");

	}

}
/*
 * Description:
 * Function responsible to turn on/off the Fan And control its speed,
 * depending on the current temperature,
 * The higher temperature the higher speed.
 */
void fan(uint8 temperature)
{
	if (temperature >= 120)
	{
		DcMotor_Rotate(MOTOR_CW, 100);

	}
	else if (temperature >= 90)
	{
		DcMotor_Rotate(MOTOR_CW, 75);

	}

	else if (temperature >= 60)
	{
		DcMotor_Rotate(MOTOR_CW, 50);


	}
	else if (temperature >= 30)
	{
		DcMotor_Rotate(MOTOR_CW, 25);

	}
	else if (temperature < 30)
	{
		DcMotor_Rotate(MOTOR_STOP, 0);

	}

}

int main()
{
	// just comment
	uint8 temperature = 0;
	DcMotor_Init();
	LCD_init();
	app_Welcome();
	while(1)
	{
		temperature = LM35_getTemperature();
		lcd_Temprint(temperature);
		fan(temperature);
	}
}

