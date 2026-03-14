#include <stdint.h>

#include "adc_converter.h"
#include "thermal_manager.h"
#include "gpio_init.h"
#include "adc_init.h"
#include "adc_get_temp.h"
#include "registers.h"

#define GPIO_OUT_SET     ((volatile uint32_t *)(GPIO_OUT_SET_OFFSET))
#define GPIO_OUT_CLR     ((volatile uint32_t *)(GPIO_OUT_CLR_OFFSET))
#define GPIO25_BIT       (1 << 25)

#define U_TO_MS(x)       (x * 1000)
#define WARNING_MCU_TEMP 35000 // 35* celsius

#define R_TIMELR         ((volatile uint32_t *)(TIMER_TIMELR))

/*
 * @brief Start up all required hardware devices.
*/
void init_thermal_m(void)
{
    gpio_init_per();
    adc_init_per();
}

/*
 * @brief After a couple operations from others functions to get the raw data,
 * this function returns MCU temperature in real time.
*/
int32_t get_thermal(void)
{
    volatile uint16_t raw_result;

    uint32_t last_time = 0;
    const uint32_t t_delay = U_TO_MS(100);
    uint32_t current_time = *R_TIMELR;

    // Hardware delay: 100ms
    if((current_time - last_time) >= t_delay)
    {
        // Gets the internal raw temperature
        raw_result = get_raw_v();
        last_time = current_time;
    }
       
    // Converts the raw data to milli celsius
    int32_t internal_temperature = get_temp_milli_celsius(raw_result);

    return internal_temperature;
}
