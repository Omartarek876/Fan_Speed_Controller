/*
 * Adc_PbCfg.c
 *
 *  Created on: Feb 15, 2024
 *      Author: omar tarek
 */

#include "Adc.h"

Adc_ConfigurationType Adc_Configuration =
{
    .autoTrigger = ADC_AUTO_TRIGGER_OFF,
    .reference   = ADC_REF_AVCC,
    .prescaler   = 128
};
