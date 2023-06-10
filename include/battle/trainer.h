#ifndef __BATTLE_TRAINER_H
#define __BATTLE_TRAINER_H

#include "message_data.h"
#include "typedefs.h"

struct TrainerData {
    u8  flags;
    u8  class;
    u8  spriteIdx;
    u8  partySize;

    u16 bagItems[4];

    u32 aiFlags;
    u32 fightType;

    u16                 name[8];
    struct MessageData  winMessage;
    struct MessageData  loseMessage;
};

// This struct is not actually used for any data in code, but is instead
// presented as a schema for how to define trainer Pokemon data.
struct __attribute__((packed)) TrainerPokemon {
    // The difficulty value of a Pokemon. This field is legacy; it is used
    // by vanilla game code to scale the power of a given Pokemon. Values
    // input here are scaled back to a max of 31 and then applied to all IVs
    // for a given Pokemon.
    u8  dv;

    // Which ability slot to be used. Valid values, by priority, are:
    //  - 2: Forces the hidden ability to be set, if any exists.
    //  - 1: Forces the Pokemon to use ability slot 2, if it has one.
    //  - 0: Forces the Pokemon to use ability slot 1.
    u8  abilitySlot;

    u16 level;

    u16 dexNumber       :11,
        formNumber      :5 ;

    u16 heldItem;

    u16 moves[4];

    u16 cbSeal;
};

#endif // __BATTLE_TRAINER_H