#include "constants/abilities.h"
#include "pokemon.h"

u16 __attribute__((long_call)) Pokemon_GetHiddenAbility(u16 species, u32 form)
{
#ifdef HIDDEN_ABILITIES
    u16 ability = ABILITY_NONE;
    u16 *hiddenAbilityTable = Malloc(0, 3000);

    species = Form_GetTrueSpecies(species, form);
    LoadFromNARC(hiddenAbilityTable, ARC_CODE_ADDONS, CODE_ADDON_HIDDEN_ABILITY_LIST);
    ability = hiddenAbilityTable[species];
    Free(hiddenAbilityTable);

    return ability;
#else
    return ABILITY_NONE;
#endif
}

void __attribute__((long_call)) BoxPokemon_ToggleHiddenAbility(void *boxMon)
{
    BOOL fastMode;
    int species, form;
    u32 ability1, ability2, abilityH;
    u32 pid;
    u16 isHiddenAbility;

    fastMode = BoxPokemon_Lock(boxMon);

    species = BoxPokemon_Get(boxMon, MON_PARAM_SPECIES, NULL);
    pid     = BoxPokemon_Get(boxMon, MON_PARAM_PID, NULL);
    form    = BoxPokemon_Get(boxMon, MON_PARAM_FORM_NUMBER, NULL);

    species = Form_GetTrueSpecies(species, form);
#ifdef DEBUG_HIDDEN_ABILITIES
    isHiddenAbility = TRUE;
#else
    isHiddenAbility = BOX_MON_IS_HIDDEN_ABILITY(boxMon);
#endif

    ability1 = PokemonBaseStats_GetWithForm(species, form, PERSONAL_ABILITY_1);
    ability2 = PokemonBaseStats_GetWithForm(species, form, PERSONAL_ABILITY_2);
    abilityH = Pokemon_GetHiddenAbility(species, form);

    if (isHiddenAbility && abilityH != 0) {
        BoxPokemon_Set(boxMon, MON_PARAM_ABILITY, (u8*) &abilityH);
    } else if (ability2 != 0) {
        if (pid & 1) {
            BoxPokemon_Set(boxMon, MON_PARAM_ABILITY, (u8*) &ability2);
        } else {
            BoxPokemon_Set(boxMon, MON_PARAM_ABILITY, (u8*) &ability1);
        }
    } else {
        BoxPokemon_Set(boxMon, MON_PARAM_ABILITY, (u8*) &ability1);
    }

    BoxPokemon_Unlock(boxMon);
}
