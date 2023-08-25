#ifndef __BATTLE_SERVER_H
#define __BATTLE_SERVER_H

#include "global.h"
#include "item.h"

#include "constants/moves.h"

#define PARTNER(battler)    (battler ^ 2)
#define ENEMY(battler)      (battler ^ 1)
#define ACROSS(battler)     (battler ^ 3)

struct __attribute__((packed)) BattleMove {
    u16 effect;                 // 0x00..0x01   ; 0x03DE    ; 0x317E
    u8  pss;                    // 0x02         ; 0x03E0    ; 0x3180
    u8  power;                  // 0x03         ; 0x03E1    ; 0x3181
    u8  type;                   // 0x04         ; 0x03E2    ; 0x3182
    u8  accuracy;               // 0x05         ; 0x03E3    ; 0x3183
    u8  pp;                     // 0x06         ; 0x03E4    ; 0x3184
    u8  secondaryChance;        // 0x07         ; 0x03E5    ; 0x3185
    u16 target;                 // 0x08..0x09   ; 0x03E6    ; 0x3186
    s8  priority;               // 0x0A         ; 0x03E8    ; 0x3188
    u8  flags;                  // 0x0B         ; 0x03E9    ; 0x3189
    u8  unk[4];                 // 0x0C..0x0F   ; 0x03EA    ; 0x318A
};  // size: 0x10

struct DamageDealtToMon {
    int dealt[4];       // This is the amount of damage dealt to a given mon by each client
    int lastDamager;    // This is the *last* client that dealt damage to this mon
    int allDamagers;    // This is a mask of *all* clients that dealt damage to this mon
};  // size: 0x18

struct __attribute__((packed)) SingleTurnEffects {
    u32 struggling      :1,                 // 0x00
        ppDecremented   :1,
        protected       :1,
        helpingHand     :1,
        magicCoat       :1,
        snatching       :1,
        roosting        :1,
        fleeing         :2,
        enduring        :1,
        _padding        :22;

    struct DamageDealtToMon physDamage;     // 0x04
    struct DamageDealtToMon specDamage;     // 0x1C
    
    int lastDamageDealt;    // This is for all damage types
    int lastDamagingClient;
    int assuranceDamageReceived;
};  // size: 0x40

struct __attribute__((packed)) SelfSingleTurnEffects {
    u32 noPressure          :1, // this should normally be on
        lightningRodActive  :1,
        stormDrainActive    :1,
        moldBreaker         :1,
        trickRoom           :1,
        endureItem          :1,
        rolloutCount        :3,
        _padding            :23;    // 0x00
    
    int physicalDamage;
    int physicalTarget;
    int specialDamage;
    int specialTarget;
    int statusFlag;
    int shellBellDamage;
};  // size: 0x1C

struct __attribute__((packed)) MoveFailedChecks {
    u32 fullyParalyzed      :1,
        ineffective         :1,
        imprisoned          :1,
        fullyInfatuated     :1,
        disabled            :1,
        taunted             :1,
        flinched            :1,
        confusionSelfHit    :1,
        gravityActive       :1,
        healBlockActive     :1,
        _padding            :22;
};  // size: 0x04

struct __attribute__((packed)) MoveEffects {
    u32 disabledTurns           :3,
        encoredTurns            :3,     // TODO: can reduce to 2 bits for gen 5
        chargedTurns            :2,
        tauntedTurns            :3,
        protectChainCount       :2,
        perishSongTurns         :2,
        rolloutChainCount       :3,
        furyCutterChainCount    :3,
        stockpileCount          :3,
        stockpileDefBoosts      :3,
        stockpileSpdBoosts      :3,
        truantActive            :1,
        flashFireActive         :1;
    
    u32 lockOnTarget            :2,
        mimicSlot               :4,     // Bitmask for which move slots are Mimic'd slots (why the fuck is this a mask???)
        boundTarget             :2,
        meanLookTarget          :2,     // TODO: no longer maintains trap after a Baton Pass
        lastResortMask          :3,
        magnetRiseTurns         :3,
        healBlockTurns          :3,
        embargoTurns            :3,
        canUnburden             :1,     // TODO: make sure this interacts correctly with Neutralizing Gas
        metronome               :4,     // this is for the item, not the move; stores the number of consecutive turns the same move has been used; TODO: we can reduce the bit allocation to 3 here
        oneTimeAccuracyMax      :1,     // micle berry
        oneTimeSpeedMax         :1,     // custap berry
        quickClawActive         :1,
        meFirstActive           :1,
        _padding                :1;
    
    int rechargeTurnCount;              // stores the turn counter for recharging after Hyper Beam
    int fakeOutTurnCount;
    int slowStartInitTurn;
    int meFirstTurnCount;
    int substituteHP;
    u32 formRand;                       // used for unown, spinda

    u16 disabledMove;
    u16 bindingMove;
    u16 encoredMove;
    u16 encoredMovePos;
    u16 lastResortMoves[4];
    u16 choicedMove;
    u16 transformedGender;

    int itemHPRestore;
};  // size: 0x0D

struct __attribute__((packed)) BattlePokemon {
    u16 species;
    u16 attack;
    u16 defense;
    u16 speed;
    u16 spAttack;
    u16 spDefense;
    u16 moves[4];

    u32 hpIV        :5,
        attackIV    :5,
        defenseIV   :5,
        speedIV     :5,
        spAttackIV  :5,
        spDefenseIV :5,
        isEgg       :1,
        hasNickname :1;
    
    s8  statBoosts[8];
    
    int weight;

    u8  type1;
    u8  type2;
    u8  formNum     :5,
        isShiny     :1,
        _padding_A  :2;
    u8  ability;

    u32 abilityAnnounced    :1, // new master flag
        intimidateDone      :1, // newly freed
        traceDone           :1,
        downloadDone        :1, // newly freed
        anticipationDone    :1, // newly freed
        forewarnDone        :1, // newly freed
        slowStartStarted    :1, // newly freed
        slowStartFinished   :1,
        friskDone           :1, // newly freed
        moldBreakerShown    :1, // newly freed
        pressureShown       :1, // newly freed
        _padding_B          :21;
    
    u8  curPP[4];
    u8  maxPP[4];

    u8  level;
    u8  friendship;
    u16 nickname[11];

    s32 curHP;
    u32 maxHP;

    u16 otName[8];

    u32 exp;
    u32 pid;
    u32 condition;
    u32 condition2;
    u32 idNumber;       // need to figure out what this does

    u16 heldItem;
    u16 dummy;

    u8  hitCount;
    u8  messageFlag;
    u8  gender          :4,
        otGender        :4;
    u8  caughtInBall;

    u32 moveEffectsMask;
    u32 moveEffectsTempMask;
    struct __attribute__((packed)) MoveEffects moveEffects;
};

struct __attribute__((packed)) FieldConditionCounts {
    u32 weatherTurns;               // 0x00

    u8  futureSightTurns[4];        // 0x04
    u8  wishTurns[4];               // 0x08

    u16 futureSightMoveID[4];       // 0x0C
    int futureSightAttacker[4];     // 0x14
    s32 futureSightDamage[4];       // 0x24

    u8  wishSelectedMon[4];         // 0x34
};  // size: 0x38

struct __attribute__((packed)) FieldConditions {
    u32 raw;                                // 0x00
    struct FieldConditionCounts counts;     // 0x04
};  // size: 0x3C

struct __attribute__((packed)) SideConditionCounts {
    u32 reflectUser         :2,     // 0x00
        reflectTurns        :3,
        lightScreenUser     :2,
        lightScreenTurns    :3,
        mistUser            :2,
        mistTurns           :3,
        safeguardUser       :2,
        safeguardTurns      :3,
        followMeActive      :1,
        followMeUser        :2,
        knockedOffItemID    :6,
        tailwindTurns       :3;
    
    u32 spikesLayers        :2,     // 0x04
        toxicSpikesLayers   :2,
        _padding            :28;
};  // size: 0x08

struct __attribute__((packed)) SideConditions {
    u32 raw[2];                             // 0x00
    struct SideConditionCounts counts[2];   // 0x08
};  // size: 0x18

struct __attribute__((packed)) SeqAndCheck {
    int     seqNum;
    int     temp;
};

struct __attribute__((packed)) MessageParams {
    u8  commandCode;    // 0x00
    u8  tag;            // 0x01
    u16 id;             // 0x02
    int params[6];      // 0x04
    int digits;         // 0x1C
    int client;         // 0x20
};  // size: 0x24

// This struct needs to be hella-investigated still
// mostly just what the fields actually are and do,
// not its structure
struct __attribute__((packed)) AIWork {
    u8  seqNum;                 // 0x00
    u8  movePos;                // 0x01
    u16 moveID;                 // 0x02..0x03
    s8  movePP[4];              // 0x04..0x07

    int calcWork;               // 0x08..0x0B
    u32 thinkingMask;           // 0x0C..0x0F

    u8  statusFlag;             // 0x10
    u8  thinkingSeq;            // 0x11
    u8  moveCheckLoopCount;     // 0x12
    u8  moveCheckStackPtr;      // 0x13
    u8  *moveCheckLoopAddr;     // 0x14..0x17
    u8  damageForMove[4];       // 0x18..0x1B
    u16 defenderMoves[4][4];    // 0x1C..0x3B
    u8  abilityNums[4];         // 0x3C..0x3F
    u16 heldItems[4];           // 0x40..0x47
    u16 bagItems[2][4];         // 0x48..0x57

    u32 stack[8];               // 0x58..0x77
    u8  stackSize;              // 0x78

    u8  itemCounts[2];          // 0x79..0x7A

    u8  attacker;               // 0x7B
    u8  defender;               // 0x7C
    u8  itemType[2];            // 0x7D..0x7E
    u8  itemCondition[2];       // 0x7F..0x80

    u8  _pad_0081;  // implicit padding, one byte

    u16 itemIDs[2];             // 0x82..0x85

    u8  dirSelectClient[4];     // 0x86..0x89

    struct BattleMove moveTable[468];   // 0x8A, length = 468 * 0x10 = 0x1D40; this is also 0x03DE in BattleServer

    u16 _pad_1DCA;              // 0x1DCA..0x1DCB

    struct ItemData   *itemTable;       // 0x1DCC..0x1DCF

    u16 calcCount[4];           // 0x1DD0..0x1DD7
    u16 calcInProgress[4];      // 0x1DD8..0x1DDF
};  // size: 0x1DE0

struct __attribute__((packed)) BattleServer {
/* 0x0000 */  u8      comSeqNum[4];
/* 0x0004 */  u8      retSeqNum[4];
/* 0x0008 */  int     serverSeqNum;
/* 0x000C */  int     serverSeqNext;

/* 0x0010 */  struct SeqAndCheck fieldConditionCheck;
/* 0x0018 */  struct SeqAndCheck pokeConditionCheck;
/* 0x0020 */  struct SeqAndCheck sideConditionCheck;
/* 0x0028 */  struct SeqAndCheck beforeActions;
/* 0x0030 */  struct SeqAndCheck afterMoveHitCheck;

/* 0x0038 */  int     afterMoveFailMessageType;
/* 0x003C */  int     afterMoveFailMessageSeqNum;

/* 0x0040 */  struct SeqAndCheck afterMoveFailEffects;

/* 0x0048 */  int     beforeMoveSeq;
/* 0x004C */  int     moveFailCheckSeq;
/* 0x0050 */  int     serverStatusCheckSeq;
/* 0x0054 */  int     serverAbilityCheckSeq;
/* 0x0058 */  int     serverSwitchInEffectsSeq;
/* 0x005C */  int     serverVanishCheckTemp;

/* 0x0060 */  int     moveSeqAddress;
/* 0x0064 */  int     attacker;
/* 0x0068 */  int     attackerTemp;
/* 0x006C */  int     defender;
/* 0x0070 */  int     defenderTemp;
/* 0x0074 */  int     faintingClient;
/* 0x0078 */  int     switchingClient;
/* 0x007C */  int     switchingClientTemp;
/* 0x0080 */  int     abilityCheckClient;
/* 0x0084 */  int     magicCoatClient;

/* 0x0088 */  int     addlEffectType;
/* 0x008C */  int     addlEffectParam;
/* 0x0090 */  int     addlEffectFlags;
/* 0x0094 */  int     addlEffectClient;

/* 0x0098 */  int     clientStorage;

/* 0x009C */  int     expGained;
/* 0x00A0 */  int     extraExpGained;
/* 0x00A4 */  u32     monsGainingExp[2];

/* 0x00AC */  int     moveSeqArchive;     // which archive to load from
/* 0x00B0 */  int     moveSeqIndex;       // which sequence to load
/* 0x00B4 */  int     moveSeqNum;         // where we are in the sequence

/* 0x00B8 */  int     stackPtr;
/* 0x00BC */  int     stackPtrMoveSeqArchive[4];
/* 0x00CC */  int     stackPtrMoveSeqIndex[4];
/* 0x00DC */  int     stackPtrMoveSeqNum[4];

/* 0x00EC */  int     speedCount;
/* 0x00F0 */  int     waitCount;

/* 0x00F4 */  struct MessageParams messageParams;

/* 0x0118 */  int     clientWork;
/* 0x011C */  int     attackerWork;
/* 0x0120 */  int     defenderWork;
/* 0x0124 */  int     moveWork;
/* 0x0128 */  int     itemWork;
/* 0x012C */  int     abilityWork;
/* 0x0130 */  int     messageWork;
/* 0x0134 */  int     calcWork;
/* 0x0138 */  int     tempWork;

/* 0x013C */  u32     clientStatus[4];
/* 0x014C */  u32     payDayCount;
/* 0x0150 */  int     totalTurns;
/* 0x0154 */  int     totalDeaths[4];
/* 0x0164 */  int     totalDamage[4];
/* 0x0174 */  int     meFirstTotalTurnOrder;

/* 0x0178 */  void *skillSequenceWork;    // TODO: document
/* 0x017C */  void *work;

/* 0x0180 */  struct FieldConditions       fieldConditions;
/* 0x01BC */  struct SideConditions        sideConditions;
/* 0x01D4 */  struct SingleTurnEffects     stFX[4];
/* 0x02D4 */  struct SelfSingleTurnEffects stSelfFX[4];
/* 0x0344 */  struct MoveFailedChecks      moveFailChecks[4];

/* 0x0354 */  struct AIWork aiWork;
/* 0x2134 */  u32           *aiSeqWork;
/* 0x2138 */  u32           aiSeqAddr;

/* 0x213C */  u32     serverStatusFlag;
/* 0x2140 */  u32     serverStatusFlag2;

/* 0x2144 */  int     damage;
/* 0x2148 */  int     trueDamage;     // this is the amount of HP actually reduced (so it accounts for fainted mons)
/* 0x214C */  int     criticalCount;
/* 0x2150 */  BOOL    critical;
/* 0x2154 */  int     movePower;      // stores the final power of a move (mostly important for variable power moves)
/* 0x2158 */  u32     powerModifier; // stores any move-specific contextual damage multipliers (e.g. Revenge)
/* 0x215C */  int     hpCalcWork;
/* 0x2160 */  int     moveType;
/* 0x2164 */  int     moveEffectCounter;
/* 0x2168 */  int     moneyMultiplier;    // amulet coin
/* 0x216C */  u32     moveStatusFlag;
/* 0x2170 */  u32     addlDirectStatus;
/* 0x2174 */  u32     addlIndirectStatus;
/* 0x2178 */  u32     addlAbilityStatus;
/* 0x217C */  u8      multiHitCounter;
/* 0x217D */  u8      multiHitCounterTemp;
/* 0x217E */  u8      multiHitLoopCounter;    // for spread moves
/* 0x217F */  u8      beatUpCount;

/* 0x2180 */  u32     loopingFlag;
/* 0x2184 */  u32     moveFailedCheck;
/* 0x2188 */  u32     loopingHitCheck;

/* 0x218C */  u32     condition2ClearRequest[4];

/* 0x219C */  u8      selectedMonNum[4];
/* 0x21A0 */  u8      switchSelectedMonNum[4];
/* 0x21A4 */  u8      aiSwitchSelectedMonNum[4];
/* 0x21A8 */  u32     clientActionWork[4][4];
/* 0x21E8 */  u8      clientSpeedWork[4];
/* 0x21EC */  u8      pokemonSpeedWork[4];
/* 0x21F0 */  u32     pokemonSpeedValues[4];

/* 0x2200 */  u8      serverQueue[4][4][16];
/* 0x2300 */  u8      serverBuffer[4][256];

/* 0x2700 */  int     moveSeqWork[400];

/* 0x2D40 */  struct BattlePokemon    activePokemon[4];

/* 0x3040 */  u32     moveIDTemp;
/* 0x3044 */  u32     moveIDCurr;
/* 0x3048 */  u32     moveIDLast;
/* 0x304C */  u32     moveIDMultiTurn[4];
    
/* 0x305C */  u16     moveIDProtect[4];
/* 0x3064 */  u16     moveIDHit[4];
/* 0x306C */  u16     moveIDHitClient[4];
/* 0x3074 */  u16     moveIDHitType[4];
/* 0x307C */  u16     moveIDOld[4];
/* 0x3084 */  u16     moveIDMirrorMove[4];
/* 0x308C */  u16     moveIDMirrorMoveHit[4][4];
/* 0x30AC */  u16     moveIDSketch[4];
/* 0x30B4 */  u16     moveIDSelected[4];
/* 0x30BC */  u16     moveIDPos[4];
/* 0x30C4 */  u16     moveIDConversion2[4];
/* 0x30CC */  u16     moveIDConversion2Client[4];
/* 0x30D4 */  u16     moveIDConversion2Type[4];
/* 0x30DC */  u16     moveIDMetronome[4];     // for the item, not the move

/* 0x30E4 */  int     storedDamage[4];        // for Bide
/* 0x30F4 */  int     clientNumHit[4];
/* 0x3104 */  int     clientNumSpeed;
/* 0x3108 */  u8      clientSwitchingTo;
/* 0x3109 */  u8      pokemonLevelUp;
/* 0x310A */  u16     queueCheckWait;

/* 0x310C */  u16     speedRand[4];           // for breaking speed ties

/* 0x3114 */  int     flingWork;
/* 0x3118 */  int     flingSeqNum;

/* 0x311C */  u8      safariCatchRateCounter;
/* 0x311D */  u8      safariFleeRateCounter;
/* 0x311E */  u8      fleeRateCounter;
/* 0x311F */  u8      fightOver;

/* 0x3120 */  u8      magnitude;

/* 0x3121 */  u8      fieldWeatherChecked;
    
/* 0x3122 */  s16     hpTemp;

/* 0x3124 */  u16     recyclableItem[4];

/* 0x312C */  u8      partyOrder[4][6];

/* 0x3144 */  BOOL    jingle;

/* 0x3148 */  int     serverQueueTimeOut;

/* 0x314C */  u8      recordingFlags[4];

/* 0x3150 */  int     clientWorkingCounter;

/* 0x3154 */  u32     battleProgressFlag;

    // new stuff starts here
/* 0x3158 */  u8      padding_3158[0x26];     // gets the move table to 317E (for convenience of 3180 in ASM)

/* 0x317E */  struct BattleMove moveTable[TOTAL_NUM_MOVES];
};

enum BattleServerParam {
    SERVER_PARAM_SIDE_CONDITIONS,
    SERVER_PARAM_MIST_TURNS,
    SERVER_PARAM_SELECTED_MON_POS,
    SERVER_PARAM_TOTAL_TURNS,
    SERVER_PARAM_LEVEL_UP_POKEMON,
    SERVER_PARAM_SAFARI_ESCAPE_COUNT,
    SERVER_PARAM_TOTAL_FAINTED,
    SERVER_PARAM_TOTAL_DAMAGE,
    SERVER_PARAM_ACTION_NUM,
    SERVER_PARAM_AI_DEFENDER,
    SERVER_PARAM_SWITCHING_CLIENT,
    SERVER_PARAM_AI_SELECTED_CLIENT,
    SERVER_PARAM_CLIENT_ACTION_WORK,
    SERVER_PARAM_SERVER_SEQ_NUM,
    SERVER_PARAM_SERVER_SEQ_NEXT
};

enum BattlePokemonParam {
    BATTLE_MON_PARAM_SPECIES,
    BATTLE_MON_PARAM_ATTACK,
    BATTLE_MON_PARAM_DEFENSE,
    BATTLE_MON_PARAM_SPEED,
    BATTLE_MON_PARAM_SPATTACK,
    BATTLE_MON_PARAM_SPDEFENSE,
    BATTLE_MON_PARAM_MOVE_1,
    BATTLE_MON_PARAM_MOVE_2,
    BATTLE_MON_PARAM_MOVE_3,
    BATTLE_MON_PARAM_MOVE_4,
    BATTLE_MON_PARAM_HP_IV,
    BATTLE_MON_PARAM_ATTACK_IV,
    BATTLE_MON_PARAM_DEFENSE_IV,
    BATTLE_MON_PARAM_SPEED_IV,
    BATTLE_MON_PARAM_SPATTACK_IV,
    BATTLE_MON_PARAM_SPDEFENSE_IV,
    BATTLE_MON_PARAM_IS_EGG,
    BATTLE_MON_PARAM_HAS_NICKNAME,
    BATTLE_MON_PARAM_HP_STAGES,
    BATTLE_MON_PARAM_ATTACK_STAGES,
    BATTLE_MON_PARAM_DEFENSE_STAGES,
    BATTLE_MON_PARAM_SPEED_STAGES,
    BATTLE_MON_PARAM_SPATTACK_STAGES,
    BATTLE_MON_PARAM_SPDEFENSE_STAGES,
    BATTLE_MON_PARAM_ACCURACY_STAGES,
    BATTLE_MON_PARAM_EVASION_STAGES,
    BATTLE_MON_PARAM_ABILITY,
    BATTLE_MON_PARAM_TYPE_1,
    BATTLE_MON_PARAM_TYPE_2,
    BATTLE_MON_PARAM_GENDER,
    BATTLE_MON_PARAM_IS_SHINY,
    BATTLE_MON_PARAM_PP_1,
    BATTLE_MON_PARAM_PP_2,
    BATTLE_MON_PARAM_PP_3,
    BATTLE_MON_PARAM_PP_4,
    BATTLE_MON_PARAM_PP_UP_COUNT_1,
    BATTLE_MON_PARAM_PP_UP_COUNT_2,
    BATTLE_MON_PARAM_PP_UP_COUNT_3,
    BATTLE_MON_PARAM_PP_UP_COUNT_4,
    BATTLE_MON_PARAM_PP_MAX_1,
    BATTLE_MON_PARAM_PP_MAX_2,
    BATTLE_MON_PARAM_PP_MAX_3,
    BATTLE_MON_PARAM_PP_MAX_4,
    BATTLE_MON_PARAM_LEVEL,
    BATTLE_MON_PARAM_FRIENDSHIP,
    BATTLE_MON_PARAM_NICKNAME,
    BATTLE_MON_PARAM_NICKNAME_CHARS,
    BATTLE_MON_PARAM_HP_CURRENT,
    BATTLE_MON_PARAM_HP_MAX,
    BATTLE_MON_PARAM_OT_NAME,
    BATTLE_MON_PARAM_EXP,
    BATTLE_MON_PARAM_PID,
    BATTLE_MON_PARAM_CONDITION,
    BATTLE_MON_PARAM_CONDITION_V,
    BATTLE_MON_PARAM_ID_NUMBER,
    BATTLE_MON_PARAM_HELD_ITEM,
    BATTLE_MON_PARAM_HIT_COUNT,
    BATTLE_MON_PARAM_MESSAGE_FLAG,
    BATTLE_MON_PARAM_OT_GENDER,
    BATTLE_MON_PARAM_MOVE_EFFECTS,
    BATTLE_MON_PARAM_MOVE_EFFECTS_TEMP,
    BATTLE_MON_PARAM_DISABLED_TURNS,
    BATTLE_MON_PARAM_ENCORED_TURNS,
    BATTLE_MON_PARAM_CHARGED_TURNS,
    BATTLE_MON_PARAM_TAUNTED_TURNS,
    BATTLE_MON_PARAM_PROTECT_CHAIN_COUNT,
    BATTLE_MON_PARAM_PERISH_SONG_TURNS,
    BATTLE_MON_PARAM_ROLLOUT_CHAIN_COUNT,
    BATTLE_MON_PARAM_FURY_CUTTER_CHAIN_COUNT,
    BATTLE_MON_PARAM_STOCKPILE_COUNT,
    BATTLE_MON_PARAM_STOCKPILE_DEF_BOOSTS,
    BATTLE_MON_PARAM_STOCKPILE_SPD_BOOSTS,
    BATTLE_MON_PARAM_TRUANT_ACTIVE,
    BATTLE_MON_PARAM_FLASH_FIRE_ACTIVE,
    BATTLE_MON_PARAM_LOCKED_ON,
    BATTLE_MON_PARAM_MIMIC_SLOT,
    BATTLE_MON_PARAM_BOUND_TARGET,
    BATTLE_MON_PARAM_MEAN_LOOK_TARGET,
    BATTLE_MON_PARAM_LAST_RESORT_MASK,
    BATTLE_MON_PARAM_MAGNET_RISE_TURNS,
    BATTLE_MON_PARAM_HEAL_BLOCK_TURNS,
    BATTLE_MON_PARAM_EMBARGO_TURNS,
    BATTLE_MON_PARAM_UNBURDEN_ACTIVE,
    BATTLE_MON_PARAM_METRONOME,
    BATTLE_MON_PARAM_ONE_TIME_ACC_MAX,
    BATTLE_MON_PARAM_ONE_TIME_SPE_MAX,
    BATTLE_MON_PARAM_QUICK_CLAW_ACTIVE,
    BATTLE_MON_PARAM_RECHARGE_TURN_COUNT,
    BATTLE_MON_PARAM_FAKE_OUT_TURN_COUNT,
    BATTLE_MON_PARAM_SLOW_START_INIT_TURN,
    BATTLE_MON_PARAM_SUBSTITUTE_HP,
    BATTLE_MON_PARAM_FORM_RAND,
    BATTLE_MON_PARAM_DISABLED_MOVE,
    BATTLE_MON_PARAM_ENCORED_MOVE,
    BATTLE_MON_PARAM_BINDING_MOVE,
    BATTLE_MON_PARAM_ITEM_HP_RESTORE,
    BATTLE_MON_PARAM_SLOW_START_FLAG,
    BATTLE_MON_PARAM_SLOW_START_END_FLAG,
    BATTLE_MON_PARAM_FORM_NUMBER
};

enum CheckAbilityMode {
    CHECK_ABILITY_EXISTS_ON_MY_SIDE,    // checks if the ability exists on the battler's side
    CHECK_ABILITY_ACTIVE_ON_MY_SIDE,    // checks if the ability is active on the battler's side (haver is alive)
    CHECK_ABILITY_EXISTS_ON_ENEMY_SIDE, // as above, but on the enemy's side
    CHECK_ABILITY_ACTIVE_ON_ENEMY_SIDE, // as above, but on the enemy's side
    CHECK_ABILITY_ACTIVE_CLIENT_ENEMY_SIDE, // return which battler on the enemy side has the ability
    CHECK_ABILITY_EXISTS,               // as above, but side-agnostic
    CHECK_ABILITY_EXISTS_NOT_MINE,      // check if the ability exists for any battler except the input
    CHECK_ABILITY_EXISTS_CLIENT_NOT_MINE,
    CHECK_ABILITY_ACTIVE,               // as above, but side-agnostic
    CHECK_ABILITY_ACTIVE_NOT_MINE,      // check if the ability is active from any battler except the input
};

/**
 * @brief Get a piece of data from th server, considering a particular battler.
 * 
 * Original function: 0x0225B45C (ov16)
 */
int __attribute__((long_call)) Server_Get(struct Battle *battle, struct BattleServer *server, int paramID, int battler);

/**
 * @brief Gets the ability for a particular battler, considering suppression effects.
 * 
 * Original function: 0x02255A4C (ov16)
 */
u8 __attribute__((long_call)) Server_Ability(struct BattleServer *server, int battler);

/**
 * @brief Check if any active battler has a particular move effect active.
 * 
 * Original function: 0x02255F68 (ov16)
 */
BOOL __attribute__((long_call)) Server_CheckActiveMoveEffect(struct Battle *battle, struct BattleServer *server, int effect);

/**
 * @brief Check if an ability is active. Exact functionality varies with the input to checkMode.
 * 
 * Original function: 0x022555A4 (ov16)
 */
int __attribute__((long_call)) Server_CheckAbility(struct Battle *battle, struct BattleServer *server, int checkMode, int battler, int ability);

/**
 * @brief Check if the defender has a given ability, ignoring it if the attacker has Mold Breaker.
 * 
 * Original function: 0x02255AB4 (ov16)
 */
BOOL __attribute__((long_call)) Server_CheckDefenderAbility(struct BattleServer *server, int attacker, int defender, int ability);

/**
 * @brief Checks if a given battler is behind a Substitute.
 * 
 * Original function: 0x02259AC0 (ov16)
 */
BOOL __attribute__((long_call)) Server_CheckSubstitute(struct BattleServer *server, int battler);

/**
 * @brief Gets the held item effect of a given active battler.
 * 
 * Original function: 0x02258AB8 (ov16)
 */
s32 __attribute__((long_call)) Server_HeldItemEffect(struct BattleServer *server, int battler);

/**
 * @brief Gets the held item power of a given active battler.
 * 
 * Original function: 0x02258ACC (ov16)
 * 
 * Flag:
 * - 0: Gets the battler's item. Does some extra checks (?)
 * - 1: Gets the battler's item, no extra checks
 * - 2: Checks for Embargo before getting the item
 */
s32 __attribute__((long_call)) Server_HeldItemPower(struct BattleServer *server, int battler, int flag);

/**
 * @brief Divide one value by another.
 * 
 * Original function: 0x022563F8 (ov16)
 */
int __attribute__((long_call)) Server_DivideBy(int numerator, int denominator);

/**
 * @brief Checks how many hits occurred for the current move.
 * 
 * If flag is 0, then all clients will be considered.
 * If flag is 1, then only clients on the same side as the input battler
 * will be considered.
 * 
 * Original function: 0x022554E0 (ov16)
 */
u8 __attribute__((long_call)) Server_HitCount(struct Battle *battle, struct BattleServer *server, int flag, int battler);

/**
 * @brief Checks if a given move is a 2-turn move.
 * 
 * Original function: 0x0225B6C8 (ov16)
 */
BOOL __attribute__((long_call)) Server_CheckTwoTurnMove(struct BattleServer *server, int moveID);

/**
 * @brief Load a sequence by its ID from a given archive.
 * 
 * This is used to queue up individual subscripts, mostly.
 * 
 * Original function: 0x02251E1C (ov16)
 * 
 * @param server
 * @param archive   ID for a given script archive.
 * @param id        ID of the script to load.
 */
void __attribute__((long_call)) Server_LoadSequence(struct BattleServer *server, int archive, int id);

/**
 * @brief Copy a BattlePokemon data over to the underlying Pokemon struct.
 * 
 * Original function: 0x02253EC0 (ov16)
 */
void __attribute__((long_call)) Server_CopyBattleMonData(struct Battle *battle, struct BattleServer *server, int battler);

/**
 * @brief Makes a parameter structure for a given battler's nickname.
 * 
 * Original function: 0x02255560 (ov16)
 */
int __attribute__((long_call)) Server_NicknameParam(struct BattleServer *server, int battler);

/**
 * @brief Gets a data value for a particular active battler.
 * 
 * Original function: 0x02252060 (ov16)
 */
int __attribute__((long_call)) BattlePokemon_Get(struct BattleServer *server, int battler, int paramID, void *data);

/**
 * @brief Adds a value to a given data point on a battler.
 * 
 * Original function: 0x02252A2C (ov16)
 */
void __attribute__((long_call)) BattlePokemon_Add(struct BattlePokemon *pokemon, int paramID, int toAdd);


/**
 * @brief Master damage calc function.
 * 
 * Hooked into: 0x02241374 (ov16)
 */
void __attribute__((long_call)) Calc_MoveDamage(struct Battle *battle, struct BattleServer *server);

/**
 * @brief Master critical determination function.
 * 
 * Hooked into: 0x0225A280 (ov16)
 * 
 * @return TRUE if a critical hit should occur, FALSE otherwise.
 */
BOOL __attribute__((long_call)) Calc_Critical(struct Battle *battle, struct BattleServer *server);

/**
 * @brief Only here to hook into the Stealth Rock check.
 * 
 * Hooked into: 0x022558CC (ov16)
 */
int  __attribute__((long_call)) Calc_TypeEffectivenessPower(u8 moveType, u8 pokeType1, u8 pokeType2);

/**
 * @brief Checks for abilities which trigger after a move deals damage.
 * 
 * Hooked into: 0x0225708C (ov16)
 * 
 * @param battle
 * @param server
 * @param seqNum Outputs the script sequence to next invoke, if any
 * @return TRUE if a sequence needs to be loaded for follow-up, otherwise FALSE.
 */
BOOL __attribute__((long_call)) Server_CheckAbilityOnHit(struct Battle *battle, struct BattleServer *server, int *seqNum);

/**
 * @brief Check for King's Rock application.
 * 
 * Hooked into: 0x022512F8 (ov16)
 * 
 * @param battle
 * @param server
 * @return TRUE if King's Rock activates, otherwise FALSE.
 */
BOOL __attribute__((long_call)) Server_CheckExtraFlinch(struct Battle *battle, struct BattleServer *server);

/**
 * @brief Check for abilities which alter the damaging properties of moves.
 * 
 * This is for stuff like Volt Absorb and Flash Fire.
 * 
 * Hooked into: 0x02256148 (ov16)
 * 
 * @param server
 * @param attacker
 * @param defender
 * @return ID of the subscript to invoke next for the ability trigger, if any.
 */
int  __attribute__((long_call)) Server_CheckAbilityDamageOverride(struct BattleServer *server, int attacker, int defender);

/**
 * @brief Check for abilities which trigger at the end of the turn.
 * 
 * Hooked into: 0x022562E8 (ov16)
 * 
 * @param battle
 * @param server
 * @param battler
 * @return TRUE if a subscript needs to be invoked, otherwise FALSE.
 */
BOOL __attribute__((long_call)) Server_CheckEndOfTurnAbility(struct Battle *battle, struct BattleServer *server, int battler);

/**
 * @brief Check for effects which trigger on switch-in.
 * 
 * Hooked into: 0x02256414 (ov16)
 * 
 * @return Any script that should be called as an effect handler.
 */
int  __attribute__((long_call)) Server_CheckSwitchInEffects(struct Battle *battle, struct BattleServer *server);

#endif // __BATTLE_SERVER_H