#include "global.h"

#include "archive.h"
#include "heap.h"
#include "item.h"
#include "pokemon.h"
#include "rtc.h"

#include "constants/item_hold_effects.h"
#include "constants/species.h"

#define FRIENDSHIP_EVO_THRESHOLD 220

enum EvoType {
    EVO_TYPE_LEVEL_UP = 0,
    EVO_TYPE_TRADE,
    EVO_TYPE_ITEM_CHECK,
    EVO_TYPE_ITEM_USE,
};

enum EvoCondition {
    EVO_CONDITION_NONE = 0,
    EVO_CONDITION_FRIENDSHIP,           // Most baby Pokemon (Togepi, Pichu, etc.)
    EVO_CONDITION_FRIENDSHIP_DAY,       // Eevee -> Espeon
    EVO_CONDITION_FRIENDSHIP_NIGHT,     // Eevee -> Umbreon
    EVO_CONDITION_LEVEL_UP,
    EVO_CONDITION_TRADE,
    EVO_CONDITION_TRADE_WITH_ITEM,
    EVO_CONDITION_USE_ITEM,
    EVO_CONDITION_ATTACK_GT_DEFENSE,    // Tyrogue -> Hitmonlee
    EVO_CONDITION_ATTACK_EQ_DEFENSE,    // Tyrogue -> Hitmontop
    EVO_CONDITION_ATTACK_LT_DEFENSE,    // Tyrogue -> Hitmonchan
    EVO_CONDITION_PID_LOW,              // Wurmple -> Silcoon
    EVO_CONDITION_PID_HIGH,             // Wurmple -> Cascoon              
    EVO_CONDITION_NINJASK,
    EVO_CONDITION_SHEDINJA,
    EVO_CONDITION_BEAUTY,               // Feebas -> Milotic
    EVO_CONDITION_USE_ITEM_MALE,        // Kirlia -> Gallade
    EVO_CONDITION_USE_ITEM_FEMALE,      // Snorunt -> Froslass
    EVO_CONDITION_HOLD_ITEM_DAY,        // Happiny -> Chansey
    EVO_CONDITION_HOLD_ITEM_NIGHT,      // Sneasel -> Weavile
    EVO_CONDITION_KNOW_MOVE,            // Piloswine -> Mamoswine
    EVO_CONDITION_MON_IN_PARTY,         // Mantyke -> Mantine
    EVO_CONDITION_MALE,                 // Burmy -> Mothim
    EVO_CONDITION_FEMALE,               // Burmy -> Wormadam
    EVO_CONDITION_ELECTRIC_FIELD,       // Magneton -> Magnezone
    EVO_CONDITION_MOSSY_STONE,          // Eevee -> Leafeon
    EVO_CONDITION_ICY_STONE             // Eevee -> Glaceon
};

// I hate this.
#define SET_EVO_RESULT_WITH_FORM { \
    if (party != NULL) { \
        for (unsigned int j = 0; j < party->count; j++) { \
            partyPokemon = Party_Member(party, j); \
            if (Pokemon_Equals(pokemon, partyPokemon)) break; \
        } \
        result = evoTable[i].target & 0x07FF; \
        form   = evoTable[i].target >> 11; \
        if (form != 0) Pokemon_Set(partyPokemon, MON_PARAM_FORM_NUMBER, &form); \
    } else { \
        result = evoTable[i].target & 0x07FF; \
        form   = evoTable[i].target >> 11; \
        Pokemon_Set(pokemon, MON_PARAM_FORM_NUMBER, &form); \
    } \
}

u16 Pokemon_CheckEvolution(struct Party *party, struct Pokemon *pokemon, u8 evoType, u16 usedItemID, int *methodOut)
{
    u16 species  = Pokemon_Get(pokemon, MON_PARAM_SPECIES,     NULL);
    u16 heldItem = Pokemon_Get(pokemon, MON_PARAM_HELD_ITEM,   NULL);
    u32 pid      = Pokemon_Get(pokemon, MON_PARAM_PID,         NULL);
    u8  beauty   = Pokemon_Get(pokemon, MON_PARAM_BEAUTY,      NULL);     // for Feebas
    u8  form     = Pokemon_Get(pokemon, MON_PARAM_FORM_NUMBER, NULL);
    u16 pidHigh  = HI_HALF(pid);

    s32 heldItemEffect = Item_Get(heldItem, ITEM_PARAM_HOLD_EFFECT, HEAP_ID_SYSTEM);
    if (heldItemEffect == HOLD_EFFECT_NO_EVOLUTION && evoType != EVO_TYPE_ITEM_USE) {   // bugfix: Kadabra now works with Everstone
        return SPECIES_NONE;
    }

    if (methodOut == NULL) {
        int dummy;
        methodOut = &dummy;
    }

    species = Pokemon_FormTarget(species, form);
    struct EvoData *evoTable = Malloc(HEAP_ID_SYSTEM, MAX_EVOLUTIONS * sizeof(struct EvoData));
    LoadFromNARC(evoTable, ARCHIVE_EVOLUTIONS, species);

    struct Pokemon *partyPokemon = NULL;
    u16 result = SPECIES_NONE;
    switch (evoType) {
    case EVO_TYPE_LEVEL_UP:
        u8  level      = Pokemon_Get(pokemon, MON_PARAM_LEVEL, NULL);
        u16 friendship = Pokemon_Get(pokemon, MON_PARAM_FRIENDSHIP, NULL);
        for (unsigned int i = 0; i < MAX_EVOLUTIONS; i++) {
            switch (evoTable[i].condition) {
            case EVO_CONDITION_FRIENDSHIP:
                if (friendship >= FRIENDSHIP_EVO_THRESHOLD) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_FRIENDSHIP;
                }
                break;

            case EVO_CONDITION_FRIENDSHIP_DAY:
                if (RTC_IsNight() == FALSE && friendship >= FRIENDSHIP_EVO_THRESHOLD) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_FRIENDSHIP_DAY;
                }
                break;

            case EVO_CONDITION_FRIENDSHIP_NIGHT:
                if (RTC_IsNight() && friendship >= FRIENDSHIP_EVO_THRESHOLD) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_FRIENDSHIP_NIGHT;
                }
                break;

            case EVO_CONDITION_LEVEL_UP:
                if (level >= evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_LEVEL_UP;
                }
                break;
            
            case EVO_CONDITION_ATTACK_GT_DEFENSE:
                if (level >= evoTable[i].param
                        && Pokemon_Get(pokemon, MON_PARAM_ATTACK, NULL) > Pokemon_Get(pokemon, MON_PARAM_DEFENSE, NULL)) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_ATTACK_GT_DEFENSE;
                }
                break;
            
            case EVO_CONDITION_ATTACK_EQ_DEFENSE:
                if (level >= evoTable[i].param
                        && Pokemon_Get(pokemon, MON_PARAM_ATTACK, NULL) == Pokemon_Get(pokemon, MON_PARAM_DEFENSE, NULL)) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_ATTACK_EQ_DEFENSE;
                }
                break;
            
            case EVO_CONDITION_ATTACK_LT_DEFENSE:
                if (level >= evoTable[i].param
                        && Pokemon_Get(pokemon, MON_PARAM_ATTACK, NULL) < Pokemon_Get(pokemon, MON_PARAM_DEFENSE, NULL)) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_ATTACK_LT_DEFENSE;
                }
                break;

            case EVO_CONDITION_PID_LOW:
                if (level >= evoTable[i].param && (pid % 10) < 5) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_PID_LOW;
                }
                break;

            case EVO_CONDITION_PID_HIGH:
                if (level >= evoTable[i].param && (pid % 10) >= 5) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_PID_HIGH;
                }
                break;
            
            case EVO_CONDITION_NINJASK:
                if (level >= evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_NINJASK;
                }
                break;

            case EVO_CONDITION_SHEDINJA:
                *methodOut = EVO_CONDITION_SHEDINJA;
                break;
            
            case EVO_CONDITION_BEAUTY:
                if (beauty >= evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_BEAUTY;
                }
                break;
            
            case EVO_CONDITION_HOLD_ITEM_DAY:
                if (RTC_IsNight() == FALSE && heldItem == evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_HOLD_ITEM_DAY;
                }
                break;
            
            case EVO_CONDITION_HOLD_ITEM_NIGHT:
                if (RTC_IsNight() && heldItem == evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_HOLD_ITEM_NIGHT;
                }
                break;
            
            case EVO_CONDITION_KNOW_MOVE:
                if (Pokemon_KnowsMove(pokemon, evoTable[i].param)) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_KNOW_MOVE;
                }
                break;

            case EVO_CONDITION_MON_IN_PARTY:
                if (party != NULL && Party_HasPokemon(party, evoTable[i].param)) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_MON_IN_PARTY;
                }
                break;
            
            case EVO_CONDITION_MALE:
                if (Pokemon_Get(pokemon, MON_PARAM_GENDER, NULL) == GENDER_MALE && level >= evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_MALE;
                }
                break;
            
            case EVO_CONDITION_FEMALE:
                if (Pokemon_Get(pokemon, MON_PARAM_GENDER, NULL) == GENDER_FEMALE && level >= evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_FEMALE;
                }
                break;
            
            case EVO_CONDITION_ELECTRIC_FIELD:
                if (usedItemID == evoTable[i].condition) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_ELECTRIC_FIELD;
                }
                break;
            
            case EVO_CONDITION_MOSSY_STONE:
                if (usedItemID == evoTable[i].condition) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_MOSSY_STONE;
                }
                break;
            
            case EVO_CONDITION_ICY_STONE:
                if (usedItemID == evoTable[i].condition) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_ICY_STONE;
                }
                break;
            }
            
            if (result) {   // stop at the first result that we find
                break;
            }
        }

        break;

    case EVO_TYPE_TRADE:
        for (unsigned int i = 0; i < MAX_EVOLUTIONS; i++) {
            switch (evoTable[i].condition) {
            case EVO_CONDITION_TRADE:
                SET_EVO_RESULT_WITH_FORM
                *methodOut = EVO_CONDITION_TRADE;
                break;

            case EVO_CONDITION_TRADE_WITH_ITEM:
                if (heldItem == evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = EVO_CONDITION_TRADE_WITH_ITEM;
                }
                break;
            }

            if (result) {
                break;
            }
        }

        break;

    case EVO_TYPE_ITEM_CHECK:
    case EVO_TYPE_ITEM_USE:
        for (unsigned int i = 0; i < MAX_EVOLUTIONS; i++) {
            switch (evoTable[i].condition) {
            case EVO_CONDITION_USE_ITEM:
                if (usedItemID == evoTable[i].param) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = 0; // ?
                }
                break;
                
            case EVO_CONDITION_USE_ITEM_MALE:
                if (usedItemID == evoTable[i].param && Pokemon_Get(pokemon, MON_PARAM_GENDER, NULL) == GENDER_MALE) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = 0; // ?
                }
                break;

            case EVO_CONDITION_USE_ITEM_FEMALE:
                if (usedItemID == evoTable[i].param && Pokemon_Get(pokemon, MON_PARAM_GENDER, NULL) == GENDER_FEMALE) {
                    SET_EVO_RESULT_WITH_FORM
                    *methodOut = 0; // ?
                }
                break;
            }

            if (result) {
                break;
            }
        }

        break;
    }

    Free(evoTable);
    return result;
}