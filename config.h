#ifndef CONFIG_H
#define CONFIG_H

#include "registers.h"
#include <stdint.h>

#define RESETSREG_BIT_SET ((volatile uint32_t *)(RESETS_BASE)) 
#define GPIO25_SET_FUNCT  ((volatile uint32_t *)(GPIO25_CTRL))
#define GPIO_OE_SET       ((volatile uint32_t *)(GPIO_OE_SET_OFFSET))
#define SET_ADC_CS        ((volatile uint32_t *)(ADC_INTERNAL_CS))
#define GET_ADC_RESULT    ((volatile uint32_t *)(ADC_INTERNAL_RESULT))

#define IO_BANK0_BIT      (1 << 5)
#define PADS_BANK0_BIT    (1 << 8)
#define GPIO25_BIT        (1 << 25)
#define TS_EN_BIT         (1 << 1)
#define START_ONCE_BIT    (1 << 2)

#define GPIO_FUNC_SIO     5

#endif
