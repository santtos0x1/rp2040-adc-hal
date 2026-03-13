#ifndef REGISTERS_H
#define REGISTERS_H

#define RESETS_BASE   0x4000c000
#define SIO_BASE      0xd0000000
#define IO_BANK0_BASE 0x40014000
#define ADC_BASE      0x4004c000
#define TIMER_BASE    0x40054000

#define RESETS_DONE          RESETS_BASE   + 0x8
#define GPIO25_CTRL          IO_BANK0_BASE + 0x0cc
#define GPIO_OE_SET_OFFSET   SIO_BASE      + 0x024
#define ADC_INTERNAL_CS      ADC_BASE      + 0x00
#define ADC_INTERNAL_RESULT  ADC_BASE      + 0x04
#define GPIO_OUT_SET_OFFSET  SIO_BASE      + 0x014
#define GPIO_OUT_CLR_OFFSET  SIO_BASE      + 0x018
#define TIMER_TIMELR        TIMER_BASE    + 0x0c

#endif
