/*
 * file_detector.h
 *
 *  Created on: Mar 20, 2024
 *      Author: Omar Tarek
 */

#ifndef FIRE_DETECTOR_H_
#define FIRE_DETECTOR_H_


#include "StdTypes.h"     // Include necessary header files
#include "Dio.h"



#define LM_OUT  DIO_PORTA , DIO_PIN2    // Define LM35 output pin
#define BUZ     DIO_PORTB , DIO_PIN2    // Define buzzer pin
#define IN1     DIO_PORTB , DIO_PIN0
#define IN2     DIO_PORTB , DIO_PIN1


extern u16 result;    // Variable to store LM35 temperature reading
extern u8 alarm_counter ;


typedef enum
{
	STOP,
	ROTATE
}rotate_state;

void fire_detector_Init (void);
void display_temp (void);
void display_warning (u16 result);
void display_alarm(void);
void motor_rotating (rotate_state state , u8 speed);


#endif /* FIRE_DETECTOR_H_ */
