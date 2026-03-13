#include <stdio.h>
#include <stdint.h>
#include "adc_converter.h"
#include "gpio_init.h"
#include "adc_init.h"
#include "adc_get_temp.h"
#include "registers.h"
#include "config.h"

#if USB_DEBUG
    // For USB debugging
    #include "pico/stdlib.h"
#endif

#define WARNING_MCU_TEMP 35000
#define GPIO_OUT_SET     ((volatile uint32_t *)(GPIO_OUT_SET_OFFSET))
#define GPIO_OUT_CLR     ((volatile uint32_t *)(GPIO_OUT_CLR_OFFSET))
#define GPIO25_BIT       (1 << 25)

#define R_TIMELR         ((volatile uint32_t *)(TIMER_TIMELR))

int main()
{
    volatile uint32_t raw_result_ptr;
    uint32_t last_time = 0;
    const uint32_t t_delay = 100000;

    #if USB_DEBUG
        // For USB debugging
        stdio_init_all();
    #endif

    gpio_init_per();
    adc_init_per();

    while(1)
    {
        uint32_t current_time = *R_TIMELR;

        if((current_time - last_time) >= t_delay)
        {
            // Gets the internal raw temperature
            raw_result_ptr = get_raw_v();
            last_time = current_time;
        }
       
        // Converts the raw data to milli celsius
        uint32_t internal_temperature = get_temp_milli_celsius(raw_result_ptr);

        #if USB_DEBUG
            // Shows the temperature in celsius
            printf("Temp: %d\n", internal_temperature);
        #endif

        if(internal_temperature > WARNING_MCU_TEMP)
        {
            *GPIO_OUT_SET = GPIO25_BIT;
        }
        else
        {
            *GPIO_OUT_CLR = GPIO25_BIT; 
        }
    }

    return 0;
}
