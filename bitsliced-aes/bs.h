
#include <stdint.h>
#include "key_schedule.h"
#define BLOCK_SIZE          128
#define KEY_SCHEDULE_SIZE   176
#define WORD_SIZE           32
#define BS_BLOCK_SIZE       (BLOCK_SIZE * WORD_SIZE / 8)
#define WORDS_PER_BLOCK     (BLOCK_SIZE / WORD_SIZE)



typedef uint32_t    word_t;
#define ONE         1UL
#define MUL_SHIFT   5
#define WFMT        "x"
#define WPAD        "08"


void bs_transpose(word_t * blocks);
void bs_transpose_rev(word_t * blocks);
void bs_transpose_dst(word_t * transpose, word_t * blocks);

void bs_sbox(word_t U[8]);

void bs_shiftrows(word_t * B);

void bs_mixcolumns(word_t * B);

void bs_shiftmix(word_t * B);

void bs_addroundkey(word_t * B, word_t * rk);
void bs_apply_sbox(word_t * input);


void expand_key(unsigned char *in);
void bs_expand_key(word_t (* rk)[BLOCK_SIZE], uint8_t * key);

void bs_cipher(word_t state[BLOCK_SIZE], word_t (* rk)[BLOCK_SIZE]);


