/*
 * Lm35.h
 *
 *  Created on: Feb 15, 2024
 *      Author: omar tarek
 */

#ifndef INC_LM35_H_
#define INC_LM35_H_

#include "StdTypes.h"
#include "Adc.h"

u8 Lm35_GetTemperature (Adc_ChannelType adcChannel);

#endif /* INC_LM35_H_ */
