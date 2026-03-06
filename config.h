#ifndef CONFIG_H
#define CONFIG_H

#include "registers.h"
#include <stdint.h>

#define RESETSREG_BIT_SET ((volatile uint32_t *)(RESETS_BASE)) 
#define GPIO25_SET_FUNCT  ((volatile uint32_t *)(GPIO25_CTRL))
#define GPIO_OE_SET       ((volatile uint32_t *)(GPIO_OE_SET_OFFSET))

#define IO_BANK0_BIT      (1 << 5)
#define PADS_BANK0_BIT    (1 << 8)
#define GPIO25_BIT        (1 << 25)

#define GPIO_FUNC_SIO     5

#endif
