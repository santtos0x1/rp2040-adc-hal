#include "gpio_init.h"
#include <stdint.h>
#include "registers.h"
#include "string.h"
#include "hadware_init.h"

#define IO_BANK0_BIT      (1 << 5)
#define PADS_BANK0_BIT    (1 << 8)
#define ADC_BIT           (1 << 0)
#define GPIO25_BIT        (1 << 25)
#define RESETSREG_BIT_SET ((volatile uint32_t *)(RESETS_BASE)) 
#define GPIO25_SET_FUNCT  ((volatile uint32_t *)(GPIO25_CTRL))
#define GPIO_OE_SET       ((volatile uint32_t *)(GPIO_OE_SET_OFFSET))
#define GPIO_FUNC_SIO     5

void gpio_init_per(void)
{
    bit_bank_t bit_bank;
    // Sets bits to 1 in a 32 bit bitset
    bit_bank.bit_arr |= (IO_BANK0_BIT | PADS_BANK0_BIT | ADC_BIT);

    // Reset bits from reset register
    *RESETSREG_BIT_SET &= ~(bit_bank.bit_arr);

    // Waits until the reset is done
    while(!IS_RESET_DONE(bit_bank)){}

    // Resets bitset from struct
    memset(&bit_bank, 0, sizeof(bit_bank_t));

    // Sets GPIO 25 to SIO
    *GPIO25_SET_FUNCT = GPIO_FUNC_SIO; 

    // Sets output enable to GPIO 25
    *GPIO_OE_SET = GPIO25_BIT;
}
