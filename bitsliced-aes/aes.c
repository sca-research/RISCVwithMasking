
/*
 *
 * Virginia Tech
 * Secure Embedded Systems Lab
 *
 * Copyright (C) 2017 Virginia Tech
 *
 * Written in 2017 by Conor Patrick. 
 *
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#include <string.h>
#include "aes.h"
#include "bs.h"

//One block encryption
void aes_ecb_encrypt(uint8_t * outputb, uint8_t * inputb,  uint8_t * key)
{
    word_t input_space[BLOCK_SIZE];
    word_t rk[11][BLOCK_SIZE];

    memset(outputb,0,16);
    word_t * state = (word_t *)outputb;

    bs_expand_key(rk, key);

    memset(input_space,0,BS_BLOCK_SIZE);
    memmove(input_space, inputb, 16);
    bs_cipher(input_space,rk);
    memmove(outputb, input_space, 16);

}




