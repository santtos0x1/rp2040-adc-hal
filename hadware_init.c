#include <stdint.h>
#include "hadware_init.h"
#include "registers.h"
#include "config.h"

uint8_t IS_RESET_DONE(void)
{
    return ((*(volatile uint32_t *)(RESETS_DONE)) & (IO_BANK0_BIT | PADS_BANK0_BIT)); 
}
