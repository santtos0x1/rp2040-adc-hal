#include <stdint.h>

#include "adc_converter.h"
#include "thermal_manager.h"
#include "gpio_init.h"
#include "adc_init.h"
#include "adc_get_temp.h"
#include "registers.h"

#define WARNING_MCU_TEMP 35000
#define GPIO_OUT_SET     ((volatile uint32_t *)(GPIO_OUT_SET_OFFSET))
#define GPIO_OUT_CLR     ((volatile uint32_t *)(GPIO_OUT_CLR_OFFSET))
#define GPIO25_BIT       (1 << 25)

#define R_TIMELR         ((volatile uint32_t *)(TIMER_TIMELR))

void init_thermal_m(void)
{
    gpio_init_per();
    adc_init_per();
}

uint32_t get_thermal(void)
{
    volatile uint32_t raw_result_ptr;

    uint32_t last_time = 0;
    const uint32_t t_delay = 100000;
    uint32_t current_time = *R_TIMELR;

    // 100 ms delay
    if((current_time - last_time) >= t_delay)
    {
        // Gets the internal raw temperature
        raw_result_ptr = get_raw_v();
        last_time = current_time;
    }
       
    // Converts the raw data to milli celsius
    uint32_t internal_temperature = get_temp_milli_celsius(raw_result_ptr);

    return internal_temperature;
}
