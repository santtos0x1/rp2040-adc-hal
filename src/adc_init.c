#include <stdint.h>
#include "adc_init.h"
#include "registers.h"

#define SET_ADC_CS ((volatile uint32_t *)(ADC_INTERNAL_CS))
#define TS_EN_BIT  (1 << 1)
#define ADC_EN_BIT (1 << 0)

void adc_init_per(void)
{
    // Enables bit 0(EN) to power ADC and enable clock
    *SET_ADC_CS |= ADC_EN_BIT;

    // Enables bit 1(TS_EN) to power on temperature sensor
    *SET_ADC_CS |= TS_EN_BIT;
}
