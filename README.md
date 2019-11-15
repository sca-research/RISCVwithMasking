# RISCVwithMasking
 Masking codes for RISC_V cores

## Bit-sliced AES
A bit-sliced AES based on [Virginia Tech's implementation](https://github.com/Secure-Embedded-Systems/Masked-AES-Implementation). As the original implementation is written in C, it naturally copes with RISC-V without any adjustment.   

## Masked Bit-sliced AES
A bit-sliced AES with 1st order masking protection from [Dr. DINU's PhD thesis](http://orbilu.uni.lu/handle/10993/33803). The baseline AES is still the same as Virginia Tech's implementation: however, the masked AES from Virginia Tech uses a technique we called "share-slicing": unlike the conventional allocation of storing data shares in different registers, share-slicing stores all secret shares within one register. According to [our analysis in TCHES 2020] (https://github.com/bristol-sca/ShareSlicing_AES), despite the efficiency benefits, the security of "share-slicing" relys on the specific implementations of the processor. Thus, we tried to avoid share-slicing issue here, sticking to the traditional way of storing data shares.

The majority of the code is still written in C (most parts remain the same as Virginia Tech's implementation): however, the masked AND and masked XOR used in the Sbox are written in RISC-V assembly. Except for these two functions, everything else should be portable (assuming there is enough memory for the bit-slicing encrypting to run).

Note that this implementation is BY NO MEANS something one would like to use in practice: the primary goal is to provide an implementation that is comprehensible and forms a good basis for further development or research. This implementation is not optimized for security or efficiency(in fact, you might even find warning in the comments saying somehting should be done in that place). I did not do so because I do not have a customised requirement right now, not becuase of it is difficult to do so or one do not need to worry about it.

  