#include <stdint.h>
#include <stdio.h>

#include "thermal_manager.h"

#include "pico/stdlib.h"

int main()
{
    // For USB debugging
    stdio_init_all();
   
    // Short delay
    __asm volatile ("nop");

    // Starts driver
    init_thermal_m();

    while(1)
    {
        int32_t mcu_temp = get_thermal();

        printf("RP2040 Temperature: %d\n", mcu_temp);
    }

    return 0;
}
