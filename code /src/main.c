/*
 * main.c
 *
 *  Created on: Feb 15, 2024
 *      Author: omar tarek
 */

#include "StdTypes.h"             // Include necessary header files
#include "fire_detector.h"

int main(void)
{
    fire_detector_Init();         // Initialize the fire detector system

    while (1)
    {
        display_temp();           // Display the temperature on the LCD
        display_warning(result);  // Display warning messages based on the temperature reading
    }
}
