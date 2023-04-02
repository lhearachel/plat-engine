#ifndef __CUSTOM_BALL_H
#define __CUSTOM_BALL_H

#include "global.h"

struct CustomBallSeal {
    u8 sealID;
    u8 x;
    u8 y;
};

struct CustomBalls {
    struct CustomBallSeal seals[8];
};

#endif // __CUSTOM_BALL_H