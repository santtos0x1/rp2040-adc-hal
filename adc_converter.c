#include <stdint.h>
#include "adc_converter.h"

int32_t get_temp_milli_celsius(uint16_t raw_value)
{
    int32_t mv = (raw_value * 3300) / 4096;

    int32_t temp = 27000 - ((mv - 706) * 1000 / 1721);

    return temp;
}
