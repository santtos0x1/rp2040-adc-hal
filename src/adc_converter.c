#include <stdint.h>
#include "adc_converter.h"

/*
 * @brief Converts the raw value got from ADC register to temperature
 */
uint32_t get_temp_milli_celsius(uint16_t raw_value)
{
    // Gets voltage
    int32_t mv = (raw_value * 3300) / 4096;

    // Converts voltage to temperature
    int32_t temp = 27000 - ((mv - 706) * 1000 / 1721);

    return temp;
}
