#ifndef __POKEMON_H
#define __POKEMON_H

#include "global.h"

#include "custom_ball.h"
#include "mail.h"

/*
 * This is the basic structure of data that all Pokemon of a particular species inherit. It defines
 * what parameters a given individual can have as far as stats, type, and ability.
 */
struct BaseStats {
    u8 baseHP;
    u8 baseAttack;
    u8 baseDefense;
    u8 baseSpeed;
    u8 baseSpAttack;
    u8 baseSpDefense;

    u8 type1;
    u8 type2;

    u8 catchRate;
    u8 expYield;

    u16 evYieldHP           :2,
        evYieldAttack       :2,
        evYieldDefense      :2,
        evYieldSpeed        :2,
        evYieldSpAttack     :2,
        evYieldSpDefense    :2,
        _evPadding          :4;

    u16 itemUncommon;       // 50% item
    u16 itemRare;           //  5% item

    u8 genderRatio;
    u8 eggCycles;
    u8 baseFriendship;
    u8 expCurve;
    u8 eggGroup1;
    u8 eggGroup2;

    u8 ability1;
    u8 ability2;

    u8 fleeRate;
    u8 bodyColor        :7,
       reverse          :1;

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
    u8 friendship;
    u8 ability;
    u8 markings;    // circle, triangle, square, heart, star, diamond
    u8 countryCode;
    u8 hpEV;
    u8 attackEV;
    u8 defenseEV;
    u8 speedEV;
    u8 spAttackEV;
    u8 spDefenseEV;
    u8 coolStat;
    u8 beautyStat;
    u8 cuteStat;
    u8 smartStat;
    u8 toughStat;
    u8 sheen;
    u32 sinnohRibbons;
};

struct PokemonDataBlockB {
    u16 moves[4];
    u8 movePP[4];
    u8 movePPUps[4];

    u32 hpIV        :5,
        attackIV    :5,
        defenseIV   :5,
        speedIV     :5,
        spAttackIV  :5,
        spDefenseIV :5,
        isEgg       :1,
        isNicknamed :1;
    u32 oldRibbons;

    u8  eventDistributed    :1,
        sex                 :2,
        formNumber          :5;

    u8  _dummy2_1;          // 24 bits of unused space
    u16 _dummy2_2;

    u16 newCatchLocation;   // These fields are only used for riddles (Trick House?)
    u16 newHatchLocation;
};

struct PokemonDataBlockC {
    u16 nickname[11];
    u8  originCountryCode;
    u8  originGame;
    u64 sinnohRibbons2;
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

    u16 _dummy;             // 16 bits of unused space
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
        _dummy:13;      // maybe used for some validation checks?
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

enum {
    // BoxPokemon header fields
	MON_PARAM_PID = 0,
	MON_PARAM_PARTY_LOCK,
    MON_PARAM_BOX_LOCK,
	MON_PARAM_BAD_EGG,
	MON_PARAM_CHECKSUM,

    MON_PARAM_HEADER_MAX,
};

// BoxPokemon data block A fields
enum {
    MON_PARAM_SPECIES = MON_PARAM_HEADER_MAX,
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
	ID_PARA_sinou_syakki_ribbon,				//シンオウしゃっきリボン
	ID_PARA_sinou_dokki_ribbon,					//シンオウどっきリボン
	ID_PARA_sinou_syonbo_ribbon,				//シンオウしょんぼリボン
	ID_PARA_sinou_ukka_ribbon,					//シンオウうっかリボン
	ID_PARA_sinou_sukki_ribbon,					//シンオウすっきリボン
	ID_PARA_sinou_gussu_ribbon,					//シンオウぐっすリボン
	ID_PARA_sinou_nikko_ribbon,					//シンオウにっこリボン
	ID_PARA_sinou_gorgeous_ribbon,				//シンオウゴージャスリボン
	ID_PARA_sinou_royal_ribbon,					//シンオウロイヤルリボン
	ID_PARA_sinou_gorgeousroyal_ribbon,			//シンオウゴージャスロイヤルリボン
	ID_PARA_sinou_ashiato_ribbon,				//シンオウあしあとリボン
	ID_PARA_sinou_record_ribbon,				//シンオウレコードリボン
	ID_PARA_sinou_history_ribbon,				//シンオウヒストリーリボン
	ID_PARA_sinou_legend_ribbon,				//シンオウレジェンドリボン
	ID_PARA_sinou_red_ribbon,					//シンオウレッドリボン
	ID_PARA_sinou_green_ribbon,					//シンオウグリーンリボン
	ID_PARA_sinou_blue_ribbon,					//シンオウブルーリボン
	ID_PARA_sinou_festival_ribbon,				//シンオウフェスティバルリボン
	ID_PARA_sinou_carnival_ribbon,				//シンオウカーニバルリボン
	ID_PARA_sinou_classic_ribbon,				//シンオウクラシックリボン
	ID_PARA_sinou_premiere_ribbon,				//シンオウプレミアリボン
	ID_PARA_sinou_amari_ribbon,					//あまり

    MON_PARAM_BLOCK_A_MAX,
};

// BoxPokemon data block B fields
enum {
	MON_PARAM_MOVE_1 = MON_PARAM_BLOCK_A_MAX,   // move IDs
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

	ID_PARA_stylemedal_normal,					// old ribbons
	ID_PARA_stylemedal_super,					//かっこよさ勲章(スーパー)AGBコンテスト
	ID_PARA_stylemedal_hyper,					//かっこよさ勲章(ハイパー)AGBコンテスト
	ID_PARA_stylemedal_master,					//かっこよさ勲章(マスター)AGBコンテスト
	ID_PARA_beautifulmedal_normal,				//うつくしさ勲章(ノーマル)AGBコンテスト
	ID_PARA_beautifulmedal_super,				//うつくしさ勲章(スーパー)AGBコンテスト
	ID_PARA_beautifulmedal_hyper,				//うつくしさ勲章(ハイパー)AGBコンテスト
	ID_PARA_beautifulmedal_master,				//うつくしさ勲章(マスター)AGBコンテスト
	ID_PARA_cutemedal_normal,					//かわいさ勲章(ノーマル)AGBコンテスト
	ID_PARA_cutemedal_super,					//かわいさ勲章(スーパー)AGBコンテスト
	ID_PARA_cutemedal_hyper,					//かわいさ勲章(ハイパー)AGBコンテスト
	ID_PARA_cutemedal_master,					//かわいさ勲章(マスター)AGBコンテスト
	ID_PARA_clevermedal_normal,					//かしこさ勲章(ノーマル)AGBコンテスト
	ID_PARA_clevermedal_super,					//かしこさ勲章(スーパー)AGBコンテスト
	ID_PARA_clevermedal_hyper,					//かしこさ勲章(ハイパー)AGBコンテスト
	ID_PARA_clevermedal_master,					//かしこさ勲章(マスター)AGBコンテスト
	ID_PARA_strongmedal_normal,					//たくましさ勲章(ノーマル)AGBコンテスト
	ID_PARA_strongmedal_super,					//たくましさ勲章(スーパー)AGBコンテスト
	ID_PARA_strongmedal_hyper,					//たくましさ勲章(ハイパー)AGBコンテスト
	ID_PARA_strongmedal_master,					//たくましさ勲章(マスター)AGBコンテスト
	ID_PARA_champ_ribbon,						//チャンプリボン
	ID_PARA_winning_ribbon,						//ウィニングリボン
	ID_PARA_victory_ribbon,						//ビクトリーリボン
	ID_PARA_bromide_ribbon,						//ブロマイドリボン
	ID_PARA_ganba_ribbon,						//がんばリボン
	ID_PARA_marine_ribbon,						//マリンリボン
	ID_PARA_land_ribbon,						//ランドリボン
	ID_PARA_sky_ribbon,							//スカイリボン
	ID_PARA_country_ribbon,						//カントリーリボン
	ID_PARA_national_ribbon,					//ナショナルリボン
	ID_PARA_earth_ribbon,						//アースリボン
	ID_PARA_world_ribbon,						//ワールドリボン

	MON_PARAM_IS_EVENT_DISTRIBUTED,
	MON_PARAM_GENDER,
	MON_PARAM_FORM_NUMBER,
	MON_PARAM_DUMMY_2_1,
	MON_PARAM_DUMMY_2_2,
	MON_PARAM_NEW_CATCH_LOCATION,
	MON_PARAM_NEW_HATCH_LOCATION,

    MON_PARAM_BLOCK_B_MAX,
};

// BoxPokemon data block C fields
enum {
    MON_PARAM_NICKNAME = MON_PARAM_BLOCK_B_MAX,
    MON_PARAM_NICKNAME_AS_CHARS_WITH_FLAG,
    MON_PARAM_NICKNAME_AS_STRBUF,
    MON_PARAM_NICKNAME_AS_STRBUF_WITH_FLAG,
	MON_PARAM_ORIGIN_COUNTRY_CODE,
	MON_PARAM_ORIGIN_GAME,

    // sinnoh ribbons part 2
	ID_PARA_trial_stylemedal_normal,			//かっこよさ勲章(ノーマル)トライアル
	ID_PARA_trial_stylemedal_super,				//かっこよさ勲章(スーパー)トライアル
	ID_PARA_trial_stylemedal_hyper,				//かっこよさ勲章(ハイパー)トライアル
	ID_PARA_trial_stylemedal_master,			//かっこよさ勲章(マスター)トライアル
	ID_PARA_trial_beautifulmedal_normal,		//うつくしさ勲章(ノーマル)トライアル
	ID_PARA_trial_beautifulmedal_super,			//うつくしさ勲章(スーパー)トライアル
	ID_PARA_trial_beautifulmedal_hyper,			//うつくしさ勲章(ハイパー)トライアル
	ID_PARA_trial_beautifulmedal_master,		//うつくしさ勲章(マスター)トライアル
	ID_PARA_trial_cutemedal_normal,				//かわいさ勲章(ノーマル)トライアル
	ID_PARA_trial_cutemedal_super,				//かわいさ勲章(スーパー)トライアル
	ID_PARA_trial_cutemedal_hyper,				//かわいさ勲章(ハイパー)トライアル
	ID_PARA_trial_cutemedal_master,				//かわいさ勲章(マスター)トライアル
	ID_PARA_trial_clevermedal_normal,			//かしこさ勲章(ノーマル)トライアル
	ID_PARA_trial_clevermedal_super,			//かしこさ勲章(スーパー)トライアル
	ID_PARA_trial_clevermedal_hyper,			//かしこさ勲章(ハイパー)トライアル
	ID_PARA_trial_clevermedal_master,			//かしこさ勲章(マスター)トライアル
	ID_PARA_trial_strongmedal_normal,			//たくましさ勲章(ノーマル)トライアル
	ID_PARA_trial_strongmedal_super,			//たくましさ勲章(スーパー)トライアル
	ID_PARA_trial_strongmedal_hyper,			//たくましさ勲章(ハイパー)トライアル
	ID_PARA_trial_strongmedal_master,			//たくましさ勲章(マスター)トライアル
	ID_PARA_amari_ribbon,						//余りリボン

    MON_PARAM_BLOCK_C_MAX,
};

// BoxPokemon data block D fields
enum {
    MON_PARAM_OT_NAME,
    MON_PARAM_OT_NAME_AS_STRBUF,

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
	MON_PARAM_MET_GENDER,
    MON_PARAM_ENCOUNTER_TYPE,
    MON_PARAM_DUMMY_4_1,

    MON_PARAM_BLOCK_D_MAX,
};

// PartyPokemon fields
enum {
    MON_PARAM_CONDITION = MON_PARAM_BLOCK_D_MAX,
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
};	

// Extra fields
enum {
	MON_PARAM_DOES_SPECIES_EXIST = MON_PARAM_PARTYPOKEMON_MAX,
	MON_PARAM_MAYBE_EGG,                        // returns the bad egg flag if flipped, else the value of the egg flag

    MON_PARAM_SPECIES_OR_EGG,                   // returns the species number, or the egg species (if this is an egg)

	MON_PARAM_ALL_IVS,                          // returns the full 30-bit structure of a mon's IVs
	MON_PARAM_NIDORAN_NICKNAME,                 // special check for Nidoran nicknames (because they are special boys and girls)

	MON_PARAM_TYPE1,                            // gets type 1 for a mon from the BaseStats struct (special case: Arceus)
	MON_PARAM_TYPE2,                            // gets type 2 for a mon from the BaseStats struct (special case: Arceus)

	MON_PARAM_DEFAULT_NAME,                     // gets the default name for a given species

	MON_PARAM_END,
};

// personal narc fields
enum {
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

#define NATURE_HARDY     0
#define NATURE_LONELY    1
#define NATURE_BRAVE     2
#define NATURE_ADAMANT   3
#define NATURE_NAUGHTY   4
#define NATURE_BOLD      5
#define NATURE_DOCILE    6
#define NATURE_RELAXED   7
#define NATURE_IMPISH    8
#define NATURE_LAX       9
#define NATURE_TIMID    10
#define NATURE_HASTY    11
#define NATURE_SERIOUS  12
#define NATURE_JOLLY    13
#define NATURE_NAIVE    14
#define NATURE_MODEST   15
#define NATURE_MILD     16
#define NATURE_QUIET    17
#define NATURE_BASHFUL  18
#define NATURE_RASH     19
#define NATURE_CALM     20
#define NATURE_GENTLE   21
#define NATURE_SASSY    22
#define NATURE_CAREFUL  23
#define NATURE_QUIRKY   24

// Hidden Ability stuff
#define DUMMY_2_1_HIDDEN_ABILITY_MASK (0x01)

#define BOX_MON_IS_HIDDEN_ABILITY(boxMon) ( \
    GetBoxMonData(boxMon, MON_PARAM_DUMMY_2_1, NULL) & DUMMY_2_1_HIDDEN_ABILITY_MASK \
)
#define SET_BOX_MON_HIDDEN_ABILITY_BIT(boxMon) { \
    u16 temp = GetBoxMonData(boxMon, MON_PARAM_DUMMY_2_1, NULL); \
    temp |= DUMMY_P2_1_HIDDEN_ABILITY_MASK; \
    SetBoxMonData(boxMon, MON_PARAM_DUMMY_2_1, (u8*) &temp); \
}

/*
 * Unmodified functions from vanilla game code
 */
u32  __attribute__((long_call)) GetBoxMonData(void *boxMon, int id, void *buf);     // GetBoxPkmnData @ 0x02074570
void __attribute__((long_call)) SetBoxMonData(void *boxMon, int id, void *buf);     // SetBoxPkmnData @ 0x02074C60
int  __attribute__((long_call)) GetSpeciesForForm(int species, int form);           // Function_2078740 (arm9)
u32  __attribute__((long_call)) GetBaseStatsData(int species, int form, int param); // GetPkmnBaseData2 @ 0x020759CC
BOOL __attribute__((long_call)) BoxMonSetFastModeOn(void *boxMon);                  // InitEncryptPkmnData_Part1 @ 0x02073D20
BOOL __attribute__((long_call)) BoxMonSetFastModeOff(void *boxMon);                 // InitEncryptPkmnData_Part1Again @ 0x02073D48

/*
 * New code
 */
u16  __attribute__((long_call)) GetMonHiddenAbility(u16 species, u32 form);
void __attribute__((long_call)) SetBoxMonAbility(void *boxMon);

#endif // __POKEMON_H