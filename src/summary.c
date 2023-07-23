#include "global.h"

#include "ui/summary.h"

#define SUMMARY_SCREEN_HEAP_ID  19

static void UpdatePokemonData(struct SummaryState *summary, u8 mode)
{
    void *maybeBoxMon = Summary_GetPokemonData(summary);
    struct Pokemon *pokemon;

    // If we're loading from the box, we need to copy the BoxPokemon
    // into a full Pokemon so that its stats are calculated correctly.
    // 
    // https://github.com/lhearachel/plat-engine/issues/76
    if (summary->baseData->dataType == 2) {
        pokemon = Pokemon_Alloc(SUMMARY_SCREEN_HEAP_ID);
        Pokemon_FromBox(maybeBoxMon, pokemon);
    } else {
        pokemon = maybeBoxMon;
    }

    int paramStart = MON_PARAM_MAX_HP;

    // Pokemon struct orders current HP before max HP, so need to handle mode == 0 as a special case
    if (mode == 0) {
        summary->pokemonData.hp = (u16) Pokemon_Get(pokemon, MON_PARAM_CURRENT_HP, NULL);
    } else {
        if (mode == 1) {
            paramStart = MON_PARAM_HP_EV;
        } else {
            paramStart = MON_PARAM_HP_IV;
        }

        summary->pokemonData.hp = (u16) Pokemon_Get(pokemon, paramStart, NULL);
    }

    // Pokemon struct orders all data parameters as such:
    // Attack -> Defense -> Speed -> SpAttack -> SpDefense
    summary->pokemonData.attack    = (u16) Pokemon_Get(pokemon, paramStart + 1, NULL);
    summary->pokemonData.defense   = (u16) Pokemon_Get(pokemon, paramStart + 2, NULL);
    summary->pokemonData.speed     = (u16) Pokemon_Get(pokemon, paramStart + 3, NULL);
    summary->pokemonData.spAttack  = (u16) Pokemon_Get(pokemon, paramStart + 4, NULL);
    summary->pokemonData.spDefense = (u16) Pokemon_Get(pokemon, paramStart + 5, NULL);
}

// Components here are indices into the system font palette.
//   l == index of the color to use for the letter itself
//   s == index of the color to use for the shadow of the letter
//   g == index of the color to use for the background of the letter (0 == transparent)
#define COLOR(l, s, g) ((u32)(((l & 0xFF) << 16) | ((s & 0xFF) << 8) | ((g & 0xFF) << 0)))
#define BLACK          (COLOR(1,  2, 0))
#define BLUE           (COLOR(3,  4, 0))
#define RED            (COLOR(5,  6, 0))
#define PINK           (COLOR(7,  8, 0))
#define GREEN          (COLOR(9, 10, 0))

static s8 sNatureStatEffects[25][6] = {
    // atk, def, spatk, spdef, speed
    {  0,  0,  0,  0,  0,  0  },    // Hardy
    {  0,  1, -1,  0,  0,  0  },    // Lonely
    {  0,  1,  0,  0,  0, -1  },    // Brave
    {  0,  1,  0, -1,  0,  0  },    // Adamant
    {  0,  1,  0,  0, -1,  0  },    // Naughty
    {  0, -1,  1,  0,  0,  0  },    // Bold
    {  0,  0,  0,  0,  0,  0  },    // Docile
    {  0,  0,  1,  0,  0, -1  },    // Relaxed
    {  0,  0,  1, -1,  0,  0  },    // Impish
    {  0,  0,  1,  0, -1,  0  },    // Lax
    {  0, -1,  0,  0,  0,  1  },    // Timid
    {  0,  0, -1,  0,  0,  1  },    // Hasty
    {  0,  0,  0,  0,  0,  0  },    // Serious
    {  0,  0,  0, -1,  0,  1  },    // Jolly
    {  0,  0,  0,  0, -1,  1  },    // Naive
    {  0, -1,  0,  1,  0,  0  },    // Modest
    {  0,  0, -1,  1,  0,  0  },    // Mild
    {  0,  0,  0,  1,  0, -1  },    // Quiet
    {  0,  0,  0,  0,  0,  0  },    // Bashful
    {  0,  0,  0,  1, -1,  0  },    // Rash
    {  0, -1,  0,  0,  1,  0  },    // Calm
    {  0,  0, -1,  0,  1,  0  },    // Gentle
    {  0,  0,  0,  0,  1, -1  },    // Sassy
    {  0,  0,  0, -1,  1,  0  },    // Careful
    {  0,  0,  0,  0,  0,  0  },    // Quirky
};

static inline void PrintStatNumberWithColor(struct SummaryState *summary, u8 windowIdx, u32 justify)
{
    u32 color = BLACK;
    if (sNatureStatEffects[summary->pokemonData.nature][windowIdx] > 0) {
        color = RED;
    } else if (sNatureStatEffects[summary->pokemonData.nature][windowIdx] < 0) {
        color = BLUE;
    }

    Summary_PrintString(summary, &summary->addlWindows[windowIdx], color, justify);
}

void Summary_ColorizeStatScreen(struct SummaryState *summary)
{
    Summary_NumberToString(summary, 120, summary->pokemonData.attack, 3, 0);
    PrintStatNumberWithColor(summary, 1, JUSTIFY_RIGHT);
    Summary_NumberToString(summary, 121, summary->pokemonData.defense, 3, 0);
    PrintStatNumberWithColor(summary, 2, JUSTIFY_RIGHT);
    Summary_NumberToString(summary, 122, summary->pokemonData.spAttack, 3, 0);
    PrintStatNumberWithColor(summary, 3, JUSTIFY_RIGHT);
    Summary_NumberToString(summary, 123, summary->pokemonData.spDefense, 3, 0);
    PrintStatNumberWithColor(summary, 4, JUSTIFY_RIGHT);
    Summary_NumberToString(summary, 124, summary->pokemonData.speed, 3, 0);
    PrintStatNumberWithColor(summary, 5, JUSTIFY_RIGHT);
}

void Summary_ChangeStatScreenState(struct SummaryState *summary, u8 mode)
{
    for (int i = 0; i < 6; i++) {
        Window_FillWithColor(&summary->addlWindows[i], 0);
    }

    UpdatePokemonData(summary, mode);

    if (mode) {
        // Print IVs or EVs
        Summary_NumberToString(summary, 119, summary->pokemonData.hp, 3, 1);
        PrintStatNumberWithColor(summary, 0, JUSTIFY_CENTER);
    } else {
        // Print cur and max
        u8 xsize = summary->addlWindows[0].sizX * 8;
        Summary_PrintCurrentOverMax(
            summary,
            0,
            117, 119, 118,
            summary->pokemonData.hp,
            summary->pokemonData.maxHP,
            3,
            xsize / 2, 0
        );
    }
    
    Summary_ColorizeStatScreen(summary);

    for (int i = 0; i < 6; i++) {
        Window_ToVRAM(&summary->addlWindows[i]);
    }

    UpdatePokemonData(summary, 0);      // Recover old data for page change
}
