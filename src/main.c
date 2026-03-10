#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "hadware_init.h"
#include "adc_converter.h"

int main()
{
    // Resets bits 5(IO_BANK0) and 8(PADS_BANK0) from reset register
    *RESETSREG_BIT_SET &= ~(IO_BANK0_BIT | PADS_BANK0_BIT);

    // Waits until the reset is done
    while(!IS_RESET_DONE()){}

    // Sets GPIO 25 to SIO
    *GPIO25_SET_FUNCT = GPIO_FUNC_SIO; 

    // Sets output enable to GPIO 25
    *GPIO_OE_SET = GPIO25_BIT;

    // Enables bit 1(TS_EN) to power on temperature sensor
    *SET_ADC_CS |= TS_EN_BIT;
    while(1)
    {
        // Enables bit 2(START_ONCE) to get internal temperature 
        *SET_ADC_CS |= START_ONCE_BIT;
    
        // Gets the internal raw temperature
        volatile uint32_t *raw_result_ptr = GET_ADC_RESULT;
        
        // Converts the raw data to milli celsius
        uint32_t internal_temperature = get_temp_milli_celsius(*raw_result_ptr);

        // Shows the temperature in celsius
        printf("%d", internal_temperature);

        if(internal_temperature > 33000)
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
