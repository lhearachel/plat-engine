#include "constants/abilities.h"
#include "constants/species.h"

#include "archive.h"
#include "config.h"
#include "pokemon.h"
#include "battle/common.h"

static int Pokemon_OverworldPoisonDamage(struct Party *party, u16 zoneID);

inline BOOL Ability_BlocksPoisonDamage(u8 abilityID)
{
    return (abilityID == ABILITY_MAGIC_GUARD)
            || (abilityID == ABILITY_POISON_HEAL)
            || (abilityID == ABILITY_IMMUNITY);
}

static int Pokemon_OverworldPoisonDamage(struct Party *party, u16 zoneID)
{
    #ifndef OVERWORLD_POISON_DAMAGE
    return 0;
    #else
    int poisonCount = 0;
    int deadCount = 0;
    for (int i = 0; i < Party_Count(party); i++) {
        struct Pokemon *poke = Party_Member(party, i);
        if ((Pokemon_CanBattle(poke))
                && (Pokemon_Get(poke, MON_PARAM_CONDITION, NULL) & CONDITION_POISON_ALL)
                && (Ability_BlocksPoisonDamage(Pokemon_Get(poke, MON_PARAM_ABILITY, NULL)) == FALSE)) {
            u32 hp = Pokemon_Get(poke, MON_PARAM_CURRENT_HP, NULL);
            if (hp > 1) {
                hp--;
            }

            Pokemon_Set(poke, MON_PARAM_CURRENT_HP, &hp);
            poisonCount++;
            if (hp == 1) {
                deadCount++;
                Pokemon_RecalcFriendship(poke, 7, zoneID);  // magic 7 here says that this is for poison "death"
            }
        }
    }

    return (deadCount) ? 2 : ((poisonCount) ? 1 : 0);
    #endif  // OVERWORLD_POISON_DAMAGE
}

BOOL Pokemon_IsNFE(u16 species, u32 form)
{
    struct EvoTable *evos = Malloc(0, sizeof(struct EvoTable));
    Pokemon_Evolutions(Form_GetTrueSpecies(species, form), evos);

    // Check for any possible evolutions
    for (unsigned int i = 0; i < 7; i++) {
        struct EvoData *data = &evos->data[i];
        if (data->condition != 0
                && data->param != 0
                && data->target != 0) {
            return TRUE;
        }
    }

    // No evolutions found, so this mon is fully-evolved.
    return FALSE;
}

#if 0

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

    BoxPokemon_Unlock(boxMon, fastMode);
}

#endif
