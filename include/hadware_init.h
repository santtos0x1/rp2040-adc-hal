#ifndef HADWARE_INIT_H
#define HADWARE_INIT_H

#include <stdint.h>

typedef struct {
    uint32_t bit_arr;
} bit_bank_t;

uint8_t IS_RESET_DONE(bit_bank_t bit_bank);

#endif
