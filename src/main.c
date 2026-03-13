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

int main()
{
    #if USB_DEBUG
        // For USB debugging
        stdio_init_all();
    #endif

    gpio_init_per();
    adc_init_per();

    while(1)
    {
        // Gets the internal raw temperature
        volatile uint32_t raw_result_ptr = get_raw_v();
        
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
