#ifndef __Q412_H
#define __Q412_H

#include "typedefs.h"

/*
 * Starting with generation 5, Pokemon moved to using the Q4.12 number format
 * for representing integers as they were to be used in damage computations.
 * This format specifies decimal values as such:
 * 
 *  0000 000000000000
 *  ^--^ ^----------^
 *    |       |
 *    |       -------- Bits 0 through 11 are the decimal component.
 *    ---------------- Bits 12 through 15 are the whole component.
 * 
 * So the value 1.5, in this format, would, in binary, be:
 * 
 *  0001 100000000000
 *  ^--^ ^----------^
 *    |       |
 *    |       -------- 1 * 2^(-1) -> 0.5
 *    ---------------- 1 * 2^0    -> 1.0
 * 
 * This means, effectively, that the integral value 4096 is equivalent to 1 when
 * interpreted in Q4.12 format.
 * 
 * Further reading: https://en.wikipedia.org/wiki/Q_(number_format)
 * 
 * For ease of use, some common values are provided here as pre-processor
 * definitions.
 */

#define UQ412__1_0          4096    // 1.0
#define UQ412__2_0          8192    // 2.0
#define UQ412__0_6666       2732    // 0.6666
#define UQ412__0_5          2048    // 0.5
#define UQ412__0_3333       1365    // 0.3333
#define UQ412__0_33         1352    // 0.33
#define UQ412__0_3          1229    // 0.3
#define UQ412__0_25         1024    // 0.25
#define UQ412__0_2          819     // 0.2
#define UQ412__0_1          410     // 0.1

#define UQ412__2_25         (UQ412__2_0 + UQ412__0_25)      // 9216
#define UQ412__1_5          (UQ412__1_0 + UQ412__0_5)       // 6144
#define UQ412__1_3333       (UQ412__1_0 + UQ412__0_3333)    // 5461
#define UQ412__1_33         (UQ412__1_0 + UQ412__0_33)      // 5448
#define UQ412__1_3          (UQ412__1_0 + UQ412__0_3)       // 5325
#define UQ412__1_25         (UQ412__1_0 + UQ412__0_25)      // 5120
#define UQ412__1_2          (UQ412__1_0 + UQ412__0_2)       // 4915
#define UQ412__1_1          (UQ412__1_0 + UQ412__0_1)       // 4506
#define UQ412__0_75         (UQ412__0_5 + UQ412__0_25)      // 3072

/*
 * Shift by this much to the right to translate the whole component from Q4.12
 * format back to a standard 16-bit integer.
 * 
 * Shift by this much to the left to translate a 16-bit integer to Q4.12 format
 * (maximum value: 15).
 */
#define UQ412_INT_BITSHIFT  12

#define UQ412__FROM_INT(n)  ((n & 0x000F) << UQ412_INT_BITSHIFT)

/*
 * This macro takes a Q4.12 number and rounds it to the nearest whole integer,
 * rounding _up_ at 0.5.
 */
#define UQ412_ROUND_UP(n)   ((n + UQ412__0_5) & 0xF000)

/*
 * This macro takes a Q4.12 number and rounds it the nearest whole integer,
 * rounding _down_ at 0.5.
 */
#define UQ412_ROUND_DOWN(n) ((n + UQ412__0_5 - 1) & 0xF000)

/**
 * @brief Multiply two Q-numeric operands together, rounding the tail
 * of the result up.
 * 
 * @param n 
 * @param by 
 * @return Product, Q-numeric.
 */
u16 __attribute__((long_call)) UQ412_Mul_RoundUp(u16 n, u16 by);

/**
 * @brief Multiply two Q-numeric operands together, rounding the tail
 * of the result down.
 * 
 * @param n 
 * @param by 
 * @return Product, Q-numeric.
 */
u16 __attribute__((long_call)) UQ412_Mul_RoundDown(u16 n, u16 by);

/**
 * @brief Multiply a 16-bit integer by a Q4.12 format operand
 * and rounds the result to the nearest integer (down at 0.5).
 * 
 * @param i 
 * @param q 
 * @return u16 
 */
u16 __attribute__((long_call)) UQ412_Mul_IntByQ_RoundDown(u16 i, u16 q);

s32 __attribute__((long_call)) Q412_Mul_IntByQ_RoundDown(s32 i, u16 q);

#endif // __Q412_H