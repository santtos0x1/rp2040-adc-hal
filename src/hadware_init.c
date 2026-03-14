#include <stdint.h>
#include <stdint.h>

#include "registers.h"
#include "hadware_init.h"

/*
 * @brief Check if reset register is already  
 */
uint8_t IS_RESET_DONE(bit_bank_t bit_bank)
{
    return ((*(volatile uint32_t *)(RESETS_DONE)) & (bit_bank.bit_arr));
}
