#include "constants/abilities.h"
#include "pokemon.h"

u16 __attribute__((long_call)) GetMonHiddenAbility(u16 species, u32 form)
{
#ifdef HIDDEN_ABILITIES
    u16 ability = ABILITY_NONE;
    u16 *hiddenAbilityTable = sys_AllocMemory(0, 3000);

    species = PokeOtherFormMonsNoGet(species, form);
    ArchiveDataLoad(hiddenAbilityTable, ARC_CODE_ADDONS, CODE_ADDON_HIDDEN_ABILITY_LIST);
    ability = hiddenAbilityTable[species];
    sys_FreeMemoryEz(hiddenAbilityTable);

    return ability;
#else
    return ABILITY_NONE;
#endif
}

void __attribute__((long_call)) SetBoxMonAbility(void *boxMon)
{
    BOOL fastMode;
    int species, form;
    u32 ability1, ability2, abilityH;
    u32 pid;
    u16 isHiddenAbility;

    fastMode = BoxMonSetFastModeOn(boxMon);

    species = GetBoxMonData(boxMon, MON_PARAM_SPECIES, NULL);
    pid     = GetBoxMonData(boxMon, MON_PARAM_PID, NULL);
    form    = GetBoxMonData(boxMon, MON_PARAM_FORM_NUMBER, NULL);

    species = PokeOtherFormMonsNoGet(species, form);
#ifdef DEBUG_HIDDEN_ABILITIES
    isHiddenAbility = TRUE;
#else
    isHiddenAbility = BOX_MON_IS_HIDDEN_ABILITY(boxMon);
#endif

    ability1 = PokeFormNoPersonalParaGet(species, form, PERSONAL_ABILITY_1);
    ability2 = PokeFormNoPersonalParaGet(species, form, PERSONAL_ABILITY_2);
    abilityH = GetMonHiddenAbility(species, form);

    if (isHiddenAbility && abilityH != 0) {
        SetBoxMonData(boxMon, MON_PARAM_ABILITY, (u8*) &abilityH);
    } else if (ability2 != 0) {
        if (pid & 1) {
            SetBoxMonData(boxMon, MON_PARAM_ABILITY, (u8*) &ability2);
        } else {
            SetBoxMonData(boxMon, MON_PARAM_ABILITY, (u8*) &ability1);
        }
    } else {
        SetBoxMonData(boxMon, MON_PARAM_ABILITY, (u8*) &ability1);
    }

    BoxMonSetFastModeOff(boxMon);
}
