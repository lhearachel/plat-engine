#ifndef __POKEMON_H
#define __POKEMON_H

#include "global.h"

#include "custom_ball.h"
#include "message_data.h"

/**
 * @brief Base Stats data structure for all data unique to a particular species.
 */
struct BaseStats {
    u8 baseHP;                      ///< Base HP stat
    u8 baseAttack;                  ///< Base Attack stat
    u8 baseDefense;                 ///< Base Defense stat
    u8 baseSpeed;                   ///< Base Speed stat
    u8 baseSpAttack;                ///< Base Special Attack stat
    u8 baseSpDefense;               ///< Base Special Defense stat

    u8 type1;                       ///< Type 1
    u8 type2;                       ///< Type 2; always equivalent to Type 1 if mono-type

    u8 catchRate;                   ///< Catch rate constant; see [here](https://bulbapedia.bulbagarden.net/wiki/Catch_rate)
    u8 expYield;                    ///< Base experience yield

    u16 evYieldHP           :2,
        evYieldAttack       :2,
        evYieldDefense      :2,
        evYieldSpeed        :2,
        evYieldSpAttack     :2,
        evYieldSpDefense    :2,
        _evPadding          :4;

    u16 itemUncommon;               ///< 50% held item in the wild
    u16 itemRare;                   ///<  5% held item in the wild

    u8 genderRatio;                 ///< Gender ratio; see [here](https://bulbapedia.bulbagarden.net/wiki/Gender#Generations_III_to_V)
    u8 eggCycles;                   ///< Egg hatch rate, 255 steps per cycle; see [here](https://bulbapedia.bulbagarden.net/wiki/Egg_cycle)
    u8 baseFriendship;              ///< Base friendship when meeting an individual of a species
    u8 expCurve;                    ///< Experience curve; curves are defined in constants/misc.h; see [here](https://bulbapedia.bulbagarden.net/wiki/Experience)
    u8 eggGroup1;                   ///< First egg group
    u8 eggGroup2;                   ///< Second egg group

    u8 ability1;                    ///< First possible ability; values defined in constants/abilities.h
    u8 ability2;                    ///< Second possible ability; may be None (0)

    u8 fleeRate;                    ///< Chance to flee; only applies in Safari Zone
    u8 bodyColor        :7,         ///< Body color; definitions in constants/misc.h
       reverse          :1;         ///< Flip the sprite or not

    // Vanilla Platinum's structure here represents the TM learnset for any
    // given Pokemon species as a quartet of consecutive bitflags, each bit
    // corresponding to the learnability of a particular TM for a given species.
    // 
    // Only 100 of these bits are actually used in vanilla code; the remaining
    // 28 bits are unused.
    u32 tmLearnsets[4];
};

struct PokemonDataBlockA {
    u16 species;
    u16 heldItem;
    u32 otID;       // low half: visible ID; high half: secret ID
    u32 exp;
    u8  friendship;
    u8  ability;
    u8  markings;    // circle, triangle, square, heart, star, diamond
    u8  countryCode;
    u8  hpEV;
    u8  attackEV;
    u8  defenseEV;
    u8  speedEV;
    u8  spAttackEV;
    u8  spDefenseEV;
    u8  coolStat;
    u8  beautyStat;
    u8  cuteStat;
    u8  smartStat;
    u8  toughStat;
    u8  sheen;
    u32 sinnohRibbons;
};

struct PokemonDataBlockB {
    u16 moves[4];
    u8  movePP[4];
    u8  movePPUps[4];

    u32 hpIV        :5,
        attackIV    :5,
        defenseIV   :5,
        speedIV     :5,
        spAttackIV  :5,
        spDefenseIV :5,
        isEgg       :1,
        isNicknamed :1;
    u32 oldRibbons;         // ribbons from gen 3

    u8  eventDistributed    :1,
        sex                 :2,
        formNumber          :5;

    u8  _dummyB_1;          // 24 bits of unused space
    u16 _dummyB_2;

    u16 newCatchLocation;   // These fields are only used for riddles (Trick House?)
    u16 newHatchLocation;
};

struct PokemonDataBlockC {
    u16 nickname[11];
    u8  originCountryCode;
    u8  originGame;
    u64 sinnohContestRibbons;
};

struct PokemonDataBlockD {
    u16 oTrainerName[8];       // 7 characters + terminator

    u8  caughtYear;
    u8  caughtMonth;
    u8  caughtDay;

    u8  birthYear;
    u8  birthMonth;
    u8  birthDay;

    u16 caughtLocation;
    u16 hatchLocation;

    u8  pokerus;
    u8  pokeball;
    u8  metLevel:7,
        metGender:1;
    u8  encounterType;

    u16 _dummyC;            // 16 bits of unused space
};

typedef union {
    struct PokemonDataBlockA blockA;
    struct PokemonDataBlockB blockB;
    struct PokemonDataBlockC blockC;
    struct PokemonDataBlockD blockD;
} PokemonDataBlock;

struct BoxPokemon {
    u32 pid;
    u16 partyLock:1,
        boxLock:1,
        badEgg:1,
        _dummyD:13;     // maybe used for some validation checks?
    u16 checksum;       // stored checksum
    PokemonDataBlock substructs[4];
};

struct PartyPokemon {
    u32 condition;      // slp:3, psn:1, brn:1, frz:1, prz:1, tox:1, ...
    u8  level;
    u8  customBallID;
    u16 currentHP;
    u16 maxHP;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
    struct MailData mailData;
    struct CustomBalls customBalls;
};

struct Pokemon {
    struct BoxPokemon   boxParams;      // a set of parameters that are applicable at all times for a given individual
    struct PartyPokemon partyParams;    // a set of parameters that are only applicable when in the party
};

struct Party {
    s32 maxPossibleCount;
    s32 count;
};

enum PokemonField {
    // BoxPokemon header fields
	MON_PARAM_PID = 0,
	MON_PARAM_PARTY_LOCK,
    MON_PARAM_BOX_LOCK,
	MON_PARAM_BAD_EGG,
	MON_PARAM_CHECKSUM,

    // BoxPokemon Block A data
    MON_PARAM_SPECIES,
	MON_PARAM_HELD_ITEM,
	MON_PARAM_OT_ID,
	MON_PARAM_EXP,
	MON_PARAM_FRIENDSHIP,
	MON_PARAM_ABILITY,
	MON_PARAM_MARKINGS,
	MON_PARAM_COUNTRY_CODE,
    
	MON_PARAM_HP_EV,            // EVs
	MON_PARAM_ATTACK_EV,
	MON_PARAM_DEFENSE_EV,
	MON_PARAM_SPEED_EV,
	MON_PARAM_SPATTACK_EV,
	MON_PARAM_SPDEFENSE_EV,

	MON_PARAM_COOL,             // contest stats
	MON_PARAM_BEAUTY,
	MON_PARAM_CUTE,
	MON_PARAM_SMART,
	MON_PARAM_TOUGH,
	MON_PARAM_SHEEN,

	MON_PARAM_SINNOH_CHAMPION_RIBBON,               // enter the Hall of Fame
	MON_PARAM_SINNOH_BATTLE_TOWER_ABILITY,          // win a 21 singles streak at the Battle Tower
	MON_PARAM_SINNOH_BATTLE_TOWER_GREAT_ABILITY,    // win a 49 singles streak at the Battle Tower
	MON_PARAM_SINNOH_BATTLE_TOWER_DOUBLE_ABILITY,   // start a double battle set at 49+ battle streak
	MON_PARAM_SINNOH_BATTLE_TOWER_MULTI_ABILITY,    // start a multi battle set with an NPC partner at 49+ battle streak
	MON_PARAM_SINNOH_BATTLE_TOWER_PAIR_ABILITY,     // start a multi battle set by connecting to another game at 49+ battle streak
	MON_PARAM_SINNOH_BATTLE_TOWER_WORLD_ABILITY,    // win a set of seven battles in a wi-fi room at Battle Tower
	MON_PARAM_SINNOH_ALERT_RIBBON,                  // given on Mondays to the first slot in the party
    MON_PARAM_SINNOH_SHOCK_RIBBON,                  // given on Tuesdays to the first slot in the party
	MON_PARAM_SINNOH_DOWNCAST_RIBBON,               // given on Wednesdays to the first slot in the party
	MON_PARAM_SINNOH_CARELESS_RIBBON,               // given on Thursdays to the first slot in the party
	MON_PARAM_SINNOH_RELAX_RIBBON,                  // given on Fridays to the first slot in the party
	MON_PARAM_SINNOH_SNOOZE_RIBBON,                 // given on Saturdays to the first slot in the party
	MON_PARAM_SINNOH_SMILE_RIBBON,                  // given on Sundays to the first slot in the party
	MON_PARAM_SINNOH_GORGEOUS_RIBBON,               // buy for $10,000
	MON_PARAM_SINNOH_ROUAL_RIBBON,                  // buy for $100,000
	MON_PARAM_SINNOH_GORGEOUS_ROYAL_RIBBON,         // buy for $999,999
	MON_PARAM_SINNOH_FOOTPRINT_RIBBON,              // maximum friendship
	MON_PARAM_SINNOH_RECORD_RIBBON,                 // unobtainable
	MON_PARAM_SINNOH_HISTORY_RIBBON,                // unobtainable; Event Ribbon in gen5
	MON_PARAM_SINNOH_LEGEND_RIBBON,                 // defeat Red at Mt. Silver
	MON_PARAM_SINNOH_RED_RIBBON,                    // unobtainable; World Champion Ribbon in gen5
	MON_PARAM_SINNOH_GREEN_RIBBON,                  // unobtainable; Birthday Ribbon in gen5
	MON_PARAM_SINNOH_BLUE_RIBBON,                   // unobtainable; Special Ribbon in gen5
	MON_PARAM_SINNOH_SOUVENIR_RIBBON,               // unobtainable; Festival Ribbon in gen5
	MON_PARAM_SINNOH_CARNIVAL_RIBBON,               // unobtainable; Wishing Ribbon in gen5
    MON_PARAM_SINNOH_CLASSIC_RIBBON,                // obtain the mon via Mystery Gift
    MON_PARAM_SINNOH_PREMIER_RIBBON,                // obtain an Event Mew
	MON_PARAM_SINNOH_PADDING_RIBBONS,               // leftover space in the bitfield

    // BoxPokemon Block B data
	MON_PARAM_MOVE_1,   // move IDs
	MON_PARAM_MOVE_2,
	MON_PARAM_MOVE_3,
	MON_PARAM_MOVE_4,

	MON_PARAM_PP_FOR_MOVE_1,                    // current PP for each move
	MON_PARAM_PP_FOR_MOVE_2,
	MON_PARAM_PP_FOR_MOVE_3,
	MON_PARAM_PP_FOR_MOVE_4,

	MON_PARAM_NUM_PP_UPS_FOR_MOVE_1,            // number of PP Ups applied to each move
	MON_PARAM_NUM_PP_UPS_FOR_MOVE_2,
	MON_PARAM_NUM_PP_UPS_FOR_MOVE_3,
	MON_PARAM_NUM_PP_UPS_FOR_MOVE_4,

	MON_PARAM_MAX_PP_FOR_MOVE_1,                // maximum PP for each move
	MON_PARAM_MAX_PP_FOR_MOVE_2,
	MON_PARAM_MAX_PP_FOR_MOVE_3,
	MON_PARAM_MAX_PP_FOR_MOVE_4,

	MON_PARAM_HP_IV,                            // IVs
    MON_PARAM_ATTACK_IV,
    MON_PARAM_DEFENSE_IV,
    MON_PARAM_SPEED_IV,
    MON_PARAM_SPATTACK_IV,
    MON_PARAM_SPDEFENSE_IV,

	MON_PARAM_IS_EGG,
	MON_PARAM_IS_NICKNAMED,

	MON_PARAM_HOENN_COOL_RIBBON,                // win a Hoenn Cool contest
	MON_PARAM_HOENN_COOL_RIBBON_SUPER,          // win a Hoenn Cool Super Rank contest
	MON_PARAM_HOENN_COOL_RIBBON_HYPER,          // win a Hoenn Cool Hyper Rank contest
	MON_PARAM_HOENN_COOL_RIBBON_MASTER,         // win a Hoenn Cool Master Rank contest
	MON_PARAM_HOENN_BEAUTY_RIBBON,              // ... etc.
	MON_PARAM_HOENN_BEAUTY_RIBBON_SUPER,
	MON_PARAM_HOENN_BEAUTY_RIBBON_HYPER,
	MON_PARAM_HOENN_BEAUTY_RIBBON_MASTER,
	MON_PARAM_HOENN_CUTE_RIBBON,
	MON_PARAM_HOENN_CUTE_RIBBON_SUPER,
	MON_PARAM_HOENN_CUTE_RIBBON_HYPER,
	MON_PARAM_HOENN_CUTE_RIBBON_MASTER,
	MON_PARAM_HOENN_SMART_RIBBON,
	MON_PARAM_HOENN_SMART_RIBBON_SUPER,
	MON_PARAM_HOENN_SMART_RIBBON_HYPER,
	MON_PARAM_HOENN_SMART_RIBBON_MASTER,
	MON_PARAM_HOENN_TOUGH_RIBBON,
	MON_PARAM_HOENN_TOUGH_RIBBON_SUPER,
	MON_PARAM_HOENN_TOUGH_RIBBON_HYPER,
	MON_PARAM_HOENN_TOUGH_RIBBON_MASTER,
	MON_PARAM_HOENN_CHAMPION_RIBBON,            // enter a gen3 league hall of fame (Hoenn, Kanto)
	MON_PARAM_HOENN_BATTLE_TOWER_WINNER,        // clear level 50 of the Hoenn Battle Tower
	MON_PARAM_HOENN_BATTLE_TOWER_VICTORY,       // clear level 100 of the Hoenn Battle Tower
	MON_PARAM_HOENN_ARTIST_RIBBON,              // win a Master Rank Hoenn contest with a high score and have the Pokemon's portrait painted
	MON_PARAM_HOENN_EFFORT_RIBBON,              // have 510 total EVs
	MON_PARAM_HOENN_MARINE_RIBBON,              // unobtainable; Battle Champion Ribbon in gen5
	MON_PARAM_HOENN_LAND_RIBBON,                // unobtainable; Regional Champion Ribbon in gen5
	MON_PARAM_HOENN_SKY_RIBBON,                 // unobtainable; National Champion Ribbon in gen5
	MON_PARAM_HOENN_COUNTRY_RIBBON,             // win a Pokemon Festa in 2004 or 2005
	MON_PARAM_HOENN_NATIONAL_RIBBON,            // purify a Shadow Pokemon (Colosseum)
	MON_PARAM_HOENN_EARTH_RIBBON,               // win 100 consecutive times at Mt. Battle (Colosseum)
	MON_PARAM_HOENN_WORLD_RIBBON,               // win a Pokemon Festa in 2004 or 2005

	MON_PARAM_IS_EVENT_DISTRIBUTED,
	MON_PARAM_GENDER,
	MON_PARAM_FORM_NUMBER,
	MON_PARAM_DUMMY_BLOCK_B_1,
	MON_PARAM_DUMMY_BLOCK_B_2,
	MON_PARAM_NEW_CATCH_LOCATION,
	MON_PARAM_NEW_HATCH_LOCATION,

    // BoxPokemon Block C data
    MON_PARAM_NICKNAME,
    MON_PARAM_NICKNAME_AS_CHARS_WITH_FLAG,
    MON_PARAM_NICKNAME_AS_STRBUF,
    MON_PARAM_NICKNAME_AS_STRBUF_WITH_FLAG,
	MON_PARAM_ORIGIN_COUNTRY_CODE,
	MON_PARAM_ORIGIN_GAME,

	MON_PARAM_SINNOH_COOL_RIBBON,               // win a Sinnoh Cool Super Contest
	MON_PARAM_SINNOH_COOL_RIBBON_GREAT,         // win a Sinnoh Cool Great Rank Super Contest
	MON_PARAM_SINNOH_COOL_RIBBON_ULTRA,         // win a Sinnoh Cool Ultra Rank Super Contest
	MON_PARAM_SINNOH_COOL_RIBBON_MASTER,        // win a Sinnoh Cool Master Rank Super Contest
	MON_PARAM_SINNOH_BEAUTY_RIBBON,             // ... etc.
	MON_PARAM_SINNOH_BEAUTY_RIBBON_GREAT,
	MON_PARAM_SINNOH_BEAUTY_RIBBON_ULTRA,
	MON_PARAM_SINNOH_BEAUTY_RIBBON_MASTER,
	MON_PARAM_SINNOH_CUTE_RIBBON,
	MON_PARAM_SINNOH_CUTE_RIBBON_GREAT,
	MON_PARAM_SINNOH_CUTE_RIBBON_ULTRA,
	MON_PARAM_SINNOH_CUTE_RIBBON_MASTER,
	MON_PARAM_SINNOH_SMART_RIBBON,
	MON_PARAM_SINNOH_SMART_RIBBON_GREAT,
	MON_PARAM_SINNOH_SMART_RIBBON_ULTRA,
	MON_PARAM_SINNOH_SMART_RIBBON_MASTER,
	MON_PARAM_SINNOH_TOUGH_RIBBON,
	MON_PARAM_SINNOH_TOUGH_RIBBON_GREAT,
	MON_PARAM_SINNOH_TOUGH_RIBBON_ULTRA,
	MON_PARAM_SINNOH_TOUGH_RIBBON_MASTER,
	MON_PARAM_SINNOH_PADDING_CONTEST_RIBBONS,   // leftover space in the bitfield

    // BoxPokemon Block D data
    MON_PARAM_OT_NAME,
    MON_PARAM_OT_NAME_AS_STRING,

    MON_PARAM_CAUGHT_YEAR,
    MON_PARAM_CAUGHT_MONTH,
    MON_PARAM_CAUGHT_DAY,
    MON_PARAM_BIRTH_YEAR,
    MON_PARAM_BIRTH_MONTH,
    MON_PARAM_BIRTH_DAY,

    MON_PARAM_CAUGHT_LOCATION,
    MON_PARAM_BIRTH_LOCATION,

	MON_PARAM_POKERUS,
	MON_PARAM_POKEBALL,
	MON_PARAM_MET_LEVEL,
	MON_PARAM_OT_GENDER,
    MON_PARAM_ENCOUNTER_TYPE,
    MON_PARAM_DUMMY_BLOCK_D,

    // PartyPokemon data
    MON_PARAM_CONDITION,
    MON_PARAM_LEVEL,
    MON_PARAM_CUSTOM_BALL_ID,
    MON_PARAM_CURRENT_HP,
    MON_PARAM_MAX_HP,
    MON_PARAM_ATTACK,
    MON_PARAM_DEFENSE,
    MON_PARAM_SPEED,
    MON_PARAM_SPATTACK,
    MON_PARAM_SPDEFENSE,
    MON_PARAM_MAIL_DATA,
    MON_PARAM_CUSTOM_BALLS,

    MON_PARAM_PARTYPOKEMON_MAX,

    // Extra data param definitions
	MON_PARAM_DOES_SPECIES_EXIST,
	MON_PARAM_MAYBE_EGG,                        // returns the bad egg flag if flipped, else the value of the egg flag

    MON_PARAM_SPECIES_OR_EGG,                   // returns the species number, or the egg species (if this is an egg)

	MON_PARAM_ALL_IVS,                          // returns the full 30-bit structure of a mon's IVs
	MON_PARAM_NIDORAN_NICKNAME,                 // special check for Nidoran nicknames (because they are special boys and girls)

	MON_PARAM_TYPE1,                            // gets type 1 for a mon from the BaseStats struct (special case: Arceus)
	MON_PARAM_TYPE2,                            // gets type 2 for a mon from the BaseStats struct (special case: Arceus)

	MON_PARAM_DEFAULT_NAME,                     // gets the default name for a given species

	MON_PARAM_END,
};

enum BaseStatsField {
    PERSONAL_BASE_HP = 0,
    PERSONAL_BASE_ATTACK,
    PERSONAL_BASE_DEFENSE,
    PERSONAL_BASE_SPEED,
    PERSONAL_BASE_SP_ATTACK,
    PERSONAL_BASE_SP_DEFENSE,
    PERSONAL_TYPE_1,
    PERSONAL_TYPE_2,
    PERSONAL_CATCH_RATE,
    PERSONAL_EXP_YIELD,
    PERSONAL_EV_YIELD_HP,
    PERSONAL_EV_YIELD_ATTACK,
    PERSONAL_EV_YIELD_DEFENSE,
    PERSONAL_EV_YIELD_SPEED,
    PERSONAL_EV_YIELD_SP_ATTACK,
    PERSONAL_EV_YIELD_SP_DEFENSE,
    PERSONAL_ITEM_1,
    PERSONAL_ITEM_2,
    PERSONAL_GENDER_RATIO,
    PERSONAL_EGG_CYCLES,
    PERSONAL_BASE_FRIENDSHIP,
    PERSONAL_EXP_GROUP,
    PERSONAL_EGG_GROUP_1,
    PERSONAL_EGG_GROUP_2,
    PERSONAL_ABILITY_1,
    PERSONAL_ABILITY_2,
    PERSONAL_RUN_CHANCE,
    PERSONAL_BODY_COLOR,
    PERSONAL_FLIP,
    PERSONAL_TM_ARRAY_1,
    PERSONAL_TM_ARRAY_2,
    PERSONAL_TM_ARRAY_3,
    PERSONAL_TM_ARRAY_4,
};

enum PokemonNature {
    NATURE_HARDY,
    NATURE_LONELY,
    NATURE_BRAVE,
    NATURE_ADAMANT,
    NATURE_NAUGHTY,
    NATURE_BOLD,
    NATURE_DOCILE,
    NATURE_RELAXED,
    NATURE_IMPISH,
    NATURE_LAX,
    NATURE_TIMID,
    NATURE_HASTY,
    NATURE_SERIOUS,
    NATURE_JOLLY,
    NATURE_NAIVE,
    NATURE_MODEST,
    NATURE_MILD,
    NATURE_QUIET,
    NATURE_BASHFUL,
    NATURE_RASH,
    NATURE_CALM,
    NATURE_GENTLE,
    NATURE_SASSY,
    NATURE_CAREFUL,
    NATURE_QUIRKY,
};

// Hidden Ability stuff
#define DUMMY_BLOCK_B_1_HIDDEN_ABILITY_MASK (0x01)

#define BOX_MON_IS_HIDDEN_ABILITY(boxMon) ( \
    BoxPokemon_Get(boxMon, MON_PARAM_DUMMY_BLOCK_B_1, NULL) & DUMMY_BLOCK_B_1_HIDDEN_ABILITY_MASK \
)
#define SET_BOX_MON_HIDDEN_ABILITY_BIT(boxMon) { \
    u16 tempassumeunused = BoxPokemon_Get(boxMon, MON_PARAM_DUMMY_BLOCK_B_1, NULL); \
    tempassumeunused |= DUMMY_P2_1_HIDDEN_ABILITY_MASK; \
    BoxPokemon_Set(boxMon, MON_PARAM_DUMMY_BLOCK_B_1, (u8*) &tempassumeunused) \
}

// ===== BASE GAME CODE FUNCTIONS (UNMODIFIED) ===== //

/**
 * @brief Get data from the BoxPokemon structure.
 * 
 * Original Function: [`GetBoxPkmnData @ 0x02074570` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_pkmndata.s#L1376)
 * 
 * @param[in]  boxMon   The BoxPokemon structure from which to pull data.
 * @param[in]  field    Field ID of the data to be pulled from the structure.
 * @param[out] buf      Buffer output, for array output.
 * @return              Result data.
 */
u32  __attribute__((long_call)) BoxPokemon_Get(struct BoxPokemon *boxMon, enum PokemonField field, void *buf);

/**
 * @brief Set data in the BoxPokemon structure.
 * 
 * Original Function: [`SetBoxPkmnData @ 0x02074C60` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_pkmndata.s#L2509)
 * 
 * @param[in,out] boxMon    The BoxPokemon structure to be modified.
 * @param[in]     field     Field ID of the data to be set within the structure.
 * @param[in]     buf       Data to be set into the structure.
 */
void __attribute__((long_call)) BoxPokemon_Set(struct BoxPokemon *boxMon, enum PokemonField field, void *buf);

/**
 * @brief Attempts to lock the BoxPokemon structure, designating to any other
 * competing threads that it is undergoing a read/write.
 * 
 * Original Function: [`InitEncryptPkmnData_Part1 @ 0x02073D20` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_pkmndata.s#L166)
 * 
 * @param[in,out] boxMon    The BoxPokemon structure to be locked.
 * @return                  TRUE if the lock was acquired, FALSE otherwise.
 */
BOOL __attribute__((long_call)) BoxPokemon_Lock(struct BoxPokemon *boxMon);

/**
 * @brief Attempts to unlock the BoxPokemon structure, permitting other threads
 * to perform read/write operations.
 * 
 * Original Function: [`InitEncryptPkmnData_Part1Again @ 0x02073D48` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_pkmndata.s#L193)
 * 
 * @param[in,out] boxMon    The BoxPokemon structure to be unlocked.
 * @param[in]     flag      If set to TRUE, will perform the unlock.
 * @return                  TRUE if the lock was released, FALSE otherwise.
 */
BOOL __attribute__((long_call)) BoxPokemon_Unlock(struct BoxPokemon *boxMon, BOOL flag);

/**
 * @brief Allocate space for a new Pokemon on the given heap.
 * 
 * Original function: 0x02073C74 (arm9)
 * 
 * @param heapID
 * @return              Pointer to the allocated Pokemon struct.
 */
struct Pokemon* __attribute__((long_call)) Pokemon_Alloc(u32 heapID);

/**
 * @brief Copies attributes from a BoxPokemon to a party Pokemon.
 * 
 * Original function: 0x020774C8 (arm9)
 * 
 * @param src           The BoxPokemon source data
 * @param dst           An allocated Pokemon to receive the data
 */
void __attribute__((long_call)) Pokemon_FromBox(struct BoxPokemon *src, struct Pokemon *dst);

/**
 * @brief Get data from the Pokemon structure.
 * 
 * Original Function: [`GetPkmnData @ 0x02074470` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L1198)
 * 
 * @param[in]  pokemon  The Pokemon structure from which to pull data.
 * @param[in]  field    Field ID of the data to be pulled from the structure.
 * @param[out] buf      Buffer output, for array output.
 * @return              Result data.
 */
u32  __attribute__((long_call)) Pokemon_Get(struct Pokemon *pokemon, enum PokemonField field, void *buf);

/**
 * @brief Set data in the Pokemon structure.
 * 
 * Original Function: 0x02074B30 (arm9)
 * 
 * @param[in,out] pokemon   The Pokemon structure to be modified.
 * @param[in]     field     Field ID of the data to be set within the structure.
 * @param[in]     buf       Data to be set into the structure.
 */
void __attribute__((long_call)) Pokemon_Set(struct Pokemon *pokemon, enum PokemonField field, void *buf);

/**
 * @brief Compute the gender of a Pokemon.
 * 
 * The gender of a given Pokemon is based on the gender ratio of its species
 * (specified in its base stats) and the individual's personality value (PID).
 * The lowest byte of the PID is pulled and then compared against the species
 * gender ratio:
 * 
 * | Gender Ratio | Nominal Ratio | Male Freq. | Female Freq. |
 * | -----------: | ------------- | ---------- | ------------ |
 * |          255 | No Gender     | N/A        | N/A          |
 * |          254 | All Female    | 0%         | 100%         |
 * |          225 | 1 : 7         | 12.11%     | 87.89%       |
 * |          191 | 1 : 3         | 25.39%     | 74.61%       |
 * |          127 | 1 : 1         | 50.39%     | 49.61%       |
 * |           63 | 3 : 1         | 75.39%     | 24.61%       |
 * |           31 | 7 : 1         | 87.89%     | 12.11%       |
 * |            0 | All Male      | 100%       | 0%           |
 * 
 * Original Function: [`Call_DecidePkmnGender @ 0x02075D6C` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L5180)
 * See Also: [Bulbapedia Article](https://bulbapedia.bulbagarden.net/wiki/Personality_value#Gender)
 * 
 * @param[in] pokemon
 * @return              Computed gender from the Pokemon's PID; 0 == Male, 1 == Female, 2 == None.
 */
u8   __attribute__((long_call)) Pokemon_CalcGender(struct Pokemon *pokemon);

/**
 * @brief Compute the nature of a Pokemon.
 * 
 * The nature of a given Pokemon is determined by computing the remainder of
 * its personality value (PID) when divided by 25.
 * 
 * See `enum PokemonNature` for the correspondence of raw result values to
 * true natures.
 * 
 * Original Function: [`Function_2075BCC` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L4914)
 * See Also: [Bulbapedia Article](https://bulbapedia.bulbagarden.net/wiki/Personality_value#Nature)
 * 
 * @param[in] pokemon
 * @return              Computed nature from the Pokemon's PID
 */
u8   __attribute__((long_call)) Pokemon_CalcNature(struct Pokemon *pokemon);

/**
 * @brief Compute the shininess of a Pokemon.
 * 
 * The shininess of a given Pokemon is determined by the following computation:
 * 
 * OT_ID ^ OT_SecretID ^ PID[31..16] ^ PID[15..0]
 *
 * Original Function: [`Call_CheckIfShinyPkmn_2 @ 0x02075E0C` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L5295)
 * See Also: [Bulbapedia Article](https://bulbapedia.bulbagarden.net/wiki/Personality_value#Shininess)
 * 
 * @param[in] pokemon
 * @return              Computed shininess from the Pokemon's PID; 1 == Shiny, 0 otherwise.
 */
u8   __attribute__((long_call)) Pokemon_CalcShiny(struct Pokemon *pokemon);

/**
 * @brief Compute the amount of experience needed for a Pokemon to reach a
 * given level.
 * 
 * The value returned is absolute; it represents the raw experience value
 * required to reach the input level, not how much is needed to reach the
 * level from any present value.
 * 
 * Original Function: [`GetBaseExpPts @ 0x02075AD0` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L4742)
 * 
 * @param[in] species   The species of a particular Pokemon.
 * @param[in] level     The level to be reached.
 * @return              The amount of experienced needed to reach the input level.
 */
u32  __attribute__((long_call)) Pokemon_CalcExpForLevel(int species, int level);

/**
 * @brief Determine if a given Pokemon likes a particular flavor.
 * 
 * Original Function: [`Call_GetPkmnNatureData @ 0x0207762C` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L9112)
 * 
 * @param[in] pokemon
 * @param[in] flavor    The flavor to test; see constants/misc.h for definitions.
 * @return              -1 if the flavor is disliked, 1 if the flavor is liked, 0 otherwise.
 */
s8   __attribute__((long_call)) Pokemon_CalcFlavorAffinity(struct Pokemon *pokemon, int flavor);

/**
 * @brief Check if a given Pokemon is immune to Pokerus (i.e. has had it before).
 * 
 * Original Function: [`Function_20778f8` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L9537)
 * 
 * @param[in] pokemon
 * @return              TRUE if the Pokemon has previously contracted Pokerus, FALSE otherwise.
 */
BOOL __attribute__((long_call)) Pokemon_CheckPokerusImmune(struct Pokemon *pokemon);

/**
 * @brief Check if a given Pokemon is currently infected with Pokerus.
 * 
 * Original Function: [`Function_20778d8` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L9508)
 * 
 * @param[in] pokemon
 * @return              TRUE if the Pokemon is currently infected with Pokerus, FALSE otherwise.
 */
BOOL __attribute__((long_call)) Pokemon_CheckPokerus(struct Pokemon *pokemon);

/**
 * @brief Recalculates the friendship of a Pokemon, according to an input mode.
 * 
 * Original function: 0x02075C74 (arm9)
 * 
 * Known modes:
 * - 7: "Death" due to poison damage
 * 
 * @param[in] pokemon
 * @param[in] mode
 * @param[in] zoneID
 */
void __attribute__((long_call)) Pokemon_RecalcFriendship(struct Pokemon *pokemon, u8 mode, u16 zoneID);

/**
 * @brief Determines if a Pokemon can battle.
 * 
 * Pokemon cannot battle if they:
 * - have a current HP of 0
 * - are an egg
 * 
 * Original function: 0x02054884 (arm9)
 * 
 * @param[in] pokemon
 * @return              TRUE if the Pokemon can battle, FALSE otherwise
 */
BOOL __attribute__((long_call)) Pokemon_CanBattle(struct Pokemon *pokemon);

/**
 * @brief Attempts to lock the Pokemon structure, designating to any other
 * competing threads that it is undergoing a read/write.
 * 
 * Original Function: [`InitEncryptPkmnData @ 0x02073C88` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L72)
 * 
 * @param[in,out] pokemon   The Pokemon structure to be locked.
 * @return                  TRUE if the lock was acquired, FALSE otherwise.
 */
BOOL __attribute__((long_call)) Pokemon_Lock(struct Pokemon *pokemon);

/**
 * @brief Attempts to unlock the Pokemon structure, permitting other threads
 * to perform read/write operations.
 * 
 * Original Function: [`InitEncryptPkmnData_Part1And2 @ 0x02073CD4` (ARM9)](https://github.com/JimB16/PokePlat/blob/ccbdf7ea8b08f23d3adcb6baa7d1f2b8dc24bbc1/source/arm9_pkmndata.s#L118)
 * 
 * @param[in,out] pokemon   The Pokemon structure to be unlocked.
 * @param[in]     flag      If set to TRUE, will perform the unlock.
 * @return                  TRUE if the lock was released, FALSE otherwise.
 */
BOOL __attribute__((long_call)) Pokemon_Unlock(struct Pokemon *pokemon, BOOL flag);

/**
 * @brief Get a data element from the base stats data for a particular species.
 * 
 * Original Function: [`GetPkmnBaseData1 @ 0x020759F0` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_pkmndata.s#L4605)
 * 
 * @param[in] species   The "true" species ID of the Pokemon.
 * @param[in] field     Field ID of the data to be pulled from the structure.
 * @return              Retrieved data.
 */
u32 __attribute__((long_call)) PokemonBaseStats_Get(int species, enum BaseStatsField field);

/**
 * @brief Get a data element from the base stats data for a particular species
 * + form.
 * 
 * In essence, this calls Form_GetTrueSpecies, then passes the result to PokemonBaseStats_Get.
 * 
 * Original Function: [`GetPkmnBaseData2 @ 0x020759CC` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_pkmndata.s#L4582)
 * 
 * @param[in] species   The National Dex species ID of the Pokemon.
 * @param[in] form      The form ID.
 * @param[in] field     Field ID of the data to be pulled from the structure.
 * @return              Retrieved data.
 */
u32  __attribute__((long_call)) PokemonBaseStats_GetWithForm(int species, int form, enum BaseStatsField field);

// ===== BASE GAME CODE FUNCTIONS (MODIFIED) ===== //

/**
 * @brief Get the special species-designation for a particular species and form.
 * 
 * The value returned here is the "true" species identifier, which is used to
 * point to data specific to that form, i.e., base stats, sprite data, etc.
 * 
 * In vanilla Gen4, this is used for stuff like Wormadam, Rotom, Deoxys, Shaymin,
 * and Giratina. The engine expands this to apply to regional, aesthetic, and
 * gendered forms (e.g. Alolan/Galarian/Hisuian, Pikachu, Meowstic).
 * 
 * Original Function: [`Function_2078740` (ARM9)](https://github.com/JimB16/PokePlat/blob/6d4ad87550eeb40079ede6dcf5dddec5873976e4/source/arm9_pkmndata.s#L12072)
 * 
 * @param[in] species   The National Dex species ID of the Pokemon.
 * @param[in] form      The form ID.
 * @return              The true species ID of the Pokemon's form.
 */
int  __attribute__((long_call)) Form_GetTrueSpecies(int species, int form);

/**
 * @brief Count the number of members in the party.
 * 
 * Original function: 0x02054B04 (arm9)
 * 
 * @param[in] party     The party.
 * @return              The number of members in the party.
 */
int  __attribute__((long_call)) Party_Count(const struct Party *party);

/**
 * @brief Get a pointer to the Pokemon at a given slot in the party.
 * 
 * Original function: 0x0207A0FC
 */
struct Pokemon* __attribute__((long_call)) Party_Member(const struct Party *party, int pos);

// ===== NOVEL FUNCTIONS ===== //

// u16  __attribute__((long_call)) Pokemon_GetHiddenAbility(u16 species, u32 form);
// void __attribute__((long_call)) BoxPokemon_ToggleHiddenAbility(void *boxMon);

BOOL __attribute__((long_call)) Pokemon_IsNFE(u16 species, u32 form);

#endif // __POKEMON_H