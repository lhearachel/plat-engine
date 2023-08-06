#include "archive.h"
#include "config.h"
#include "debug.h"
#include "pokemon.h"

#include "constants/abilities.h"
#include "constants/species.h"

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

static inline u32 LoadTargetFromFormTable(u32 species, u32 form)
{
    for (unsigned int i = 0; i < NELEMS(gPokemonFormTable); i++) {
        if (species == gPokemonFormTable[i].species && form == gPokemonFormTable[i].formNum) {
            return gPokemonFormTable[i].target;
        }
    }

    // no match found, return the original species input
    return species;
}

u16 BoxPokemon_Form(const struct BoxPokemon *pokemon)
{
    u32 species = BoxPokemon_Get(pokemon, MON_PARAM_SPECIES, NULL);
    #ifdef DEBUG_FORMS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | Invoking BoxPokemon_Form\n");
    debugsyscall(buf);
    sprintf(buf, "PLAT-ENGINE | -- species: 0x%X\n", species);
    debugsyscall(buf);
    #endif

    switch (species) {
    case SPECIES_UNOWN:
    case SPECIES_DEOXYS:
    case SPECIES_BURMY:
    case SPECIES_WORMADAM:
    case SPECIES_SHELLOS:
    case SPECIES_GASTRODON:
    case SPECIES_GIRATINA:
    case SPECIES_SHAYMIN:
    case SPECIES_ROTOM:
        #ifdef DEBUG_FORMS
        sprintf(buf, "PLAT-ENGINE | -- Original Platinum form; using raw form number\n");
        debugsyscall(buf);
        #endif
        return BoxPokemon_Get(pokemon, MON_PARAM_FORM_NUMBER, NULL);
    
    default:
        #ifdef DEBUG_FORMS
        sprintf(buf, "PLAT-ENGINE | -- Consulting the form table...\n");
        debugsyscall(buf);
        #endif
        for (unsigned int i = 0; i < NELEMS(gPokemonFormTable); i++) {
            if (species == gPokemonFormTable[i].species) {
                #ifdef DEBUG_FORMS
                sprintf(buf, "PLAT-ENGINE | -- This species has an alt-form!\n\n");
                debugsyscall(buf);
                #endif
                return BoxPokemon_Get(pokemon, MON_PARAM_FORM_NUMBER, NULL);
            }
        }
    }

    #ifdef DEBUG_FORMS
    sprintf(buf, "PLAT-ENGINE | -- This species does not have alt-forms!\n\n");
    debugsyscall(buf);
    #endif
    return 0;   // no match found, return the base form number (0)
}

u32 Pokemon_IconGraphicsID(u32 species, BOOL isEgg, u32 form)
{
    if (isEgg) {
        // Use a different icon for Manaphy eggs.
        return species == SPECIES_MANAPHY ? 502 : 501;
    }

    form = Pokemon_NormalizedForm(species, form);
    if (!form) {
        return species + 7;
    }

    switch (species) {
        case SPECIES_DEOXYS:        return 503 + form - 1;
        case SPECIES_UNOWN:         return 507 + form - 1;  // I hate this entry it ruins everything
        case SPECIES_BURMY:         return 534 + form - 1;
        case SPECIES_WORMADAM:      return 536 + form - 1;
        case SPECIES_SHELLOS:       return 538 + form - 1;
        case SPECIES_GASTRODON:     return 539 + form - 1;
        case SPECIES_GIRATINA:      return 540 + form - 1;
        case SPECIES_SHAYMIN:       return 541 + form - 1;
        case SPECIES_ROTOM:         return 542 + form - 1;
        case SPECIES_CASTFORM:      return 547 + form - 1;  // new to Platinum
        case SPECIES_CHERRIM:       return 550 + form - 1;  // new to Platinum
        default:                    return LoadTargetFromFormTable(species, form) + 7;
    }
}

u32 Pokemon_IconPaletteID(u32 species, u32 form, BOOL isEgg)
{
    if (isEgg) {
        // Use Bad Egg's palette for the Manaphy egg.
        return species == SPECIES_MANAPHY ? SPECIES_BAD_EGG : SPECIES_EGG;
    }

    if (!form) {
        return species;
    }

    switch (species) {
        case SPECIES_DEOXYS:        return 496 + form - 1;
        case SPECIES_UNOWN:         return 499 + form - 1;
        case SPECIES_BURMY:         return 527 + form - 1;
        case SPECIES_WORMADAM:      return 529 + form - 1;
        case SPECIES_SHELLOS:       return 531 + form - 1;
        case SPECIES_GASTRODON:     return 532 + form - 1;
        case SPECIES_GIRATINA:      return 533 + form - 1;
        case SPECIES_SHAYMIN:       return 534 + form - 1;
        case SPECIES_ROTOM:         return 535 + form - 1;
        case SPECIES_CASTFORM:      return 540 + form - 1;  // new to Platinum
        case SPECIES_CHERRIM:       return 543 + form - 1;  // new to Platinum
        default:                    return LoadTargetFromFormTable(species, form);
    }
}

int Form_GetTrueSpecies(int species, int form)
{
    if (!form) {            // form 0 is always a pointer to the base species definition
        return species;
    }

    switch (species) {
    case SPECIES_DEOXYS:
        if (form <= 3) {
            return SPECIES_DEOXYS_ATTACK + form - 1;
        }
        break;

    case SPECIES_WORMADAM:
        if (form <= 2) {
            return SPECIES_WORMADAM_SANDY + form - 1;
        }
        break;

    case SPECIES_GIRATINA:
        if (form <= 1) {
            return SPECIES_GIRATINA_ORIGIN;
        }
        break;

    case SPECIES_SHAYMIN:
        if (form <= 1) {
            return SPECIES_SHAYMIN_SKY;
        }
        break;

    case SPECIES_ROTOM:
        if (form <= 5) {
            return SPECIES_ROTOM_HEAT + form - 1;
        }
        break;
    
    default:
        return LoadTargetFromFormTable(species, form);
    }

    return species;
}

u16 Pokemon_FormTarget(int species, int form)
{
    for (unsigned int i = 0; i < NELEMS(gPokemonFormTable); i++) {
        if (species == gPokemonFormTable[i].species && form == gPokemonFormTable[i].formNum) {
            return gPokemonFormTable[i].target;
        }
    }

    return species;
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
