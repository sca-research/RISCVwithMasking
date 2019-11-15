
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
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "bs.h"


#define bs2le(x) (x)
#define bs2be(x) (x)



void bs_addroundkey(word_t * B, word_t * rk)
{
    int i;
    for (i = 0; i < BLOCK_SIZE; i++)
        B[i] ^= rk[i];
}

void bs_apply_sbox(word_t ** input)
{
    int i;
    for(i=0; i < BLOCK_SIZE; i+=8)
    {
        bs_sbox(input[0]+i,input[1]+i);
    }
}
/*
void maskedXOR(word_t* input1, word_t* input2, word_t* output)
{
   for(int i=0;i<ORDER;i++)
    output[i]=input1[i]^input2[i];

}
*/
extern void maskedXOR(word_t* input1, word_t* input2, word_t* output);
extern void maskedAND(word_t* input1, word_t* input2, word_t* output);
/*void maskedAND(word_t* input1, word_t* input2, word_t* output)
{
   output[0]=(input1[0]&input2[0])^(input1[0] | (~input2[1]));
   output[1]=(input1[1]&input2[0])^(input1[1] | (~input2[1]));
}
*/
void bs_sbox(word_t U0[8],word_t U1[8])
{
    word_t S[8][ORDER];
    word_t U[8][ORDER];
    word_t
        T1[ORDER],T2[ORDER],T3[ORDER],T4[ORDER],T5[ORDER],T6[ORDER],T7[ORDER],T8[ORDER],
        T9[ORDER],T10[ORDER],T11[ORDER],T12[ORDER],T13[ORDER],T14[ORDER],T15[ORDER],T16[ORDER],
        T17[ORDER],T18[ORDER],T19[ORDER],T20[ORDER],T21[ORDER],T22[ORDER],T23[ORDER],T24[ORDER],
        T25[ORDER], T26[ORDER], T27[ORDER];

    word_t
        M1[ORDER],M2[ORDER],M3[ORDER],M4[ORDER],M5[ORDER],M6[ORDER],M7[ORDER],M8[ORDER],
        M9[ORDER],M10[ORDER],M11[ORDER],M12[ORDER],M13[ORDER],M14[ORDER],M15[ORDER],
        M16[ORDER],M17[ORDER],M18[ORDER],M19[ORDER],M20[ORDER],M21[ORDER],M22[ORDER],
        M23[ORDER],M24[ORDER],M25[ORDER],M26[ORDER],M27[ORDER],M28[ORDER],M29[ORDER],
        M30[ORDER],M31[ORDER],M32[ORDER],M33[ORDER],M34[ORDER],M35[ORDER],M36[ORDER],
        M37[ORDER],M38[ORDER],M39[ORDER],M40[ORDER],M41[ORDER],M42[ORDER],M43[ORDER],
        M44[ORDER],M45[ORDER],M46[ORDER],M47[ORDER],M48[ORDER],M49[ORDER],M50[ORDER],
        M51[ORDER],M52[ORDER],M53[ORDER],M54[ORDER],M55[ORDER],M56[ORDER],M57[ORDER],
        M58[ORDER],M59[ORDER],M60[ORDER],M61[ORDER],M62[ORDER],M63[ORDER];

    word_t
        L0[ORDER],L1[ORDER],L2[ORDER],L3[ORDER],L4[ORDER],L5[ORDER],L6[ORDER],L7[ORDER],L8[ORDER],
        L9[ORDER],L10[ORDER],L11[ORDER],L12[ORDER],L13[ORDER],L14[ORDER],
        L15[ORDER],L16[ORDER],L17[ORDER],L18[ORDER],L19[ORDER],L20[ORDER],
        L21[ORDER],L22[ORDER],L23[ORDER],L24[ORDER],L25[ORDER],L26[ORDER],
        L27[ORDER],L28[ORDER],L29[ORDER];

    for(int i=0;i<8;i++)
    {
      U[i][0]=U0[i];
      U[i][1]=U1[i];
    }

    maskedXOR(U[7],U[4],T1);//T1 = U[7] ^ U[4];
    maskedXOR(U[7],U[2],T2);//T2 = U[7] ^ U[2];
    maskedXOR(U[7],U[1],T3);//T3 = U[7] ^ U[1];
    maskedXOR(U[4],U[2],T4);//T4 = U[4] ^ U[2];
    maskedXOR(U[3],U[1],T5);//T5 = U[3] ^ U[1];
    maskedXOR(T1,T5,T6);    //T6 = T1 ^ T5;
    maskedXOR(U[6],U[5],T7);//T7 = U[6] ^ U[5];
    maskedXOR(U[0],T6,T8);  //T8 = U[0] ^ T6;
    maskedXOR(U[0],T7,T9);  //T9 = U[0] ^ T7;
    maskedXOR(T6,T7,T10);   //T10 = T6 ^ T7;
    maskedXOR(U[6],U[2],T11);//T11 = U[6] ^ U[2];
    maskedXOR(U[5],U[2],T12);//T12 = U[5] ^ U[2];
    maskedXOR(T3,T4,T13);    //T13 = T3 ^ T4;
    maskedXOR(T6,T11,T14);   //T14 = T6 ^ T11;
    maskedXOR(T5,T11,T15);   //T15 = T5 ^ T11;
    maskedXOR(T5,T12,T16);   //T16 = T5 ^ T12;
    maskedXOR(T9,T16,T17);   //T17 = T9 ^ T16;
    maskedXOR(U[4],U[0],T18);//T18 = U[4] ^ U[0];
    maskedXOR(T7,T18,T19);   //T19 = T7 ^ T18;
    maskedXOR(T1,T19,T20);   //T20 = T1 ^ T19;
    maskedXOR(U[1],U[0],T21);//T21 = U[1] ^ U[0];
    maskedXOR(T7,T21,T22);   //T22 = T7 ^ T21;
    maskedXOR(T2,T22,T23);//T23 = T2 ^ T22;
    maskedXOR(T2,T10,T24);//T24 = T2 ^ T10;
    maskedXOR(T20,T17,T25);//T25 = T20 ^ T17;
    maskedXOR(T3,T16,T26);//T26 = T3 ^ T16;
    maskedXOR(T1,T12,T27);//T27 = T1 ^ T12;
    maskedAND(T13,T6,M1);//M1 = T13 & T6;
    maskedAND(T23,T8,M2);//M2 = T23 & T8;
    maskedXOR(T14,M1,M3);//M3 = T14 ^ M1;
    maskedAND(T19,U[0],M4);//M4 = T19 & U[0];
    maskedXOR(M4,M1,M5);//M5 = M4 ^ M1;
    maskedAND(T3,T16,M6);//M6 = T3 & T16;
    maskedAND(T22,T9,M7);//M7 = T22 & T9;
    maskedXOR(T26,M6,M8);//M8 = T26 ^ M6;
    maskedAND(T20,T17,M9);//M9 = T20 & T17;
    maskedXOR(M9,M6,M10);//M10 = M9 ^ M6;
    maskedAND(T1,T15,M11);//M11 = T1 & T15;
    maskedAND(T4,T27,M12);//M12 = T4 & T27;
    maskedXOR(M12,M11,M13);//M13 = M12 ^ M11;
    maskedAND(T2,T10,M14);//M14 = T2 & T10;
    maskedXOR(M14,M11,M15);//M15 = M14 ^ M11;
    maskedXOR(M3,M2,M16);//M16 = M3 ^ M2;
    maskedXOR(M5,T24,M17);//M17 = M5 ^ T24;
    maskedXOR(M8,M7,M18);//M18 = M8 ^ M7;
    maskedXOR(M10,M15,M19);//M19 = M10 ^ M15;
    maskedXOR(M16,M13,M20);//M20 = M16 ^ M13;
    maskedXOR(M17,M15,M21);//M21 = M17 ^ M15;
    maskedXOR(M18,M13,M22);//M22 = M18 ^ M13;
    maskedXOR(M19,T25,M23);//M23 = M19 ^ T25;
    maskedXOR(M22,M23,M24);//M24 = M22 ^ M23;
    maskedAND(M22,M20,M25);//M25 = M22 & M20;
    maskedXOR(M21,M25,M26);//M26 = M21 ^ M25;
    maskedXOR(M20,M21,M27);//M27 = M20 ^ M21;
    maskedXOR(M23,M25,M28);//M28 = M23 ^ M25;
    maskedAND(M27,M28,M29);//M29 = M28 & M27;
    maskedAND(M26,M24,M30);//M30 = M26 & M24;
    maskedAND(M23,M20,M31);//M31 = M20 & M23;
    maskedAND(M27,M31,M32);//M32 = M27 & M31;
    maskedXOR(M27,M25,M33);//M33 = M27 ^ M25;
    maskedAND(M21,M22,M34);//M34 = M21 & M22;
    maskedAND(M24,M34,M35);//M35 = M24 & M34;
    maskedXOR(M25,M24,M36);//M36 = M24 ^ M25;
    maskedXOR(M21,M29,M37);//M37 = M21 ^ M29;
    maskedXOR(M32,M33,M38);//M38 = M32 ^ M33;
    maskedXOR(M23,M30,M39);//M39 = M23 ^ M30;
    maskedXOR(M35,M36,M40);//M40 = M35 ^ M36;
    maskedXOR(M38,M40,M41);//M41 = M38 ^ M40;
    maskedXOR(M37,M39,M42);//M42 = M37 ^ M39;
    maskedXOR(M37,M38,M43);//M43 = M37 ^ M38;
    maskedXOR(M39,M40,M44);//M44 = M39 ^ M40;
    maskedXOR(M42,M41,M45);//M45 = M42 ^ M41;
    maskedAND(M44,T6,M46);//M46 = M44 & T6;
    maskedAND(M40,T8,M47);//M47 = M40 & T8;
    maskedAND(M39,U[0],M48);//M48 = M39 & U[0];
    maskedAND(M43,T16,M49);//M49 = M43 & T16;
    maskedAND(M38,T9,M50);//M50 = M38 & T9;
    maskedAND(M37,T17,M51);//M51 = M37 & T17;
    maskedAND(M42,T15,M52);//M52 = M42 & T15;
    maskedAND(M45,T27,M53);//M53 = M45 & T27;
    maskedAND(M41,T10,M54);//M54 = M41 & T10;
    maskedAND(M44,T13,M55);//M55 = M44 & T13;
    maskedAND(M40,T23,M56);//M56 = M40 & T23;
    maskedAND(M39,T19,M57);//M57 = M39 & T19;
    maskedAND(M43,T3,M58);//M58 = M43 & T3;
    maskedAND(M38,T22,M59);//M59 = M38 & T22;
    maskedAND(M37,T20,M60);//M60 = M37 & T20;
    maskedAND(M42,T1,M61);//M61 = M42 & T1;
    maskedAND(M45,T4,M62);//M62 = M45 & T4;
    maskedAND(M41,T2,M63);//M63 = M41 & T2;
    maskedXOR(M61,M62,L0);//L0 = M61 ^ M62;
    maskedXOR(M50,M56,L1);//L1 = M50 ^ M56;
    maskedXOR(M46,M48,L2);//L2 = M46 ^ M48;
    maskedXOR(M47,M55,L3);//L3 = M47 ^ M55;
    maskedXOR(M54,M58,L4);//L4 = M54 ^ M58;
    maskedXOR(M49,M61,L5);//L5 = M49 ^ M61;
    maskedXOR(M62,L5,L6);//L6 = M62 ^ L5;
    maskedXOR(M46,L3,L7);//L7 = M46 ^ L3;
    maskedXOR(M51,M59,L8);//L8 = M51 ^ M59;
    maskedXOR(M52,M53,L9);//L9 = M52 ^ M53;
    maskedXOR(M53,L4,L10);//L10 = M53 ^ L4;
    maskedXOR(M60,L2,L11);//L11 = M60 ^ L2;
    maskedXOR(M48,M51,L12);//L12 = M48 ^ M51;
    maskedXOR(M50,L0,L13);// L13 = M50 ^ L0;
    maskedXOR(M52,M61,L14);//L14 = M52 ^ M61;
    maskedXOR(M55,L1,L15);// L15 = M55 ^ L1;
    maskedXOR(M56,L0,L16);// L16 = M56 ^ L0;
    maskedXOR(M57,L1,L17);// L17 = M57 ^ L1;
    maskedXOR(M58,L8,L18);// L18 = M58 ^ L8;
    maskedXOR(M63,L4,L19);// L19 = M63 ^ L4;
    maskedXOR(L0,L1,L20);//  L20 = L0 ^ L1;
    maskedXOR(L1,L7,L21);//  L21 = L1 ^ L7;
    maskedXOR(L3,L12,L22);// L22 = L3 ^ L12;
    maskedXOR(L18,L2,L23);// L23 = L18 ^ L2;
    maskedXOR(L15,L9,L24);// L24 = L15 ^ L9;
    maskedXOR(L6,L10,L25);// L25 = L6 ^ L10;
    maskedXOR(L7,L9,L26);//  L26 = L7 ^ L9;
    maskedXOR(L8,L10,L27);// L27 = L8 ^ L10;
    maskedXOR(L11,L14,L28);//L28 = L11 ^ L14;
    maskedXOR(L11,L17,L29);//L29 = L11 ^ L17;
    maskedXOR(L6,L24,S[7]);//S[7] = L6 ^ L24;
    maskedXOR(L16,L26,S[6]);//S[6] = ~(L16 ^ L26);
    S[6][0]=~S[6][0];
    maskedXOR(L19,L28,S[5]);//S[5] = ~(L19 ^ L28);
    S[5][0]=~S[5][0];
    maskedXOR(L6,L21,S[4]);//S[4] = L6 ^ L21;
    maskedXOR(L20,L22,S[3]);//S[3] = L20 ^ L22;
    maskedXOR(L25,L29,S[2]);//S[2] = L25 ^ L29;
    maskedXOR(L13,L27,S[1]);//S[1] = ~(L13 ^ L27);
    S[1][0]=~S[1][0];
    maskedXOR(L6,L23,S[0]);//S[0] = ~(L6 ^ L23);
    S[0][0]=~S[0][0];
    //memmove(U,S,sizeof(S));
    for(int i=0;i<8;i++)
    {
      U0[i]=S[i][0];
      U1[i]=S[i][1];
    }
}

void bs_transpose(word_t * blocks)
{
    word_t transpose[BLOCK_SIZE];
    memset(transpose, 0, sizeof(transpose));
    bs_transpose_dst(transpose,blocks);
    memmove(blocks,transpose,sizeof(transpose));
}

void bs_transpose_dst(word_t * transpose, word_t * blocks)
{
    int i,k;
    word_t w;
    for(k=0; k < WORD_SIZE; k++)
    {
        int bitpos = ONE << k;
        for (i=0; i < WORDS_PER_BLOCK; i++)
        {
            w = bs2le(blocks[k * WORDS_PER_BLOCK + i]);
            int offset = i << MUL_SHIFT;

            int j;
            for(j=0; j < WORD_SIZE; j++)
            {
                // TODO make const time
                transpose[offset + j] |= (w & (ONE << j)) ? bitpos : 0;
            }

                // constant time:
                //transpose[(i<<MUL_SHIFT)+ j] |= (((int64_t)((w & (ONE << j)) << (WORD_SIZE-1-j)))>>(WORD_SIZE-1)) & (ONE<<k);
        }
    }
}

void bs_transpose_rev(word_t * blocks)
{
    int i,k;
    word_t w;
    word_t transpose[BLOCK_SIZE];
    memset(transpose, 0, sizeof(transpose));
    for(k=0; k < BLOCK_SIZE; k++)
    {
        w = blocks[k];
        word_t bitpos = bs2be(ONE << (k % WORD_SIZE));
        word_t offset = k / WORD_SIZE;
        int j;
        for(j=0; j < WORD_SIZE; j++)
        {
            word_t bit = (w & (ONE << j)) ? (ONE << (k % WORD_SIZE)) : 0;
            transpose[j * WORDS_PER_BLOCK + (offset)] |= bit;
        }

    }
    memmove(blocks,transpose,sizeof(transpose));
}


#define R0          0
#define R1          8
#define R2          16
#define R3          24

#define B0          0
#define B1          32
#define B2          64
#define B3          96

#define R0_shift        (BLOCK_SIZE/4)*0
#define R1_shift        (BLOCK_SIZE/4)*1
#define R2_shift        (BLOCK_SIZE/4)*2
#define R3_shift        (BLOCK_SIZE/4)*3
#define B_MOD           (BLOCK_SIZE)


void bs_shiftrows(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;
    word_t * Br0 = B + 0;
    word_t * Br1 = B + 32;
    word_t * Br2 = B + 64;
    word_t * Br3 = B + 96;
    uint8_t offsetr0 = 0;
    uint8_t offsetr1 = 32;
    uint8_t offsetr2 = 64;
    uint8_t offsetr3 = 96;


    int i;
    for(i=0; i<4; i++)
    {
        Bp[B0 + 0] = Br0[0];
        Bp[B0 + 1] = Br0[1];
        Bp[B0 + 2] = Br0[2];
        Bp[B0 + 3] = Br0[3];
        Bp[B0 + 4] = Br0[4];
        Bp[B0 + 5] = Br0[5];
        Bp[B0 + 6] = Br0[6];
        Bp[B0 + 7] = Br0[7];
        Bp[B1 + 0] = Br1[0];
        Bp[B1 + 1] = Br1[1];
        Bp[B1 + 2] = Br1[2];
        Bp[B1 + 3] = Br1[3];
        Bp[B1 + 4] = Br1[4];
        Bp[B1 + 5] = Br1[5];
        Bp[B1 + 6] = Br1[6];
        Bp[B1 + 7] = Br1[7];
        Bp[B2 + 0] = Br2[0];
        Bp[B2 + 1] = Br2[1];
        Bp[B2 + 2] = Br2[2];
        Bp[B2 + 3] = Br2[3];
        Bp[B2 + 4] = Br2[4];
        Bp[B2 + 5] = Br2[5];
        Bp[B2 + 6] = Br2[6];
        Bp[B2 + 7] = Br2[7];
        Bp[B3 + 0] = Br3[0];
        Bp[B3 + 1] = Br3[1];
        Bp[B3 + 2] = Br3[2];
        Bp[B3 + 3] = Br3[3];
        Bp[B3 + 4] = Br3[4];
        Bp[B3 + 5] = Br3[5];
        Bp[B3 + 6] = Br3[6];
        Bp[B3 + 7] = Br3[7];

        offsetr0 = (offsetr0 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr1 = (offsetr1 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr2 = (offsetr2 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr3 = (offsetr3 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;

        Br0 = B + offsetr0;
        Br1 = B + offsetr1;
        Br2 = B + offsetr2;
        Br3 = B + offsetr3;

        Bp += 8;
    }
    memmove(B,Bp_space,sizeof(Bp_space));
}


#define A0  0
#define A1  8
#define A2  16
#define A3  24

// Does shift rows and mix columns in same step
void bs_shiftmix(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;

    word_t * Br0 = B + 0;
    word_t * Br1 = B + 32;
    word_t * Br2 = B + 64;
    word_t * Br3 = B + 96;

    uint8_t offsetr0 = 0;
    uint8_t offsetr1 = 32;
    uint8_t offsetr2 = 64;
    uint8_t offsetr3 = 96;

        Br0 = B + offsetr0;
        Br1 = B + offsetr1;
        Br2 = B + offsetr2;
        Br3 = B + offsetr3;


    int i;
    for (i = 0; i < 4; i++)
    {
        // B0
        //            2*A0        2*A1              A1           A2           A3
        word_t of =Br0[R0+7]^ Br1[R1+7];
        Bp[A0+0] =                         Br1[R1+0] ^ Br2[R2+0] ^ Br3[R3+0] ^ of;
        Bp[A0+1] = Br0[R0+0] ^ Br1[R1+0] ^ Br1[R1+1] ^ Br2[R2+1] ^ Br3[R3+1] ^ of;
        Bp[A0+2] = Br0[R0+1] ^ Br1[R1+1] ^ Br1[R1+2] ^ Br2[R2+2] ^ Br3[R3+2];
        Bp[A0+3] = Br0[R0+2] ^ Br1[R1+2] ^ Br1[R1+3] ^ Br2[R2+3] ^ Br3[R3+3] ^ of;
        Bp[A0+4] = Br0[R0+3] ^ Br1[R1+3] ^ Br1[R1+4] ^ Br2[R2+4] ^ Br3[R3+4] ^ of;
        Bp[A0+5] = Br0[R0+4] ^ Br1[R1+4] ^ Br1[R1+5] ^ Br2[R2+5] ^ Br3[R3+5];
        Bp[A0+6] = Br0[R0+5] ^ Br1[R1+5] ^ Br1[R1+6] ^ Br2[R2+6] ^ Br3[R3+6];
        Bp[A0+7] = Br0[R0+6] ^ Br1[R1+6] ^ Br1[R1+7] ^ Br2[R2+7] ^ Br3[R3+7];

        //            A0            2*A1        2*A2        A2       A3
        of = Br1[R1+7] ^ Br2[R2+7];
        Bp[A1+0] = Br0[R0+0]                         ^ Br2[R2+0] ^ Br3[R3+0] ^ of;
        Bp[A1+1] = Br0[R0+1] ^ Br1[R1+0] ^ Br2[R2+0] ^ Br2[R2+1] ^ Br3[R3+1] ^ of;
        Bp[A1+2] = Br0[R0+2] ^ Br1[R1+1] ^ Br2[R2+1] ^ Br2[R2+2] ^ Br3[R3+2];
        Bp[A1+3] = Br0[R0+3] ^ Br1[R1+2] ^ Br2[R2+2] ^ Br2[R2+3] ^ Br3[R3+3] ^ of;
        Bp[A1+4] = Br0[R0+4] ^ Br1[R1+3] ^ Br2[R2+3] ^ Br2[R2+4] ^ Br3[R3+4] ^ of;
        Bp[A1+5] = Br0[R0+5] ^ Br1[R1+4] ^ Br2[R2+4] ^ Br2[R2+5] ^ Br3[R3+5];
        Bp[A1+6] = Br0[R0+6] ^ Br1[R1+5] ^ Br2[R2+5] ^ Br2[R2+6] ^ Br3[R3+6];
        Bp[A1+7] = Br0[R0+7] ^ Br1[R1+6] ^ Br2[R2+6] ^ Br2[R2+7] ^ Br3[R3+7];

        //            A0             A1      2*A2        2*A3         A3
        of = Br2[R2+7] ^ Br3[R3+7];
        Bp[A2+0] = Br0[R0+0] ^ Br1[R1+0]                         ^ Br3[R3+0] ^ of;
        Bp[A2+1] = Br0[R0+1] ^ Br1[R1+1] ^ Br2[R2+0] ^ Br3[R3+0] ^ Br3[R3+1] ^ of;
        Bp[A2+2] = Br0[R0+2] ^ Br1[R1+2] ^ Br2[R2+1] ^ Br3[R3+1] ^ Br3[R3+2];
        Bp[A2+3] = Br0[R0+3] ^ Br1[R1+3] ^ Br2[R2+2] ^ Br3[R3+2] ^ Br3[R3+3] ^ of;
        Bp[A2+4] = Br0[R0+4] ^ Br1[R1+4] ^ Br2[R2+3] ^ Br3[R3+3] ^ Br3[R3+4] ^ of;
        Bp[A2+5] = Br0[R0+5] ^ Br1[R1+5] ^ Br2[R2+4] ^ Br3[R3+4] ^ Br3[R3+5];
        Bp[A2+6] = Br0[R0+6] ^ Br1[R1+6] ^ Br2[R2+5] ^ Br3[R3+5] ^ Br3[R3+6];
        Bp[A2+7] = Br0[R0+7] ^ Br1[R1+7] ^ Br2[R2+6] ^ Br3[R3+6] ^ Br3[R3+7];

        //             A0          2*A0           A1       A2      2*A3
        of = Br0[R0+7] ^ Br3[R3+7];
        Bp[A3+0] = Br0[R0+0] ^             Br1[R1+0] ^ Br2[R2+0]             ^ of;
        Bp[A3+1] = Br0[R0+1] ^ Br0[R0+0] ^ Br1[R1+1] ^ Br2[R2+1] ^ Br3[R3+0] ^ of;
        Bp[A3+2] = Br0[R0+2] ^ Br0[R0+1] ^ Br1[R1+2] ^ Br2[R2+2] ^ Br3[R3+1];
        Bp[A3+3] = Br0[R0+3] ^ Br0[R0+2] ^ Br1[R1+3] ^ Br2[R2+3] ^ Br3[R3+2] ^ of;
        Bp[A3+4] = Br0[R0+4] ^ Br0[R0+3] ^ Br1[R1+4] ^ Br2[R2+4] ^ Br3[R3+3] ^ of;
        Bp[A3+5] = Br0[R0+5] ^ Br0[R0+4] ^ Br1[R1+5] ^ Br2[R2+5] ^ Br3[R3+4];
        Bp[A3+6] = Br0[R0+6] ^ Br0[R0+5] ^ Br1[R1+6] ^ Br2[R2+6] ^ Br3[R3+5];
        Bp[A3+7] = Br0[R0+7] ^ Br0[R0+6] ^ Br1[R1+7] ^ Br2[R2+7] ^ Br3[R3+6];

        Bp += BLOCK_SIZE/4;

        offsetr0 = (offsetr0 + BLOCK_SIZE/4) & 0x7f;
        offsetr1 = (offsetr1 + BLOCK_SIZE/4) & 0x7f;
        offsetr2 = (offsetr2 + BLOCK_SIZE/4) & 0x7f;
        offsetr3 = (offsetr3 + BLOCK_SIZE/4) & 0x7f;

        Br0 = B + offsetr0;
        Br1 = B + offsetr1;
        Br2 = B + offsetr2;
        Br3 = B + offsetr3;
    }

    memmove(B,Bp_space,sizeof(Bp_space));
}



void bs_mixcolumns(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;
    // to understand this, see
    // https://en.wikipedia.org/wiki/Rijndael_mix_columns
    
    int i = 0;
    for (; i < 4; i++)
    {
    //  of = A0 ^ A1;
    //  A0 = A0 ^ (0x1b & ((signed char)of>>7));

    //// 2 * A0
    //  A0 = A0 ^ (A0 << 1)

    //// + 3 * A1
    //  A0 = A0 ^ (A1)
    //  A0 = A0 ^ (A1<<1)

    //// + A2 + A3
    //  A0 = A0 ^ (A2)
    //  A0 = A0 ^ (A3)
    //          A0.7    A1.7
    word_t of = B[A0+7] ^ B[A1+7];

    //          2*A0     2*A1          A1      A2           A3
    Bp[A0+0] =                     B[A1+0] ^ B[A2+0] ^ B[A3+0] ^ of;
    Bp[A0+1] = B[A0+0] ^ B[A1+0] ^ B[A1+1] ^ B[A2+1] ^ B[A3+1] ^ of;
    Bp[A0+2] = B[A0+1] ^ B[A1+1] ^ B[A1+2] ^ B[A2+2] ^ B[A3+2];
    Bp[A0+3] = B[A0+2] ^ B[A1+2] ^ B[A1+3] ^ B[A2+3] ^ B[A3+3] ^ of;
    Bp[A0+4] = B[A0+3] ^ B[A1+3] ^ B[A1+4] ^ B[A2+4] ^ B[A3+4] ^ of;
    Bp[A0+5] = B[A0+4] ^ B[A1+4] ^ B[A1+5] ^ B[A2+5] ^ B[A3+5];
    Bp[A0+6] = B[A0+5] ^ B[A1+5] ^ B[A1+6] ^ B[A2+6] ^ B[A3+6];
    Bp[A0+7] = B[A0+6] ^ B[A1+6] ^ B[A1+7] ^ B[A2+7] ^ B[A3+7];



    //  of = A1 ^ A2
    //  A1 = A1 ^ (0x1b & ((signed char)of>>7));

    //// A0
    //  A1 = A1 ^ (A0)

    //// + 2 * A1
    //  A1 = A1 ^ (A1 << 1)

    //// + 3 * A2
    //  A1 = A1 ^ (A2)
    //  A1 = A1 ^ (A2<<1)

    //// + A3
    //  A1 = A1 ^ (A3)

    of = B[A1+7] ^ B[A2+7];

    //          A0      2*A1        2*A2      A2        A3
    Bp[A1+0] = B[A0+0]                     ^ B[A2+0] ^ B[A3+0] ^ of;
    Bp[A1+1] = B[A0+1] ^ B[A1+0] ^ B[A2+0] ^ B[A2+1] ^ B[A3+1] ^ of;
    Bp[A1+2] = B[A0+2] ^ B[A1+1] ^ B[A2+1] ^ B[A2+2] ^ B[A3+2];
    Bp[A1+3] = B[A0+3] ^ B[A1+2] ^ B[A2+2] ^ B[A2+3] ^ B[A3+3] ^ of;
    Bp[A1+4] = B[A0+4] ^ B[A1+3] ^ B[A2+3] ^ B[A2+4] ^ B[A3+4] ^ of;
    Bp[A1+5] = B[A0+5] ^ B[A1+4] ^ B[A2+4] ^ B[A2+5] ^ B[A3+5];
    Bp[A1+6] = B[A0+6] ^ B[A1+5] ^ B[A2+5] ^ B[A2+6] ^ B[A3+6];
    Bp[A1+7] = B[A0+7] ^ B[A1+6] ^ B[A2+6] ^ B[A2+7] ^ B[A3+7];
    

    //  of = A2 ^ A3
    //  A2 = A2 ^ (0x1b & ((signed char)of>>7));

    //// A0 + A1
    //  A2 = A2 ^ (A0)
    //  A2 = A2 ^ (A1)

    //// + 2 * A2
    //  A2 = A2 ^ (A2 << 1)

    //// + 3 * A3
    //  A2 = A2 ^ (A3)
    //  A2 = A2 ^ (A3<<1)


    of = B[A2+7] ^ B[A3+7];

    //          A0      A1          2*A2       2*A3         A3
    Bp[A2+0] = B[A0+0] ^ B[A1+0]                     ^ B[A3+0] ^ of;
    Bp[A2+1] = B[A0+1] ^ B[A1+1] ^ B[A2+0] ^ B[A3+0] ^ B[A3+1] ^ of;
    Bp[A2+2] = B[A0+2] ^ B[A1+2] ^ B[A2+1] ^ B[A3+1] ^ B[A3+2];
    Bp[A2+3] = B[A0+3] ^ B[A1+3] ^ B[A2+2] ^ B[A3+2] ^ B[A3+3] ^ of;
    Bp[A2+4] = B[A0+4] ^ B[A1+4] ^ B[A2+3] ^ B[A3+3] ^ B[A3+4] ^ of;
    Bp[A2+5] = B[A0+5] ^ B[A1+5] ^ B[A2+4] ^ B[A3+4] ^ B[A3+5];
    Bp[A2+6] = B[A0+6] ^ B[A1+6] ^ B[A2+5] ^ B[A3+5] ^ B[A3+6];
    Bp[A2+7] = B[A0+7] ^ B[A1+7] ^ B[A2+6] ^ B[A3+6] ^ B[A3+7];
    

    //  A3 = A0 ^ A3
    //  A3 = A3 ^ (0x1b & ((signed char)of>>7));

    //// 3 * A0
    //  A3 = A3 ^ (A0)
    //  A3 = A3 ^ (A0 << 1)

    //// + A1 + A2
    //  A3 = A3 ^ A1
    //  A3 = A3 ^ A2

    //// + 2 * A3
    //  A3 = A3 ^ (A3<<1)

    of = B[A0+7] ^ B[A3+7];

    //        2*A0       A0         A1         A2       2*A3
    Bp[A3+0] = B[A0+0] ^           B[A1+0] ^ B[A2+0]           ^ of;
    Bp[A3+1] = B[A0+1] ^ B[A0+0] ^ B[A1+1] ^ B[A2+1] ^ B[A3+0] ^ of;
    Bp[A3+2] = B[A0+2] ^ B[A0+1] ^ B[A1+2] ^ B[A2+2] ^ B[A3+1];
    Bp[A3+3] = B[A0+3] ^ B[A0+2] ^ B[A1+3] ^ B[A2+3] ^ B[A3+2] ^ of;
    Bp[A3+4] = B[A0+4] ^ B[A0+3] ^ B[A1+4] ^ B[A2+4] ^ B[A3+3] ^ of;
    Bp[A3+5] = B[A0+5] ^ B[A0+4] ^ B[A1+5] ^ B[A2+5] ^ B[A3+4];
    Bp[A3+6] = B[A0+6] ^ B[A0+5] ^ B[A1+6] ^ B[A2+6] ^ B[A3+5];
    Bp[A3+7] = B[A0+7] ^ B[A0+6] ^ B[A1+7] ^ B[A2+7] ^ B[A3+6];
    

    //
    Bp += BLOCK_SIZE/4;
    B  += BLOCK_SIZE/4;
    }


    memmove(B - BLOCK_SIZE,Bp - BLOCK_SIZE,sizeof(Bp_space));
}


void bs_expand_key(word_t (* rk)[BLOCK_SIZE], uint8_t * _key)
{
    // TODO integrate this better
    uint8_t key[KEY_SCHEDULE_SIZE];
    memmove(key,_key,BLOCK_SIZE/8);
    expand_key(key);

    int i, j = 0, k, l;
    for (i = 0; i < KEY_SCHEDULE_SIZE; i += (BLOCK_SIZE/8))
    {
        memmove(rk[j], key + i, BLOCK_SIZE / 8);

        for (k = WORDS_PER_BLOCK; k < 128; k += WORDS_PER_BLOCK)
        {
            for (l = 0; l < WORDS_PER_BLOCK; l++)
            {
                rk[j][k + l] = rk[j][l];
            }
        }
        bs_transpose(rk[j]);
        j++;
    }

}

void bs_cipher(word_t stateIn[BLOCK_SIZE], word_t (* rk)[BLOCK_SIZE])
{
    int round;
    //random seed
    srand(0x1234567);
    
    word_t** state=(word_t**)malloc(sizeof(word_t*)*ORDER);
    state[0]=stateIn;
    //space for the second share
    for(int i=1;i<ORDER;i++)
       state[i]=(word_t*)malloc(sizeof(word_t)*BLOCK_SIZE);

    bs_transpose(state[0]);
    bs_transpose(state[1]);

    bs_addroundkey(state[0],rk[0]);
    for (round = 1; round < 10; round++)
    {
        bs_apply_sbox(state);
        /*bs_shiftrows(state);*/
        /*bs_mixcolumns(state);*/
        bs_shiftmix(state[0]);
        bs_shiftmix(state[1]);
        bs_addroundkey(state[0],rk[round]);
    }
    bs_apply_sbox(state);
    bs_shiftrows(state[0]);
    bs_shiftrows(state[1]);
    bs_addroundkey(state[0],rk[10]);
    bs_transpose_rev(state[0]);
    bs_transpose_rev(state[1]);

    //combining data shares (only ORDER=2)
    for(int i=0;i<BLOCK_SIZE;i++)
    {
	state[0][i]=state[0][i]^state[1][i];
    }
}



