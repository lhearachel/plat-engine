#include "global.h"
#include "summary.h"

#include "constants/misc.h"

void Summary_SetPokemonData(void *summary, struct Pokemon *pokemon, struct SummaryPokemonData *data)
{
    BOOL locked = Pokemon_Lock(pokemon);
    struct BoxPokemon *boxMon = &pokemon->boxParams;

    // TODO: build strings

    data->species   = (u16) Pokemon_Get(pokemon, MON_PARAM_SPECIES,     NULL);
    data->heldItem  = (u16) Pokemon_Get(pokemon, MON_PARAM_HELD_ITEM,   NULL);
    data->level     =  (u8) Pokemon_Get(pokemon, MON_PARAM_LEVEL,       NULL);
    data->isEgg     =       Pokemon_Get(pokemon, MON_PARAM_IS_EGG,      NULL);
    data->ballType  =  (u8) Pokemon_Get(pokemon, MON_PARAM_POKEBALL,    NULL);
    data->type1     =  (u8) Pokemon_Get(pokemon, MON_PARAM_TYPE1,       NULL);
    data->type2     =  (u8) Pokemon_Get(pokemon, MON_PARAM_TYPE2,       NULL);
    data->otID      =       Pokemon_Get(pokemon, MON_PARAM_OT_ID,       NULL);
    data->otGender  =       Pokemon_Get(pokemon, MON_PARAM_OT_GENDER,   NULL);
    data->ability   =  (u8) Pokemon_Get(pokemon, MON_PARAM_ABILITY,     NULL);
    data->curExp    =       Pokemon_Get(pokemon, MON_PARAM_EXP,         NULL);
    data->mark      =       Pokemon_Get(pokemon, MON_PARAM_MARKINGS,    NULL);
    data->form      =       Pokemon_Get(pokemon, MON_PARAM_FORM_NUMBER, NULL);

    data->hp        = (u16) Pokemon_Get(pokemon, MON_PARAM_CURRENT_HP,  NULL);
    data->maxHP     = (u16) Pokemon_Get(pokemon, MON_PARAM_MAX_HP,      NULL);
    data->attack    = (u16) Pokemon_Get(pokemon, MON_PARAM_ATTACK,      NULL);
    data->defense   = (u16) Pokemon_Get(pokemon, MON_PARAM_DEFENSE,     NULL);
    data->spAttack  = (u16) Pokemon_Get(pokemon, MON_PARAM_SPATTACK,    NULL);
    data->spDefense = (u16) Pokemon_Get(pokemon, MON_PARAM_SPDEFENSE,   NULL);
    data->speed     = (u16) Pokemon_Get(pokemon, MON_PARAM_SPEED,       NULL);

    data->cool      =  (u8) Pokemon_Get(pokemon, MON_PARAM_COOL,        NULL);
    data->beauty    =  (u8) Pokemon_Get(pokemon, MON_PARAM_BEAUTY,      NULL);
    data->cute      =  (u8) Pokemon_Get(pokemon, MON_PARAM_CUTE,        NULL);
    data->smart     =  (u8) Pokemon_Get(pokemon, MON_PARAM_SMART,       NULL);
    data->tough     =  (u8) Pokemon_Get(pokemon, MON_PARAM_TOUGH,       NULL);
    data->sheen     =  (u8) Pokemon_Get(pokemon, MON_PARAM_SHEEN,       NULL);

    data->gender      = Pokemon_CalcGender(pokemon);
    data->nature      = Pokemon_CalcNature(pokemon);
    data->isShiny     = Pokemon_CalcShiny(pokemon);
    data->curLevelExp = Pokemon_CalcExpForLevel(data->species, data->level);

    // Don't show gender marker for hatched Nidorans
    data->showGender  = Pokemon_Get(pokemon, MON_PARAM_NIDORAN_NICKNAME, NULL) == FALSE;

    // Handle level 100 mons' next-level values
    if (data->level == 100) {
        data->nextLevelExp = 0;
    } else {
        data->nextLevelExp = Pokemon_CalcLevelExp(data->species, data->level + 1);
    }

    // Compute the mon's favorite flavor
    data->favoriteFlavor = FLAVOR_NONE;
    for (int i = 0; i < 5; i++) {
        if (Pokemon_CalcFlavorAffinity(pokemon, i) == 1) {
            data->favoriteFlavor = i;
            break;
        }
    }

    // Compute any status icon for the display
    data->status = Summary_PickStatusIcon(pokemon);
    if (Pokemon_CheckPokerusImmune(pokemon)) {
        data->pokerus = 2;
    } else if (Pokemon_CheckPokerus(pokemon)) {
        data->pokerus = 1;
        if (data->status == STATUS_ICON_NONE) {
            data->status =  STATUS_ICON_POKERUS;
        }
    } else {
        data->pokerus = 0;
    }

    // TODO: Compute ribbons for display
}
