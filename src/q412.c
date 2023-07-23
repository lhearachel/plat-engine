#include "q412.h"

u16 UQ412_Mul_RoundUp(u16 n, u16 by)
{
    if (by == UQ412__1_0) {
        return n;
    }

    u32 temp = (u32) n * (u32) by;
    temp = temp + UQ412__0_5;           // round up any mid-value on the tail
    return temp >> UQ412_INT_BITSHIFT;  // undo the implicit bitshift from n*by
}

u16 UQ412_Mul_RoundDown(u16 n, u16 by)
{
    u32 temp = (u32) n * (u32) by;
    temp = temp + UQ412__0_5 - 1;       // round down any mid-value on the tail
    return temp >> UQ412_INT_BITSHIFT;  // undo the implicit bitshift from n*by
}

u16 UQ412_Mul_IntByQ_RoundDown(u16 i, u16 q)
{
    if (q == UQ412__1_0) {
        return i;
    }

    u32 temp = (u32) i << UQ412_INT_BITSHIFT;   // transform to Q20.12 fixed-point
    temp = temp * (u32) q;                      // implicit shift here
    temp = temp >> UQ412_INT_BITSHIFT;          // undo the implicit shift
    temp = temp + UQ412__0_5 - 1;               // round the result (down at 0.5)
    return temp >> UQ412_INT_BITSHIFT;          // undo the initial shift
}

u32 Q412_Mul_IntByQ_RoundDown(u32 i, u16 q)
{
    if (q == UQ412__1_0) {
        return i;
    }

    u32 temp = (u32) (i << UQ412_INT_BITSHIFT); // transform to Q20.12 fixed-point
    temp = temp * (u32) q;                      // implicit shift here
    temp = temp + UQ412__0_5 - 1;               // round the result tail (down at 0.5)
    temp = temp >> UQ412_INT_BITSHIFT;          // undo the implicit shift
    return (u32) (temp >> UQ412_INT_BITSHIFT);  // undo the initial shift
}