#include "adc_get_temp.h"
#include <stdint.h>
#include "registers.h"

#define GET_ADC_RESULT ((volatile uint32_t *)(ADC_INTERNAL_RESULT))
#define SET_ADC_CS     ((volatile uint32_t *)(ADC_INTERNAL_CS))

#define START_ONCE_BIT (1 << 2)

volatile uint32_t get_raw_v(void)
{
    // Enables bit 2(START_ONCE) to get internal temperature 
    *SET_ADC_CS |= START_ONCE_BIT;

    return *GET_ADC_RESULT;
}
