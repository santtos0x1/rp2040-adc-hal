#include <stdint.h>
#include "thermal_manager.h"
#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all();
   
    __asm volatile ("nop");

    // Starts driver
    init_thermal_m();


    while(1)
    {
        uint32_t mcu_temp = get_thermal();

        printf("RP2040 Temperature: %d\n", mcu_temp);
    }

    return 0;
}
