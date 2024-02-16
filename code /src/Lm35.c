/*
 * Lm35.c
 *
 *  Created on: Feb 15, 2024
 *      Author: omar tarek
 */
#include "StdTypes.h"
#include "Adc.h"
#include "Delay.h"
#include "Lm35.h"

u8 Lm35_GetTemperature (Adc_ChannelType adcChannel)
{

        u32 result = 0;
        Adc_StartConversion(adcChannel);
        result = Adc_GetResult();
        return ((result*500)/1024);
}

