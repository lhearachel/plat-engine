#ifndef __SPRITE_H
#define __SPRITE_H

struct PokemonSprite {
    u16 archiveNum;
    u16 indexPic;
    u16 indexPal;
    u16 randomizedMon;  // spinda
    u8  formNum;
    u8  _dummy[3];
    u32 pid;
};

#endif // __SPRITE_H