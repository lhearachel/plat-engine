#include "archive.h"
#include "debug.h"
#include "heap.h"
#include "pokemon.h"
#include "sprite.h"

#include "constants/abilities.h"
#include "constants/species.h"

#include "battle/common.h"

#define RANDOMIZE_IVS 32

struct UnownTable {
    int size;
    const u8 *table;
};

extern const struct UnownTable gUnownTable[];  // 02248FF0

void Encounter_Set(
    const u16 speciesAndForm,
    const u8 level,
    const int partyIdx,
    const struct EncounterInfo *inputEncInfo,
    struct Pokemon *inputPlayerLead,
    struct BattleParams *battleParamsOutput
)
{
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | Invoking Encounter_Set\n");
    debugsyscall();

    // speciesAndForm is a composite input from the encounter file
    u16 form    = (speciesAndForm & 0xF800) >> 11; // top 5 bits are the form
    u16 species = (speciesAndForm & 0x07FF);       // bottom 11 bits are the species

    struct Pokemon *encounter = Pokemon_Alloc(HEAP_ID_FIELD);
    Pokemon_Init(encounter);

    BOOL forcedGender = FALSE;
    u8   gender, nature = GF_RAND() % 25;
    if (inputEncInfo->isEgg == FALSE) {
        if (inputEncInfo->playerLeadAbility == ABILITY_CUTE_CHARM) {
            // Cute Charm can force the encounter to be of a specific gender
            // Note that because of the way that this works, it is impossible for
            // Cute Charm to affect Pyroar, Frillish, Jellicent, Meowstic,
            // Basculegion, and Unfezant.
            switch (PokemonBaseStats_GetWithForm(species, form, PERSONAL_GENDER_RATIO)) {
            case GENDER_RATIO_ALL_MALE:
            case GENDER_RATIO_ALL_FEMALE:
            case GENDER_RATIO_NONE:
                break;

            default:
                // 2/3 chance to force the same gender as the lead
                if (GF_RAND() % 3 != 0) {
                    gender = Pokemon_Get(inputPlayerLead, MON_PARAM_GENDER, NULL);
                    gender = gender ^ 1;    // flip female to male, male to female
                    forcedGender = TRUE;
                }
                break;
            }
        } else if (inputEncInfo->playerLeadAbility == ABILITY_SYNCHRONIZE) {
            // 50% chance to force the same nature as the lead
            if (GF_RAND() & 1) {
                nature = Pokemon_CalcNature(inputPlayerLead);
            }
        }
    }

    if (forcedGender) {
        Pokemon_SetGenderAndNature(encounter, species, form, level, RANDOMIZE_IVS, gender, nature);
    } else {
        Pokemon_SetNature(encounter, species, level, RANDOMIZE_IVS, nature);
    }

    Pokemon_Set(encounter, MON_PARAM_OT_ID,         &inputEncInfo->trainerID);
    Pokemon_Set(encounter, MON_PARAM_FORM_NUMBER,   &form);
    Pokemon_CalcPassiveForm(encounter);

    Pokemon_CalcStats(encounter);
    BoxPokemon_CalcAbility(&encounter->boxParams);
    BoxPokemon_InitMoveset(&encounter->boxParams);
    Encounter_AddToWildParty(partyIdx, inputEncInfo, encounter, battleParamsOutput);
    Free(encounter);
}

BOOL Encounter_AddToWildParty(int partyIdx, struct EncounterInfo *encounterInfo, struct Pokemon *encounter, struct BattleParams *battleParams)
{
    #ifdef DEBUG_FORMS
    u8 buf[128];
    sprintf(buf, "PLAT-ENGINE | Invoking Encounter_AddToWildParty\n");
    debugsyscall(buf);
    sprintf(buf, "PLAT-ENGINE | -- partyIdx: %d\n", partyIdx);
    debugsyscall(buf);
    #endif

    int itemRange = 0;
    if (encounterInfo->isEgg == FALSE && encounterInfo->playerLeadAbility == ABILITY_COMPOUND_EYES) {
        itemRange = 1;
    }

    Pokemon_SetItem(encounter, battleParams->battleType, itemRange);

    BOOL formChange = FALSE;
    u16  species    = Pokemon_Get(encounter, MON_PARAM_SPECIES,     NULL);
    u8   formNum    = Pokemon_Get(encounter, MON_PARAM_FORM_NUMBER, NULL);

    // Forms handled this way by the original Platinum code
    if (species == SPECIES_SHELLOS) {
        formChange = TRUE;
        if (!encounterInfo->formChance[0]) {
            #ifdef DEBUG_FORMS
            sprintf(buf, "PLAT-ENGINE | -- Encounter table specifies West-Sea Shellos\n");
            debugsyscall(buf);
            #endif

            formNum = 0;
        } else {
            #ifdef DEBUG_FORMS
            sprintf(buf, "PLAT-ENGINE | -- Encounter table specifies East-Sea Shellos\n");
            debugsyscall(buf);
            #endif

            formNum = 1;
        }
    } else if (species == SPECIES_GASTRODON) {
        formChange = TRUE;
        if (!encounterInfo->formChance[1]) {
            #ifdef DEBUG_FORMS
            sprintf(buf, "PLAT-ENGINE | -- Encounter table specifies West-Sea Gastrodon\n");
            debugsyscall(buf);
            #endif

            formNum = 0;
        } else {
            #ifdef DEBUG_FORMS
            sprintf(buf, "PLAT-ENGINE | -- Encounter table specifies East-Sea Gastrodon\n");
            debugsyscall(buf);
            #endif

            formNum = 1;
        }
    } else if (species == SPECIES_UNOWN) {
        #ifdef DEBUG_FORMS
        sprintf(buf, "PLAT-ENGINE | -- Unown; consulting the Unown form table\n");
        debugsyscall(buf);
        #endif

        formChange = TRUE;
        u8 tableSize = gUnownTable[encounterInfo->unownTableType].size;
        formNum = gUnownTable[encounterInfo->unownTableType].table[GF_RAND() % tableSize];
    } else if (formNum > 0) {
        formChange = TRUE;
    }

    if (formChange) {
        #ifdef DEBUG_FORMS
        sprintf(buf, "PLAT-ENGINE | -- Recomputing stats, ability, moves...\n");
        debugsyscall(buf);
        #endif

        Pokemon_Set(encounter, MON_PARAM_FORM_NUMBER, &formNum);
        Pokemon_CalcStats(encounter);
        BoxPokemon_CalcAbility(&encounter->boxParams);
        BoxPokemon_InitMoveset(&encounter->boxParams);
    }

    #ifdef DEBUG_FORMS
    sprintf(buf, "PLAT-ENGINE | -- Done; expected species and form:\n");
    debugsyscall(buf);
    sprintf(buf, "PLAT-ENGINE | ---- species: 0x%X\n", species);
    debugsyscall(buf);
    sprintf(buf, "PLAT-ENGINE | ---- form:    %d\n", formNum);
    debugsyscall(buf);
    #endif

    BOOL result = Party_Add(battleParams->parties[partyIdx], encounter);
    #ifdef DEBUG_FORMS
    sprintf(buf, "PLAT-ENGINE | -- Returning\n");
    debugsyscall(buf);
    #endif

    return result;
}
