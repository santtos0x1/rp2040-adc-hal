#include <stdint.h>

#include "registers.h"
#include "adc_get_temp.h"

#define GET_ADC_RESULT ((volatile uint32_t *)(ADC_INTERNAL_RESULT))
#define SET_ADC_CS     ((volatile uint32_t *)(ADC_INTERNAL_CS))

#define ERR_STICKY_BIT  (1 << 10)
#define START_ONCE_BIT  (1 << 2)
#define READY_BIT       (1 << 8)

#define AINSEL_SHIFT    12 // Start bit
#define AINSEL_MUX_MASK (0x7 << AINSEL_SHIFT) // (14, 13, 12)

volatile uint32_t get_raw_v(void)
{
    // Clears AINSEL bits (000)
    *SET_ADC_CS &= ~(AINSEL_MUX_MASK);

    // Set bits 14, 13 and 12 to (100), to select channel 4 in mux
    *SET_ADC_CS |= (0b100 << AINSEL_SHIFT);

    // Clears before error to start a new conversion
    *SET_ADC_CS |= ERR_STICKY_BIT;

    // Enables bit 2(START_ONCE) to get internal temperature 
    *SET_ADC_CS |= START_ONCE_BIT;

    // Waits until finish conversion
    while(!(*SET_ADC_CS & READY_BIT)){};

    // No operation assembly tag for "delay"
    __asm volatile ("nop");

    return *GET_ADC_RESULT;
}
