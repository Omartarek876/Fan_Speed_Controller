/*
 * main.c
 *
 *  Created on: Feb 15, 2024
 *      Author: omar tarek
 */

#include "StdTypes.h"        // Include necessary header files
#include "Delay.h"
#include "Dio.h"
#include "Fcpu.h"
#include "Lm35.h"
#include "Adc.h"
#include "lcd.h"


#define LM_OUT  DIO_PORTA , DIO_PIN2    // Define LM35 output pin
#define BUZ     DIO_PORTB , DIO_PIN2    // Define buzzer pin


u16 result = 0;    // Variable to store LM35 temperature reading

int main (void)
{
    Lcd_Init(&Lcd_Configuration);    // Initialize LCD module
    Adc_Init(&Adc_Configuration);    // Initialize ADC module


    Dio_SetPinMode(LM_OUT, DIO_MODE_INPUT_PULLUP);    // Set LM35 pin as input with pull-up resistor
    Dio_SetPinMode(BUZ, DIO_MODE_OUTPUT);    // Set buzzer pin as output

    Lcd_DisplayString("TEM = ");    // Display temperature label on LCD
    Lcd_SetCursorPosition(0 , 9);    // Set cursor position on LCD
    Lcd_DisplayString(" C");    // Display temperature unit on LCD

    while (1)
    {
        result = Lm35_GetTemperature(ADC_CHANNEL_ADC2);    // Read temperature from LM35 sensor

        Lcd_SetCursorPosition(0 , 6);    // Set cursor position for temperature display

        if (result < 100 && result >= 10)
        {
            Lcd_DisplayNumber(result);    // Display two-digit temperature reading
            Lcd_DisplayString(" ");
        }
        else if (result < 10)
        {
            Lcd_DisplayNumber(result);    // Display single-digit temperature reading
            Lcd_DisplayString("  ");
        }
        else
        {
            Lcd_DisplayNumber(result);    // Display three-digit temperature reading
        }


        if (result >= 60)    // Check if temperature is higher than or equal to 60 degrees
        {
            Lcd_SetCursorPosition(1 , 3);    // Set cursor position for status display
            Lcd_DisplayString("FIRE FIRE");    // Display "FIRE FIRE" message on LCD
            Dio_SetPinLevel(BUZ , DIO_HIGH);    // Activate the buzzer
        }
        else if (result >= 30)    // Check if temperature is higher than or equal to 30 degrees
        {
            Lcd_SetCursorPosition(1 , 3);    // Set cursor position for status display
            Lcd_DisplayString("HOT AIR !");    // Display "HOT AIR !" message on LCD
        }
        else
        {
            Lcd_SetCursorPosition(1 , 3);    // Set cursor position for status display
            Lcd_DisplayString("SAFE");    // Display "SAFE" message on LCD
        }

    }
}
