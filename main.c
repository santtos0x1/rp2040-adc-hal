#include <stdio.h>
#include <stdint.h>
#include "config.h"
#include "hadware_init.h"

int main()
{
    *RESETSREG_BIT_SET &= ~(IO_BANK0_BIT | PADS_BANK0_BIT);
    while(!IS_RESET_DONE()){}

    // Set GPIO 25 to SIO
   *GPIO25_SET_FUNCT = GPIO_FUNC_SIO; 

    

    return 0;
}
