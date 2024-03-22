/*
 * fire_detector.c
 *
 *  Created on: Mar 20, 2024
 *      Author: Omar Tarek
 */

#include "StdTypes.h"     // Include necessary header files
#include "Dio.h"
#include "Lm35.h"
#include "Delay.h"
#include "Adc.h"
#include "Pwm.h"
#include "lcd.h"
#include "fire_detector.h"


u16 result = 0;    // Variable to store LM35 temperature reading

void fire_detector_Init (void)
{
    Lcd_Init(&Lcd_Configuration);    // Initialize LCD module
    Adc_Init(&Adc_Configuration);    // Initialize ADC module
    Pwm_Init(&Pwm_Configuration);



    Dio_SetPinMode(LM_OUT, DIO_MODE_INPUT_PULLUP);    // Set LM35 pin as input with pull-up resistor
    Dio_SetPinMode(BUZ, DIO_MODE_OUTPUT);    // Set buzzer pin as output

    Dio_SetPinMode(IN1, DIO_MODE_OUTPUT);    // Set buzzer pin as output
    Dio_SetPinMode(IN2, DIO_MODE_OUTPUT);    // Set buzzer pin as output

    Dio_SetPinLevel(IN1 , DIO_HIGH);
    Dio_SetPinLevel(IN2 , DIO_LOW);

    Lcd_DisplayString("TEM = ");    // Display temperature label on LCD
    Lcd_SetCursorPosition(0 , 9);    // Set cursor position on LCD
    Lcd_DisplayString(" C");    // Display temperature unit on LCD

   //  _delay_ms(250);
}

void display_temp (void)
{
    result = Lm35_GetTemperature(ADC_CHANNEL_ADC2);    // Read temperature from LM35 sensor
    Lcd_SetCursorPosition(0 , 6);                      // Set cursor position for temperature display
	Lcd_DisplayNumber(result);                         // Display the temperature reading
    Lcd_DisplayString("  ");
}

void display_warning (u16 result)
{
    if (result >= 80)    // Check if temperature is higher than or equal to 60 degrees
    {
        Lcd_SetCursorPosition(1 , 3);    // Set cursor position for status display
        Lcd_DisplayString("FIRE FIRE    ");    // Display "FIRE FIRE" message on LCD
      //  display_alarm();

        motor_rotating(ROTATE , 100);
    }
    else if (result >= 60)    // Check if temperature is higher than or equal to 30 degrees
    {
        Lcd_SetCursorPosition(1 , 3);    // Set cursor position for status display
        Lcd_DisplayString("TOO HOT AIR !");    // Display "HOT AIR !" message on LCD

        motor_rotating(ROTATE , 70);
    }
    else if (result >= 30)    // Check if temperature is higher than or equal to 30 degrees
    {
        Lcd_SetCursorPosition(1 , 3);    // Set cursor position for status display
        Lcd_DisplayString("HOT AIR !    ");    // Display "HOT AIR !" message on LCD

        motor_rotating(ROTATE , 40);
    }
    else
    {
        Lcd_SetCursorPosition(1 , 3);    // Set cursor position for status display
        Lcd_DisplayString("SAFE         ");    // Display "SAFE" message on LCD

        motor_rotating(ROTATE , 0);
    }

}

void motor_rotating (rotate_state state , u8 speed)
{
	switch (state)
	{
	       case STOP :
	           Dio_SetPinLevel(IN1 , DIO_LOW);
	           Dio_SetPinLevel(IN2 , DIO_LOW);
	    	   break;

	       case ROTATE :
	           Dio_SetPinLevel(IN1 , DIO_HIGH);
	           Dio_SetPinLevel(IN2 , DIO_LOW);
	    	   break;
	}

	if ( (speed > 0 ) && (speed <= 100) )
	{
        Pwm_SetDutyCycle( PWM_OUT_OC0, speed );
	}
	else
	{
        Pwm_SetDutyCycle( PWM_OUT_OC0, 0 );

	}
}
