#include <stdio.h>
#include <stdint.h>
#include "adc_converter.h"
#include "gpio_init.h"
#include "adc_init.h"
#include "adc_get_temp.h"
#include "registers.h"

#define WARNING_MCU_TEMP 33000
#define GPIO_OUT_SET     ((volatile uint32_t *)(GPIO_OUT_SET_OFFSET))
#define GPIO_OUT_CLR     ((volatile uint32_t *)(GPIO_OUT_CLR_OFFSET))
#define GPIO25_BIT       (1 << 25)

int main()
{
    gpio_init();
    adc_init();

    while(1)
    {
        // Gets the internal raw temperature
        volatile uint32_t raw_result_ptr = get_raw_v();
        
        // Converts the raw data to milli celsius
        uint32_t internal_temperature = get_temp_milli_celsius(raw_result_ptr);

        // Shows the temperature in celsius
        printf("Temp: %d", internal_temperature);

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
