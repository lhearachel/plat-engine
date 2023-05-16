#ifndef __UI_SUMMARY_H
#define __UI_SUMMARY_H

#include "lib/string.h"

#include "global.h"
#include "pokemon.h"

#include "ui/window.h"

enum SummaryStringJustify {
    JUSTIFY_LEFT,
    JUSTIFY_RIGHT,
    JUSTIFY_CENTER,
};

struct SummaryBaseData {
    void *ppd;                  /* 0x00 */
    void *config;               /* 0x04 */
    u16  *playerName;           /* 0x08 */
    u32  playerID;              /* 0x0C */
    u8   playerGender;          /* 0x10 */
    u8   dataType;              /* 0x11 */
    u8   mode;
    u8   limit;
    u8   pos;
    u8   pageFlag;

    u8   selectedMoveOut;
    u8   selectedModeOut;
    u16  move;

    u32  dexDisplayMode;

    void *ribbons;
    void *pokeblocks;
    void *cry;

    BOOL contest;
};

struct SummaryPokemonData {
    void *speciesName;
    void *nickname;
    void *otName;

    u16  species;
    u16  heldItem;

    u8   type1;
    u8   type2;
    u8   level      :7,
         showGender :1;
    u8   gender     :2,
         ballType   :6;
        
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

struct SummaryState {
    void *bgl;
    struct Window defnWindows[36];
    struct Window *addlWindows;
    u32 addlWindowCount;

    struct SummaryBaseData    *baseData;
    struct SummaryPokemonData pokemonData;

    // rest of the hooked struct from here is undocumented
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

/**
 * @brief Returns the underlying Pokemon struct attached to this summary.
 * 
 * This can be either a BoxPokemon or a Pokemon struct; which of them it is
 * depends on the source of the summary screen (since it can be accessed
 * from the PC).
 * 
 * Original Function: `Function_208dd48` (ARM9)
 * 
 * @param[in] summary
 * @return              The Pokemon struct attached to the summary.
 */
void* __attribute__((long_call)) Summary_GetPokemonData(struct SummaryState *summary);

/**
 * @brief Converts a number input to a displayable string and stores it in
 * the summary's holding buffer.
 * 
 * Original Function: `Function_2090184` (ARM9)
 * 
 * @param[in,out] summary
 * @param[in]     arcMessageID  ID of the string to be pulled from text archive 455.
 * @param[in]     num           The number to be converted.
 * @param[in]     digits        The maximum number of digits permitted.
 * @param[in]     displayType   0 == left-justified; 1 == left-padded by spaces; 2 == left-padded by zeroes.
 */
void  __attribute__((long_call)) Summary_NumberToString(struct SummaryState *summary, u32 arcMessageID, u32 num, u8 digits, u8 displayType);

/**
 * @brief Prints the string in the summary's holding buffer to the given window.
 * 
 * Original Function: `Function_20900d8` (ARM9)
 * 
 * @param[in,out] summary
 * @param[in,out] window    The window to print the string into.
 * @param[in]     color     The color to print the font in.
 * @param[in]     justify   Justification mode; see enum SummaryStringJustify.
 */
void  __attribute__((long_call)) Summary_PrintString(struct SummaryState *summary, struct Window *window, u32 color, u32 justify);

/**
 * @brief Print a string for a `current / max` visualization.
 * 
 * Original Function: `Function_20901d0` (ARM9)
 * 
 * @param[in,out] summary
 * @param[in]     windowIdx Index of the window to print the constructed string into.
 * @param[in]     idSep     ID of the separator string within text archive 455.
 * @param[in]     idCur     ID of the placeholder string within text archive 455 for the value of `current`.
 * @param[in]     idMax     ID of the placeholder string within text archive 455 for the value of `max`.
 * @param[in]     cur
 * @param[in]     max
 * @param[in]     digits    The maximum number of digits permitted.
 * @param[in]     x
 * @param[in]     y
 */
void  __attribute__((long_call)) Summary_PrintCurrentOverMax(struct SummaryState *summary, u32 windowIdx, u32 idSep, u32 idCur, u32 idMax, u16 cur, u16 max, u8 digits, u8 x, u8 y);

// ========================================================================= //
//                      NOVEL FUNCTIONS START HERE                           //
// ========================================================================= //

/**
 * @brief Updates the state necessary for the stats page of the summary.
 * 
 * Accepted modes are as follows:
 * - `0`: Display the calculated stats page (including current and max HP).
 * - `1`: Display EVs for the Pokemon.
 * - `2`: Display IVs for the Pokemon.
 * 
 * Output will be color-coded according to the Pokemon's nature.
 * 
 * @param[in,out] summary
 * @param[in]     mode      Determines which page of the stat screen to show.
 */
void  __attribute__((long_call)) Summary_ChangeStatScreenState(struct SummaryState *summary, u8 mode);

#endif // __UI_SUMMARY_H