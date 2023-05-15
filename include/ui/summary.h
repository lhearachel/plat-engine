#ifndef __UI_SUMMARY_H
#define __UI_SUMMARY_H

#include "lib/string.h"

#include "global.h"
#include "pokemon.h"

enum SummaryStatusIcon {
    STATUS_ICON_POKERUS,
    STATUS_ICON_PARALYZED,
    STATUS_ICON_FROZEN,
    STATUS_ICON_ASLEEP,
    STATUS_ICON_POISONED,
    STATUS_ICON_BURNED,
    STATUS_ICON_FAINTED,

    STATUS_ICON_NONE,
};

struct SummaryPokemonData {
    struct String *speciesName;
    struct String *nickname;
    struct String *otName;

    u16  species;
    u16  heldItem;

    u8   type1;
    u8   type2;
    u8   level      :7,
         showGender :1;
    u8   gender     :2,
         ballType   :6;             // oh fuck this is going to break with new balls huh
        
    u32 otID;
    u32 curExp;
    u32 curLevelExp;
    u32 nextLevelExp;

    u16 hp;
    u16 maxHP;
    u16 attack;
    u16 defense;
    u16 spAttack;
    u16 spDefense;
    u16 speed;

    u8  ability;
    u8  nature;

    u16 moves[4];
    u8  curPP[4];
    u8  maxPP[4];

    u8  otGender;
    u8  cool;
    u8  beauty;
    u8  cute;
    u8  smart;
    u8  tough;
    u8  sheen;
    u8  favoriteFlavor;
    
    u16 mark;
    u16 form;

    u32 status      :28,
        isEgg       :1,
        isShiny     :1,
        pokerus     :2;
    
    u32 ribbons[4];
};

/**
 * @brief Picks the status icon to display on the summary page, if any.
 * 
 * Original Function: `Function_208e9f0` (ARM9)
 * 
 * @param[in] pokemon
 * @return                  ID of the status icon to display.
 */
u32  __attribute__((long_call)) Summary_PickStatusIcon(struct Pokemon *pokemon);

/**
 * @brief Assigns data about the input Pokemon to the struct used for display
 * on the summary screen.
 * 
 * Original Function: `Function_208d200` (ARM9)
 * 
 * @param[in]     summary
 * @param[in]     pokemon
 * @param[in,out] data
 */
void __attribute__((long_call)) Summary_SetPokemonData(void *summary, struct Pokemon *pokemon, struct SummaryPokemonData *data);

#endif // __UI_SUMMARY_H