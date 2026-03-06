#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "hadware_init.h"
#include "adc_converter.h"

int main()
{
    
    *RESETSREG_BIT_SET &= ~(IO_BANK0_BIT | PADS_BANK0_BIT);
    while(!IS_RESET_DONE()){}

    // Set GPIO 25 to SIO
    *GPIO25_SET_FUNCT = GPIO_FUNC_SIO; 

    // Set output enable to GPIO 25
    *GPIO_OE_SET = GPIO25_BIT;

    *SET_ADC_CS &= TS_EN_BIT;
    *SET_ADC_CS &= START_ONCE_BIT;

    volatile uint32_t *raw_result_ptr = GET_ADC_RESULT;
    uint32_t ADC_voltage = get_temp_milli_celsius(*raw_result_ptr);

    return 0;
}
