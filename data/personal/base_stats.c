#include "global.h"

#include "battle.h"
#include "pokemon.h"
#include "constants/abilities.h"
#include "constants/item.h"
#include "constants/misc.h"
#include "constants/species.h"

#include "./tm_learnsets.h"

u32 __size = sizeof(struct BaseStats);

const struct BaseStats __data[] = {

    [SPECIES_NONE] = {
        .baseHP        = 0,
        .baseAttack    = 0,
        .baseDefense   = 0,
        .baseSpeed     = 0,
        .baseSpAttack  = 0,
        .baseSpDefense = 0,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_NONE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 0,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 0,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 0,
        .eggCycles = 0,
        .eggGroup1 = EGG_GROUP_NONE,
        .eggGroup2 = EGG_GROUP_NONE,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NONE,
            TM_LEARNSET_2_NONE,
            TM_LEARNSET_3_NONE,
            TM_LEARNSET_4_NONE
        },
    },

    [SPECIES_BULBASAUR] = {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 49,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 64,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BULBASAUR,
            TM_LEARNSET_2_BULBASAUR,
            TM_LEARNSET_3_BULBASAUR,
            TM_LEARNSET_4_BULBASAUR
        },
    },

    [SPECIES_IVYSAUR] = {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 63,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 141,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_IVYSAUR,
            TM_LEARNSET_2_IVYSAUR,
            TM_LEARNSET_3_IVYSAUR,
            TM_LEARNSET_4_IVYSAUR
        },
    },

    [SPECIES_VENUSAUR] = {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 83,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 208,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VENUSAUR,
            TM_LEARNSET_2_VENUSAUR,
            TM_LEARNSET_3_VENUSAUR,
            TM_LEARNSET_4_VENUSAUR
        },
    },

    [SPECIES_CHARMANDER] = {
        .baseHP        = 39,
        .baseAttack    = 52,
        .baseDefense   = 43,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 65,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHARMANDER,
            TM_LEARNSET_2_CHARMANDER,
            TM_LEARNSET_3_CHARMANDER,
            TM_LEARNSET_4_CHARMANDER
        },
    },

    [SPECIES_CHARMELEON] = {
        .baseHP        = 58,
        .baseAttack    = 64,
        .baseDefense   = 58,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 65,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 142,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHARMELEON,
            TM_LEARNSET_2_CHARMELEON,
            TM_LEARNSET_3_CHARMELEON,
            TM_LEARNSET_4_CHARMELEON
        },
    },

    [SPECIES_CHARIZARD] = {
        .baseHP        = 78,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = 109,
        .baseSpDefense = 85,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 209,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHARIZARD,
            TM_LEARNSET_2_CHARIZARD,
            TM_LEARNSET_3_CHARIZARD,
            TM_LEARNSET_4_CHARIZARD
        },
    },

    [SPECIES_SQUIRTLE] = {
        .baseHP        = 44,
        .baseAttack    = 48,
        .baseDefense   = 65,
        .baseSpeed     = 43,
        .baseSpAttack  = 50,
        .baseSpDefense = 64,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 66,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SQUIRTLE,
            TM_LEARNSET_2_SQUIRTLE,
            TM_LEARNSET_3_SQUIRTLE,
            TM_LEARNSET_4_SQUIRTLE
        },
    },

    [SPECIES_WARTORTLE] = {
        .baseHP        = 59,
        .baseAttack    = 63,
        .baseDefense   = 80,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = 80,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 143,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WARTORTLE,
            TM_LEARNSET_2_WARTORTLE,
            TM_LEARNSET_3_WARTORTLE,
            TM_LEARNSET_4_WARTORTLE
        },
    },

    [SPECIES_BLASTOISE] = {
        .baseHP        = 79,
        .baseAttack    = 83,
        .baseDefense   = 100,
        .baseSpeed     = 78,
        .baseSpAttack  = 85,
        .baseSpDefense = 105,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 210,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BLASTOISE,
            TM_LEARNSET_2_BLASTOISE,
            TM_LEARNSET_3_BLASTOISE,
            TM_LEARNSET_4_BLASTOISE
        },
    },

    [SPECIES_CATERPIE] = {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 35,
        .baseSpeed     = 45,
        .baseSpAttack  = 20,
        .baseSpDefense = 20,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SHIELD_DUST,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 53,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CATERPIE,
            TM_LEARNSET_2_CATERPIE,
            TM_LEARNSET_3_CATERPIE,
            TM_LEARNSET_4_CATERPIE
        },
    },

    [SPECIES_METAPOD] = {
        .baseHP        = 50,
        .baseAttack    = 20,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 72,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_METAPOD,
            TM_LEARNSET_2_METAPOD,
            TM_LEARNSET_3_METAPOD,
            TM_LEARNSET_4_METAPOD
        },
    },

    [SPECIES_BUTTERFREE] = {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_COMPOUND_EYES,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SILVER_POWDER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 160,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BUTTERFREE,
            TM_LEARNSET_2_BUTTERFREE,
            TM_LEARNSET_3_BUTTERFREE,
            TM_LEARNSET_4_BUTTERFREE
        },
    },

    [SPECIES_WEEDLE] = {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 50,
        .baseSpAttack  = 20,
        .baseSpDefense = 20,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SHIELD_DUST,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 52,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WEEDLE,
            TM_LEARNSET_2_WEEDLE,
            TM_LEARNSET_3_WEEDLE,
            TM_LEARNSET_4_WEEDLE
        },
    },

    [SPECIES_KAKUNA] = {
        .baseHP        = 45,
        .baseAttack    = 25,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 71,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KAKUNA,
            TM_LEARNSET_2_KAKUNA,
            TM_LEARNSET_3_KAKUNA,
            TM_LEARNSET_4_KAKUNA
        },
    },

    [SPECIES_BEEDRILL] = {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 40,
        .baseSpeed     = 75,
        .baseSpAttack  = 45,
        .baseSpDefense = 80,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 159,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BEEDRILL,
            TM_LEARNSET_2_BEEDRILL,
            TM_LEARNSET_3_BEEDRILL,
            TM_LEARNSET_4_BEEDRILL
        },
    },

    [SPECIES_PIDGEY] = {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 56,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_TANGLED_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 55,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PIDGEY,
            TM_LEARNSET_2_PIDGEY,
            TM_LEARNSET_3_PIDGEY,
            TM_LEARNSET_4_PIDGEY
        },
    },

    [SPECIES_PIDGEOTTO] = {
        .baseHP        = 63,
        .baseAttack    = 60,
        .baseDefense   = 55,
        .baseSpeed     = 71,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_TANGLED_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 113,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PIDGEOTTO,
            TM_LEARNSET_2_PIDGEOTTO,
            TM_LEARNSET_3_PIDGEOTTO,
            TM_LEARNSET_4_PIDGEOTTO
        },
    },

    [SPECIES_PIDGEOT] = {
        .baseHP        = 83,
        .baseAttack    = 80,
        .baseDefense   = 75,
        .baseSpeed     = 91,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_TANGLED_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 3,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 172,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PIDGEOT,
            TM_LEARNSET_2_PIDGEOT,
            TM_LEARNSET_3_PIDGEOT,
            TM_LEARNSET_4_PIDGEOT
        },
    },

    [SPECIES_RATTATA] = {
        .baseHP        = 30,
        .baseAttack    = 56,
        .baseDefense   = 35,
        .baseSpeed     = 72,
        .baseSpAttack  = 25,
        .baseSpDefense = 35,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_GUTS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHILAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 57,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RATTATA,
            TM_LEARNSET_2_RATTATA,
            TM_LEARNSET_3_RATTATA,
            TM_LEARNSET_4_RATTATA
        },
    },

    [SPECIES_RATICATE] = {
        .baseHP        = 55,
        .baseAttack    = 81,
        .baseDefense   = 60,
        .baseSpeed     = 97,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_GUTS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHILAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 127,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 116,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RATICATE,
            TM_LEARNSET_2_RATICATE,
            TM_LEARNSET_3_RATICATE,
            TM_LEARNSET_4_RATICATE
        },
    },

    [SPECIES_SPEAROW] = {
        .baseHP        = 40,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 70,
        .baseSpAttack  = 31,
        .baseSpDefense = 31,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 58,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SPEAROW,
            TM_LEARNSET_2_SPEAROW,
            TM_LEARNSET_3_SPEAROW,
            TM_LEARNSET_4_SPEAROW
        },
    },

    [SPECIES_FEAROW] = {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 61,
        .baseSpDefense = 61,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHARP_BEAK,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 162,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FEAROW,
            TM_LEARNSET_2_FEAROW,
            TM_LEARNSET_3_FEAROW,
            TM_LEARNSET_4_FEAROW
        },
    },

    [SPECIES_EKANS] = {
        .baseHP        = 35,
        .baseAttack    = 60,
        .baseDefense   = 44,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 54,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_SHED_SKIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 62,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_EKANS,
            TM_LEARNSET_2_EKANS,
            TM_LEARNSET_3_EKANS,
            TM_LEARNSET_4_EKANS
        },
    },

    [SPECIES_ARBOK] = {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 69,
        .baseSpeed     = 80,
        .baseSpAttack  = 65,
        .baseSpDefense = 79,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_SHED_SKIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 147,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ARBOK,
            TM_LEARNSET_2_ARBOK,
            TM_LEARNSET_3_ARBOK,
            TM_LEARNSET_4_ARBOK
        },
    },

    [SPECIES_PIKACHU] = {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 30,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 40,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_ORAN_BERRY,
        .itemRare     = ITEM_LIGHT_BALL,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 82,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PIKACHU,
            TM_LEARNSET_2_PIKACHU,
            TM_LEARNSET_3_PIKACHU,
            TM_LEARNSET_4_PIKACHU
        },
    },

    [SPECIES_RAICHU] = {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 55,
        .baseSpeed     = 100,
        .baseSpAttack  = 90,
        .baseSpDefense = 80,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_ORAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 3,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 122,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RAICHU,
            TM_LEARNSET_2_RAICHU,
            TM_LEARNSET_3_RAICHU,
            TM_LEARNSET_4_RAICHU
        },
    },

    [SPECIES_SANDSHREW] = {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_QUICK_CLAW,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 93,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SANDSHREW,
            TM_LEARNSET_2_SANDSHREW,
            TM_LEARNSET_3_SANDSHREW,
            TM_LEARNSET_4_SANDSHREW
        },
    },

    [SPECIES_SANDSLASH] = {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_QUICK_CLAW,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 163,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SANDSLASH,
            TM_LEARNSET_2_SANDSLASH,
            TM_LEARNSET_3_SANDSLASH,
            TM_LEARNSET_4_SANDSLASH
        },
    },

    [SPECIES_NIDORAN_F] = {
        .baseHP        = 55,
        .baseAttack    = 47,
        .baseDefense   = 52,
        .baseSpeed     = 41,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_RIVALRY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 235,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 59,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NIDORAN_F,
            TM_LEARNSET_2_NIDORAN_F,
            TM_LEARNSET_3_NIDORAN_F,
            TM_LEARNSET_4_NIDORAN_F
        },
    },

    [SPECIES_NIDORINA] = {
        .baseHP        = 70,
        .baseAttack    = 62,
        .baseDefense   = 67,
        .baseSpeed     = 56,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_RIVALRY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 117,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NIDORINA,
            TM_LEARNSET_2_NIDORINA,
            TM_LEARNSET_3_NIDORINA,
            TM_LEARNSET_4_NIDORINA
        },
    },

    [SPECIES_NIDOQUEEN] = {
        .baseHP        = 90,
        .baseAttack    = 82,
        .baseDefense   = 87,
        .baseSpeed     = 76,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_RIVALRY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 194,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NIDOQUEEN,
            TM_LEARNSET_2_NIDOQUEEN,
            TM_LEARNSET_3_NIDOQUEEN,
            TM_LEARNSET_4_NIDOQUEEN
        },
    },

    [SPECIES_NIDORAN_M] = {
        .baseHP        = 46,
        .baseAttack    = 57,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_RIVALRY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 235,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 60,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NIDORAN_M,
            TM_LEARNSET_2_NIDORAN_M,
            TM_LEARNSET_3_NIDORAN_M,
            TM_LEARNSET_4_NIDORAN_M
        },
    },

    [SPECIES_NIDORINO] = {
        .baseHP        = 61,
        .baseAttack    = 72,
        .baseDefense   = 57,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_RIVALRY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 118,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NIDORINO,
            TM_LEARNSET_2_NIDORINO,
            TM_LEARNSET_3_NIDORINO,
            TM_LEARNSET_4_NIDORINO
        },
    },

    [SPECIES_NIDOKING] = {
        .baseHP        = 81,
        .baseAttack    = 92,
        .baseDefense   = 77,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_RIVALRY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 195,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NIDOKING,
            TM_LEARNSET_2_NIDOKING,
            TM_LEARNSET_3_NIDOKING,
            TM_LEARNSET_4_NIDOKING
        },
    },

    [SPECIES_CLEFAIRY] = {
        .baseHP        = 70,
        .baseAttack    = 45,
        .baseDefense   = 48,
        .baseSpeed     = 35,
        .baseSpAttack  = 60,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_MAGIC_GUARD,

        .itemUncommon = ITEM_LEPPA_BERRY,
        .itemRare     = ITEM_MOON_STONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 150,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 140,
        .expCurve = GROWTH_FAST,
        .expYield = 68,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CLEFAIRY,
            TM_LEARNSET_2_CLEFAIRY,
            TM_LEARNSET_3_CLEFAIRY,
            TM_LEARNSET_4_CLEFAIRY
        },
    },

    [SPECIES_CLEFABLE] = {
        .baseHP        = 95,
        .baseAttack    = 70,
        .baseDefense   = 73,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 90,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_MAGIC_GUARD,

        .itemUncommon = ITEM_LEPPA_BERRY,
        .itemRare     = ITEM_MOON_STONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 140,
        .expCurve = GROWTH_FAST,
        .expYield = 129,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CLEFABLE,
            TM_LEARNSET_2_CLEFABLE,
            TM_LEARNSET_3_CLEFABLE,
            TM_LEARNSET_4_CLEFABLE
        },
    },

    [SPECIES_VULPIX] = {
        .baseHP        = 38,
        .baseAttack    = 41,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 65,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_FLASH_FIRE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_RAWST_BERRY,
        .itemRare     = ITEM_RAWST_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 63,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VULPIX,
            TM_LEARNSET_2_VULPIX,
            TM_LEARNSET_3_VULPIX,
            TM_LEARNSET_4_VULPIX
        },
    },

    [SPECIES_NINETALES] = {
        .baseHP        = 73,
        .baseAttack    = 76,
        .baseDefense   = 75,
        .baseSpeed     = 100,
        .baseSpAttack  = 81,
        .baseSpDefense = 100,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_FLASH_FIRE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_RAWST_BERRY,
        .itemRare     = ITEM_RAWST_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 178,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NINETALES,
            TM_LEARNSET_2_NINETALES,
            TM_LEARNSET_3_NINETALES,
            TM_LEARNSET_4_NINETALES
        },
    },

    [SPECIES_JIGGLYPUFF] = {
        .baseHP        = 115,
        .baseAttack    = 45,
        .baseDefense   = 20,
        .baseSpeed     = 20,
        .baseSpAttack  = 45,
        .baseSpDefense = 25,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 170,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 76,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_JIGGLYPUFF,
            TM_LEARNSET_2_JIGGLYPUFF,
            TM_LEARNSET_3_JIGGLYPUFF,
            TM_LEARNSET_4_JIGGLYPUFF
        },
    },

    [SPECIES_WIGGLYTUFF] = {
        .baseHP        = 140,
        .baseAttack    = 70,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 75,
        .baseSpDefense = 50,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 50,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 109,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WIGGLYTUFF,
            TM_LEARNSET_2_WIGGLYTUFF,
            TM_LEARNSET_3_WIGGLYTUFF,
            TM_LEARNSET_4_WIGGLYTUFF
        },
    },

    [SPECIES_ZUBAT] = {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 55,
        .baseSpAttack  = 30,
        .baseSpDefense = 40,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 54,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ZUBAT,
            TM_LEARNSET_2_ZUBAT,
            TM_LEARNSET_3_ZUBAT,
            TM_LEARNSET_4_ZUBAT
        },
    },

    [SPECIES_GOLBAT] = {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 65,
        .baseSpDefense = 75,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 171,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GOLBAT,
            TM_LEARNSET_2_GOLBAT,
            TM_LEARNSET_3_GOLBAT,
            TM_LEARNSET_4_GOLBAT
        },
    },

    [SPECIES_ODDISH] = {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 75,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 78,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ODDISH,
            TM_LEARNSET_2_ODDISH,
            TM_LEARNSET_3_ODDISH,
            TM_LEARNSET_4_ODDISH
        },
    },

    [SPECIES_GLOOM] = {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GLOOM,
            TM_LEARNSET_2_GLOOM,
            TM_LEARNSET_3_GLOOM,
            TM_LEARNSET_4_GLOOM
        },
    },

    [SPECIES_VILEPLUME] = {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 85,
        .baseSpeed     = 50,
        .baseSpAttack  = 100,
        .baseSpDefense = 90,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 184,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VILEPLUME,
            TM_LEARNSET_2_VILEPLUME,
            TM_LEARNSET_3_VILEPLUME,
            TM_LEARNSET_4_VILEPLUME
        },
    },

    [SPECIES_PARAS] = {
        .baseHP        = 35,
        .baseAttack    = 70,
        .baseDefense   = 55,
        .baseSpeed     = 25,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_EFFECT_SPORE,
        .ability2 = ABILITY_DRY_SKIN,

        .itemUncommon = ITEM_TINY_MUSHROOM,
        .itemRare     = ITEM_BIG_MUSHROOM,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 70,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PARAS,
            TM_LEARNSET_2_PARAS,
            TM_LEARNSET_3_PARAS,
            TM_LEARNSET_4_PARAS
        },
    },

    [SPECIES_PARASECT] = {
        .baseHP        = 60,
        .baseAttack    = 95,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 60,
        .baseSpDefense = 80,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_EFFECT_SPORE,
        .ability2 = ABILITY_DRY_SKIN,

        .itemUncommon = ITEM_TINY_MUSHROOM,
        .itemRare     = ITEM_BIG_MUSHROOM,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 128,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PARASECT,
            TM_LEARNSET_2_PARASECT,
            TM_LEARNSET_3_PARASECT,
            TM_LEARNSET_4_PARASECT
        },
    },

    [SPECIES_VENONAT] = {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 45,
        .baseSpAttack  = 40,
        .baseSpDefense = 55,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_COMPOUND_EYES,
        .ability2 = ABILITY_TINTED_LENS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 75,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VENONAT,
            TM_LEARNSET_2_VENONAT,
            TM_LEARNSET_3_VENONAT,
            TM_LEARNSET_4_VENONAT
        },
    },

    [SPECIES_VENOMOTH] = {
        .baseHP        = 70,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 90,
        .baseSpAttack  = 90,
        .baseSpDefense = 75,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SHIELD_DUST,
        .ability2 = ABILITY_TINTED_LENS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHED_SHELL,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 138,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VENOMOTH,
            TM_LEARNSET_2_VENOMOTH,
            TM_LEARNSET_3_VENOMOTH,
            TM_LEARNSET_4_VENOMOTH
        },
    },

    [SPECIES_DIGLETT] = {
        .baseHP        = 10,
        .baseAttack    = 55,
        .baseDefense   = 25,
        .baseSpeed     = 95,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_ARENA_TRAP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SOFT_SAND,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 81,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DIGLETT,
            TM_LEARNSET_2_DIGLETT,
            TM_LEARNSET_3_DIGLETT,
            TM_LEARNSET_4_DIGLETT
        },
    },

    [SPECIES_DUGTRIO] = {
        .baseHP        = 35,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 120,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_ARENA_TRAP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SOFT_SAND,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 50,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 153,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DUGTRIO,
            TM_LEARNSET_2_DUGTRIO,
            TM_LEARNSET_3_DUGTRIO,
            TM_LEARNSET_4_DUGTRIO
        },
    },

    [SPECIES_MEOWTH] = {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_PICKUP,
        .ability2 = ABILITY_TECHNICIAN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_QUICK_CLAW,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 69,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MEOWTH,
            TM_LEARNSET_2_MEOWTH,
            TM_LEARNSET_3_MEOWTH,
            TM_LEARNSET_4_MEOWTH
        },
    },

    [SPECIES_PERSIAN] = {
        .baseHP        = 65,
        .baseAttack    = 70,
        .baseDefense   = 60,
        .baseSpeed     = 115,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_LIMBER,
        .ability2 = ABILITY_TECHNICIAN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_QUICK_CLAW,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 148,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PERSIAN,
            TM_LEARNSET_2_PERSIAN,
            TM_LEARNSET_3_PERSIAN,
            TM_LEARNSET_4_PERSIAN
        },
    },

    [SPECIES_PSYDUCK] = {
        .baseHP        = 50,
        .baseAttack    = 52,
        .baseDefense   = 48,
        .baseSpeed     = 55,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_DAMP,
        .ability2 = ABILITY_CLOUD_NINE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 90,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 80,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PSYDUCK,
            TM_LEARNSET_2_PSYDUCK,
            TM_LEARNSET_3_PSYDUCK,
            TM_LEARNSET_4_PSYDUCK
        },
    },

    [SPECIES_GOLDUCK] = {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 78,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 80,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_DAMP,
        .ability2 = ABILITY_CLOUD_NINE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 174,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GOLDUCK,
            TM_LEARNSET_2_GOLDUCK,
            TM_LEARNSET_3_GOLDUCK,
            TM_LEARNSET_4_GOLDUCK
        },
    },

    [SPECIES_MANKEY] = {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_ANGER_POINT,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PAYAPA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 74,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MANKEY,
            TM_LEARNSET_2_MANKEY,
            TM_LEARNSET_3_MANKEY,
            TM_LEARNSET_4_MANKEY
        },
    },

    [SPECIES_PRIMEAPE] = {
        .baseHP        = 65,
        .baseAttack    = 105,
        .baseDefense   = 60,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_ANGER_POINT,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PAYAPA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 149,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PRIMEAPE,
            TM_LEARNSET_2_PRIMEAPE,
            TM_LEARNSET_3_PRIMEAPE,
            TM_LEARNSET_4_PRIMEAPE
        },
    },

    [SPECIES_GROWLITHE] = {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_FLASH_FIRE,

        .itemUncommon = ITEM_RAWST_BERRY,
        .itemRare     = ITEM_RAWST_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 91,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GROWLITHE,
            TM_LEARNSET_2_GROWLITHE,
            TM_LEARNSET_3_GROWLITHE,
            TM_LEARNSET_4_GROWLITHE
        },
    },

    [SPECIES_ARCANINE] = {
        .baseHP        = 90,
        .baseAttack    = 110,
        .baseDefense   = 80,
        .baseSpeed     = 95,
        .baseSpAttack  = 100,
        .baseSpDefense = 80,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_FLASH_FIRE,

        .itemUncommon = ITEM_RAWST_BERRY,
        .itemRare     = ITEM_RAWST_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 213,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ARCANINE,
            TM_LEARNSET_2_ARCANINE,
            TM_LEARNSET_3_ARCANINE,
            TM_LEARNSET_4_ARCANINE
        },
    },

    [SPECIES_POLIWAG] = {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_WATER_ABSORB,
        .ability2 = ABILITY_DAMP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 77,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_POLIWAG,
            TM_LEARNSET_2_POLIWAG,
            TM_LEARNSET_3_POLIWAG,
            TM_LEARNSET_4_POLIWAG
        },
    },

    [SPECIES_POLIWHIRL] = {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 90,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_WATER_ABSORB,
        .ability2 = ABILITY_DAMP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KINGS_ROCK,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 131,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_POLIWHIRL,
            TM_LEARNSET_2_POLIWHIRL,
            TM_LEARNSET_3_POLIWHIRL,
            TM_LEARNSET_4_POLIWHIRL
        },
    },

    [SPECIES_POLIWRATH] = {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 90,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_WATER_ABSORB,
        .ability2 = ABILITY_DAMP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KINGS_ROCK,

        .evYieldHP        = 0,
        .evYieldAttack    = 3,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 185,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_POLIWRATH,
            TM_LEARNSET_2_POLIWRATH,
            TM_LEARNSET_3_POLIWRATH,
            TM_LEARNSET_4_POLIWRATH
        },
    },

    [SPECIES_ABRA] = {
        .baseHP        = 25,
        .baseAttack    = 20,
        .baseDefense   = 15,
        .baseSpeed     = 90,
        .baseSpAttack  = 105,
        .baseSpDefense = 55,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_INNER_FOCUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_TWISTED_SPOON,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 75,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ABRA,
            TM_LEARNSET_2_ABRA,
            TM_LEARNSET_3_ABRA,
            TM_LEARNSET_4_ABRA
        },
    },

    [SPECIES_KADABRA] = {
        .baseHP        = 40,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 105,
        .baseSpAttack  = 120,
        .baseSpDefense = 70,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_INNER_FOCUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_TWISTED_SPOON,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 100,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 145,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KADABRA,
            TM_LEARNSET_2_KADABRA,
            TM_LEARNSET_3_KADABRA,
            TM_LEARNSET_4_KADABRA
        },
    },

    [SPECIES_ALAKAZAM] = {
        .baseHP        = 55,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 120,
        .baseSpAttack  = 135,
        .baseSpDefense = 85,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_INNER_FOCUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_TWISTED_SPOON,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 50,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 186,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ALAKAZAM,
            TM_LEARNSET_2_ALAKAZAM,
            TM_LEARNSET_3_ALAKAZAM,
            TM_LEARNSET_4_ALAKAZAM
        },
    },

    [SPECIES_MACHOP] = {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_NO_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 180,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 75,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MACHOP,
            TM_LEARNSET_2_MACHOP,
            TM_LEARNSET_3_MACHOP,
            TM_LEARNSET_4_MACHOP
        },
    },

    [SPECIES_MACHOKE] = {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = 60,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_NO_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 146,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_MACHOKE,
            TM_LEARNSET_2_MACHOKE,
            TM_LEARNSET_3_MACHOKE,
            TM_LEARNSET_4_MACHOKE
        },
    },

    [SPECIES_MACHAMP] = {
        .baseHP        = 90,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 55,
        .baseSpAttack  = 65,
        .baseSpDefense = 85,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_NO_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 193,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MACHAMP,
            TM_LEARNSET_2_MACHAMP,
            TM_LEARNSET_3_MACHAMP,
            TM_LEARNSET_4_MACHAMP
        },
    },

    [SPECIES_BELLSPROUT] = {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 35,
        .baseSpeed     = 40,
        .baseSpAttack  = 70,
        .baseSpDefense = 30,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 84,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BELLSPROUT,
            TM_LEARNSET_2_BELLSPROUT,
            TM_LEARNSET_3_BELLSPROUT,
            TM_LEARNSET_4_BELLSPROUT
        },
    },

    [SPECIES_WEEPINBELL] = {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 85,
        .baseSpDefense = 45,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 151,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WEEPINBELL,
            TM_LEARNSET_2_WEEPINBELL,
            TM_LEARNSET_3_WEEPINBELL,
            TM_LEARNSET_4_WEEPINBELL
        },
    },

    [SPECIES_VICTREEBEL] = {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 100,
        .baseSpDefense = 60,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 191,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VICTREEBEL,
            TM_LEARNSET_2_VICTREEBEL,
            TM_LEARNSET_3_VICTREEBEL,
            TM_LEARNSET_4_VICTREEBEL
        },
    },

    [SPECIES_TENTACOOL] = {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 50,
        .baseSpDefense = 100,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_LIQUID_OOZE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 105,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TENTACOOL,
            TM_LEARNSET_2_TENTACOOL,
            TM_LEARNSET_3_TENTACOOL,
            TM_LEARNSET_4_TENTACOOL
        },
    },

    [SPECIES_TENTACRUEL] = {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 65,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 120,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_LIQUID_OOZE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 205,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TENTACRUEL,
            TM_LEARNSET_2_TENTACRUEL,
            TM_LEARNSET_3_TENTACRUEL,
            TM_LEARNSET_4_TENTACRUEL
        },
    },

    [SPECIES_GEODUDE] = {
        .baseHP        = 40,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 20,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_EVERSTONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 73,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GEODUDE,
            TM_LEARNSET_2_GEODUDE,
            TM_LEARNSET_3_GEODUDE,
            TM_LEARNSET_4_GEODUDE
        },
    },

    [SPECIES_GRAVELER] = {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 115,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_EVERSTONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 134,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GRAVELER,
            TM_LEARNSET_2_GRAVELER,
            TM_LEARNSET_3_GRAVELER,
            TM_LEARNSET_4_GRAVELER
        },
    },

    [SPECIES_GOLEM] = {
        .baseHP        = 80,
        .baseAttack    = 110,
        .baseDefense   = 130,
        .baseSpeed     = 45,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_EVERSTONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 3,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 177,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GOLEM,
            TM_LEARNSET_2_GOLEM,
            TM_LEARNSET_3_GOLEM,
            TM_LEARNSET_4_GOLEM
        },
    },

    [SPECIES_PONYTA] = {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_FLASH_FIRE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHUCA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 152,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PONYTA,
            TM_LEARNSET_2_PONYTA,
            TM_LEARNSET_3_PONYTA,
            TM_LEARNSET_4_PONYTA
        },
    },

    [SPECIES_RAPIDASH] = {
        .baseHP        = 65,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 105,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_FLASH_FIRE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHUCA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 192,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RAPIDASH,
            TM_LEARNSET_2_RAPIDASH,
            TM_LEARNSET_3_RAPIDASH,
            TM_LEARNSET_4_RAPIDASH
        },
    },

    [SPECIES_SLOWPOKE] = {
        .baseHP        = 90,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 15,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_OWN_TEMPO,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_LAGGING_TAIL,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 99,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SLOWPOKE,
            TM_LEARNSET_2_SLOWPOKE,
            TM_LEARNSET_3_SLOWPOKE,
            TM_LEARNSET_4_SLOWPOKE
        },
    },

    [SPECIES_SLOWBRO] = {
        .baseHP        = 95,
        .baseAttack    = 75,
        .baseDefense   = 110,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 80,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_OWN_TEMPO,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KINGS_ROCK,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 164,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SLOWBRO,
            TM_LEARNSET_2_SLOWBRO,
            TM_LEARNSET_3_SLOWBRO,
            TM_LEARNSET_4_SLOWBRO
        },
    },

    [SPECIES_MAGNEMITE] = {
        .baseHP        = 25,
        .baseAttack    = 35,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 95,
        .baseSpDefense = 55,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_MAGNET_PULL,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 89,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGNEMITE,
            TM_LEARNSET_2_MAGNEMITE,
            TM_LEARNSET_3_MAGNEMITE,
            TM_LEARNSET_4_MAGNEMITE
        },
    },

    [SPECIES_MAGNETON] = {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 95,
        .baseSpeed     = 70,
        .baseSpAttack  = 120,
        .baseSpDefense = 70,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_MAGNET_PULL,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 161,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGNETON,
            TM_LEARNSET_2_MAGNETON,
            TM_LEARNSET_3_MAGNETON,
            TM_LEARNSET_4_MAGNETON
        },
    },

    [SPECIES_FARFETCHD] = {
        .baseHP        = 52,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 58,
        .baseSpDefense = 62,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_INNER_FOCUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_STICK,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 94,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FARFETCHD,
            TM_LEARNSET_2_FARFETCHD,
            TM_LEARNSET_3_FARFETCHD,
            TM_LEARNSET_4_FARFETCHD
        },
    },

    [SPECIES_DODUO] = {
        .baseHP        = 35,
        .baseAttack    = 85,
        .baseDefense   = 45,
        .baseSpeed     = 75,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHARP_BEAK,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 96,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DODUO,
            TM_LEARNSET_2_DODUO,
            TM_LEARNSET_3_DODUO,
            TM_LEARNSET_4_DODUO
        },
    },

    [SPECIES_DODRIO] = {
        .baseHP        = 60,
        .baseAttack    = 110,
        .baseDefense   = 70,
        .baseSpeed     = 100,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHARP_BEAK,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 158,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DODRIO,
            TM_LEARNSET_2_DODRIO,
            TM_LEARNSET_3_DODRIO,
            TM_LEARNSET_4_DODRIO
        },
    },

    [SPECIES_SEEL] = {
        .baseHP        = 65,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 45,
        .baseSpAttack  = 45,
        .baseSpDefense = 70,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_HYDRATION,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 100,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SEEL,
            TM_LEARNSET_2_SEEL,
            TM_LEARNSET_3_SEEL,
            TM_LEARNSET_4_SEEL
        },
    },

    [SPECIES_DEWGONG] = {
        .baseHP        = 90,
        .baseAttack    = 70,
        .baseDefense   = 80,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 95,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_HYDRATION,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 176,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DEWGONG,
            TM_LEARNSET_2_DEWGONG,
            TM_LEARNSET_3_DEWGONG,
            TM_LEARNSET_4_DEWGONG
        },
    },

    [SPECIES_GRIMER] = {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_STENCH,
        .ability2 = ABILITY_STICKY_HOLD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NUGGET,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 90,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GRIMER,
            TM_LEARNSET_2_GRIMER,
            TM_LEARNSET_3_GRIMER,
            TM_LEARNSET_4_GRIMER
        },
    },

    [SPECIES_MUK] = {
        .baseHP        = 105,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 100,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_STENCH,
        .ability2 = ABILITY_STICKY_HOLD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NUGGET,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 157,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MUK,
            TM_LEARNSET_2_MUK,
            TM_LEARNSET_3_MUK,
            TM_LEARNSET_4_MUK
        },
    },

    [SPECIES_SHELLDER] = {
        .baseHP        = 30,
        .baseAttack    = 65,
        .baseDefense   = 100,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 25,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_BATTLE_ARMOR,
        .ability2 = ABILITY_SKILL_LINK,

        .itemUncommon = ITEM_PEARL,
        .itemRare     = ITEM_BIG_PEARL,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 97,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHELLDER,
            TM_LEARNSET_2_SHELLDER,
            TM_LEARNSET_3_SHELLDER,
            TM_LEARNSET_4_SHELLDER
        },
    },

    [SPECIES_CLOYSTER] = {
        .baseHP        = 50,
        .baseAttack    = 95,
        .baseDefense   = 180,
        .baseSpeed     = 70,
        .baseSpAttack  = 85,
        .baseSpDefense = 45,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_BATTLE_ARMOR,
        .ability2 = ABILITY_SKILL_LINK,

        .itemUncommon = ITEM_PEARL,
        .itemRare     = ITEM_BIG_PEARL,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 203,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CLOYSTER,
            TM_LEARNSET_2_CLOYSTER,
            TM_LEARNSET_3_CLOYSTER,
            TM_LEARNSET_4_CLOYSTER
        },
    },

    [SPECIES_GASTLY] = {
        .baseHP        = 30,
        .baseAttack    = 35,
        .baseDefense   = 30,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 35,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 95,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GASTLY,
            TM_LEARNSET_2_GASTLY,
            TM_LEARNSET_3_GASTLY,
            TM_LEARNSET_4_GASTLY
        },
    },

    [SPECIES_HAUNTER] = {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 115,
        .baseSpDefense = 55,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 126,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HAUNTER,
            TM_LEARNSET_2_HAUNTER,
            TM_LEARNSET_3_HAUNTER,
            TM_LEARNSET_4_HAUNTER
        },
    },

    [SPECIES_GENGAR] = {
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = 75,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 190,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GENGAR,
            TM_LEARNSET_2_GENGAR,
            TM_LEARNSET_3_GENGAR,
            TM_LEARNSET_4_GENGAR
        },
    },

    [SPECIES_ONIX] = {
        .baseHP        = 35,
        .baseAttack    = 45,
        .baseDefense   = 160,
        .baseSpeed     = 70,
        .baseSpAttack  = 30,
        .baseSpDefense = 45,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 108,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ONIX,
            TM_LEARNSET_2_ONIX,
            TM_LEARNSET_3_ONIX,
            TM_LEARNSET_4_ONIX
        },
    },

    [SPECIES_DROWZEE] = {
        .baseHP        = 60,
        .baseAttack    = 48,
        .baseDefense   = 45,
        .baseSpeed     = 42,
        .baseSpAttack  = 43,
        .baseSpDefense = 90,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_FOREWARN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 102,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DROWZEE,
            TM_LEARNSET_2_DROWZEE,
            TM_LEARNSET_3_DROWZEE,
            TM_LEARNSET_4_DROWZEE
        },
    },

    [SPECIES_HYPNO] = {
        .baseHP        = 85,
        .baseAttack    = 73,
        .baseDefense   = 70,
        .baseSpeed     = 67,
        .baseSpAttack  = 73,
        .baseSpDefense = 115,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_FOREWARN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 165,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HYPNO,
            TM_LEARNSET_2_HYPNO,
            TM_LEARNSET_3_HYPNO,
            TM_LEARNSET_4_HYPNO
        },
    },

    [SPECIES_KRABBY] = {
        .baseHP        = 30,
        .baseAttack    = 105,
        .baseDefense   = 90,
        .baseSpeed     = 50,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 115,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KRABBY,
            TM_LEARNSET_2_KRABBY,
            TM_LEARNSET_3_KRABBY,
            TM_LEARNSET_4_KRABBY
        },
    },

    [SPECIES_KINGLER] = {
        .baseHP        = 55,
        .baseAttack    = 130,
        .baseDefense   = 115,
        .baseSpeed     = 75,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 206,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_RED,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_KINGLER,
            TM_LEARNSET_2_KINGLER,
            TM_LEARNSET_3_KINGLER,
            TM_LEARNSET_4_KINGLER
        },
    },

    [SPECIES_VOLTORB] = {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 100,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_SOUNDPROOF,
        .ability2 = ABILITY_STATIC,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 103,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VOLTORB,
            TM_LEARNSET_2_VOLTORB,
            TM_LEARNSET_3_VOLTORB,
            TM_LEARNSET_4_VOLTORB
        },
    },

    [SPECIES_ELECTRODE] = {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 70,
        .baseSpeed     = 140,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_SOUNDPROOF,
        .ability2 = ABILITY_STATIC,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 150,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ELECTRODE,
            TM_LEARNSET_2_ELECTRODE,
            TM_LEARNSET_3_ELECTRODE,
            TM_LEARNSET_4_ELECTRODE
        },
    },

    [SPECIES_EXEGGCUTE] = {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 80,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 45,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 98,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_EXEGGCUTE,
            TM_LEARNSET_2_EXEGGCUTE,
            TM_LEARNSET_3_EXEGGCUTE,
            TM_LEARNSET_4_EXEGGCUTE
        },
    },

    [SPECIES_EXEGGUTOR] = {
        .baseHP        = 95,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 125,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 212,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_EXEGGUTOR,
            TM_LEARNSET_2_EXEGGUTOR,
            TM_LEARNSET_3_EXEGGUTOR,
            TM_LEARNSET_4_EXEGGUTOR
        },
    },

    [SPECIES_CUBONE] = {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 95,
        .baseSpeed     = 35,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_LIGHTNING_ROD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_THICK_CLUB,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 87,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CUBONE,
            TM_LEARNSET_2_CUBONE,
            TM_LEARNSET_3_CUBONE,
            TM_LEARNSET_4_CUBONE
        },
    },

    [SPECIES_MAROWAK] = {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_LIGHTNING_ROD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_THICK_CLUB,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 124,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAROWAK,
            TM_LEARNSET_2_MAROWAK,
            TM_LEARNSET_3_MAROWAK,
            TM_LEARNSET_4_MAROWAK
        },
    },

    [SPECIES_HITMONLEE] = {
        .baseHP        = 50,
        .baseAttack    = 120,
        .baseDefense   = 53,
        .baseSpeed     = 87,
        .baseSpAttack  = 35,
        .baseSpDefense = 110,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_LIMBER,
        .ability2 = ABILITY_RECKLESS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 139,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HITMONLEE,
            TM_LEARNSET_2_HITMONLEE,
            TM_LEARNSET_3_HITMONLEE,
            TM_LEARNSET_4_HITMONLEE
        },
    },

    [SPECIES_HITMONCHAN] = {
        .baseHP        = 50,
        .baseAttack    = 105,
        .baseDefense   = 79,
        .baseSpeed     = 76,
        .baseSpAttack  = 35,
        .baseSpDefense = 110,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_IRON_FIST,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 140,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HITMONCHAN,
            TM_LEARNSET_2_HITMONCHAN,
            TM_LEARNSET_3_HITMONCHAN,
            TM_LEARNSET_4_HITMONCHAN
        },
    },

    [SPECIES_LICKITUNG] = {
        .baseHP        = 90,
        .baseAttack    = 55,
        .baseDefense   = 75,
        .baseSpeed     = 30,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_OWN_TEMPO,
        .ability2 = ABILITY_OBLIVIOUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_LAGGING_TAIL,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 127,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LICKITUNG,
            TM_LEARNSET_2_LICKITUNG,
            TM_LEARNSET_3_LICKITUNG,
            TM_LEARNSET_4_LICKITUNG
        },
    },

    [SPECIES_KOFFING] = {
        .baseHP        = 40,
        .baseAttack    = 65,
        .baseDefense   = 95,
        .baseSpeed     = 35,
        .baseSpAttack  = 60,
        .baseSpDefense = 45,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SMOKE_BALL,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 114,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KOFFING,
            TM_LEARNSET_2_KOFFING,
            TM_LEARNSET_3_KOFFING,
            TM_LEARNSET_4_KOFFING
        },
    },

    [SPECIES_WEEZING] = {
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 120,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 70,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SMOKE_BALL,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 173,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WEEZING,
            TM_LEARNSET_2_WEEZING,
            TM_LEARNSET_3_WEEZING,
            TM_LEARNSET_4_WEEZING
        },
    },

    [SPECIES_RHYHORN] = {
        .baseHP        = 80,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 25,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_LIGHTNING_ROD,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 135,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RHYHORN,
            TM_LEARNSET_2_RHYHORN,
            TM_LEARNSET_3_RHYHORN,
            TM_LEARNSET_4_RHYHORN
        },
    },

    [SPECIES_RHYDON] = {
        .baseHP        = 105,
        .baseAttack    = 130,
        .baseDefense   = 120,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_LIGHTNING_ROD,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 204,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RHYDON,
            TM_LEARNSET_2_RHYDON,
            TM_LEARNSET_3_RHYDON,
            TM_LEARNSET_4_RHYDON
        },
    },

    [SPECIES_CHANSEY] = {
        .baseHP        = 250,
        .baseAttack    = 5,
        .baseDefense   = 5,
        .baseSpeed     = 50,
        .baseSpAttack  = 35,
        .baseSpDefense = 105,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_SERENE_GRACE,

        .itemUncommon = ITEM_OVAL_STONE,
        .itemRare     = ITEM_LUCKY_EGG,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 140,
        .expCurve = GROWTH_FAST,
        .expYield = 255,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHANSEY,
            TM_LEARNSET_2_CHANSEY,
            TM_LEARNSET_3_CHANSEY,
            TM_LEARNSET_4_CHANSEY
        },
    },

    [SPECIES_TANGELA] = {
        .baseHP        = 65,
        .baseAttack    = 55,
        .baseDefense   = 115,
        .baseSpeed     = 60,
        .baseSpAttack  = 100,
        .baseSpDefense = 40,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_LEAF_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 90,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 166,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TANGELA,
            TM_LEARNSET_2_TANGELA,
            TM_LEARNSET_3_TANGELA,
            TM_LEARNSET_4_TANGELA
        },
    },

    [SPECIES_KANGASKHAN] = {
        .baseHP        = 105,
        .baseAttack    = 95,
        .baseDefense   = 80,
        .baseSpeed     = 90,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_EARLY_BIRD,
        .ability2 = ABILITY_SCRAPPY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 150,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 175,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KANGASKHAN,
            TM_LEARNSET_2_KANGASKHAN,
            TM_LEARNSET_3_KANGASKHAN,
            TM_LEARNSET_4_KANGASKHAN
        },
    },

    [SPECIES_HORSEA] = {
        .baseHP        = 30,
        .baseAttack    = 40,
        .baseDefense   = 70,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 25,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_SNIPER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_SCALE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 83,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HORSEA,
            TM_LEARNSET_2_HORSEA,
            TM_LEARNSET_3_HORSEA,
            TM_LEARNSET_4_HORSEA
        },
    },

    [SPECIES_SEADRA] = {
        .baseHP        = 55,
        .baseAttack    = 65,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 45,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_SNIPER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_SCALE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 155,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SEADRA,
            TM_LEARNSET_2_SEADRA,
            TM_LEARNSET_3_SEADRA,
            TM_LEARNSET_4_SEADRA
        },
    },

    [SPECIES_GOLDEEN] = {
        .baseHP        = 45,
        .baseAttack    = 67,
        .baseDefense   = 60,
        .baseSpeed     = 63,
        .baseSpAttack  = 35,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_WATER_VEIL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 111,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GOLDEEN,
            TM_LEARNSET_2_GOLDEEN,
            TM_LEARNSET_3_GOLDEEN,
            TM_LEARNSET_4_GOLDEEN
        },
    },

    [SPECIES_SEAKING] = {
        .baseHP        = 80,
        .baseAttack    = 92,
        .baseDefense   = 65,
        .baseSpeed     = 68,
        .baseSpAttack  = 65,
        .baseSpDefense = 80,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_WATER_VEIL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 170,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SEAKING,
            TM_LEARNSET_2_SEAKING,
            TM_LEARNSET_3_SEAKING,
            TM_LEARNSET_4_SEAKING
        },
    },

    [SPECIES_STARYU] = {
        .baseHP        = 30,
        .baseAttack    = 45,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 70,
        .baseSpDefense = 55,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_ILLUMINATE,
        .ability2 = ABILITY_NATURAL_CURE,

        .itemUncommon = ITEM_STARDUST,
        .itemRare     = ITEM_STAR_PIECE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 106,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_STARYU,
            TM_LEARNSET_2_STARYU,
            TM_LEARNSET_3_STARYU,
            TM_LEARNSET_4_STARYU
        },
    },

    [SPECIES_STARMIE] = {
        .baseHP        = 60,
        .baseAttack    = 75,
        .baseDefense   = 85,
        .baseSpeed     = 115,
        .baseSpAttack  = 100,
        .baseSpDefense = 85,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_ILLUMINATE,
        .ability2 = ABILITY_NATURAL_CURE,

        .itemUncommon = ITEM_STARDUST,
        .itemRare     = ITEM_STAR_PIECE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 207,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_STARMIE,
            TM_LEARNSET_2_STARMIE,
            TM_LEARNSET_3_STARMIE,
            TM_LEARNSET_4_STARMIE
        },
    },

    [SPECIES_MR_MIME] = {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 65,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 120,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SOUNDPROOF,
        .ability2 = ABILITY_FILTER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_LEPPA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 136,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MR_MIME,
            TM_LEARNSET_2_MR_MIME,
            TM_LEARNSET_3_MR_MIME,
            TM_LEARNSET_4_MR_MIME
        },
    },

    [SPECIES_SCYTHER] = {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 80,
        .baseSpeed     = 105,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_TECHNICIAN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 187,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SCYTHER,
            TM_LEARNSET_2_SCYTHER,
            TM_LEARNSET_3_SCYTHER,
            TM_LEARNSET_4_SCYTHER
        },
    },

    [SPECIES_JYNX] = {
        .baseHP        = 65,
        .baseAttack    = 50,
        .baseDefense   = 35,
        .baseSpeed     = 95,
        .baseSpAttack  = 115,
        .baseSpDefense = 95,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_FOREWARN,

        .itemUncommon = ITEM_ASPEAR_BERRY,
        .itemRare     = ITEM_ASPEAR_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 137,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_JYNX,
            TM_LEARNSET_2_JYNX,
            TM_LEARNSET_3_JYNX,
            TM_LEARNSET_4_JYNX
        },
    },

    [SPECIES_ELECTABUZZ] = {
        .baseHP        = 65,
        .baseAttack    = 83,
        .baseDefense   = 57,
        .baseSpeed     = 105,
        .baseSpAttack  = 95,
        .baseSpDefense = 85,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_ELECTIRIZER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 156,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_ELECTABUZZ,
            TM_LEARNSET_2_ELECTABUZZ,
            TM_LEARNSET_3_ELECTABUZZ,
            TM_LEARNSET_4_ELECTABUZZ
        },
    },

    [SPECIES_MAGMAR] = {
        .baseHP        = 65,
        .baseAttack    = 95,
        .baseDefense   = 57,
        .baseSpeed     = 93,
        .baseSpAttack  = 100,
        .baseSpDefense = 85,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_FLAME_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_MAGMARIZER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 167,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGMAR,
            TM_LEARNSET_2_MAGMAR,
            TM_LEARNSET_3_MAGMAR,
            TM_LEARNSET_4_MAGMAR
        },
    },

    [SPECIES_PINSIR] = {
        .baseHP        = 65,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 70,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_MOLD_BREAKER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 200,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PINSIR,
            TM_LEARNSET_2_PINSIR,
            TM_LEARNSET_3_PINSIR,
            TM_LEARNSET_4_PINSIR
        },
    },

    [SPECIES_TAUROS] = {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 95,
        .baseSpeed     = 110,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_ANGER_POINT,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 211,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TAUROS,
            TM_LEARNSET_2_TAUROS,
            TM_LEARNSET_3_TAUROS,
            TM_LEARNSET_4_TAUROS
        },
    },

    [SPECIES_MAGIKARP] = {
        .baseHP        = 20,
        .baseAttack    = 10,
        .baseDefense   = 55,
        .baseSpeed     = 80,
        .baseSpAttack  = 15,
        .baseSpDefense = 20,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 90,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 20,
        .eggCycles = 5,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGIKARP,
            TM_LEARNSET_2_MAGIKARP,
            TM_LEARNSET_3_MAGIKARP,
            TM_LEARNSET_4_MAGIKARP
        },
    },

    [SPECIES_GYARADOS] = {
        .baseHP        = 95,
        .baseAttack    = 125,
        .baseDefense   = 79,
        .baseSpeed     = 81,
        .baseSpAttack  = 60,
        .baseSpDefense = 100,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 214,
        .eggCycles = 5,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GYARADOS,
            TM_LEARNSET_2_GYARADOS,
            TM_LEARNSET_3_GYARADOS,
            TM_LEARNSET_4_GYARADOS
        },
    },

    [SPECIES_LAPRAS] = {
        .baseHP        = 130,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 95,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_WATER_ABSORB,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 219,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LAPRAS,
            TM_LEARNSET_2_LAPRAS,
            TM_LEARNSET_3_LAPRAS,
            TM_LEARNSET_4_LAPRAS
        },
    },

    [SPECIES_DITTO] = {
        .baseHP        = 48,
        .baseAttack    = 48,
        .baseDefense   = 48,
        .baseSpeed     = 48,
        .baseSpAttack  = 48,
        .baseSpDefense = 48,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_LIMBER,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_QUICK_POWDER,
        .itemRare     = ITEM_METAL_POWDER,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 35,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 61,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_DITTO,
        .eggGroup2 = EGG_GROUP_DITTO,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DITTO,
            TM_LEARNSET_2_DITTO,
            TM_LEARNSET_3_DITTO,
            TM_LEARNSET_4_DITTO
        },
    },

    [SPECIES_EEVEE] = {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 50,
        .baseSpeed     = 55,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_ADAPTABILITY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 92,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_EEVEE,
            TM_LEARNSET_2_EEVEE,
            TM_LEARNSET_3_EEVEE,
            TM_LEARNSET_4_EEVEE
        },
    },

    [SPECIES_VAPOREON] = {
        .baseHP        = 130,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = 110,
        .baseSpDefense = 95,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_WATER_ABSORB,
        .ability2 = ABILITY_WATER_ABSORB,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 196,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VAPOREON,
            TM_LEARNSET_2_VAPOREON,
            TM_LEARNSET_3_VAPOREON,
            TM_LEARNSET_4_VAPOREON
        },
    },

    [SPECIES_JOLTEON] = {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 130,
        .baseSpAttack  = 110,
        .baseSpDefense = 95,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_VOLT_ABSORB,
        .ability2 = ABILITY_VOLT_ABSORB,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 197,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_JOLTEON,
            TM_LEARNSET_2_JOLTEON,
            TM_LEARNSET_3_JOLTEON,
            TM_LEARNSET_4_JOLTEON
        },
    },

    [SPECIES_FLAREON] = {
        .baseHP        = 65,
        .baseAttack    = 130,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = 110,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_FLASH_FIRE,
        .ability2 = ABILITY_FLASH_FIRE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 198,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FLAREON,
            TM_LEARNSET_2_FLAREON,
            TM_LEARNSET_3_FLAREON,
            TM_LEARNSET_4_FLAREON
        },
    },

    [SPECIES_PORYGON] = {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_TRACE,
        .ability2 = ABILITY_DOWNLOAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 130,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PORYGON,
            TM_LEARNSET_2_PORYGON,
            TM_LEARNSET_3_PORYGON,
            TM_LEARNSET_4_PORYGON
        },
    },

    [SPECIES_OMANYTE] = {
        .baseHP        = 35,
        .baseAttack    = 40,
        .baseDefense   = 100,
        .baseSpeed     = 35,
        .baseSpAttack  = 90,
        .baseSpDefense = 55,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 99,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_OMANYTE,
            TM_LEARNSET_2_OMANYTE,
            TM_LEARNSET_3_OMANYTE,
            TM_LEARNSET_4_OMANYTE
        },
    },

    [SPECIES_OMASTAR] = {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 125,
        .baseSpeed     = 55,
        .baseSpAttack  = 115,
        .baseSpDefense = 70,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 199,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_OMASTAR,
            TM_LEARNSET_2_OMASTAR,
            TM_LEARNSET_3_OMASTAR,
            TM_LEARNSET_4_OMASTAR
        },
    },

    [SPECIES_KABUTO] = {
        .baseHP        = 30,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 55,
        .baseSpAttack  = 55,
        .baseSpDefense = 45,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 99,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KABUTO,
            TM_LEARNSET_2_KABUTO,
            TM_LEARNSET_3_KABUTO,
            TM_LEARNSET_4_KABUTO
        },
    },

    [SPECIES_KABUTOPS] = {
        .baseHP        = 60,
        .baseAttack    = 115,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 199,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KABUTOPS,
            TM_LEARNSET_2_KABUTOPS,
            TM_LEARNSET_3_KABUTOPS,
            TM_LEARNSET_4_KABUTOPS
        },
    },

    [SPECIES_AERODACTYL] = {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 65,
        .baseSpeed     = 130,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_PRESSURE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 202,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AERODACTYL,
            TM_LEARNSET_2_AERODACTYL,
            TM_LEARNSET_3_AERODACTYL,
            TM_LEARNSET_4_AERODACTYL
        },
    },

    [SPECIES_SNORLAX] = {
        .baseHP        = 160,
        .baseAttack    = 110,
        .baseDefense   = 65,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = 110,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_IMMUNITY,
        .ability2 = ABILITY_THICK_FAT,

        .itemUncommon = ITEM_LEFTOVERS,
        .itemRare     = ITEM_LEFTOVERS,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 154,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SNORLAX,
            TM_LEARNSET_2_SNORLAX,
            TM_LEARNSET_3_SNORLAX,
            TM_LEARNSET_4_SNORLAX
        },
    },

    [SPECIES_ARTICUNO] = {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 100,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 125,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ARTICUNO,
            TM_LEARNSET_2_ARTICUNO,
            TM_LEARNSET_3_ARTICUNO,
            TM_LEARNSET_4_ARTICUNO
        },
    },

    [SPECIES_ZAPDOS] = {
        .baseHP        = 90,
        .baseAttack    = 90,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 125,
        .baseSpDefense = 90,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 216,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ZAPDOS,
            TM_LEARNSET_2_ZAPDOS,
            TM_LEARNSET_3_ZAPDOS,
            TM_LEARNSET_4_ZAPDOS
        },
    },

    [SPECIES_MOLTRES] = {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 125,
        .baseSpDefense = 85,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 217,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MOLTRES,
            TM_LEARNSET_2_MOLTRES,
            TM_LEARNSET_3_MOLTRES,
            TM_LEARNSET_4_MOLTRES
        },
    },

    [SPECIES_DRATINI] = {
        .baseHP        = 41,
        .baseAttack    = 64,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_SCALE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 67,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DRATINI,
            TM_LEARNSET_2_DRATINI,
            TM_LEARNSET_3_DRATINI,
            TM_LEARNSET_4_DRATINI
        },
    },

    [SPECIES_DRAGONAIR] = {
        .baseHP        = 61,
        .baseAttack    = 84,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_SCALE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 144,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DRAGONAIR,
            TM_LEARNSET_2_DRAGONAIR,
            TM_LEARNSET_3_DRAGONAIR,
            TM_LEARNSET_4_DRAGONAIR
        },
    },

    [SPECIES_DRAGONITE] = {
        .baseHP        = 91,
        .baseAttack    = 134,
        .baseDefense   = 95,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_SCALE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 218,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DRAGONITE,
            TM_LEARNSET_2_DRAGONITE,
            TM_LEARNSET_3_DRAGONITE,
            TM_LEARNSET_4_DRAGONITE
        },
    },

    [SPECIES_MEWTWO] = {
        .baseHP        = 106,
        .baseAttack    = 110,
        .baseDefense   = 90,
        .baseSpeed     = 130,
        .baseSpAttack  = 154,
        .baseSpDefense = 90,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MEWTWO,
            TM_LEARNSET_2_MEWTWO,
            TM_LEARNSET_3_MEWTWO,
            TM_LEARNSET_4_MEWTWO
        },
    },

    [SPECIES_MEW] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_LUM_BERRY,
        .itemRare     = ITEM_LUM_BERRY,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 100,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 64,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MEW,
            TM_LEARNSET_2_MEW,
            TM_LEARNSET_3_MEW,
            TM_LEARNSET_4_MEW
        },
    },

    [SPECIES_CHIKORITA] = {
        .baseHP        = 45,
        .baseAttack    = 49,
        .baseDefense   = 65,
        .baseSpeed     = 45,
        .baseSpAttack  = 49,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 64,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHIKORITA,
            TM_LEARNSET_2_CHIKORITA,
            TM_LEARNSET_3_CHIKORITA,
            TM_LEARNSET_4_CHIKORITA
        },
    },

    [SPECIES_BAYLEEF] = {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 80,
        .baseSpeed     = 60,
        .baseSpAttack  = 63,
        .baseSpDefense = 80,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 141,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BAYLEEF,
            TM_LEARNSET_2_BAYLEEF,
            TM_LEARNSET_3_BAYLEEF,
            TM_LEARNSET_4_BAYLEEF
        },
    },

    [SPECIES_MEGANIUM] = {
        .baseHP        = 80,
        .baseAttack    = 82,
        .baseDefense   = 100,
        .baseSpeed     = 80,
        .baseSpAttack  = 83,
        .baseSpDefense = 100,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 208,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MEGANIUM,
            TM_LEARNSET_2_MEGANIUM,
            TM_LEARNSET_3_MEGANIUM,
            TM_LEARNSET_4_MEGANIUM
        },
    },

    [SPECIES_CYNDAQUIL] = {
        .baseHP        = 39,
        .baseAttack    = 52,
        .baseDefense   = 43,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 65,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CYNDAQUIL,
            TM_LEARNSET_2_CYNDAQUIL,
            TM_LEARNSET_3_CYNDAQUIL,
            TM_LEARNSET_4_CYNDAQUIL
        },
    },

    [SPECIES_QUILAVA] = {
        .baseHP        = 58,
        .baseAttack    = 64,
        .baseDefense   = 58,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 65,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 142,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_QUILAVA,
            TM_LEARNSET_2_QUILAVA,
            TM_LEARNSET_3_QUILAVA,
            TM_LEARNSET_4_QUILAVA
        },
    },

    [SPECIES_TYPHLOSION] = {
        .baseHP        = 78,
        .baseAttack    = 84,
        .baseDefense   = 78,
        .baseSpeed     = 100,
        .baseSpAttack  = 109,
        .baseSpDefense = 85,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 209,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TYPHLOSION,
            TM_LEARNSET_2_TYPHLOSION,
            TM_LEARNSET_3_TYPHLOSION,
            TM_LEARNSET_4_TYPHLOSION
        },
    },

    [SPECIES_TOTODILE] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 64,
        .baseSpeed     = 43,
        .baseSpAttack  = 44,
        .baseSpDefense = 48,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 66,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TOTODILE,
            TM_LEARNSET_2_TOTODILE,
            TM_LEARNSET_3_TOTODILE,
            TM_LEARNSET_4_TOTODILE
        },
    },

    [SPECIES_CROCONAW] = {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 58,
        .baseSpAttack  = 59,
        .baseSpDefense = 63,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 143,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_CROCONAW,
            TM_LEARNSET_2_CROCONAW,
            TM_LEARNSET_3_CROCONAW,
            TM_LEARNSET_4_CROCONAW
        },
    },

    [SPECIES_FERALIGATR] = {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 100,
        .baseSpeed     = 78,
        .baseSpAttack  = 79,
        .baseSpDefense = 83,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 210,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FERALIGATR,
            TM_LEARNSET_2_FERALIGATR,
            TM_LEARNSET_3_FERALIGATR,
            TM_LEARNSET_4_FERALIGATR
        },
    },

    [SPECIES_SENTRET] = {
        .baseHP        = 35,
        .baseAttack    = 46,
        .baseDefense   = 34,
        .baseSpeed     = 20,
        .baseSpAttack  = 35,
        .baseSpDefense = 45,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_KEEN_EYE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_ORAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 57,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SENTRET,
            TM_LEARNSET_2_SENTRET,
            TM_LEARNSET_3_SENTRET,
            TM_LEARNSET_4_SENTRET
        },
    },

    [SPECIES_FURRET] = {
        .baseHP        = 85,
        .baseAttack    = 76,
        .baseDefense   = 64,
        .baseSpeed     = 90,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_KEEN_EYE,

        .itemUncommon = ITEM_ORAN_BERRY,
        .itemRare     = ITEM_SITRUS_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 116,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FURRET,
            TM_LEARNSET_2_FURRET,
            TM_LEARNSET_3_FURRET,
            TM_LEARNSET_4_FURRET
        },
    },

    [SPECIES_HOOTHOOT] = {
        .baseHP        = 60,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 50,
        .baseSpAttack  = 36,
        .baseSpDefense = 56,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_KEEN_EYE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 90,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 58,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HOOTHOOT,
            TM_LEARNSET_2_HOOTHOOT,
            TM_LEARNSET_3_HOOTHOOT,
            TM_LEARNSET_4_HOOTHOOT
        },
    },

    [SPECIES_NOCTOWL] = {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = 76,
        .baseSpDefense = 96,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_KEEN_EYE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 162,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NOCTOWL,
            TM_LEARNSET_2_NOCTOWL,
            TM_LEARNSET_3_NOCTOWL,
            TM_LEARNSET_4_NOCTOWL
        },
    },

    [SPECIES_LEDYBA] = {
        .baseHP        = 40,
        .baseAttack    = 20,
        .baseDefense   = 30,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 80,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 54,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LEDYBA,
            TM_LEARNSET_2_LEDYBA,
            TM_LEARNSET_3_LEDYBA,
            TM_LEARNSET_4_LEDYBA
        },
    },

    [SPECIES_LEDIAN] = {
        .baseHP        = 55,
        .baseAttack    = 35,
        .baseDefense   = 50,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 110,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 134,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LEDIAN,
            TM_LEARNSET_2_LEDIAN,
            TM_LEARNSET_3_LEDIAN,
            TM_LEARNSET_4_LEDIAN
        },
    },

    [SPECIES_SPINARAK] = {
        .baseHP        = 40,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_INSOMNIA,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 54,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SPINARAK,
            TM_LEARNSET_2_SPINARAK,
            TM_LEARNSET_3_SPINARAK,
            TM_LEARNSET_4_SPINARAK
        },
    },

    [SPECIES_ARIADOS] = {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_INSOMNIA,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 134,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ARIADOS,
            TM_LEARNSET_2_ARIADOS,
            TM_LEARNSET_3_ARIADOS,
            TM_LEARNSET_4_ARIADOS
        },
    },

    [SPECIES_CROBAT] = {
        .baseHP        = 85,
        .baseAttack    = 90,
        .baseDefense   = 80,
        .baseSpeed     = 130,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 3,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 204,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CROBAT,
            TM_LEARNSET_2_CROBAT,
            TM_LEARNSET_3_CROBAT,
            TM_LEARNSET_4_CROBAT
        },
    },

    [SPECIES_CHINCHOU] = {
        .baseHP        = 75,
        .baseAttack    = 38,
        .baseDefense   = 38,
        .baseSpeed     = 67,
        .baseSpAttack  = 56,
        .baseSpDefense = 56,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_VOLT_ABSORB,
        .ability2 = ABILITY_ILLUMINATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DEEP_SEA_SCALE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 90,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHINCHOU,
            TM_LEARNSET_2_CHINCHOU,
            TM_LEARNSET_3_CHINCHOU,
            TM_LEARNSET_4_CHINCHOU
        },
    },

    [SPECIES_LANTURN] = {
        .baseHP        = 125,
        .baseAttack    = 58,
        .baseDefense   = 58,
        .baseSpeed     = 67,
        .baseSpAttack  = 76,
        .baseSpDefense = 76,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_VOLT_ABSORB,
        .ability2 = ABILITY_ILLUMINATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DEEP_SEA_SCALE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 156,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LANTURN,
            TM_LEARNSET_2_LANTURN,
            TM_LEARNSET_3_LANTURN,
            TM_LEARNSET_4_LANTURN
        },
    },

    [SPECIES_PICHU] = {
        .baseHP        = 20,
        .baseAttack    = 40,
        .baseDefense   = 15,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_ORAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 42,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PICHU,
            TM_LEARNSET_2_PICHU,
            TM_LEARNSET_3_PICHU,
            TM_LEARNSET_4_PICHU
        },
    },

    [SPECIES_CLEFFA] = {
        .baseHP        = 50,
        .baseAttack    = 25,
        .baseDefense   = 28,
        .baseSpeed     = 15,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_MAGIC_GUARD,

        .itemUncommon = ITEM_LEPPA_BERRY,
        .itemRare     = ITEM_MOON_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 150,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 140,
        .expCurve = GROWTH_FAST,
        .expYield = 37,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CLEFFA,
            TM_LEARNSET_2_CLEFFA,
            TM_LEARNSET_3_CLEFFA,
            TM_LEARNSET_4_CLEFFA
        },
    },

    [SPECIES_IGGLYBUFF] = {
        .baseHP        = 90,
        .baseAttack    = 30,
        .baseDefense   = 15,
        .baseSpeed     = 15,
        .baseSpAttack  = 40,
        .baseSpDefense = 20,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 170,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 39,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_IGGLYBUFF,
            TM_LEARNSET_2_IGGLYBUFF,
            TM_LEARNSET_3_IGGLYBUFF,
            TM_LEARNSET_4_IGGLYBUFF
        },
    },

    [SPECIES_TOGEPI] = {
        .baseHP        = 35,
        .baseAttack    = 20,
        .baseDefense   = 65,
        .baseSpeed     = 20,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_HUSTLE,
        .ability2 = ABILITY_SERENE_GRACE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 74,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TOGEPI,
            TM_LEARNSET_2_TOGEPI,
            TM_LEARNSET_3_TOGEPI,
            TM_LEARNSET_4_TOGEPI
        },
    },

    [SPECIES_TOGETIC] = {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 85,
        .baseSpeed     = 40,
        .baseSpAttack  = 80,
        .baseSpDefense = 105,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_HUSTLE,
        .ability2 = ABILITY_SERENE_GRACE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 114,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TOGETIC,
            TM_LEARNSET_2_TOGETIC,
            TM_LEARNSET_3_TOGETIC,
            TM_LEARNSET_4_TOGETIC
        },
    },

    [SPECIES_NATU] = {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 45,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 73,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NATU,
            TM_LEARNSET_2_NATU,
            TM_LEARNSET_3_NATU,
            TM_LEARNSET_4_NATU
        },
    },

    [SPECIES_XATU] = {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 95,
        .baseSpDefense = 70,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 171,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_XATU,
            TM_LEARNSET_2_XATU,
            TM_LEARNSET_3_XATU,
            TM_LEARNSET_4_XATU
        },
    },

    [SPECIES_MAREEP] = {
        .baseHP        = 55,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 235,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 59,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAREEP,
            TM_LEARNSET_2_MAREEP,
            TM_LEARNSET_3_MAREEP,
            TM_LEARNSET_4_MAREEP
        },
    },

    [SPECIES_FLAAFFY] = {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 45,
        .baseSpAttack  = 80,
        .baseSpDefense = 60,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 117,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FLAAFFY,
            TM_LEARNSET_2_FLAAFFY,
            TM_LEARNSET_3_FLAAFFY,
            TM_LEARNSET_4_FLAAFFY
        },
    },

    [SPECIES_AMPHAROS] = {
        .baseHP        = 90,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 55,
        .baseSpAttack  = 115,
        .baseSpDefense = 90,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 194,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AMPHAROS,
            TM_LEARNSET_2_AMPHAROS,
            TM_LEARNSET_3_AMPHAROS,
            TM_LEARNSET_4_AMPHAROS
        },
    },

    [SPECIES_BELLOSSOM] = {
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 85,
        .baseSpeed     = 50,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 184,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BELLOSSOM,
            TM_LEARNSET_2_BELLOSSOM,
            TM_LEARNSET_3_BELLOSSOM,
            TM_LEARNSET_4_BELLOSSOM
        },
    },

    [SPECIES_MARILL] = {
        .baseHP        = 70,
        .baseAttack    = 20,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 20,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_HUGE_POWER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 58,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MARILL,
            TM_LEARNSET_2_MARILL,
            TM_LEARNSET_3_MARILL,
            TM_LEARNSET_4_MARILL
        },
    },

    [SPECIES_AZUMARILL] = {
        .baseHP        = 100,
        .baseAttack    = 50,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 80,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_HUGE_POWER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 153,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AZUMARILL,
            TM_LEARNSET_2_AZUMARILL,
            TM_LEARNSET_3_AZUMARILL,
            TM_LEARNSET_4_AZUMARILL
        },
    },

    [SPECIES_SUDOWOODO] = {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 115,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 65,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 65,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 135,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SUDOWOODO,
            TM_LEARNSET_2_SUDOWOODO,
            TM_LEARNSET_3_SUDOWOODO,
            TM_LEARNSET_4_SUDOWOODO
        },
    },

    [SPECIES_POLITOED] = {
        .baseHP        = 90,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 70,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_WATER_ABSORB,
        .ability2 = ABILITY_DAMP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KINGS_ROCK,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 185,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_POLITOED,
            TM_LEARNSET_2_POLITOED,
            TM_LEARNSET_3_POLITOED,
            TM_LEARNSET_4_POLITOED
        },
    },

    [SPECIES_HOPPIP] = {
        .baseHP        = 35,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 35,
        .baseSpDefense = 55,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_LEAF_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 74,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HOPPIP,
            TM_LEARNSET_2_HOPPIP,
            TM_LEARNSET_3_HOPPIP,
            TM_LEARNSET_4_HOPPIP
        },
    },

    [SPECIES_SKIPLOOM] = {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_LEAF_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 136,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SKIPLOOM,
            TM_LEARNSET_2_SKIPLOOM,
            TM_LEARNSET_3_SKIPLOOM,
            TM_LEARNSET_4_SKIPLOOM
        },
    },

    [SPECIES_JUMPLUFF] = {
        .baseHP        = 75,
        .baseAttack    = 55,
        .baseDefense   = 70,
        .baseSpeed     = 110,
        .baseSpAttack  = 55,
        .baseSpDefense = 85,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_LEAF_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 3,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 176,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_JUMPLUFF,
            TM_LEARNSET_2_JUMPLUFF,
            TM_LEARNSET_3_JUMPLUFF,
            TM_LEARNSET_4_JUMPLUFF
        },
    },

    [SPECIES_AIPOM] = {
        .baseHP        = 55,
        .baseAttack    = 70,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 40,
        .baseSpDefense = 55,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_PICKUP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 94,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AIPOM,
            TM_LEARNSET_2_AIPOM,
            TM_LEARNSET_3_AIPOM,
            TM_LEARNSET_4_AIPOM
        },
    },

    [SPECIES_SUNKERN] = {
        .baseHP        = 30,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_SOLAR_POWER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_COBA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 235,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 52,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SUNKERN,
            TM_LEARNSET_2_SUNKERN,
            TM_LEARNSET_3_SUNKERN,
            TM_LEARNSET_4_SUNKERN
        },
    },

    [SPECIES_SUNFLORA] = {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 55,
        .baseSpeed     = 30,
        .baseSpAttack  = 105,
        .baseSpDefense = 85,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_SOLAR_POWER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 146,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SUNFLORA,
            TM_LEARNSET_2_SUNFLORA,
            TM_LEARNSET_3_SUNFLORA,
            TM_LEARNSET_4_SUNFLORA
        },
    },

    [SPECIES_YANMA] = {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 45,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SPEED_BOOST,
        .ability2 = ABILITY_COMPOUND_EYES,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_WIDE_LENS,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 147,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_YANMA,
            TM_LEARNSET_2_YANMA,
            TM_LEARNSET_3_YANMA,
            TM_LEARNSET_4_YANMA
        },
    },

    [SPECIES_WOOPER] = {
        .baseHP        = 55,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_DAMP,
        .ability2 = ABILITY_WATER_ABSORB,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 52,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WOOPER,
            TM_LEARNSET_2_WOOPER,
            TM_LEARNSET_3_WOOPER,
            TM_LEARNSET_4_WOOPER
        },
    },

    [SPECIES_QUAGSIRE] = {
        .baseHP        = 95,
        .baseAttack    = 85,
        .baseDefense   = 85,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_DAMP,
        .ability2 = ABILITY_WATER_ABSORB,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 137,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_QUAGSIRE,
            TM_LEARNSET_2_QUAGSIRE,
            TM_LEARNSET_3_QUAGSIRE,
            TM_LEARNSET_4_QUAGSIRE
        },
    },

    [SPECIES_ESPEON] = {
        .baseHP        = 65,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = 95,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_SYNCHRONIZE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 197,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ESPEON,
            TM_LEARNSET_2_ESPEON,
            TM_LEARNSET_3_ESPEON,
            TM_LEARNSET_4_ESPEON
        },
    },

    [SPECIES_UMBREON] = {
        .baseHP        = 95,
        .baseAttack    = 65,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = 60,
        .baseSpDefense = 130,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_SYNCHRONIZE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 197,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_UMBREON,
            TM_LEARNSET_2_UMBREON,
            TM_LEARNSET_3_UMBREON,
            TM_LEARNSET_4_UMBREON
        },
    },

    [SPECIES_MURKROW] = {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 42,
        .baseSpeed     = 91,
        .baseSpAttack  = 85,
        .baseSpDefense = 42,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_SUPER_LUCK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 107,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MURKROW,
            TM_LEARNSET_2_MURKROW,
            TM_LEARNSET_3_MURKROW,
            TM_LEARNSET_4_MURKROW
        },
    },

    [SPECIES_SLOWKING] = {
        .baseHP        = 95,
        .baseAttack    = 75,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 100,
        .baseSpDefense = 110,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_OWN_TEMPO,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KINGS_ROCK,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 70,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 164,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SLOWKING,
            TM_LEARNSET_2_SLOWKING,
            TM_LEARNSET_3_SLOWKING,
            TM_LEARNSET_4_SLOWKING
        },
    },

    [SPECIES_MISDREAVUS] = {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 85,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_FAST,
        .expYield = 147,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MISDREAVUS,
            TM_LEARNSET_2_MISDREAVUS,
            TM_LEARNSET_3_MISDREAVUS,
            TM_LEARNSET_4_MISDREAVUS
        },
    },

    [SPECIES_UNOWN] = {
        .baseHP        = 48,
        .baseAttack    = 72,
        .baseDefense   = 48,
        .baseSpeed     = 48,
        .baseSpAttack  = 72,
        .baseSpDefense = 48,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 61,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_UNOWN,
            TM_LEARNSET_2_UNOWN,
            TM_LEARNSET_3_UNOWN,
            TM_LEARNSET_4_UNOWN
        },
    },

    [SPECIES_WOBBUFFET] = {
        .baseHP        = 190,
        .baseAttack    = 33,
        .baseDefense   = 58,
        .baseSpeed     = 33,
        .baseSpAttack  = 33,
        .baseSpDefense = 58,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SHADOW_TAG,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 177,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WOBBUFFET,
            TM_LEARNSET_2_WOBBUFFET,
            TM_LEARNSET_3_WOBBUFFET,
            TM_LEARNSET_4_WOBBUFFET
        },
    },

    [SPECIES_GIRAFARIG] = {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 90,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PERSIM_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 149,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GIRAFARIG,
            TM_LEARNSET_2_GIRAFARIG,
            TM_LEARNSET_3_GIRAFARIG,
            TM_LEARNSET_4_GIRAFARIG
        },
    },

    [SPECIES_PINECO] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 90,
        .baseSpeed     = 15,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 60,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PINECO,
            TM_LEARNSET_2_PINECO,
            TM_LEARNSET_3_PINECO,
            TM_LEARNSET_4_PINECO
        },
    },

    [SPECIES_FORRETRESS] = {
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 140,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 118,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FORRETRESS,
            TM_LEARNSET_2_FORRETRESS,
            TM_LEARNSET_3_FORRETRESS,
            TM_LEARNSET_4_FORRETRESS
        },
    },

    [SPECIES_DUNSPARCE] = {
        .baseHP        = 100,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_SERENE_GRACE,
        .ability2 = ABILITY_RUN_AWAY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 125,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DUNSPARCE,
            TM_LEARNSET_2_DUNSPARCE,
            TM_LEARNSET_3_DUNSPARCE,
            TM_LEARNSET_4_DUNSPARCE
        },
    },

    [SPECIES_GLIGAR] = {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 105,
        .baseSpeed     = 85,
        .baseSpAttack  = 35,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_SAND_VEIL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 108,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GLIGAR,
            TM_LEARNSET_2_GLIGAR,
            TM_LEARNSET_3_GLIGAR,
            TM_LEARNSET_4_GLIGAR
        },
    },

    [SPECIES_STEELIX] = {
        .baseHP        = 75,
        .baseAttack    = 85,
        .baseDefense   = 200,
        .baseSpeed     = 30,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 196,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_STEELIX,
            TM_LEARNSET_2_STEELIX,
            TM_LEARNSET_3_STEELIX,
            TM_LEARNSET_4_STEELIX
        },
    },

    [SPECIES_SNUBBULL] = {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_RUN_AWAY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 63,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SNUBBULL,
            TM_LEARNSET_2_SNUBBULL,
            TM_LEARNSET_3_SNUBBULL,
            TM_LEARNSET_4_SNUBBULL
        },
    },

    [SPECIES_GRANBULL] = {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 75,
        .baseSpeed     = 45,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_QUICK_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 178,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GRANBULL,
            TM_LEARNSET_2_GRANBULL,
            TM_LEARNSET_3_GRANBULL,
            TM_LEARNSET_4_GRANBULL
        },
    },

    [SPECIES_QWILFISH] = {
        .baseHP        = 65,
        .baseAttack    = 95,
        .baseDefense   = 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_POISON_POINT,
        .ability2 = ABILITY_SWIFT_SWIM,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 100,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_QWILFISH,
            TM_LEARNSET_2_QWILFISH,
            TM_LEARNSET_3_QWILFISH,
            TM_LEARNSET_4_QWILFISH
        },
    },

    [SPECIES_SCIZOR] = {
        .baseHP        = 70,
        .baseAttack    = 130,
        .baseDefense   = 100,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_TECHNICIAN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 200,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SCIZOR,
            TM_LEARNSET_2_SCIZOR,
            TM_LEARNSET_3_SCIZOR,
            TM_LEARNSET_4_SCIZOR
        },
    },

    [SPECIES_SHUCKLE] = {
        .baseHP        = 20,
        .baseAttack    = 10,
        .baseDefense   = 230,
        .baseSpeed     = 5,
        .baseSpAttack  = 10,
        .baseSpDefense = 230,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_GLUTTONY,

        .itemUncommon = ITEM_ORAN_BERRY,
        .itemRare     = ITEM_ORAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 80,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHUCKLE,
            TM_LEARNSET_2_SHUCKLE,
            TM_LEARNSET_3_SHUCKLE,
            TM_LEARNSET_4_SHUCKLE
        },
    },

    [SPECIES_HERACROSS] = {
        .baseHP        = 80,
        .baseAttack    = 125,
        .baseDefense   = 75,
        .baseSpeed     = 85,
        .baseSpAttack  = 40,
        .baseSpDefense = 95,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_GUTS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 200,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HERACROSS,
            TM_LEARNSET_2_HERACROSS,
            TM_LEARNSET_3_HERACROSS,
            TM_LEARNSET_4_HERACROSS
        },
    },

    [SPECIES_SNEASEL] = {
        .baseHP        = 55,
        .baseAttack    = 95,
        .baseDefense   = 55,
        .baseSpeed     = 115,
        .baseSpAttack  = 35,
        .baseSpDefense = 75,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_KEEN_EYE,

        .itemUncommon = ITEM_GRIP_CLAW,
        .itemRare     = ITEM_QUICK_CLAW,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_SNEASEL,
            TM_LEARNSET_2_SNEASEL,
            TM_LEARNSET_3_SNEASEL,
            TM_LEARNSET_4_SNEASEL
        },
    },

    [SPECIES_TEDDIURSA] = {
        .baseHP        = 60,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_PICKUP,
        .ability2 = ABILITY_QUICK_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 124,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_TEDDIURSA,
            TM_LEARNSET_2_TEDDIURSA,
            TM_LEARNSET_3_TEDDIURSA,
            TM_LEARNSET_4_TEDDIURSA
        },
    },

    [SPECIES_URSARING] = {
        .baseHP        = 90,
        .baseAttack    = 130,
        .baseDefense   = 75,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 75,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_QUICK_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 189,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_URSARING,
            TM_LEARNSET_2_URSARING,
            TM_LEARNSET_3_URSARING,
            TM_LEARNSET_4_URSARING
        },
    },

    [SPECIES_SLUGMA] = {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 70,
        .baseSpDefense = 40,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_MAGMA_ARMOR,
        .ability2 = ABILITY_FLAME_BODY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 78,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SLUGMA,
            TM_LEARNSET_2_SLUGMA,
            TM_LEARNSET_3_SLUGMA,
            TM_LEARNSET_4_SLUGMA
        },
    },

    [SPECIES_MAGCARGO] = {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 120,
        .baseSpeed     = 30,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_MAGMA_ARMOR,
        .ability2 = ABILITY_FLAME_BODY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 154,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGCARGO,
            TM_LEARNSET_2_MAGCARGO,
            TM_LEARNSET_3_MAGCARGO,
            TM_LEARNSET_4_MAGCARGO
        },
    },

    [SPECIES_SWINUB] = {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_SNOW_CLOAK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 78,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SWINUB,
            TM_LEARNSET_2_SWINUB,
            TM_LEARNSET_3_SWINUB,
            TM_LEARNSET_4_SWINUB
        },
    },

    [SPECIES_PILOSWINE] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_SNOW_CLOAK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 160,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PILOSWINE,
            TM_LEARNSET_2_PILOSWINE,
            TM_LEARNSET_3_PILOSWINE,
            TM_LEARNSET_4_PILOSWINE
        },
    },

    [SPECIES_CORSOLA] = {
        .baseHP        = 55,
        .baseAttack    = 55,
        .baseDefense   = 85,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 85,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_HUSTLE,
        .ability2 = ABILITY_NATURAL_CURE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HARD_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 113,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CORSOLA,
            TM_LEARNSET_2_CORSOLA,
            TM_LEARNSET_3_CORSOLA,
            TM_LEARNSET_4_CORSOLA
        },
    },

    [SPECIES_REMORAID] = {
        .baseHP        = 35,
        .baseAttack    = 65,
        .baseDefense   = 35,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 35,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_HUSTLE,
        .ability2 = ABILITY_SNIPER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 78,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_REMORAID,
            TM_LEARNSET_2_REMORAID,
            TM_LEARNSET_3_REMORAID,
            TM_LEARNSET_4_REMORAID
        },
    },

    [SPECIES_OCTILLERY] = {
        .baseHP        = 75,
        .baseAttack    = 105,
        .baseDefense   = 75,
        .baseSpeed     = 45,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SUCTION_CUPS,
        .ability2 = ABILITY_SNIPER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 164,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_OCTILLERY,
            TM_LEARNSET_2_OCTILLERY,
            TM_LEARNSET_3_OCTILLERY,
            TM_LEARNSET_4_OCTILLERY
        },
    },

    [SPECIES_DELIBIRD] = {
        .baseHP        = 45,
        .baseAttack    = 55,
        .baseDefense   = 45,
        .baseSpeed     = 75,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_HUSTLE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 183,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DELIBIRD,
            TM_LEARNSET_2_DELIBIRD,
            TM_LEARNSET_3_DELIBIRD,
            TM_LEARNSET_4_DELIBIRD
        },
    },

    [SPECIES_MANTINE] = {
        .baseHP        = 65,
        .baseAttack    = 40,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 80,
        .baseSpDefense = 140,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_WATER_ABSORB,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 168,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MANTINE,
            TM_LEARNSET_2_MANTINE,
            TM_LEARNSET_3_MANTINE,
            TM_LEARNSET_4_MANTINE
        },
    },

    [SPECIES_SKARMORY] = {
        .baseHP        = 65,
        .baseAttack    = 80,
        .baseDefense   = 140,
        .baseSpeed     = 70,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 168,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SKARMORY,
            TM_LEARNSET_2_SKARMORY,
            TM_LEARNSET_3_SKARMORY,
            TM_LEARNSET_4_SKARMORY
        },
    },

    [SPECIES_HOUNDOUR] = {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 65,
        .baseSpAttack  = 80,
        .baseSpDefense = 50,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_EARLY_BIRD,
        .ability2 = ABILITY_FLASH_FIRE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 114,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HOUNDOUR,
            TM_LEARNSET_2_HOUNDOUR,
            TM_LEARNSET_3_HOUNDOUR,
            TM_LEARNSET_4_HOUNDOUR
        },
    },

    [SPECIES_HOUNDOOM] = {
        .baseHP        = 75,
        .baseAttack    = 90,
        .baseDefense   = 50,
        .baseSpeed     = 95,
        .baseSpAttack  = 110,
        .baseSpDefense = 80,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_EARLY_BIRD,
        .ability2 = ABILITY_FLASH_FIRE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 204,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HOUNDOOM,
            TM_LEARNSET_2_HOUNDOOM,
            TM_LEARNSET_3_HOUNDOOM,
            TM_LEARNSET_4_HOUNDOOM
        },
    },

    [SPECIES_KINGDRA] = {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 95,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_SNIPER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_SCALE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 207,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KINGDRA,
            TM_LEARNSET_2_KINGDRA,
            TM_LEARNSET_3_KINGDRA,
            TM_LEARNSET_4_KINGDRA
        },
    },

    [SPECIES_PHANPY] = {
        .baseHP        = 90,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_PICKUP,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PASSHO_BERRY,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 124,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PHANPY,
            TM_LEARNSET_2_PHANPY,
            TM_LEARNSET_3_PHANPY,
            TM_LEARNSET_4_PHANPY
        },
    },

    [SPECIES_DONPHAN] = {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PASSHO_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 189,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DONPHAN,
            TM_LEARNSET_2_DONPHAN,
            TM_LEARNSET_3_DONPHAN,
            TM_LEARNSET_4_DONPHAN
        },
    },

    [SPECIES_PORYGON2] = {
        .baseHP        = 85,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 105,
        .baseSpDefense = 95,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_TRACE,
        .ability2 = ABILITY_DOWNLOAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 180,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PORYGON2,
            TM_LEARNSET_2_PORYGON2,
            TM_LEARNSET_3_PORYGON2,
            TM_LEARNSET_4_PORYGON2
        },
    },

    [SPECIES_STANTLER] = {
        .baseHP        = 73,
        .baseAttack    = 95,
        .baseDefense   = 62,
        .baseSpeed     = 85,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_FRISK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 165,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_STANTLER,
            TM_LEARNSET_2_STANTLER,
            TM_LEARNSET_3_STANTLER,
            TM_LEARNSET_4_STANTLER
        },
    },

    [SPECIES_SMEARGLE] = {
        .baseHP        = 55,
        .baseAttack    = 20,
        .baseDefense   = 35,
        .baseSpeed     = 75,
        .baseSpAttack  = 20,
        .baseSpDefense = 45,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_OWN_TEMPO,
        .ability2 = ABILITY_TECHNICIAN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 106,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SMEARGLE,
            TM_LEARNSET_2_SMEARGLE,
            TM_LEARNSET_3_SMEARGLE,
            TM_LEARNSET_4_SMEARGLE
        },
    },

    [SPECIES_TYROGUE] = {
        .baseHP        = 35,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 35,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_STEADFAST,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 91,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TYROGUE,
            TM_LEARNSET_2_TYROGUE,
            TM_LEARNSET_3_TYROGUE,
            TM_LEARNSET_4_TYROGUE
        },
    },

    [SPECIES_HITMONTOP] = {
        .baseHP        = 50,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 70,
        .baseSpAttack  = 35,
        .baseSpDefense = 110,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_TECHNICIAN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 138,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HITMONTOP,
            TM_LEARNSET_2_HITMONTOP,
            TM_LEARNSET_3_HITMONTOP,
            TM_LEARNSET_4_HITMONTOP
        },
    },

    [SPECIES_SMOOCHUM] = {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 15,
        .baseSpeed     = 65,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_FOREWARN,

        .itemUncommon = ITEM_ASPEAR_BERRY,
        .itemRare     = ITEM_ASPEAR_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 87,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SMOOCHUM,
            TM_LEARNSET_2_SMOOCHUM,
            TM_LEARNSET_3_SMOOCHUM,
            TM_LEARNSET_4_SMOOCHUM
        },
    },

    [SPECIES_ELEKID] = {
        .baseHP        = 45,
        .baseAttack    = 63,
        .baseDefense   = 37,
        .baseSpeed     = 95,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_ELECTIRIZER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 106,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_ELEKID,
            TM_LEARNSET_2_ELEKID,
            TM_LEARNSET_3_ELEKID,
            TM_LEARNSET_4_ELEKID
        },
    },

    [SPECIES_MAGBY] = {
        .baseHP        = 45,
        .baseAttack    = 75,
        .baseDefense   = 37,
        .baseSpeed     = 83,
        .baseSpAttack  = 70,
        .baseSpDefense = 55,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_FLAME_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_MAGMARIZER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 117,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGBY,
            TM_LEARNSET_2_MAGBY,
            TM_LEARNSET_3_MAGBY,
            TM_LEARNSET_4_MAGBY
        },
    },

    [SPECIES_MILTANK] = {
        .baseHP        = 95,
        .baseAttack    = 80,
        .baseDefense   = 105,
        .baseSpeed     = 100,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_SCRAPPY,

        .itemUncommon = ITEM_MOOMOO_MILK,
        .itemRare     = ITEM_MOOMOO_MILK,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 200,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MILTANK,
            TM_LEARNSET_2_MILTANK,
            TM_LEARNSET_3_MILTANK,
            TM_LEARNSET_4_MILTANK
        },
    },

    [SPECIES_BLISSEY] = {
        .baseHP        = 255,
        .baseAttack    = 10,
        .baseDefense   = 10,
        .baseSpeed     = 55,
        .baseSpAttack  = 75,
        .baseSpDefense = 135,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_SERENE_GRACE,

        .itemUncommon = ITEM_OVAL_STONE,
        .itemRare     = ITEM_LUCKY_EGG,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 140,
        .expCurve = GROWTH_FAST,
        .expYield = 255,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BLISSEY,
            TM_LEARNSET_2_BLISSEY,
            TM_LEARNSET_3_BLISSEY,
            TM_LEARNSET_4_BLISSEY
        },
    },

    [SPECIES_RAIKOU] = {
        .baseHP        = 90,
        .baseAttack    = 85,
        .baseDefense   = 75,
        .baseSpeed     = 115,
        .baseSpAttack  = 115,
        .baseSpDefense = 100,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 216,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RAIKOU,
            TM_LEARNSET_2_RAIKOU,
            TM_LEARNSET_3_RAIKOU,
            TM_LEARNSET_4_RAIKOU
        },
    },

    [SPECIES_ENTEI] = {
        .baseHP        = 115,
        .baseAttack    = 115,
        .baseDefense   = 85,
        .baseSpeed     = 100,
        .baseSpAttack  = 90,
        .baseSpDefense = 75,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 217,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ENTEI,
            TM_LEARNSET_2_ENTEI,
            TM_LEARNSET_3_ENTEI,
            TM_LEARNSET_4_ENTEI
        },
    },

    [SPECIES_SUICUNE] = {
        .baseHP        = 100,
        .baseAttack    = 75,
        .baseDefense   = 115,
        .baseSpeed     = 85,
        .baseSpAttack  = 90,
        .baseSpDefense = 115,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SUICUNE,
            TM_LEARNSET_2_SUICUNE,
            TM_LEARNSET_3_SUICUNE,
            TM_LEARNSET_4_SUICUNE
        },
    },

    [SPECIES_LARVITAR] = {
        .baseHP        = 50,
        .baseAttack    = 64,
        .baseDefense   = 50,
        .baseSpeed     = 41,
        .baseSpAttack  = 45,
        .baseSpDefense = 50,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 67,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LARVITAR,
            TM_LEARNSET_2_LARVITAR,
            TM_LEARNSET_3_LARVITAR,
            TM_LEARNSET_4_LARVITAR
        },
    },

    [SPECIES_PUPITAR] = {
        .baseHP        = 70,
        .baseAttack    = 84,
        .baseDefense   = 70,
        .baseSpeed     = 51,
        .baseSpAttack  = 65,
        .baseSpDefense = 70,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 144,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PUPITAR,
            TM_LEARNSET_2_PUPITAR,
            TM_LEARNSET_3_PUPITAR,
            TM_LEARNSET_4_PUPITAR
        },
    },

    [SPECIES_TYRANITAR] = {
        .baseHP        = 100,
        .baseAttack    = 134,
        .baseDefense   = 110,
        .baseSpeed     = 61,
        .baseSpAttack  = 95,
        .baseSpDefense = 100,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_SAND_STREAM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 218,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TYRANITAR,
            TM_LEARNSET_2_TYRANITAR,
            TM_LEARNSET_3_TYRANITAR,
            TM_LEARNSET_4_TYRANITAR
        },
    },

    [SPECIES_LUGIA] = {
        .baseHP        = 106,
        .baseAttack    = 90,
        .baseDefense   = 130,
        .baseSpeed     = 110,
        .baseSpAttack  = 90,
        .baseSpDefense = 154,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUGIA,
            TM_LEARNSET_2_LUGIA,
            TM_LEARNSET_3_LUGIA,
            TM_LEARNSET_4_LUGIA
        },
    },

    [SPECIES_HO_OH] = {
        .baseHP        = 106,
        .baseAttack    = 130,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 110,
        .baseSpDefense = 154,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_SACRED_ASH,
        .itemRare     = ITEM_SACRED_ASH,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HO_OH,
            TM_LEARNSET_2_HO_OH,
            TM_LEARNSET_3_HO_OH,
            TM_LEARNSET_4_HO_OH
        },
    },

    [SPECIES_CELEBI] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_LUM_BERRY,
        .itemRare     = ITEM_LUM_BERRY,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 100,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 64,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CELEBI,
            TM_LEARNSET_2_CELEBI,
            TM_LEARNSET_3_CELEBI,
            TM_LEARNSET_4_CELEBI
        },
    },

    [SPECIES_TREECKO] = {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 70,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 65,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TREECKO,
            TM_LEARNSET_2_TREECKO,
            TM_LEARNSET_3_TREECKO,
            TM_LEARNSET_4_TREECKO
        },
    },

    [SPECIES_GROVYLE] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 95,
        .baseSpAttack  = 85,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 141,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GROVYLE,
            TM_LEARNSET_2_GROVYLE,
            TM_LEARNSET_3_GROVYLE,
            TM_LEARNSET_4_GROVYLE
        },
    },

    [SPECIES_SCEPTILE] = {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 65,
        .baseSpeed     = 120,
        .baseSpAttack  = 105,
        .baseSpDefense = 85,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 3,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 208,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SCEPTILE,
            TM_LEARNSET_2_SCEPTILE,
            TM_LEARNSET_3_SCEPTILE,
            TM_LEARNSET_4_SCEPTILE
        },
    },

    [SPECIES_TORCHIC] = {
        .baseHP        = 45,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 45,
        .baseSpAttack  = 70,
        .baseSpDefense = 50,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 65,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TORCHIC,
            TM_LEARNSET_2_TORCHIC,
            TM_LEARNSET_3_TORCHIC,
            TM_LEARNSET_4_TORCHIC
        },
    },

    [SPECIES_COMBUSKEN] = {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 85,
        .baseSpDefense = 60,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 142,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_COMBUSKEN,
            TM_LEARNSET_2_COMBUSKEN,
            TM_LEARNSET_3_COMBUSKEN,
            TM_LEARNSET_4_COMBUSKEN
        },
    },

    [SPECIES_BLAZIKEN] = {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 70,
        .baseSpeed     = 80,
        .baseSpAttack  = 110,
        .baseSpDefense = 70,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 209,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BLAZIKEN,
            TM_LEARNSET_2_BLAZIKEN,
            TM_LEARNSET_3_BLAZIKEN,
            TM_LEARNSET_4_BLAZIKEN
        },
    },

    [SPECIES_MUDKIP] = {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 65,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MUDKIP,
            TM_LEARNSET_2_MUDKIP,
            TM_LEARNSET_3_MUDKIP,
            TM_LEARNSET_4_MUDKIP
        },
    },

    [SPECIES_MARSHTOMP] = {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 143,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MARSHTOMP,
            TM_LEARNSET_2_MARSHTOMP,
            TM_LEARNSET_3_MARSHTOMP,
            TM_LEARNSET_4_MARSHTOMP
        },
    },

    [SPECIES_SWAMPERT] = {
        .baseHP        = 100,
        .baseAttack    = 110,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 85,
        .baseSpDefense = 90,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 210,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SWAMPERT,
            TM_LEARNSET_2_SWAMPERT,
            TM_LEARNSET_3_SWAMPERT,
            TM_LEARNSET_4_SWAMPERT
        },
    },

    [SPECIES_POOCHYENA] = {
        .baseHP        = 35,
        .baseAttack    = 55,
        .baseDefense   = 35,
        .baseSpeed     = 35,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_QUICK_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PECHA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 55,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_POOCHYENA,
            TM_LEARNSET_2_POOCHYENA,
            TM_LEARNSET_3_POOCHYENA,
            TM_LEARNSET_4_POOCHYENA
        },
    },

    [SPECIES_MIGHTYENA] = {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_QUICK_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PECHA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 127,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 128,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MIGHTYENA,
            TM_LEARNSET_2_MIGHTYENA,
            TM_LEARNSET_3_MIGHTYENA,
            TM_LEARNSET_4_MIGHTYENA
        },
    },

    [SPECIES_ZIGZAGOON] = {
        .baseHP        = 38,
        .baseAttack    = 30,
        .baseDefense   = 41,
        .baseSpeed     = 60,
        .baseSpAttack  = 30,
        .baseSpDefense = 41,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_PICKUP,
        .ability2 = ABILITY_GLUTTONY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_ORAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 60,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ZIGZAGOON,
            TM_LEARNSET_2_ZIGZAGOON,
            TM_LEARNSET_3_ZIGZAGOON,
            TM_LEARNSET_4_ZIGZAGOON
        },
    },

    [SPECIES_LINOONE] = {
        .baseHP        = 78,
        .baseAttack    = 70,
        .baseDefense   = 61,
        .baseSpeed     = 100,
        .baseSpAttack  = 50,
        .baseSpDefense = 61,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_PICKUP,
        .ability2 = ABILITY_GLUTTONY,

        .itemUncommon = ITEM_ORAN_BERRY,
        .itemRare     = ITEM_SITRUS_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 128,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LINOONE,
            TM_LEARNSET_2_LINOONE,
            TM_LEARNSET_3_LINOONE,
            TM_LEARNSET_4_LINOONE
        },
    },

    [SPECIES_WURMPLE] = {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 35,
        .baseSpeed     = 20,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SHIELD_DUST,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 54,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WURMPLE,
            TM_LEARNSET_2_WURMPLE,
            TM_LEARNSET_3_WURMPLE,
            TM_LEARNSET_4_WURMPLE
        },
    },

    [SPECIES_SILCOON] = {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 55,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 72,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SILCOON,
            TM_LEARNSET_2_SILCOON,
            TM_LEARNSET_3_SILCOON,
            TM_LEARNSET_4_SILCOON
        },
    },

    [SPECIES_BEAUTIFLY] = {
        .baseHP        = 60,
        .baseAttack    = 70,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 90,
        .baseSpDefense = 50,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHED_SHELL,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 161,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BEAUTIFLY,
            TM_LEARNSET_2_BEAUTIFLY,
            TM_LEARNSET_3_BEAUTIFLY,
            TM_LEARNSET_4_BEAUTIFLY
        },
    },

    [SPECIES_CASCOON] = {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 55,
        .baseSpeed     = 15,
        .baseSpAttack  = 25,
        .baseSpDefense = 25,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 72,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CASCOON,
            TM_LEARNSET_2_CASCOON,
            TM_LEARNSET_3_CASCOON,
            TM_LEARNSET_4_CASCOON
        },
    },

    [SPECIES_DUSTOX] = {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 90,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SHIELD_DUST,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SHED_SHELL,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 161,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DUSTOX,
            TM_LEARNSET_2_DUSTOX,
            TM_LEARNSET_3_DUSTOX,
            TM_LEARNSET_4_DUSTOX
        },
    },

    [SPECIES_LOTAD] = {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_RAIN_DISH,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 74,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LOTAD,
            TM_LEARNSET_2_LOTAD,
            TM_LEARNSET_3_LOTAD,
            TM_LEARNSET_4_LOTAD
        },
    },

    [SPECIES_LOMBRE] = {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_RAIN_DISH,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 141,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LOMBRE,
            TM_LEARNSET_2_LOMBRE,
            TM_LEARNSET_3_LOMBRE,
            TM_LEARNSET_4_LOMBRE
        },
    },

    [SPECIES_LUDICOLO] = {
        .baseHP        = 80,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 90,
        .baseSpDefense = 100,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_RAIN_DISH,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 181,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUDICOLO,
            TM_LEARNSET_2_LUDICOLO,
            TM_LEARNSET_3_LUDICOLO,
            TM_LEARNSET_4_LUDICOLO
        },
    },

    [SPECIES_SEEDOT] = {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 74,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SEEDOT,
            TM_LEARNSET_2_SEEDOT,
            TM_LEARNSET_3_SEEDOT,
            TM_LEARNSET_4_SEEDOT
        },
    },

    [SPECIES_NUZLEAF] = {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 40,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 141,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NUZLEAF,
            TM_LEARNSET_2_NUZLEAF,
            TM_LEARNSET_3_NUZLEAF,
            TM_LEARNSET_4_NUZLEAF
        },
    },

    [SPECIES_SHIFTRY] = {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 80,
        .baseSpAttack  = 90,
        .baseSpDefense = 60,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_EARLY_BIRD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 181,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHIFTRY,
            TM_LEARNSET_2_SHIFTRY,
            TM_LEARNSET_3_SHIFTRY,
            TM_LEARNSET_4_SHIFTRY
        },
    },

    [SPECIES_TAILLOW] = {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 30,
        .baseSpeed     = 85,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHARTI_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 59,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TAILLOW,
            TM_LEARNSET_2_TAILLOW,
            TM_LEARNSET_3_TAILLOW,
            TM_LEARNSET_4_TAILLOW
        },
    },

    [SPECIES_SWELLOW] = {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 125,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_GUTS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHARTI_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 162,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SWELLOW,
            TM_LEARNSET_2_SWELLOW,
            TM_LEARNSET_3_SWELLOW,
            TM_LEARNSET_4_SWELLOW
        },
    },

    [SPECIES_WINGULL] = {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 30,
        .baseSpeed     = 85,
        .baseSpAttack  = 55,
        .baseSpDefense = 30,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 64,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WINGULL,
            TM_LEARNSET_2_WINGULL,
            TM_LEARNSET_3_WINGULL,
            TM_LEARNSET_4_WINGULL
        },
    },

    [SPECIES_PELIPPER] = {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 100,
        .baseSpeed     = 65,
        .baseSpAttack  = 85,
        .baseSpDefense = 70,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 164,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PELIPPER,
            TM_LEARNSET_2_PELIPPER,
            TM_LEARNSET_3_PELIPPER,
            TM_LEARNSET_4_PELIPPER
        },
    },

    [SPECIES_RALTS] = {
        .baseHP        = 28,
        .baseAttack    = 25,
        .baseDefense   = 25,
        .baseSpeed     = 40,
        .baseSpAttack  = 45,
        .baseSpDefense = 35,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_TRACE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 235,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 70,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RALTS,
            TM_LEARNSET_2_RALTS,
            TM_LEARNSET_3_RALTS,
            TM_LEARNSET_4_RALTS
        },
    },

    [SPECIES_KIRLIA] = {
        .baseHP        = 38,
        .baseAttack    = 35,
        .baseDefense   = 35,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 55,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_TRACE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 140,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KIRLIA,
            TM_LEARNSET_2_KIRLIA,
            TM_LEARNSET_3_KIRLIA,
            TM_LEARNSET_4_KIRLIA
        },
    },

    [SPECIES_GARDEVOIR] = {
        .baseHP        = 68,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 125,
        .baseSpDefense = 115,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SYNCHRONIZE,
        .ability2 = ABILITY_TRACE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 208,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GARDEVOIR,
            TM_LEARNSET_2_GARDEVOIR,
            TM_LEARNSET_3_GARDEVOIR,
            TM_LEARNSET_4_GARDEVOIR
        },
    },

    [SPECIES_SURSKIT] = {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 32,
        .baseSpeed     = 65,
        .baseSpAttack  = 50,
        .baseSpDefense = 52,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 63,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SURSKIT,
            TM_LEARNSET_2_SURSKIT,
            TM_LEARNSET_3_SURSKIT,
            TM_LEARNSET_4_SURSKIT
        },
    },

    [SPECIES_MASQUERAIN] = {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 62,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 82,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SILVER_POWDER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 1,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 128,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MASQUERAIN,
            TM_LEARNSET_2_MASQUERAIN,
            TM_LEARNSET_3_MASQUERAIN,
            TM_LEARNSET_4_MASQUERAIN
        },
    },

    [SPECIES_SHROOMISH] = {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 35,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_EFFECT_SPORE,
        .ability2 = ABILITY_POISON_HEAL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KEBIA_BERRY,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 65,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHROOMISH,
            TM_LEARNSET_2_SHROOMISH,
            TM_LEARNSET_3_SHROOMISH,
            TM_LEARNSET_4_SHROOMISH
        },
    },

    [SPECIES_BRELOOM] = {
        .baseHP        = 60,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_EFFECT_SPORE,
        .ability2 = ABILITY_POISON_HEAL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KEBIA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 165,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BRELOOM,
            TM_LEARNSET_2_BRELOOM,
            TM_LEARNSET_3_BRELOOM,
            TM_LEARNSET_4_BRELOOM
        },
    },

    [SPECIES_SLAKOTH] = {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 30,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_TRUANT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 83,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SLAKOTH,
            TM_LEARNSET_2_SLAKOTH,
            TM_LEARNSET_3_SLAKOTH,
            TM_LEARNSET_4_SLAKOTH
        },
    },

    [SPECIES_VIGOROTH] = {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 90,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 126,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VIGOROTH,
            TM_LEARNSET_2_VIGOROTH,
            TM_LEARNSET_3_VIGOROTH,
            TM_LEARNSET_4_VIGOROTH
        },
    },

    [SPECIES_SLAKING] = {
        .baseHP        = 150,
        .baseAttack    = 160,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 95,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_TRUANT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 210,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SLAKING,
            TM_LEARNSET_2_SLAKING,
            TM_LEARNSET_3_SLAKING,
            TM_LEARNSET_4_SLAKING
        },
    },

    [SPECIES_NINCADA] = {
        .baseHP        = 31,
        .baseAttack    = 45,
        .baseDefense   = 90,
        .baseSpeed     = 40,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_COMPOUND_EYES,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 65,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NINCADA,
            TM_LEARNSET_2_NINCADA,
            TM_LEARNSET_3_NINCADA,
            TM_LEARNSET_4_NINCADA
        },
    },

    [SPECIES_NINJASK] = {
        .baseHP        = 61,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 160,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SPEED_BOOST,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 155,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NINJASK,
            TM_LEARNSET_2_NINJASK,
            TM_LEARNSET_3_NINJASK,
            TM_LEARNSET_4_NINJASK
        },
    },

    [SPECIES_SHEDINJA] = {
        .baseHP        = 1,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 40,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_WONDER_GUARD,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 95,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHEDINJA,
            TM_LEARNSET_2_SHEDINJA,
            TM_LEARNSET_3_SHEDINJA,
            TM_LEARNSET_4_SHEDINJA
        },
    },

    [SPECIES_WHISMUR] = {
        .baseHP        = 64,
        .baseAttack    = 51,
        .baseDefense   = 23,
        .baseSpeed     = 28,
        .baseSpAttack  = 51,
        .baseSpDefense = 23,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_SOUNDPROOF,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHESTO_BERRY,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 68,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WHISMUR,
            TM_LEARNSET_2_WHISMUR,
            TM_LEARNSET_3_WHISMUR,
            TM_LEARNSET_4_WHISMUR
        },
    },

    [SPECIES_LOUDRED] = {
        .baseHP        = 84,
        .baseAttack    = 71,
        .baseDefense   = 43,
        .baseSpeed     = 48,
        .baseSpAttack  = 71,
        .baseSpDefense = 43,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_SOUNDPROOF,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHESTO_BERRY,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 126,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LOUDRED,
            TM_LEARNSET_2_LOUDRED,
            TM_LEARNSET_3_LOUDRED,
            TM_LEARNSET_4_LOUDRED
        },
    },

    [SPECIES_EXPLOUD] = {
        .baseHP        = 104,
        .baseAttack    = 91,
        .baseDefense   = 63,
        .baseSpeed     = 68,
        .baseSpAttack  = 91,
        .baseSpDefense = 63,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_SOUNDPROOF,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHESTO_BERRY,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 184,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_EXPLOUD,
            TM_LEARNSET_2_EXPLOUD,
            TM_LEARNSET_3_EXPLOUD,
            TM_LEARNSET_4_EXPLOUD
        },
    },

    [SPECIES_MAKUHITA] = {
        .baseHP        = 72,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 25,
        .baseSpAttack  = 20,
        .baseSpDefense = 30,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_GUTS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 180,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 87,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAKUHITA,
            TM_LEARNSET_2_MAKUHITA,
            TM_LEARNSET_3_MAKUHITA,
            TM_LEARNSET_4_MAKUHITA
        },
    },

    [SPECIES_HARIYAMA] = {
        .baseHP        = 144,
        .baseAttack    = 120,
        .baseDefense   = 60,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_GUTS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KINGS_ROCK,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 184,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HARIYAMA,
            TM_LEARNSET_2_HARIYAMA,
            TM_LEARNSET_3_HARIYAMA,
            TM_LEARNSET_4_HARIYAMA
        },
    },

    [SPECIES_AZURILL] = {
        .baseHP        = 50,
        .baseAttack    = 20,
        .baseDefense   = 40,
        .baseSpeed     = 20,
        .baseSpAttack  = 20,
        .baseSpDefense = 40,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_HUGE_POWER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 150,
        .fleeRate = 120,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 33,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AZURILL,
            TM_LEARNSET_2_AZURILL,
            TM_LEARNSET_3_AZURILL,
            TM_LEARNSET_4_AZURILL
        },
    },

    [SPECIES_NOSEPASS] = {
        .baseHP        = 30,
        .baseAttack    = 45,
        .baseDefense   = 135,
        .baseSpeed     = 30,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_MAGNET_PULL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HARD_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 108,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NOSEPASS,
            TM_LEARNSET_2_NOSEPASS,
            TM_LEARNSET_3_NOSEPASS,
            TM_LEARNSET_4_NOSEPASS
        },
    },

    [SPECIES_SKITTY] = {
        .baseHP        = 50,
        .baseAttack    = 45,
        .baseDefense   = 45,
        .baseSpeed     = 50,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_NORMALIZE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_LEPPA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 65,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SKITTY,
            TM_LEARNSET_2_SKITTY,
            TM_LEARNSET_3_SKITTY,
            TM_LEARNSET_4_SKITTY
        },
    },

    [SPECIES_DELCATTY] = {
        .baseHP        = 70,
        .baseAttack    = 65,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_NORMALIZE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_LEPPA_BERRY,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 138,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DELCATTY,
            TM_LEARNSET_2_DELCATTY,
            TM_LEARNSET_3_DELCATTY,
            TM_LEARNSET_4_DELCATTY
        },
    },

    [SPECIES_SABLEYE] = {
        .baseHP        = 50,
        .baseAttack    = 75,
        .baseDefense   = 75,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 65,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_STALL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 98,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SABLEYE,
            TM_LEARNSET_2_SABLEYE,
            TM_LEARNSET_3_SABLEYE,
            TM_LEARNSET_4_SABLEYE
        },
    },

    [SPECIES_MAWILE] = {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 85,
        .baseSpeed     = 50,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_INTIMIDATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_OCCA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 98,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAWILE,
            TM_LEARNSET_2_MAWILE,
            TM_LEARNSET_3_MAWILE,
            TM_LEARNSET_4_MAWILE
        },
    },

    [SPECIES_ARON] = {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 100,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HARD_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 180,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 96,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ARON,
            TM_LEARNSET_2_ARON,
            TM_LEARNSET_3_ARON,
            TM_LEARNSET_4_ARON
        },
    },

    [SPECIES_LAIRON] = {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 140,
        .baseSpeed     = 40,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HARD_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 152,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LAIRON,
            TM_LEARNSET_2_LAIRON,
            TM_LEARNSET_3_LAIRON,
            TM_LEARNSET_4_LAIRON
        },
    },

    [SPECIES_AGGRON] = {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 180,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HARD_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 3,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 205,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AGGRON,
            TM_LEARNSET_2_AGGRON,
            TM_LEARNSET_3_AGGRON,
            TM_LEARNSET_4_AGGRON
        },
    },

    [SPECIES_MEDITITE] = {
        .baseHP        = 30,
        .baseAttack    = 40,
        .baseDefense   = 55,
        .baseSpeed     = 60,
        .baseSpAttack  = 40,
        .baseSpDefense = 55,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_HUGE_POWER,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 180,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 91,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MEDITITE,
            TM_LEARNSET_2_MEDITITE,
            TM_LEARNSET_3_MEDITITE,
            TM_LEARNSET_4_MEDITITE
        },
    },

    [SPECIES_MEDICHAM] = {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 75,
        .baseSpeed     = 80,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_HUGE_POWER,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 153,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MEDICHAM,
            TM_LEARNSET_2_MEDICHAM,
            TM_LEARNSET_3_MEDICHAM,
            TM_LEARNSET_4_MEDICHAM
        },
    },

    [SPECIES_ELECTRIKE] = {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 40,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_LIGHTNING_ROD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 104,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ELECTRIKE,
            TM_LEARNSET_2_ELECTRIKE,
            TM_LEARNSET_3_ELECTRIKE,
            TM_LEARNSET_4_ELECTRIKE
        },
    },

    [SPECIES_MANECTRIC] = {
        .baseHP        = 70,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 105,
        .baseSpDefense = 60,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_STATIC,
        .ability2 = ABILITY_LIGHTNING_ROD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 168,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MANECTRIC,
            TM_LEARNSET_2_MANECTRIC,
            TM_LEARNSET_3_MANECTRIC,
            TM_LEARNSET_4_MANECTRIC
        },
    },

    [SPECIES_PLUSLE] = {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 40,
        .baseSpeed     = 95,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_PLUS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 120,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PLUSLE,
            TM_LEARNSET_2_PLUSLE,
            TM_LEARNSET_3_PLUSLE,
            TM_LEARNSET_4_PLUSLE
        },
    },

    [SPECIES_MINUN] = {
        .baseHP        = 60,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_MINUS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 120,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MINUN,
            TM_LEARNSET_2_MINUN,
            TM_LEARNSET_3_MINUN,
            TM_LEARNSET_4_MINUN
        },
    },

    [SPECIES_VOLBEAT] = {
        .baseHP        = 65,
        .baseAttack    = 73,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 47,
        .baseSpDefense = 75,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_ILLUMINATE,
        .ability2 = ABILITY_SWARM,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 150,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 146,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VOLBEAT,
            TM_LEARNSET_2_VOLBEAT,
            TM_LEARNSET_3_VOLBEAT,
            TM_LEARNSET_4_VOLBEAT
        },
    },

    [SPECIES_ILLUMISE] = {
        .baseHP        = 65,
        .baseAttack    = 47,
        .baseDefense   = 55,
        .baseSpeed     = 85,
        .baseSpAttack  = 73,
        .baseSpDefense = 75,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_TINTED_LENS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 150,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 146,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ILLUMISE,
            TM_LEARNSET_2_ILLUMISE,
            TM_LEARNSET_3_ILLUMISE,
            TM_LEARNSET_4_ILLUMISE
        },
    },

    [SPECIES_ROSELIA] = {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 65,
        .baseSpAttack  = 100,
        .baseSpDefense = 80,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_POISON_POINT,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 150,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 152,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROSELIA,
            TM_LEARNSET_2_ROSELIA,
            TM_LEARNSET_3_ROSELIA,
            TM_LEARNSET_4_ROSELIA
        },
    },

    [SPECIES_GULPIN] = {
        .baseHP        = 70,
        .baseAttack    = 43,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 43,
        .baseSpDefense = 53,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_LIQUID_OOZE,
        .ability2 = ABILITY_STICKY_HOLD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BIG_PEARL,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 75,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GULPIN,
            TM_LEARNSET_2_GULPIN,
            TM_LEARNSET_3_GULPIN,
            TM_LEARNSET_4_GULPIN
        },
    },

    [SPECIES_SWALOT] = {
        .baseHP        = 100,
        .baseAttack    = 73,
        .baseDefense   = 83,
        .baseSpeed     = 55,
        .baseSpAttack  = 73,
        .baseSpDefense = 83,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_LIQUID_OOZE,
        .ability2 = ABILITY_STICKY_HOLD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BIG_PEARL,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 168,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SWALOT,
            TM_LEARNSET_2_SWALOT,
            TM_LEARNSET_3_SWALOT,
            TM_LEARNSET_4_SWALOT
        },
    },

    [SPECIES_CARVANHA] = {
        .baseHP        = 45,
        .baseAttack    = 90,
        .baseDefense   = 20,
        .baseSpeed     = 65,
        .baseSpAttack  = 65,
        .baseSpDefense = 20,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_ROUGH_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DEEP_SEA_TOOTH,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 90,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 88,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CARVANHA,
            TM_LEARNSET_2_CARVANHA,
            TM_LEARNSET_3_CARVANHA,
            TM_LEARNSET_4_CARVANHA
        },
    },

    [SPECIES_SHARPEDO] = {
        .baseHP        = 70,
        .baseAttack    = 120,
        .baseDefense   = 40,
        .baseSpeed     = 95,
        .baseSpAttack  = 95,
        .baseSpDefense = 40,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_ROUGH_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DEEP_SEA_TOOTH,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 175,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHARPEDO,
            TM_LEARNSET_2_SHARPEDO,
            TM_LEARNSET_3_SHARPEDO,
            TM_LEARNSET_4_SHARPEDO
        },
    },

    [SPECIES_WAILMER] = {
        .baseHP        = 130,
        .baseAttack    = 70,
        .baseDefense   = 35,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 35,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_WATER_VEIL,
        .ability2 = ABILITY_OBLIVIOUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 125,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 137,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WAILMER,
            TM_LEARNSET_2_WAILMER,
            TM_LEARNSET_3_WAILMER,
            TM_LEARNSET_4_WAILMER
        },
    },

    [SPECIES_WAILORD] = {
        .baseHP        = 170,
        .baseAttack    = 90,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 90,
        .baseSpDefense = 45,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_WATER_VEIL,
        .ability2 = ABILITY_OBLIVIOUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 206,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WAILORD,
            TM_LEARNSET_2_WAILORD,
            TM_LEARNSET_3_WAILORD,
            TM_LEARNSET_4_WAILORD
        },
    },

    [SPECIES_NUMEL] = {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 65,
        .baseSpDefense = 45,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_SIMPLE,

        .itemUncommon = ITEM_RAWST_BERRY,
        .itemRare     = ITEM_RAWST_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 88,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_NUMEL,
            TM_LEARNSET_2_NUMEL,
            TM_LEARNSET_3_NUMEL,
            TM_LEARNSET_4_NUMEL
        },
    },

    [SPECIES_CAMERUPT] = {
        .baseHP        = 70,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 105,
        .baseSpDefense = 75,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_MAGMA_ARMOR,
        .ability2 = ABILITY_FILTER,

        .itemUncommon = ITEM_RAWST_BERRY,
        .itemRare     = ITEM_RAWST_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 150,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 175,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CAMERUPT,
            TM_LEARNSET_2_CAMERUPT,
            TM_LEARNSET_3_CAMERUPT,
            TM_LEARNSET_4_CAMERUPT
        },
    },

    [SPECIES_TORKOAL] = {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 140,
        .baseSpeed     = 20,
        .baseSpAttack  = 85,
        .baseSpDefense = 70,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 161,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TORKOAL,
            TM_LEARNSET_2_TORKOAL,
            TM_LEARNSET_3_TORKOAL,
            TM_LEARNSET_4_TORKOAL
        },
    },

    [SPECIES_SPOINK] = {
        .baseHP        = 60,
        .baseAttack    = 25,
        .baseDefense   = 35,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_OWN_TEMPO,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_TANGA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 89,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SPOINK,
            TM_LEARNSET_2_SPOINK,
            TM_LEARNSET_3_SPOINK,
            TM_LEARNSET_4_SPOINK
        },
    },

    [SPECIES_GRUMPIG] = {
        .baseHP        = 80,
        .baseAttack    = 45,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 90,
        .baseSpDefense = 110,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_OWN_TEMPO,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_TANGA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 164,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GRUMPIG,
            TM_LEARNSET_2_GRUMPIG,
            TM_LEARNSET_3_GRUMPIG,
            TM_LEARNSET_4_GRUMPIG
        },
    },

    [SPECIES_SPINDA] = {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_OWN_TEMPO,
        .ability2 = ABILITY_TANGLED_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHESTO_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 85,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_SPINDA,
            TM_LEARNSET_2_SPINDA,
            TM_LEARNSET_3_SPINDA,
            TM_LEARNSET_4_SPINDA
        },
    },

    [SPECIES_TRAPINCH] = {
        .baseHP        = 45,
        .baseAttack    = 100,
        .baseDefense   = 45,
        .baseSpeed     = 10,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_ARENA_TRAP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SOFT_SAND,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 73,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TRAPINCH,
            TM_LEARNSET_2_TRAPINCH,
            TM_LEARNSET_3_TRAPINCH,
            TM_LEARNSET_4_TRAPINCH
        },
    },

    [SPECIES_VIBRAVA] = {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 50,
        .baseSpeed     = 70,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_LEVITATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 126,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VIBRAVA,
            TM_LEARNSET_2_VIBRAVA,
            TM_LEARNSET_3_VIBRAVA,
            TM_LEARNSET_4_VIBRAVA
        },
    },

    [SPECIES_FLYGON] = {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_LEVITATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 197,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FLYGON,
            TM_LEARNSET_2_FLYGON,
            TM_LEARNSET_3_FLYGON,
            TM_LEARNSET_4_FLYGON
        },
    },

    [SPECIES_CACNEA] = {
        .baseHP        = 50,
        .baseAttack    = 85,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 85,
        .baseSpDefense = 40,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_STICKY_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 97,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CACNEA,
            TM_LEARNSET_2_CACNEA,
            TM_LEARNSET_3_CACNEA,
            TM_LEARNSET_4_CACNEA
        },
    },

    [SPECIES_CACTURNE] = {
        .baseHP        = 70,
        .baseAttack    = 115,
        .baseDefense   = 60,
        .baseSpeed     = 55,
        .baseSpAttack  = 115,
        .baseSpDefense = 60,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_STICKY_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 177,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CACTURNE,
            TM_LEARNSET_2_CACTURNE,
            TM_LEARNSET_3_CACTURNE,
            TM_LEARNSET_4_CACTURNE
        },
    },

    [SPECIES_SWABLU] = {
        .baseHP        = 45,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 75,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 74,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SWABLU,
            TM_LEARNSET_2_SWABLU,
            TM_LEARNSET_3_SWABLU,
            TM_LEARNSET_4_SWABLU
        },
    },

    [SPECIES_ALTARIA] = {
        .baseHP        = 75,
        .baseAttack    = 70,
        .baseDefense   = 90,
        .baseSpeed     = 80,
        .baseSpAttack  = 70,
        .baseSpDefense = 105,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 188,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ALTARIA,
            TM_LEARNSET_2_ALTARIA,
            TM_LEARNSET_3_ALTARIA,
            TM_LEARNSET_4_ALTARIA
        },
    },

    [SPECIES_ZANGOOSE] = {
        .baseHP        = 73,
        .baseAttack    = 115,
        .baseDefense   = 60,
        .baseSpeed     = 90,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_IMMUNITY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_QUICK_CLAW,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 165,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_ZANGOOSE,
            TM_LEARNSET_2_ZANGOOSE,
            TM_LEARNSET_3_ZANGOOSE,
            TM_LEARNSET_4_ZANGOOSE
        },
    },

    [SPECIES_SEVIPER] = {
        .baseHP        = 73,
        .baseAttack    = 100,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = 100,
        .baseSpDefense = 60,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 165,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_SEVIPER,
            TM_LEARNSET_2_SEVIPER,
            TM_LEARNSET_3_SEVIPER,
            TM_LEARNSET_4_SEVIPER
        },
    },

    [SPECIES_LUNATONE] = {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 65,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 85,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_MOON_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 150,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUNATONE,
            TM_LEARNSET_2_LUNATONE,
            TM_LEARNSET_3_LUNATONE,
            TM_LEARNSET_4_LUNATONE
        },
    },

    [SPECIES_SOLROCK] = {
        .baseHP        = 70,
        .baseAttack    = 95,
        .baseDefense   = 85,
        .baseSpeed     = 70,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SUN_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 150,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SOLROCK,
            TM_LEARNSET_2_SOLROCK,
            TM_LEARNSET_3_SOLROCK,
            TM_LEARNSET_4_SOLROCK
        },
    },

    [SPECIES_BARBOACH] = {
        .baseHP        = 50,
        .baseAttack    = 48,
        .baseDefense   = 43,
        .baseSpeed     = 60,
        .baseSpAttack  = 46,
        .baseSpDefense = 41,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_ANTICIPATION,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 92,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BARBOACH,
            TM_LEARNSET_2_BARBOACH,
            TM_LEARNSET_3_BARBOACH,
            TM_LEARNSET_4_BARBOACH
        },
    },

    [SPECIES_WHISCASH] = {
        .baseHP        = 110,
        .baseAttack    = 78,
        .baseDefense   = 73,
        .baseSpeed     = 60,
        .baseSpAttack  = 76,
        .baseSpDefense = 71,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_ANTICIPATION,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 158,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WHISCASH,
            TM_LEARNSET_2_WHISCASH,
            TM_LEARNSET_3_WHISCASH,
            TM_LEARNSET_4_WHISCASH
        },
    },

    [SPECIES_CORPHISH] = {
        .baseHP        = 43,
        .baseAttack    = 80,
        .baseDefense   = 65,
        .baseSpeed     = 35,
        .baseSpAttack  = 50,
        .baseSpDefense = 35,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 205,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 111,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CORPHISH,
            TM_LEARNSET_2_CORPHISH,
            TM_LEARNSET_3_CORPHISH,
            TM_LEARNSET_4_CORPHISH
        },
    },

    [SPECIES_CRAWDAUNT] = {
        .baseHP        = 63,
        .baseAttack    = 120,
        .baseDefense   = 85,
        .baseSpeed     = 55,
        .baseSpAttack  = 90,
        .baseSpDefense = 55,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_BATTLE_ARMOR,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 155,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 161,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CRAWDAUNT,
            TM_LEARNSET_2_CRAWDAUNT,
            TM_LEARNSET_3_CRAWDAUNT,
            TM_LEARNSET_4_CRAWDAUNT
        },
    },

    [SPECIES_BALTOY] = {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 55,
        .baseSpeed     = 55,
        .baseSpAttack  = 40,
        .baseSpDefense = 70,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 58,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BALTOY,
            TM_LEARNSET_2_BALTOY,
            TM_LEARNSET_3_BALTOY,
            TM_LEARNSET_4_BALTOY
        },
    },

    [SPECIES_CLAYDOL] = {
        .baseHP        = 60,
        .baseAttack    = 70,
        .baseDefense   = 105,
        .baseSpeed     = 75,
        .baseSpAttack  = 70,
        .baseSpDefense = 120,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 189,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CLAYDOL,
            TM_LEARNSET_2_CLAYDOL,
            TM_LEARNSET_3_CLAYDOL,
            TM_LEARNSET_4_CLAYDOL
        },
    },

    [SPECIES_LILEEP] = {
        .baseHP        = 66,
        .baseAttack    = 41,
        .baseDefense   = 77,
        .baseSpeed     = 23,
        .baseSpAttack  = 61,
        .baseSpDefense = 87,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_SUCTION_CUPS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BIG_ROOT,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 99,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LILEEP,
            TM_LEARNSET_2_LILEEP,
            TM_LEARNSET_3_LILEEP,
            TM_LEARNSET_4_LILEEP
        },
    },

    [SPECIES_CRADILY] = {
        .baseHP        = 86,
        .baseAttack    = 81,
        .baseDefense   = 97,
        .baseSpeed     = 43,
        .baseSpAttack  = 81,
        .baseSpDefense = 107,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_SUCTION_CUPS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BIG_ROOT,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 199,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CRADILY,
            TM_LEARNSET_2_CRADILY,
            TM_LEARNSET_3_CRADILY,
            TM_LEARNSET_4_CRADILY
        },
    },

    [SPECIES_ANORITH] = {
        .baseHP        = 45,
        .baseAttack    = 95,
        .baseDefense   = 50,
        .baseSpeed     = 75,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_BATTLE_ARMOR,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 99,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ANORITH,
            TM_LEARNSET_2_ANORITH,
            TM_LEARNSET_3_ANORITH,
            TM_LEARNSET_4_ANORITH
        },
    },

    [SPECIES_ARMALDO] = {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 100,
        .baseSpeed     = 45,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_BATTLE_ARMOR,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 199,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_WATER_3,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ARMALDO,
            TM_LEARNSET_2_ARMALDO,
            TM_LEARNSET_3_ARMALDO,
            TM_LEARNSET_4_ARMALDO
        },
    },

    [SPECIES_FEEBAS] = {
        .baseHP        = 20,
        .baseAttack    = 15,
        .baseDefense   = 20,
        .baseSpeed     = 80,
        .baseSpAttack  = 10,
        .baseSpDefense = 55,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 61,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FEEBAS,
            TM_LEARNSET_2_FEEBAS,
            TM_LEARNSET_3_FEEBAS,
            TM_LEARNSET_4_FEEBAS
        },
    },

    [SPECIES_MILOTIC] = {
        .baseHP        = 95,
        .baseAttack    = 60,
        .baseDefense   = 79,
        .baseSpeed     = 81,
        .baseSpAttack  = 100,
        .baseSpDefense = 125,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_MARVEL_SCALE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 213,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MILOTIC,
            TM_LEARNSET_2_MILOTIC,
            TM_LEARNSET_3_MILOTIC,
            TM_LEARNSET_4_MILOTIC
        },
    },

    [SPECIES_CASTFORM] = {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 70,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 70,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_FORECAST,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_MYSTIC_WATER,
        .itemRare     = ITEM_MYSTIC_WATER,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 145,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CASTFORM,
            TM_LEARNSET_2_CASTFORM,
            TM_LEARNSET_3_CASTFORM,
            TM_LEARNSET_4_CASTFORM
        },
    },

    [SPECIES_KECLEON] = {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 70,
        .baseSpeed     = 40,
        .baseSpAttack  = 60,
        .baseSpDefense = 120,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_COLOR_CHANGE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PERSIM_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 200,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KECLEON,
            TM_LEARNSET_2_KECLEON,
            TM_LEARNSET_3_KECLEON,
            TM_LEARNSET_4_KECLEON
        },
    },

    [SPECIES_SHUPPET] = {
        .baseHP        = 44,
        .baseAttack    = 75,
        .baseDefense   = 35,
        .baseSpeed     = 45,
        .baseSpAttack  = 63,
        .baseSpDefense = 33,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_FRISK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SPELL_TAG,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_FAST,
        .expYield = 97,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHUPPET,
            TM_LEARNSET_2_SHUPPET,
            TM_LEARNSET_3_SHUPPET,
            TM_LEARNSET_4_SHUPPET
        },
    },

    [SPECIES_BANETTE] = {
        .baseHP        = 64,
        .baseAttack    = 115,
        .baseDefense   = 65,
        .baseSpeed     = 65,
        .baseSpAttack  = 83,
        .baseSpDefense = 63,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_FRISK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SPELL_TAG,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_FAST,
        .expYield = 179,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BANETTE,
            TM_LEARNSET_2_BANETTE,
            TM_LEARNSET_3_BANETTE,
            TM_LEARNSET_4_BANETTE
        },
    },

    [SPECIES_DUSKULL] = {
        .baseHP        = 20,
        .baseAttack    = 40,
        .baseDefense   = 90,
        .baseSpeed     = 25,
        .baseSpAttack  = 30,
        .baseSpDefense = 90,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KASIB_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_FAST,
        .expYield = 97,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DUSKULL,
            TM_LEARNSET_2_DUSKULL,
            TM_LEARNSET_3_DUSKULL,
            TM_LEARNSET_4_DUSKULL
        },
    },

    [SPECIES_DUSCLOPS] = {
        .baseHP        = 40,
        .baseAttack    = 70,
        .baseDefense   = 130,
        .baseSpeed     = 25,
        .baseSpAttack  = 60,
        .baseSpDefense = 130,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KASIB_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_FAST,
        .expYield = 179,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DUSCLOPS,
            TM_LEARNSET_2_DUSCLOPS,
            TM_LEARNSET_3_DUSCLOPS,
            TM_LEARNSET_4_DUSCLOPS
        },
    },

    [SPECIES_TROPIUS] = {
        .baseHP        = 99,
        .baseAttack    = 68,
        .baseDefense   = 83,
        .baseSpeed     = 51,
        .baseSpAttack  = 72,
        .baseSpDefense = 87,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_SOLAR_POWER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 169,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TROPIUS,
            TM_LEARNSET_2_TROPIUS,
            TM_LEARNSET_3_TROPIUS,
            TM_LEARNSET_4_TROPIUS
        },
    },

    [SPECIES_CHIMECHO] = {
        .baseHP        = 65,
        .baseAttack    = 50,
        .baseDefense   = 70,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = 80,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_COLBUR_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 147,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHIMECHO,
            TM_LEARNSET_2_CHIMECHO,
            TM_LEARNSET_3_CHIMECHO,
            TM_LEARNSET_4_CHIMECHO
        },
    },

    [SPECIES_ABSOL] = {
        .baseHP        = 65,
        .baseAttack    = 130,
        .baseDefense   = 60,
        .baseSpeed     = 75,
        .baseSpAttack  = 75,
        .baseSpDefense = 60,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_SUPER_LUCK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 174,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_ABSOL,
            TM_LEARNSET_2_ABSOL,
            TM_LEARNSET_3_ABSOL,
            TM_LEARNSET_4_ABSOL
        },
    },

    [SPECIES_WYNAUT] = {
        .baseHP        = 95,
        .baseAttack    = 23,
        .baseDefense   = 48,
        .baseSpeed     = 23,
        .baseSpAttack  = 23,
        .baseSpDefense = 48,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SHADOW_TAG,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 125,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 44,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WYNAUT,
            TM_LEARNSET_2_WYNAUT,
            TM_LEARNSET_3_WYNAUT,
            TM_LEARNSET_4_WYNAUT
        },
    },

    [SPECIES_SNORUNT] = {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_ICE_BODY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BABIRI_BERRY,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 74,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SNORUNT,
            TM_LEARNSET_2_SNORUNT,
            TM_LEARNSET_3_SNORUNT,
            TM_LEARNSET_4_SNORUNT
        },
    },

    [SPECIES_GLALIE] = {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_INNER_FOCUS,
        .ability2 = ABILITY_ICE_BODY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BABIRI_BERRY,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 187,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GLALIE,
            TM_LEARNSET_2_GLALIE,
            TM_LEARNSET_3_GLALIE,
            TM_LEARNSET_4_GLALIE
        },
    },

    [SPECIES_SPHEAL] = {
        .baseHP        = 70,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 25,
        .baseSpAttack  = 55,
        .baseSpDefense = 50,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_ICE_BODY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 75,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SPHEAL,
            TM_LEARNSET_2_SPHEAL,
            TM_LEARNSET_3_SPHEAL,
            TM_LEARNSET_4_SPHEAL
        },
    },

    [SPECIES_SEALEO] = {
        .baseHP        = 90,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 45,
        .baseSpAttack  = 75,
        .baseSpDefense = 70,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_ICE_BODY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 128,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SEALEO,
            TM_LEARNSET_2_SEALEO,
            TM_LEARNSET_3_SEALEO,
            TM_LEARNSET_4_SEALEO
        },
    },

    [SPECIES_WALREIN] = {
        .baseHP        = 110,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 65,
        .baseSpAttack  = 95,
        .baseSpDefense = 90,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_ICE_BODY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 192,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WALREIN,
            TM_LEARNSET_2_WALREIN,
            TM_LEARNSET_3_WALREIN,
            TM_LEARNSET_4_WALREIN
        },
    },

    [SPECIES_CLAMPERL] = {
        .baseHP        = 35,
        .baseAttack    = 64,
        .baseDefense   = 85,
        .baseSpeed     = 32,
        .baseSpAttack  = 74,
        .baseSpDefense = 55,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_BATTLE_ARMOR,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BIG_PEARL,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 142,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CLAMPERL,
            TM_LEARNSET_2_CLAMPERL,
            TM_LEARNSET_3_CLAMPERL,
            TM_LEARNSET_4_CLAMPERL
        },
    },

    [SPECIES_HUNTAIL] = {
        .baseHP        = 55,
        .baseAttack    = 104,
        .baseDefense   = 105,
        .baseSpeed     = 52,
        .baseSpAttack  = 94,
        .baseSpDefense = 75,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DEEP_SEA_TOOTH,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 178,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HUNTAIL,
            TM_LEARNSET_2_HUNTAIL,
            TM_LEARNSET_3_HUNTAIL,
            TM_LEARNSET_4_HUNTAIL
        },
    },

    [SPECIES_GOREBYSS] = {
        .baseHP        = 55,
        .baseAttack    = 84,
        .baseDefense   = 105,
        .baseSpeed     = 52,
        .baseSpAttack  = 114,
        .baseSpDefense = 75,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DEEP_SEA_SCALE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 178,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_1,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GOREBYSS,
            TM_LEARNSET_2_GOREBYSS,
            TM_LEARNSET_3_GOREBYSS,
            TM_LEARNSET_4_GOREBYSS
        },
    },

    [SPECIES_RELICANTH] = {
        .baseHP        = 100,
        .baseAttack    = 90,
        .baseDefense   = 130,
        .baseSpeed     = 55,
        .baseSpAttack  = 45,
        .baseSpDefense = 65,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DEEP_SEA_SCALE,

        .evYieldHP        = 1,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 198,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RELICANTH,
            TM_LEARNSET_2_RELICANTH,
            TM_LEARNSET_3_RELICANTH,
            TM_LEARNSET_4_RELICANTH
        },
    },

    [SPECIES_LUVDISC] = {
        .baseHP        = 43,
        .baseAttack    = 30,
        .baseDefense   = 55,
        .baseSpeed     = 97,
        .baseSpAttack  = 40,
        .baseSpDefense = 65,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_HEART_SCALE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 110,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUVDISC,
            TM_LEARNSET_2_LUVDISC,
            TM_LEARNSET_3_LUVDISC,
            TM_LEARNSET_4_LUVDISC
        },
    },

    [SPECIES_BAGON] = {
        .baseHP        = 45,
        .baseAttack    = 75,
        .baseDefense   = 60,
        .baseSpeed     = 50,
        .baseSpAttack  = 40,
        .baseSpDefense = 30,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_FANG,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 89,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_DRAGON,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BAGON,
            TM_LEARNSET_2_BAGON,
            TM_LEARNSET_3_BAGON,
            TM_LEARNSET_4_BAGON
        },
    },

    [SPECIES_SHELGON] = {
        .baseHP        = 65,
        .baseAttack    = 95,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_ROCK_HEAD,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_FANG,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 144,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_DRAGON,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHELGON,
            TM_LEARNSET_2_SHELGON,
            TM_LEARNSET_3_SHELGON,
            TM_LEARNSET_4_SHELGON
        },
    },

    [SPECIES_SALAMENCE] = {
        .baseHP        = 95,
        .baseAttack    = 135,
        .baseDefense   = 80,
        .baseSpeed     = 100,
        .baseSpAttack  = 110,
        .baseSpDefense = 80,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_DRAGON_FANG,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 218,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_DRAGON,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SALAMENCE,
            TM_LEARNSET_2_SALAMENCE,
            TM_LEARNSET_3_SALAMENCE,
            TM_LEARNSET_4_SALAMENCE
        },
    },

    [SPECIES_BELDUM] = {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 35,
        .baseSpDefense = 60,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 103,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BELDUM,
            TM_LEARNSET_2_BELDUM,
            TM_LEARNSET_3_BELDUM,
            TM_LEARNSET_4_BELDUM
        },
    },

    [SPECIES_METANG] = {
        .baseHP        = 60,
        .baseAttack    = 75,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 55,
        .baseSpDefense = 80,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 153,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_METANG,
            TM_LEARNSET_2_METANG,
            TM_LEARNSET_3_METANG,
            TM_LEARNSET_4_METANG
        },
    },

    [SPECIES_METAGROSS] = {
        .baseHP        = 80,
        .baseAttack    = 135,
        .baseDefense   = 130,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 90,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 3,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 210,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_METAGROSS,
            TM_LEARNSET_2_METAGROSS,
            TM_LEARNSET_3_METAGROSS,
            TM_LEARNSET_4_METAGROSS
        },
    },

    [SPECIES_REGIROCK] = {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 200,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 100,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 3,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 217,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_REGIROCK,
            TM_LEARNSET_2_REGIROCK,
            TM_LEARNSET_3_REGIROCK,
            TM_LEARNSET_4_REGIROCK
        },
    },

    [SPECIES_REGICE] = {
        .baseHP        = 80,
        .baseAttack    = 50,
        .baseDefense   = 100,
        .baseSpeed     = 50,
        .baseSpAttack  = 100,
        .baseSpDefense = 200,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 216,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_REGICE,
            TM_LEARNSET_2_REGICE,
            TM_LEARNSET_3_REGICE,
            TM_LEARNSET_4_REGICE
        },
    },

    [SPECIES_REGISTEEL] = {
        .baseHP        = 80,
        .baseAttack    = 75,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 75,
        .baseSpDefense = 150,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_CLEAR_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_REGISTEEL,
            TM_LEARNSET_2_REGISTEEL,
            TM_LEARNSET_3_REGISTEEL,
            TM_LEARNSET_4_REGISTEEL
        },
    },

    [SPECIES_LATIAS] = {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 90,
        .baseSpeed     = 110,
        .baseSpAttack  = 110,
        .baseSpDefense = 130,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 90,
        .expCurve = GROWTH_SLOW,
        .expYield = 211,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LATIAS,
            TM_LEARNSET_2_LATIAS,
            TM_LEARNSET_3_LATIAS,
            TM_LEARNSET_4_LATIAS
        },
    },

    [SPECIES_LATIOS] = {
        .baseHP        = 80,
        .baseAttack    = 90,
        .baseDefense   = 80,
        .baseSpeed     = 110,
        .baseSpAttack  = 130,
        .baseSpDefense = 110,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 90,
        .expCurve = GROWTH_SLOW,
        .expYield = 211,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LATIOS,
            TM_LEARNSET_2_LATIOS,
            TM_LEARNSET_3_LATIOS,
            TM_LEARNSET_4_LATIOS
        },
    },

    [SPECIES_KYOGRE] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 140,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_DRIZZLE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 5,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 218,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KYOGRE,
            TM_LEARNSET_2_KYOGRE,
            TM_LEARNSET_3_KYOGRE,
            TM_LEARNSET_4_KYOGRE
        },
    },

    [SPECIES_GROUDON] = {
        .baseHP        = 100,
        .baseAttack    = 150,
        .baseDefense   = 140,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 90,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_DROUGHT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 5,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 218,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GROUDON,
            TM_LEARNSET_2_GROUDON,
            TM_LEARNSET_3_GROUDON,
            TM_LEARNSET_4_GROUDON
        },
    },

    [SPECIES_RAYQUAZA] = {
        .baseHP        = 105,
        .baseAttack    = 150,
        .baseDefense   = 90,
        .baseSpeed     = 95,
        .baseSpAttack  = 150,
        .baseSpDefense = 90,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_CLOUD_NINE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RAYQUAZA,
            TM_LEARNSET_2_RAYQUAZA,
            TM_LEARNSET_3_RAYQUAZA,
            TM_LEARNSET_4_RAYQUAZA
        },
    },

    [SPECIES_JIRACHI] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SERENE_GRACE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_STAR_PIECE,
        .itemRare     = ITEM_STAR_PIECE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 100,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_JIRACHI,
            TM_LEARNSET_2_JIRACHI,
            TM_LEARNSET_3_JIRACHI,
            TM_LEARNSET_4_JIRACHI
        },
    },

    [SPECIES_DEOXYS] = {
        .baseHP        = 50,
        .baseAttack    = 150,
        .baseDefense   = 50,
        .baseSpeed     = 150,
        .baseSpAttack  = 150,
        .baseSpDefense = 50,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DEOXYS,
            TM_LEARNSET_2_DEOXYS,
            TM_LEARNSET_3_DEOXYS,
            TM_LEARNSET_4_DEOXYS
        },
    },

    [SPECIES_TURTWIG] = {
        .baseHP        = 55,
        .baseAttack    = 68,
        .baseDefense   = 64,
        .baseSpeed     = 31,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 64,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TURTWIG,
            TM_LEARNSET_2_TURTWIG,
            TM_LEARNSET_3_TURTWIG,
            TM_LEARNSET_4_TURTWIG
        },
    },

    [SPECIES_GROTLE] = {
        .baseHP        = 75,
        .baseAttack    = 89,
        .baseDefense   = 85,
        .baseSpeed     = 36,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 141,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GROTLE,
            TM_LEARNSET_2_GROTLE,
            TM_LEARNSET_3_GROTLE,
            TM_LEARNSET_4_GROTLE
        },
    },

    [SPECIES_TORTERRA] = {
        .baseHP        = 95,
        .baseAttack    = 109,
        .baseDefense   = 105,
        .baseSpeed     = 56,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_OVERGROW,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 208,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_TORTERRA,
            TM_LEARNSET_2_TORTERRA,
            TM_LEARNSET_3_TORTERRA,
            TM_LEARNSET_4_TORTERRA
        },
    },

    [SPECIES_CHIMCHAR] = {
        .baseHP        = 44,
        .baseAttack    = 58,
        .baseDefense   = 44,
        .baseSpeed     = 61,
        .baseSpAttack  = 58,
        .baseSpDefense = 44,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 65,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHIMCHAR,
            TM_LEARNSET_2_CHIMCHAR,
            TM_LEARNSET_3_CHIMCHAR,
            TM_LEARNSET_4_CHIMCHAR
        },
    },

    [SPECIES_MONFERNO] = {
        .baseHP        = 64,
        .baseAttack    = 78,
        .baseDefense   = 52,
        .baseSpeed     = 81,
        .baseSpAttack  = 78,
        .baseSpDefense = 52,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 142,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_MONFERNO,
            TM_LEARNSET_2_MONFERNO,
            TM_LEARNSET_3_MONFERNO,
            TM_LEARNSET_4_MONFERNO
        },
    },

    [SPECIES_INFERNAPE] = {
        .baseHP        = 76,
        .baseAttack    = 104,
        .baseDefense   = 71,
        .baseSpeed     = 108,
        .baseSpAttack  = 104,
        .baseSpDefense = 71,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_BLAZE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 209,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_INFERNAPE,
            TM_LEARNSET_2_INFERNAPE,
            TM_LEARNSET_3_INFERNAPE,
            TM_LEARNSET_4_INFERNAPE
        },
    },

    [SPECIES_PIPLUP] = {
        .baseHP        = 53,
        .baseAttack    = 51,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 61,
        .baseSpDefense = 56,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 66,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PIPLUP,
            TM_LEARNSET_2_PIPLUP,
            TM_LEARNSET_3_PIPLUP,
            TM_LEARNSET_4_PIPLUP
        },
    },

    [SPECIES_PRINPLUP] = {
        .baseHP        = 64,
        .baseAttack    = 66,
        .baseDefense   = 68,
        .baseSpeed     = 50,
        .baseSpAttack  = 81,
        .baseSpDefense = 76,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 143,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PRINPLUP,
            TM_LEARNSET_2_PRINPLUP,
            TM_LEARNSET_3_PRINPLUP,
            TM_LEARNSET_4_PRINPLUP
        },
    },

    [SPECIES_EMPOLEON] = {
        .baseHP        = 84,
        .baseAttack    = 86,
        .baseDefense   = 88,
        .baseSpeed     = 60,
        .baseSpAttack  = 111,
        .baseSpDefense = 101,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_TORRENT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 210,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_EMPOLEON,
            TM_LEARNSET_2_EMPOLEON,
            TM_LEARNSET_3_EMPOLEON,
            TM_LEARNSET_4_EMPOLEON
        },
    },

    [SPECIES_STARLY] = {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 30,
        .baseSpeed     = 60,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_YACHE_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 90,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 56,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_STARLY,
            TM_LEARNSET_2_STARLY,
            TM_LEARNSET_3_STARLY,
            TM_LEARNSET_4_STARLY
        },
    },

    [SPECIES_STARAVIA] = {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_YACHE_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 113,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_STARAVIA,
            TM_LEARNSET_2_STARAVIA,
            TM_LEARNSET_3_STARAVIA,
            TM_LEARNSET_4_STARAVIA
        },
    },

    [SPECIES_STARAPTOR] = {
        .baseHP        = 85,
        .baseAttack    = 120,
        .baseDefense   = 70,
        .baseSpeed     = 100,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INTIMIDATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_YACHE_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 172,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_STARAPTOR,
            TM_LEARNSET_2_STARAPTOR,
            TM_LEARNSET_3_STARAPTOR,
            TM_LEARNSET_4_STARAPTOR
        },
    },

    [SPECIES_BIDOOF] = {
        .baseHP        = 59,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 31,
        .baseSpAttack  = 35,
        .baseSpDefense = 40,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_SIMPLE,
        .ability2 = ABILITY_UNAWARE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 90,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 58,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BIDOOF,
            TM_LEARNSET_2_BIDOOF,
            TM_LEARNSET_3_BIDOOF,
            TM_LEARNSET_4_BIDOOF
        },
    },

    [SPECIES_BIBAREL] = {
        .baseHP        = 79,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 71,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SIMPLE,
        .ability2 = ABILITY_UNAWARE,

        .itemUncommon = ITEM_ORAN_BERRY,
        .itemRare     = ITEM_SITRUS_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 127,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 116,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BIBAREL,
            TM_LEARNSET_2_BIBAREL,
            TM_LEARNSET_3_BIBAREL,
            TM_LEARNSET_4_BIBAREL
        },
    },

    [SPECIES_KRICKETOT] = {
        .baseHP        = 37,
        .baseAttack    = 25,
        .baseDefense   = 41,
        .baseSpeed     = 25,
        .baseSpAttack  = 25,
        .baseSpDefense = 41,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METRONOME,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 54,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KRICKETOT,
            TM_LEARNSET_2_KRICKETOT,
            TM_LEARNSET_3_KRICKETOT,
            TM_LEARNSET_4_KRICKETOT
        },
    },

    [SPECIES_KRICKETUNE] = {
        .baseHP        = 77,
        .baseAttack    = 85,
        .baseDefense   = 51,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 51,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METRONOME,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 159,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_KRICKETUNE,
            TM_LEARNSET_2_KRICKETUNE,
            TM_LEARNSET_3_KRICKETUNE,
            TM_LEARNSET_4_KRICKETUNE
        },
    },

    [SPECIES_SHINX] = {
        .baseHP        = 45,
        .baseAttack    = 65,
        .baseDefense   = 34,
        .baseSpeed     = 45,
        .baseSpAttack  = 40,
        .baseSpDefense = 34,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_RIVALRY,
        .ability2 = ABILITY_INTIMIDATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 235,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 60,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHINX,
            TM_LEARNSET_2_SHINX,
            TM_LEARNSET_3_SHINX,
            TM_LEARNSET_4_SHINX
        },
    },

    [SPECIES_LUXIO] = {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 49,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 49,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_RIVALRY,
        .ability2 = ABILITY_INTIMIDATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 100,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 117,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUXIO,
            TM_LEARNSET_2_LUXIO,
            TM_LEARNSET_3_LUXIO,
            TM_LEARNSET_4_LUXIO
        },
    },

    [SPECIES_LUXRAY] = {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 79,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 79,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_RIVALRY,
        .ability2 = ABILITY_INTIMIDATE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 194,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUXRAY,
            TM_LEARNSET_2_LUXRAY,
            TM_LEARNSET_3_LUXRAY,
            TM_LEARNSET_4_LUXRAY
        },
    },

    [SPECIES_BUDEW] = {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 35,
        .baseSpeed     = 55,
        .baseSpAttack  = 50,
        .baseSpDefense = 70,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_POISON_POINT,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 68,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_BUDEW,
            TM_LEARNSET_2_BUDEW,
            TM_LEARNSET_3_BUDEW,
            TM_LEARNSET_4_BUDEW
        },
    },

    [SPECIES_ROSERADE] = {
        .baseHP        = 60,
        .baseAttack    = 70,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 125,
        .baseSpDefense = 105,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_POISON,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_POISON_POINT,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 204,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROSERADE,
            TM_LEARNSET_2_ROSERADE,
            TM_LEARNSET_3_ROSERADE,
            TM_LEARNSET_4_ROSERADE
        },
    },

    [SPECIES_CRANIDOS] = {
        .baseHP        = 67,
        .baseAttack    = 125,
        .baseDefense   = 40,
        .baseSpeed     = 58,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_MOLD_BREAKER,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 99,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CRANIDOS,
            TM_LEARNSET_2_CRANIDOS,
            TM_LEARNSET_3_CRANIDOS,
            TM_LEARNSET_4_CRANIDOS
        },
    },

    [SPECIES_RAMPARDOS] = {
        .baseHP        = 97,
        .baseAttack    = 165,
        .baseDefense   = 60,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_MOLD_BREAKER,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 199,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RAMPARDOS,
            TM_LEARNSET_2_RAMPARDOS,
            TM_LEARNSET_3_RAMPARDOS,
            TM_LEARNSET_4_RAMPARDOS
        },
    },

    [SPECIES_SHIELDON] = {
        .baseHP        = 30,
        .baseAttack    = 42,
        .baseDefense   = 118,
        .baseSpeed     = 30,
        .baseSpAttack  = 42,
        .baseSpDefense = 88,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 99,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHIELDON,
            TM_LEARNSET_2_SHIELDON,
            TM_LEARNSET_3_SHIELDON,
            TM_LEARNSET_4_SHIELDON
        },
    },

    [SPECIES_BASTIODON] = {
        .baseHP        = 60,
        .baseAttack    = 52,
        .baseDefense   = 168,
        .baseSpeed     = 30,
        .baseSpAttack  = 47,
        .baseSpDefense = 138,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 199,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BASTIODON,
            TM_LEARNSET_2_BASTIODON,
            TM_LEARNSET_3_BASTIODON,
            TM_LEARNSET_4_BASTIODON
        },
    },

    [SPECIES_BURMY] = {
        .baseHP        = 40,
        .baseAttack    = 29,
        .baseDefense   = 45,
        .baseSpeed     = 36,
        .baseSpAttack  = 29,
        .baseSpDefense = 45,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_SHED_SKIN,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 61,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BURMY,
            TM_LEARNSET_2_BURMY,
            TM_LEARNSET_3_BURMY,
            TM_LEARNSET_4_BURMY
        },
    },

    [SPECIES_WORMADAM] = {
        .baseHP        = 60,
        .baseAttack    = 59,
        .baseDefense   = 85,
        .baseSpeed     = 36,
        .baseSpAttack  = 79,
        .baseSpDefense = 105,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_ANTICIPATION,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SILVER_POWDER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 159,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WORMADAM,
            TM_LEARNSET_2_WORMADAM,
            TM_LEARNSET_3_WORMADAM,
            TM_LEARNSET_4_WORMADAM
        },
    },

    [SPECIES_MOTHIM] = {
        .baseHP        = 70,
        .baseAttack    = 94,
        .baseDefense   = 50,
        .baseSpeed     = 66,
        .baseSpAttack  = 94,
        .baseSpDefense = 50,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SWARM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SILVER_POWDER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 159,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MOTHIM,
            TM_LEARNSET_2_MOTHIM,
            TM_LEARNSET_3_MOTHIM,
            TM_LEARNSET_4_MOTHIM
        },
    },

    [SPECIES_COMBEE] = {
        .baseHP        = 30,
        .baseAttack    = 30,
        .baseDefense   = 42,
        .baseSpeed     = 70,
        .baseSpAttack  = 30,
        .baseSpDefense = 42,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_HONEY_GATHER,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_HONEY,
        .itemRare     = ITEM_HONEY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 63,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_COMBEE,
            TM_LEARNSET_2_COMBEE,
            TM_LEARNSET_3_COMBEE,
            TM_LEARNSET_4_COMBEE
        },
    },

    [SPECIES_VESPIQUEN] = {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 102,
        .baseSpeed     = 40,
        .baseSpAttack  = 80,
        .baseSpDefense = 102,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 188,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_VESPIQUEN,
            TM_LEARNSET_2_VESPIQUEN,
            TM_LEARNSET_3_VESPIQUEN,
            TM_LEARNSET_4_VESPIQUEN
        },
    },

    [SPECIES_PACHIRISU] = {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_PICKUP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 100,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 120,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PACHIRISU,
            TM_LEARNSET_2_PACHIRISU,
            TM_LEARNSET_3_PACHIRISU,
            TM_LEARNSET_4_PACHIRISU
        },
    },

    [SPECIES_BUIZEL] = {
        .baseHP        = 55,
        .baseAttack    = 65,
        .baseDefense   = 35,
        .baseSpeed     = 85,
        .baseSpAttack  = 60,
        .baseSpDefense = 30,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_WACAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 75,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BUIZEL,
            TM_LEARNSET_2_BUIZEL,
            TM_LEARNSET_3_BUIZEL,
            TM_LEARNSET_4_BUIZEL
        },
    },

    [SPECIES_FLOATZEL] = {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 55,
        .baseSpeed     = 115,
        .baseSpAttack  = 85,
        .baseSpDefense = 50,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_WACAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 178,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FLOATZEL,
            TM_LEARNSET_2_FLOATZEL,
            TM_LEARNSET_3_FLOATZEL,
            TM_LEARNSET_4_FLOATZEL
        },
    },

    [SPECIES_CHERUBI] = {
        .baseHP        = 45,
        .baseAttack    = 35,
        .baseDefense   = 45,
        .baseSpeed     = 35,
        .baseSpAttack  = 62,
        .baseSpDefense = 53,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_MIRACLE_SEED,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 68,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHERUBI,
            TM_LEARNSET_2_CHERUBI,
            TM_LEARNSET_3_CHERUBI,
            TM_LEARNSET_4_CHERUBI
        },
    },

    [SPECIES_CHERRIM] = {
        .baseHP        = 70,
        .baseAttack    = 60,
        .baseDefense   = 70,
        .baseSpeed     = 85,
        .baseSpAttack  = 87,
        .baseSpDefense = 78,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_FLOWER_GIFT,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_MIRACLE_SEED,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 133,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHERRIM,
            TM_LEARNSET_2_CHERRIM,
            TM_LEARNSET_3_CHERRIM,
            TM_LEARNSET_4_CHERRIM
        },
    },

    [SPECIES_SHELLOS] = {
        .baseHP        = 76,
        .baseAttack    = 48,
        .baseDefense   = 48,
        .baseSpeed     = 34,
        .baseSpAttack  = 57,
        .baseSpDefense = 62,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_STICKY_HOLD,
        .ability2 = ABILITY_STORM_DRAIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 73,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHELLOS,
            TM_LEARNSET_2_SHELLOS,
            TM_LEARNSET_3_SHELLOS,
            TM_LEARNSET_4_SHELLOS
        },
    },

    [SPECIES_GASTRODON] = {
        .baseHP        = 111,
        .baseAttack    = 83,
        .baseDefense   = 68,
        .baseSpeed     = 39,
        .baseSpAttack  = 92,
        .baseSpDefense = 82,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_STICKY_HOLD,
        .ability2 = ABILITY_STORM_DRAIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 176,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GASTRODON,
            TM_LEARNSET_2_GASTRODON,
            TM_LEARNSET_3_GASTRODON,
            TM_LEARNSET_4_GASTRODON
        },
    },

    [SPECIES_AMBIPOM] = {
        .baseHP        = 75,
        .baseAttack    = 100,
        .baseDefense   = 66,
        .baseSpeed     = 115,
        .baseSpAttack  = 60,
        .baseSpDefense = 66,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_TECHNICIAN,
        .ability2 = ABILITY_PICKUP,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 100,
        .expCurve = GROWTH_FAST,
        .expYield = 186,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AMBIPOM,
            TM_LEARNSET_2_AMBIPOM,
            TM_LEARNSET_3_AMBIPOM,
            TM_LEARNSET_4_AMBIPOM
        },
    },

    [SPECIES_DRIFLOON] = {
        .baseHP        = 90,
        .baseAttack    = 50,
        .baseDefense   = 34,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 44,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_AFTERMATH,
        .ability2 = ABILITY_UNBURDEN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 125,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 127,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DRIFLOON,
            TM_LEARNSET_2_DRIFLOON,
            TM_LEARNSET_3_DRIFLOON,
            TM_LEARNSET_4_DRIFLOON
        },
    },

    [SPECIES_DRIFBLIM] = {
        .baseHP        = 150,
        .baseAttack    = 80,
        .baseDefense   = 44,
        .baseSpeed     = 80,
        .baseSpAttack  = 90,
        .baseSpDefense = 54,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_AFTERMATH,
        .ability2 = ABILITY_UNBURDEN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FLUCTUATING,
        .expYield = 204,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DRIFBLIM,
            TM_LEARNSET_2_DRIFBLIM,
            TM_LEARNSET_3_DRIFBLIM,
            TM_LEARNSET_4_DRIFBLIM
        },
    },

    [SPECIES_BUNEARY] = {
        .baseHP        = 55,
        .baseAttack    = 66,
        .baseDefense   = 44,
        .baseSpeed     = 85,
        .baseSpAttack  = 44,
        .baseSpDefense = 56,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_RUN_AWAY,
        .ability2 = ABILITY_KLUTZ,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHOPLE_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 0,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 84,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BUNEARY,
            TM_LEARNSET_2_BUNEARY,
            TM_LEARNSET_3_BUNEARY,
            TM_LEARNSET_4_BUNEARY
        },
    },

    [SPECIES_LOPUNNY] = {
        .baseHP        = 65,
        .baseAttack    = 76,
        .baseDefense   = 84,
        .baseSpeed     = 105,
        .baseSpAttack  = 54,
        .baseSpDefense = 96,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_CUTE_CHARM,
        .ability2 = ABILITY_KLUTZ,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHOPLE_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 140,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 178,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LOPUNNY,
            TM_LEARNSET_2_LOPUNNY,
            TM_LEARNSET_3_LOPUNNY,
            TM_LEARNSET_4_LOPUNNY
        },
    },

    [SPECIES_MISMAGIUS] = {
        .baseHP        = 60,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 105,
        .baseSpAttack  = 105,
        .baseSpDefense = 105,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_FAST,
        .expYield = 187,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MISMAGIUS,
            TM_LEARNSET_2_MISMAGIUS,
            TM_LEARNSET_3_MISMAGIUS,
            TM_LEARNSET_4_MISMAGIUS
        },
    },

    [SPECIES_HONCHKROW] = {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 52,
        .baseSpeed     = 71,
        .baseSpAttack  = 105,
        .baseSpDefense = 52,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_INSOMNIA,
        .ability2 = ABILITY_SUPER_LUCK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 187,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HONCHKROW,
            TM_LEARNSET_2_HONCHKROW,
            TM_LEARNSET_3_HONCHKROW,
            TM_LEARNSET_4_HONCHKROW
        },
    },

    [SPECIES_GLAMEOW] = {
        .baseHP        = 49,
        .baseAttack    = 55,
        .baseDefense   = 42,
        .baseSpeed     = 85,
        .baseSpAttack  = 42,
        .baseSpDefense = 37,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_LIMBER,
        .ability2 = ABILITY_OWN_TEMPO,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHERI_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 71,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GLAMEOW,
            TM_LEARNSET_2_GLAMEOW,
            TM_LEARNSET_3_GLAMEOW,
            TM_LEARNSET_4_GLAMEOW
        },
    },

    [SPECIES_PURUGLY] = {
        .baseHP        = 71,
        .baseAttack    = 82,
        .baseDefense   = 64,
        .baseSpeed     = 112,
        .baseSpAttack  = 64,
        .baseSpDefense = 59,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_THICK_FAT,
        .ability2 = ABILITY_OWN_TEMPO,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_CHERI_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 191,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 183,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PURUGLY,
            TM_LEARNSET_2_PURUGLY,
            TM_LEARNSET_3_PURUGLY,
            TM_LEARNSET_4_PURUGLY
        },
    },

    [SPECIES_CHINGLING] = {
        .baseHP        = 45,
        .baseAttack    = 30,
        .baseDefense   = 50,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_COLBUR_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 74,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHINGLING,
            TM_LEARNSET_2_CHINGLING,
            TM_LEARNSET_3_CHINGLING,
            TM_LEARNSET_4_CHINGLING
        },
    },

    [SPECIES_STUNKY] = {
        .baseHP        = 63,
        .baseAttack    = 63,
        .baseDefense   = 47,
        .baseSpeed     = 74,
        .baseSpAttack  = 41,
        .baseSpDefense = 41,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_STENCH,
        .ability2 = ABILITY_AFTERMATH,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PECHA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 225,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 79,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_STUNKY,
            TM_LEARNSET_2_STUNKY,
            TM_LEARNSET_3_STUNKY,
            TM_LEARNSET_4_STUNKY
        },
    },

    [SPECIES_SKUNTANK] = {
        .baseHP        = 103,
        .baseAttack    = 93,
        .baseDefense   = 67,
        .baseSpeed     = 84,
        .baseSpAttack  = 71,
        .baseSpDefense = 61,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_STENCH,
        .ability2 = ABILITY_AFTERMATH,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_PECHA_BERRY,

        .evYieldHP        = 2,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 209,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SKUNTANK,
            TM_LEARNSET_2_SKUNTANK,
            TM_LEARNSET_3_SKUNTANK,
            TM_LEARNSET_4_SKUNTANK
        },
    },

    [SPECIES_BRONZOR] = {
        .baseHP        = 57,
        .baseAttack    = 24,
        .baseDefense   = 86,
        .baseSpeed     = 23,
        .baseSpAttack  = 24,
        .baseSpDefense = 86,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_HEATPROOF,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 72,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BRONZOR,
            TM_LEARNSET_2_BRONZOR,
            TM_LEARNSET_3_BRONZOR,
            TM_LEARNSET_4_BRONZOR
        },
    },

    [SPECIES_BRONZONG] = {
        .baseHP        = 67,
        .baseAttack    = 89,
        .baseDefense   = 116,
        .baseSpeed     = 33,
        .baseSpAttack  = 79,
        .baseSpDefense = 116,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_HEATPROOF,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 90,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 188,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BRONZONG,
            TM_LEARNSET_2_BRONZONG,
            TM_LEARNSET_3_BRONZONG,
            TM_LEARNSET_4_BRONZONG
        },
    },

    [SPECIES_BONSLY] = {
        .baseHP        = 50,
        .baseAttack    = 80,
        .baseDefense   = 95,
        .baseSpeed     = 10,
        .baseSpAttack  = 10,
        .baseSpDefense = 45,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_ROCK_HEAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 255,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 68,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BONSLY,
            TM_LEARNSET_2_BONSLY,
            TM_LEARNSET_3_BONSLY,
            TM_LEARNSET_4_BONSLY
        },
    },

    [SPECIES_MIME_JR] = {
        .baseHP        = 20,
        .baseAttack    = 25,
        .baseDefense   = 45,
        .baseSpeed     = 60,
        .baseSpAttack  = 70,
        .baseSpDefense = 90,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_SOUNDPROOF,
        .ability2 = ABILITY_FILTER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_LEPPA_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 145,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 78,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MIME_JR,
            TM_LEARNSET_2_MIME_JR,
            TM_LEARNSET_3_MIME_JR,
            TM_LEARNSET_4_MIME_JR
        },
    },

    [SPECIES_HAPPINY] = {
        .baseHP        = 100,
        .baseAttack    = 5,
        .baseDefense   = 5,
        .baseSpeed     = 30,
        .baseSpAttack  = 15,
        .baseSpDefense = 65,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_SERENE_GRACE,

        .itemUncommon = ITEM_OVAL_STONE,
        .itemRare     = ITEM_LUCKY_PUNCH,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 130,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 140,
        .expCurve = GROWTH_FAST,
        .expYield = 255,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HAPPINY,
            TM_LEARNSET_2_HAPPINY,
            TM_LEARNSET_3_HAPPINY,
            TM_LEARNSET_4_HAPPINY
        },
    },

    [SPECIES_CHATOT] = {
        .baseHP        = 76,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 91,
        .baseSpAttack  = 92,
        .baseSpDefense = 42,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_KEEN_EYE,
        .ability2 = ABILITY_TANGLED_FEET,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METRONOME,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 107,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FLYING,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CHATOT,
            TM_LEARNSET_2_CHATOT,
            TM_LEARNSET_3_CHATOT,
            TM_LEARNSET_4_CHATOT
        },
    },

    [SPECIES_SPIRITOMB] = {
        .baseHP        = 50,
        .baseAttack    = 92,
        .baseDefense   = 108,
        .baseSpeed     = 35,
        .baseSpAttack  = 92,
        .baseSpDefense = 108,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 100,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 168,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SPIRITOMB,
            TM_LEARNSET_2_SPIRITOMB,
            TM_LEARNSET_3_SPIRITOMB,
            TM_LEARNSET_4_SPIRITOMB
        },
    },

    [SPECIES_GIBLE] = {
        .baseHP        = 58,
        .baseAttack    = 70,
        .baseDefense   = 45,
        .baseSpeed     = 42,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HABAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 67,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GIBLE,
            TM_LEARNSET_2_GIBLE,
            TM_LEARNSET_3_GIBLE,
            TM_LEARNSET_4_GIBLE
        },
    },

    [SPECIES_GABITE] = {
        .baseHP        = 68,
        .baseAttack    = 90,
        .baseDefense   = 65,
        .baseSpeed     = 82,
        .baseSpAttack  = 50,
        .baseSpDefense = 55,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HABAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 144,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GABITE,
            TM_LEARNSET_2_GABITE,
            TM_LEARNSET_3_GABITE,
            TM_LEARNSET_4_GABITE
        },
    },

    [SPECIES_GARCHOMP] = {
        .baseHP        = 108,
        .baseAttack    = 130,
        .baseDefense   = 95,
        .baseSpeed     = 102,
        .baseSpAttack  = 80,
        .baseSpDefense = 85,
        
        .type1 = TYPE_DRAGON,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_VEIL,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HABAN_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 218,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_DRAGON,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GARCHOMP,
            TM_LEARNSET_2_GARCHOMP,
            TM_LEARNSET_3_GARCHOMP,
            TM_LEARNSET_4_GARCHOMP
        },
    },

    [SPECIES_MUNCHLAX] = {
        .baseHP        = 135,
        .baseAttack    = 85,
        .baseDefense   = 40,
        .baseSpeed     = 5,
        .baseSpAttack  = 40,
        .baseSpDefense = 85,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_PICKUP,
        .ability2 = ABILITY_THICK_FAT,

        .itemUncommon = ITEM_LEFTOVERS,
        .itemRare     = ITEM_LEFTOVERS,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 50,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 94,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MUNCHLAX,
            TM_LEARNSET_2_MUNCHLAX,
            TM_LEARNSET_3_MUNCHLAX,
            TM_LEARNSET_4_MUNCHLAX
        },
    },

    [SPECIES_RIOLU] = {
        .baseHP        = 40,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 40,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_STEADFAST,
        .ability2 = ABILITY_INNER_FOCUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 72,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RIOLU,
            TM_LEARNSET_2_RIOLU,
            TM_LEARNSET_3_RIOLU,
            TM_LEARNSET_4_RIOLU
        },
    },

    [SPECIES_LUCARIO] = {
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 115,
        .baseSpDefense = 70,
        
        .type1 = TYPE_FIGHTING,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_STEADFAST,
        .ability2 = ABILITY_INNER_FOCUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 204,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUCARIO,
            TM_LEARNSET_2_LUCARIO,
            TM_LEARNSET_3_LUCARIO,
            TM_LEARNSET_4_LUCARIO
        },
    },

    [SPECIES_HIPPOPOTAS] = {
        .baseHP        = 68,
        .baseAttack    = 72,
        .baseDefense   = 78,
        .baseSpeed     = 32,
        .baseSpAttack  = 38,
        .baseSpDefense = 42,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_STREAM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 140,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 95,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HIPPOPOTAS,
            TM_LEARNSET_2_HIPPOPOTAS,
            TM_LEARNSET_3_HIPPOPOTAS,
            TM_LEARNSET_4_HIPPOPOTAS
        },
    },

    [SPECIES_HIPPOWDON] = {
        .baseHP        = 108,
        .baseAttack    = 112,
        .baseDefense   = 118,
        .baseSpeed     = 47,
        .baseSpAttack  = 68,
        .baseSpDefense = 72,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_SAND_STREAM,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 198,
        .eggCycles = 30,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HIPPOWDON,
            TM_LEARNSET_2_HIPPOWDON,
            TM_LEARNSET_3_HIPPOWDON,
            TM_LEARNSET_4_HIPPOWDON
        },
    },

    [SPECIES_SKORUPI] = {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 90,
        .baseSpeed     = 65,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_BUG,

        .ability1 = ABILITY_BATTLE_ARMOR,
        .ability2 = ABILITY_SNIPER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 114,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SKORUPI,
            TM_LEARNSET_2_SKORUPI,
            TM_LEARNSET_3_SKORUPI,
            TM_LEARNSET_4_SKORUPI
        },
    },

    [SPECIES_DRAPION] = {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 110,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_BATTLE_ARMOR,
        .ability2 = ABILITY_SNIPER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_POISON_BARB,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 204,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_WATER_3,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DRAPION,
            TM_LEARNSET_2_DRAPION,
            TM_LEARNSET_3_DRAPION,
            TM_LEARNSET_4_DRAPION
        },
    },

    [SPECIES_CROAGUNK] = {
        .baseHP        = 48,
        .baseAttack    = 61,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 61,
        .baseSpDefense = 40,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_ANTICIPATION,
        .ability2 = ABILITY_DRY_SKIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BLACK_SLUDGE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 140,
        .fleeRate = 150,
        .genderRatio = 127,
        .baseFriendship = 100,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 83,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CROAGUNK,
            TM_LEARNSET_2_CROAGUNK,
            TM_LEARNSET_3_CROAGUNK,
            TM_LEARNSET_4_CROAGUNK
        },
    },

    [SPECIES_TOXICROAK] = {
        .baseHP        = 83,
        .baseAttack    = 106,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 86,
        .baseSpDefense = 65,
        
        .type1 = TYPE_POISON,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_ANTICIPATION,
        .ability2 = ABILITY_DRY_SKIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BLACK_SLUDGE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 120,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 181,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TOXICROAK,
            TM_LEARNSET_2_TOXICROAK,
            TM_LEARNSET_3_TOXICROAK,
            TM_LEARNSET_4_TOXICROAK
        },
    },

    [SPECIES_CARNIVINE] = {
        .baseHP        = 74,
        .baseAttack    = 100,
        .baseDefense   = 72,
        .baseSpeed     = 46,
        .baseSpAttack  = 90,
        .baseSpDefense = 72,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 200,
        .fleeRate = 60,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 164,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CARNIVINE,
            TM_LEARNSET_2_CARNIVINE,
            TM_LEARNSET_3_CARNIVINE,
            TM_LEARNSET_4_CARNIVINE
        },
    },

    [SPECIES_FINNEON] = {
        .baseHP        = 49,
        .baseAttack    = 49,
        .baseDefense   = 56,
        .baseSpeed     = 66,
        .baseSpAttack  = 49,
        .baseSpDefense = 61,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_STORM_DRAIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_RINDO_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 190,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 90,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FINNEON,
            TM_LEARNSET_2_FINNEON,
            TM_LEARNSET_3_FINNEON,
            TM_LEARNSET_4_FINNEON
        },
    },

    [SPECIES_LUMINEON] = {
        .baseHP        = 69,
        .baseAttack    = 69,
        .baseDefense   = 76,
        .baseSpeed     = 91,
        .baseSpAttack  = 69,
        .baseSpDefense = 86,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_STORM_DRAIN,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_RINDO_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_ERRATIC,
        .expYield = 156,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_WATER_2,
        .eggGroup2 = EGG_GROUP_WATER_2,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LUMINEON,
            TM_LEARNSET_2_LUMINEON,
            TM_LEARNSET_3_LUMINEON,
            TM_LEARNSET_4_LUMINEON
        },
    },

    [SPECIES_MANTYKE] = {
        .baseHP        = 45,
        .baseAttack    = 20,
        .baseDefense   = 50,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 120,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SWIFT_SWIM,
        .ability2 = ABILITY_WATER_ABSORB,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 25,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 108,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MANTYKE,
            TM_LEARNSET_2_MANTYKE,
            TM_LEARNSET_3_MANTYKE,
            TM_LEARNSET_4_MANTYKE
        },
    },

    [SPECIES_SNOVER] = {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 62,
        .baseSpDefense = 60,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_SNOW_WARNING,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NEVER_MELT_ICE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 120,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 131,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SNOVER,
            TM_LEARNSET_2_SNOVER,
            TM_LEARNSET_3_SNOVER,
            TM_LEARNSET_4_SNOVER
        },
    },

    [SPECIES_ABOMASNOW] = {
        .baseHP        = 90,
        .baseAttack    = 92,
        .baseDefense   = 75,
        .baseSpeed     = 60,
        .baseSpAttack  = 92,
        .baseSpDefense = 85,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_SNOW_WARNING,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NEVER_MELT_ICE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 214,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ABOMASNOW,
            TM_LEARNSET_2_ABOMASNOW,
            TM_LEARNSET_3_ABOMASNOW,
            TM_LEARNSET_4_ABOMASNOW
        },
    },

    [SPECIES_WEAVILE] = {
        .baseHP        = 70,
        .baseAttack    = 120,
        .baseDefense   = 65,
        .baseSpeed     = 125,
        .baseSpAttack  = 45,
        .baseSpDefense = 85,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_PRESSURE,

        .itemUncommon = ITEM_GRIP_CLAW,
        .itemRare     = ITEM_QUICK_CLAW,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 199,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WEAVILE,
            TM_LEARNSET_2_WEAVILE,
            TM_LEARNSET_3_WEAVILE,
            TM_LEARNSET_4_WEAVILE
        },
    },

    [SPECIES_MAGNEZONE] = {
        .baseHP        = 70,
        .baseAttack    = 70,
        .baseDefense   = 115,
        .baseSpeed     = 60,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_MAGNET_PULL,
        .ability2 = ABILITY_STURDY,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_METAL_COAT,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 211,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGNEZONE,
            TM_LEARNSET_2_MAGNEZONE,
            TM_LEARNSET_3_MAGNEZONE,
            TM_LEARNSET_4_MAGNEZONE
        },
    },

    [SPECIES_LICKILICKY] = {
        .baseHP        = 110,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 50,
        .baseSpAttack  = 80,
        .baseSpDefense = 95,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_OWN_TEMPO,
        .ability2 = ABILITY_OBLIVIOUS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_LAGGING_TAIL,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 193,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_MONSTER,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LICKILICKY,
            TM_LEARNSET_2_LICKILICKY,
            TM_LEARNSET_3_LICKILICKY,
            TM_LEARNSET_4_LICKILICKY
        },
    },

    [SPECIES_RHYPERIOR] = {
        .baseHP        = 115,
        .baseAttack    = 140,
        .baseDefense   = 130,
        .baseSpeed     = 40,
        .baseSpAttack  = 55,
        .baseSpDefense = 55,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_ROCK,

        .ability1 = ABILITY_LIGHTNING_ROD,
        .ability2 = ABILITY_FILTER,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 217,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MONSTER,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_RHYPERIOR,
            TM_LEARNSET_2_RHYPERIOR,
            TM_LEARNSET_3_RHYPERIOR,
            TM_LEARNSET_4_RHYPERIOR
        },
    },

    [SPECIES_TANGROWTH] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 125,
        .baseSpeed     = 50,
        .baseSpAttack  = 110,
        .baseSpDefense = 50,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_CHLOROPHYLL,
        .ability2 = ABILITY_LEAF_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 211,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_GRASS,
        .eggGroup2 = EGG_GROUP_GRASS,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_TANGROWTH,
            TM_LEARNSET_2_TANGROWTH,
            TM_LEARNSET_3_TANGROWTH,
            TM_LEARNSET_4_TANGROWTH
        },
    },

    [SPECIES_ELECTIVIRE] = {
        .baseHP        = 75,
        .baseAttack    = 123,
        .baseDefense   = 67,
        .baseSpeed     = 95,
        .baseSpAttack  = 95,
        .baseSpDefense = 85,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_ELECTRIC,

        .ability1 = ABILITY_MOTOR_DRIVE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_ELECTIRIZER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 199,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ELECTIVIRE,
            TM_LEARNSET_2_ELECTIVIRE,
            TM_LEARNSET_3_ELECTIVIRE,
            TM_LEARNSET_4_ELECTIVIRE
        },
    },

    [SPECIES_MAGMORTAR] = {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 67,
        .baseSpeed     = 83,
        .baseSpAttack  = 125,
        .baseSpDefense = 95,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_FIRE,

        .ability1 = ABILITY_FLAME_BODY,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_MAGMARIZER,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 63,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 199,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_HUMAN_LIKE,
        .eggGroup2 = EGG_GROUP_HUMAN_LIKE,
        .bodyColor = BODY_COLOR_RED,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAGMORTAR,
            TM_LEARNSET_2_MAGMORTAR,
            TM_LEARNSET_3_MAGMORTAR,
            TM_LEARNSET_4_MAGMORTAR
        },
    },

    [SPECIES_TOGEKISS] = {
        .baseHP        = 85,
        .baseAttack    = 50,
        .baseDefense   = 95,
        .baseSpeed     = 80,
        .baseSpAttack  = 120,
        .baseSpDefense = 115,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_HUSTLE,
        .ability2 = ABILITY_SERENE_GRACE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 1,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 70,
        .expCurve = GROWTH_FAST,
        .expYield = 220,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_FLYING,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_TOGEKISS,
            TM_LEARNSET_2_TOGEKISS,
            TM_LEARNSET_3_TOGEKISS,
            TM_LEARNSET_4_TOGEKISS
        },
    },

    [SPECIES_YANMEGA] = {
        .baseHP        = 86,
        .baseAttack    = 76,
        .baseDefense   = 86,
        .baseSpeed     = 95,
        .baseSpAttack  = 116,
        .baseSpDefense = 56,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SPEED_BOOST,
        .ability2 = ABILITY_TINTED_LENS,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_WIDE_LENS,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 198,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_YANMEGA,
            TM_LEARNSET_2_YANMEGA,
            TM_LEARNSET_3_YANMEGA,
            TM_LEARNSET_4_YANMEGA
        },
    },

    [SPECIES_LEAFEON] = {
        .baseHP        = 65,
        .baseAttack    = 110,
        .baseDefense   = 130,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 65,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_LEAF_GUARD,
        .ability2 = ABILITY_LEAF_GUARD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 196,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_LEAFEON,
            TM_LEARNSET_2_LEAFEON,
            TM_LEARNSET_3_LEAFEON,
            TM_LEARNSET_4_LEAFEON
        },
    },

    [SPECIES_GLACEON] = {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 110,
        .baseSpeed     = 65,
        .baseSpAttack  = 130,
        .baseSpDefense = 95,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_ICE,

        .ability1 = ABILITY_SNOW_CLOAK,
        .ability2 = ABILITY_SNOW_CLOAK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 31,
        .baseFriendship = 35,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 196,
        .eggCycles = 35,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GLACEON,
            TM_LEARNSET_2_GLACEON,
            TM_LEARNSET_3_GLACEON,
            TM_LEARNSET_4_GLACEON
        },
    },

    [SPECIES_GLISCOR] = {
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 125,
        .baseSpeed     = 95,
        .baseSpAttack  = 45,
        .baseSpDefense = 75,
        
        .type1 = TYPE_GROUND,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_HYPER_CUTTER,
        .ability2 = ABILITY_SAND_VEIL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 192,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GLISCOR,
            TM_LEARNSET_2_GLISCOR,
            TM_LEARNSET_3_GLISCOR,
            TM_LEARNSET_4_GLISCOR
        },
    },

    [SPECIES_MAMOSWINE] = {
        .baseHP        = 110,
        .baseAttack    = 130,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 70,
        .baseSpDefense = 60,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_OBLIVIOUS,
        .ability2 = ABILITY_SNOW_CLOAK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 50,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 207,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FIELD,
        .eggGroup2 = EGG_GROUP_FIELD,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MAMOSWINE,
            TM_LEARNSET_2_MAMOSWINE,
            TM_LEARNSET_3_MAMOSWINE,
            TM_LEARNSET_4_MAMOSWINE
        },
    },

    [SPECIES_PORYGON_Z] = {
        .baseHP        = 85,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 135,
        .baseSpDefense = 75,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_ADAPTABILITY,
        .ability2 = ABILITY_DOWNLOAD,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 185,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PORYGON_Z,
            TM_LEARNSET_2_PORYGON_Z,
            TM_LEARNSET_3_PORYGON_Z,
            TM_LEARNSET_4_PORYGON_Z
        },
    },

    [SPECIES_GALLADE] = {
        .baseHP        = 68,
        .baseAttack    = 125,
        .baseDefense   = 65,
        .baseSpeed     = 80,
        .baseSpAttack  = 65,
        .baseSpDefense = 115,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_FIGHTING,

        .ability1 = ABILITY_STEADFAST,
        .ability2 = ABILITY_STEADFAST,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 0,
        .baseFriendship = 35,
        .expCurve = GROWTH_SLOW,
        .expYield = 208,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GALLADE,
            TM_LEARNSET_2_GALLADE,
            TM_LEARNSET_3_GALLADE,
            TM_LEARNSET_4_GALLADE
        },
    },

    [SPECIES_PROBOPASS] = {
        .baseHP        = 60,
        .baseAttack    = 55,
        .baseDefense   = 145,
        .baseSpeed     = 40,
        .baseSpAttack  = 75,
        .baseSpDefense = 150,
        
        .type1 = TYPE_ROCK,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_STURDY,
        .ability2 = ABILITY_MAGNET_PULL,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_HARD_STONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 60,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 198,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_MINERAL,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PROBOPASS,
            TM_LEARNSET_2_PROBOPASS,
            TM_LEARNSET_3_PROBOPASS,
            TM_LEARNSET_4_PROBOPASS
        },
    },

    [SPECIES_DUSKNOIR] = {
        .baseHP        = 45,
        .baseAttack    = 100,
        .baseDefense   = 135,
        .baseSpeed     = 45,
        .baseSpAttack  = 65,
        .baseSpDefense = 135,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_KASIB_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 2,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 35,
        .expCurve = GROWTH_FAST,
        .expYield = 210,
        .eggCycles = 25,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DUSKNOIR,
            TM_LEARNSET_2_DUSKNOIR,
            TM_LEARNSET_3_DUSKNOIR,
            TM_LEARNSET_4_DUSKNOIR
        },
    },

    [SPECIES_FROSLASS] = {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 110,
        .baseSpAttack  = 80,
        .baseSpDefense = 70,
        
        .type1 = TYPE_ICE,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_SNOW_CLOAK,
        .ability2 = ABILITY_SNOW_CLOAK,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_BABIRI_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 2,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 75,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 187,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_FAIRY,
        .eggGroup2 = EGG_GROUP_MINERAL,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_FROSLASS,
            TM_LEARNSET_2_FROSLASS,
            TM_LEARNSET_3_FROSLASS,
            TM_LEARNSET_4_FROSLASS
        },
    },

    [SPECIES_ROTOM] = {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 77,
        .baseSpeed     = 91,
        .baseSpAttack  = 95,
        .baseSpDefense = 77,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROTOM,
            TM_LEARNSET_2_ROTOM,
            TM_LEARNSET_3_ROTOM,
            TM_LEARNSET_4_ROTOM
        },
    },

    [SPECIES_UXIE] = {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 130,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 130,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 140,
        .expCurve = GROWTH_SLOW,
        .expYield = 210,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_UXIE,
            TM_LEARNSET_2_UXIE,
            TM_LEARNSET_3_UXIE,
            TM_LEARNSET_4_UXIE
        },
    },

    [SPECIES_MESPRIT] = {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = 105,
        .baseSpDefense = 105,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 1,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 1,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 140,
        .expCurve = GROWTH_SLOW,
        .expYield = 210,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PINK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MESPRIT,
            TM_LEARNSET_2_MESPRIT,
            TM_LEARNSET_3_MESPRIT,
            TM_LEARNSET_4_MESPRIT
        },
    },

    [SPECIES_AZELF] = {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 70,
        .baseSpeed     = 115,
        .baseSpAttack  = 125,
        .baseSpDefense = 70,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 140,
        .expCurve = GROWTH_SLOW,
        .expYield = 210,
        .eggCycles = 80,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_AZELF,
            TM_LEARNSET_2_AZELF,
            TM_LEARNSET_3_AZELF,
            TM_LEARNSET_4_AZELF
        },
    },

    [SPECIES_DIALGA] = {
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 100,
        
        .type1 = TYPE_STEEL,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DIALGA,
            TM_LEARNSET_2_DIALGA,
            TM_LEARNSET_3_DIALGA,
            TM_LEARNSET_4_DIALGA
        },
    },

    [SPECIES_PALKIA] = {
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_PURPLE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PALKIA,
            TM_LEARNSET_2_PALKIA,
            TM_LEARNSET_3_PALKIA,
            TM_LEARNSET_4_PALKIA
        },
    },

    [SPECIES_HEATRAN] = {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 106,
        .baseSpeed     = 77,
        .baseSpAttack  = 130,
        .baseSpDefense = 106,
        
        .type1 = TYPE_FIRE,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_FLASH_FIRE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 3,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 127,
        .baseFriendship = 100,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BROWN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_HEATRAN,
            TM_LEARNSET_2_HEATRAN,
            TM_LEARNSET_3_HEATRAN,
            TM_LEARNSET_4_HEATRAN
        },
    },

    [SPECIES_REGIGIGAS] = {
        .baseHP        = 110,
        .baseAttack    = 160,
        .baseDefense   = 110,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 110,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_SLOW_START,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 3,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_WHITE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_REGIGIGAS,
            TM_LEARNSET_2_REGIGIGAS,
            TM_LEARNSET_3_REGIGIGAS,
            TM_LEARNSET_4_REGIGIGAS
        },
    },

    [SPECIES_GIRATINA] = {
        .baseHP        = 150,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 120,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GIRATINA,
            TM_LEARNSET_2_GIRATINA,
            TM_LEARNSET_3_GIRATINA,
            TM_LEARNSET_4_GIRATINA
        },
    },

    [SPECIES_CRESSELIA] = {
        .baseHP        = 120,
        .baseAttack    = 70,
        .baseDefense   = 120,
        .baseSpeed     = 85,
        .baseSpAttack  = 75,
        .baseSpDefense = 130,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 3,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 100,
        .expCurve = GROWTH_SLOW,
        .expYield = 210,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_YELLOW,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_CRESSELIA,
            TM_LEARNSET_2_CRESSELIA,
            TM_LEARNSET_3_CRESSELIA,
            TM_LEARNSET_4_CRESSELIA
        },
    },

    [SPECIES_PHIONE] = {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_HYDRATION,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 1,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 30,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 165,
        .eggCycles = 40,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_PHIONE,
            TM_LEARNSET_2_PHIONE,
            TM_LEARNSET_3_PHIONE,
            TM_LEARNSET_4_PHIONE
        },
    },

    [SPECIES_MANAPHY] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        
        .type1 = TYPE_WATER,
        .type2 = TYPE_WATER,

        .ability1 = ABILITY_HYDRATION,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 10,
        .eggGroup1 = EGG_GROUP_WATER_1,
        .eggGroup2 = EGG_GROUP_FAIRY,
        .bodyColor = BODY_COLOR_BLUE,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_MANAPHY,
            TM_LEARNSET_2_MANAPHY,
            TM_LEARNSET_3_MANAPHY,
            TM_LEARNSET_4_MANAPHY
        },
    },

    [SPECIES_DARKRAI] = {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 90,
        .baseSpeed     = 125,
        .baseSpAttack  = 135,
        .baseSpDefense = 90,
        
        .type1 = TYPE_DARK,
        .type2 = TYPE_DARK,

        .ability1 = ABILITY_BAD_DREAMS,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 2,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 210,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DARKRAI,
            TM_LEARNSET_2_DARKRAI,
            TM_LEARNSET_3_DARKRAI,
            TM_LEARNSET_4_DARKRAI
        },
    },

    [SPECIES_SHAYMIN] = {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_GRASS,

        .ability1 = ABILITY_NATURAL_CURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_LUM_BERRY,
        .itemRare     = ITEM_LUM_BERRY,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 100,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 64,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHAYMIN,
            TM_LEARNSET_2_SHAYMIN,
            TM_LEARNSET_3_SHAYMIN,
            TM_LEARNSET_4_SHAYMIN
        },
    },

    [SPECIES_ARCEUS] = {
        .baseHP        = 120,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 120,
        .baseSpAttack  = 120,
        .baseSpDefense = 120,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_MULTITYPE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 255,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ARCEUS,
            TM_LEARNSET_2_ARCEUS,
            TM_LEARNSET_3_ARCEUS,
            TM_LEARNSET_4_ARCEUS
        },
    },

    [SPECIES_EGG] = {
        .baseHP        = 10,
        .baseAttack    = 10,
        .baseDefense   = 10,
        .baseSpeed     = 10,
        .baseSpAttack  = 10,
        .baseSpDefense = 10,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_NONE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 255,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_EGG,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_EGG,
            TM_LEARNSET_2_EGG,
            TM_LEARNSET_3_EGG,
            TM_LEARNSET_4_EGG
        },
    },

    [SPECIES_BAD_EGG] = {
        .baseHP        = 10,
        .baseAttack    = 10,
        .baseDefense   = 10,
        .baseSpeed     = 10,
        .baseSpAttack  = 10,
        .baseSpDefense = 10,
        
        .type1 = TYPE_NORMAL,
        .type2 = TYPE_NORMAL,

        .ability1 = ABILITY_NONE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 255,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_EGG,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_BAD_EGG,
            TM_LEARNSET_2_BAD_EGG,
            TM_LEARNSET_3_BAD_EGG,
            TM_LEARNSET_4_BAD_EGG
        },
    },

    [SPECIES_DEOXYS_ATTACK] = {
        .baseHP        = 50,
        .baseAttack    = 180,
        .baseDefense   = 20,
        .baseSpeed     = 150,
        .baseSpAttack  = 180,
        .baseSpDefense = 20,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 2,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DEOXYS_ATTACK,
            TM_LEARNSET_2_DEOXYS_ATTACK,
            TM_LEARNSET_3_DEOXYS_ATTACK,
            TM_LEARNSET_4_DEOXYS_ATTACK
        },
    },

    [SPECIES_DEOXYS_DEFENSE] = {
        .baseHP        = 50,
        .baseAttack    = 70,
        .baseDefense   = 160,
        .baseSpeed     = 90,
        .baseSpAttack  = 70,
        .baseSpDefense = 160,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DEOXYS_DEFENSE,
            TM_LEARNSET_2_DEOXYS_DEFENSE,
            TM_LEARNSET_3_DEOXYS_DEFENSE,
            TM_LEARNSET_4_DEOXYS_DEFENSE
        },
    },

    [SPECIES_DEOXYS_SPEED] = {
        .baseHP        = 50,
        .baseAttack    = 95,
        .baseDefense   = 90,
        .baseSpeed     = 180,
        .baseSpAttack  = 95,
        .baseSpDefense = 90,
        
        .type1 = TYPE_PSYCHIC,
        .type2 = TYPE_PSYCHIC,

        .ability1 = ABILITY_PRESSURE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 3,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 215,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_DEOXYS_SPEED,
            TM_LEARNSET_2_DEOXYS_SPEED,
            TM_LEARNSET_3_DEOXYS_SPEED,
            TM_LEARNSET_4_DEOXYS_SPEED
        },
    },

    [SPECIES_WORMADAM_SANDY] = {
        .baseHP        = 60,
        .baseAttack    = 79,
        .baseDefense   = 105,
        .baseSpeed     = 36,
        .baseSpAttack  = 59,
        .baseSpDefense = 85,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_GROUND,

        .ability1 = ABILITY_ANTICIPATION,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SILVER_POWDER,

        .evYieldHP        = 0,
        .evYieldAttack    = 2,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 159,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WORMADAM_SANDY,
            TM_LEARNSET_2_WORMADAM_SANDY,
            TM_LEARNSET_3_WORMADAM_SANDY,
            TM_LEARNSET_4_WORMADAM_SANDY
        },
    },

    [SPECIES_WORMADAM_TRASH] = {
        .baseHP        = 60,
        .baseAttack    = 69,
        .baseDefense   = 95,
        .baseSpeed     = 36,
        .baseSpAttack  = 69,
        .baseSpDefense = 95,
        
        .type1 = TYPE_BUG,
        .type2 = TYPE_STEEL,

        .ability1 = ABILITY_ANTICIPATION,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_SILVER_POWDER,

        .evYieldHP        = 0,
        .evYieldAttack    = 1,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 1,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 254,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 159,
        .eggCycles = 15,
        .eggGroup1 = EGG_GROUP_BUG,
        .eggGroup2 = EGG_GROUP_BUG,
        .bodyColor = BODY_COLOR_GRAY,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_WORMADAM_TRASH,
            TM_LEARNSET_2_WORMADAM_TRASH,
            TM_LEARNSET_3_WORMADAM_TRASH,
            TM_LEARNSET_4_WORMADAM_TRASH
        },
    },

    [SPECIES_GIRATINA_ORIGIN] = {
        .baseHP        = 150,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 90,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        
        .type1 = TYPE_GHOST,
        .type2 = TYPE_DRAGON,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 3,
        .evYieldAttack    = 0,
        .evYieldDefense   = 0,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 3,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 0,
        .expCurve = GROWTH_SLOW,
        .expYield = 220,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_BLACK,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_GIRATINA_ORIGIN,
            TM_LEARNSET_2_GIRATINA_ORIGIN,
            TM_LEARNSET_3_GIRATINA_ORIGIN,
            TM_LEARNSET_4_GIRATINA_ORIGIN
        },
    },

    [SPECIES_SHAYMIN_SKY] = {
        .baseHP        = 100,
        .baseAttack    = 103,
        .baseDefense   = 75,
        .baseSpeed     = 127,
        .baseSpAttack  = 120,
        .baseSpDefense = 75,
        
        .type1 = TYPE_GRASS,
        .type2 = TYPE_FLYING,

        .ability1 = ABILITY_SERENE_GRACE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_LUM_BERRY,
        .itemRare     = ITEM_LUM_BERRY,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 3,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 0,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 100,
        .expCurve = GROWTH_MEDIUM_SLOW,
        .expYield = 64,
        .eggCycles = 120,
        .eggGroup1 = EGG_GROUP_UNDISCOVERED,
        .eggGroup2 = EGG_GROUP_UNDISCOVERED,
        .bodyColor = BODY_COLOR_GREEN,
        .reverse = TRUE,

        .tmLearnsets = {
            TM_LEARNSET_1_SHAYMIN_SKY,
            TM_LEARNSET_2_SHAYMIN_SKY,
            TM_LEARNSET_3_SHAYMIN_SKY,
            TM_LEARNSET_4_SHAYMIN_SKY
        },
    },

    [SPECIES_ROTOM_HEAT] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 107,
        .baseSpeed     = 86,
        .baseSpAttack  = 105,
        .baseSpDefense = 107,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROTOM_HEAT,
            TM_LEARNSET_2_ROTOM_HEAT,
            TM_LEARNSET_3_ROTOM_HEAT,
            TM_LEARNSET_4_ROTOM_HEAT
        },
    },

    [SPECIES_ROTOM_WASH] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 107,
        .baseSpeed     = 86,
        .baseSpAttack  = 105,
        .baseSpDefense = 107,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROTOM_WASH,
            TM_LEARNSET_2_ROTOM_WASH,
            TM_LEARNSET_3_ROTOM_WASH,
            TM_LEARNSET_4_ROTOM_WASH
        },
    },

    [SPECIES_ROTOM_FROST] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 107,
        .baseSpeed     = 86,
        .baseSpAttack  = 105,
        .baseSpDefense = 107,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROTOM_FROST,
            TM_LEARNSET_2_ROTOM_FROST,
            TM_LEARNSET_3_ROTOM_FROST,
            TM_LEARNSET_4_ROTOM_FROST
        },
    },

    [SPECIES_ROTOM_FAN] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 107,
        .baseSpeed     = 86,
        .baseSpAttack  = 105,
        .baseSpDefense = 107,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROTOM_FAN,
            TM_LEARNSET_2_ROTOM_FAN,
            TM_LEARNSET_3_ROTOM_FAN,
            TM_LEARNSET_4_ROTOM_FAN
        },
    },

    [SPECIES_ROTOM_MOW] = {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 107,
        .baseSpeed     = 86,
        .baseSpAttack  = 105,
        .baseSpDefense = 107,
        
        .type1 = TYPE_ELECTRIC,
        .type2 = TYPE_GHOST,

        .ability1 = ABILITY_LEVITATE,
        .ability2 = ABILITY_NONE,

        .itemUncommon = ITEM_NONE,
        .itemRare     = ITEM_NONE,

        .evYieldHP        = 0,
        .evYieldAttack    = 0,
        .evYieldDefense   = 1,
        .evYieldSpeed     = 0,
        .evYieldSpAttack  = 1,
        .evYieldSpDefense = 0,

        .catchRate = 45,
        .fleeRate = 0,
        .genderRatio = 255,
        .baseFriendship = 70,
        .expCurve = GROWTH_MEDIUM_FAST,
        .expYield = 132,
        .eggCycles = 20,
        .eggGroup1 = EGG_GROUP_AMORPHOUS,
        .eggGroup2 = EGG_GROUP_AMORPHOUS,
        .bodyColor = BODY_COLOR_RED,
        .reverse = FALSE,

        .tmLearnsets = {
            TM_LEARNSET_1_ROTOM_MOW,
            TM_LEARNSET_2_ROTOM_MOW,
            TM_LEARNSET_3_ROTOM_MOW,
            TM_LEARNSET_4_ROTOM_MOW
        },
    },
    
};