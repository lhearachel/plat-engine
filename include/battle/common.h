#ifndef __BATTLE_COMMON_H
#define __BATTLE_COMMON_H

#include "typedefs.h"

#include "lib/string.h"
#include "ui/window.h"

// ========================================================================= //
//                         BATTLE TYPE CONSTANTS                             //
// ========================================================================= //

// These are definitions for the various types of battles supported in the engine.
// Each is represented as a bit-flag, allowing them to be stacked atop one another.
// Note that not specifying the `DOUBLES` flag implicitly turns a battle into a
// Single-battle.
#define BATTLE_TYPE_SINGLES         (0x00000000)    ///< Single-battle
#define BATTLE_TYPE_WILD_MON        (0x00000000)    ///< Wild Pokemon, implicitly singles
#define BATTLE_TYPE_TRAINER         (0x00000001)    ///< Trainer battle
#define BATTLE_TYPE_DOUBLES         (0x00000002)    ///< Double-battle
#define BATTLE_TYPE_LINK            (0x00000004)    ///< Link room battle (vs another player)
#define BATTLE_TYPE_2vs2            (0x00000008)    ///< Two clients per side
#define BATTLE_TYPE_TAG             (0x00000010)    ///< 1vs2 battle
#define BATTLE_TYPE_SAFARI          (0x00000020)    ///< Safari Zone (no mon sent out from player)
#define BATTLE_TYPE_AI              (0x00000040)    ///< at least one client is AI-controlled
#define BATTLE_TYPE_TOWER           (0x00000080)    ///< vs Battle Tower trainer
#define BATTLE_TYPE_ROAMER          (0x00000100)    ///< vs Roaming Pokemon
#define BATTLE_TYPE_PAL_PARK        (0x00000200)    ///< Pal Park (no mon sent out from player)
#define BATTLE_TYPE_CATCH_TUTORIAL  (0x00000400)    ///< Catching tutorial (scripted)

#define BATTLE_TYPE_DEBUG           (0x80000000)

// These are convenience types which combined the various bit-flags together into
// more complete battle types.
#define BATTLE_TYPE_ONE_WILD_MON            (BATTLE_TYPE_SINGLES | BATTLE_TYPE_WILD_MON)
#define BATTLE_TYPE_TWO_WILD_MONS           (BATTLE_TYPE_DOUBLES | BATTLE_TYPE_WILD_MON)
#define BATTLE_TYPE_TWO_WILD_MONS_PARTNER   (BATTLE_TYPE_DOUBLES | BATTLE_TYPE_WILD_MON | BATTLE_TYPE_AI)
#define BATTLE_TYPE_ONE_TRAINER_SINGLES     (BATTLE_TYPE_SINGLES | BATTLE_TYPE_TRAINER)
#define BATTLE_TYPE_ONE_TRAINER_DOUBLES     (BATTLE_TYPE_DOUBLES | BATTLE_TYPE_TRAINER)
#define BATTLE_TYPE_TWO_TRAINERS            (BATTLE_TYPE_DOUBLES | BATTLE_TYPE_TRAINER | BATTLE_TYPE_TAG)
#define BATTLE_TYPE_TWO_TRAINERS_PARTNER    (BATTLE_TYPE_TWO_TRAINERS | BATTLE_TYPE_2vs2 | BATTLE_TYPE_AI)

// These are fights which will disable EXP gain.
#define BATTLE_TYPE_NO_EXP  (BATTLE_TYPE_LINK | BATTLE_TYPE_SAFARI | BATTLE_TYPE_SAFARI | BATTLE_TYPE_PAL_PARK)

// These are fights which will use the built-in battle AI for move determination.
#define BATTLE_TYPE_USE_AI_CALC (BATTLE_TYPE_TRAINER | BATTLE_TYPE_ROAMER)


// ========================================================================= //
//                        BATTLE RESULT CONSTANTS                            //
// ========================================================================= //

#define BATTLE_WIN                  (0x01)
#define BATTLE_LOSE                 (0x02)
#define BATTLE_DRAW                 (0x03)
#define BATTLE_CAUGHT_WILD          (0x04)
#define BATTLE_ESCAPE               (0x05)
#define BATTLE_ENEMY_ESCAPE         (0x06)

#define BATTLE_ESCAPE_SELECT_PAUSE  (0x40)
#define BATTLE_ESCAPE_SELECT        (0x80)
#define BATTLE_ESCAPE_SELECT_OFF    (0xC0 ^ 0xFF)


// ========================================================================= //
//                        BATTLE CLIENT CONSTANTS                            //
// ========================================================================= //

#define CLIENT_PLAYER           0
#define CLIENT_ENEMY            1
#define CLIENT_PARTNER          2
#define CLIENT_ENEMY_PARTNER    3

#define SIDE_ALL                (0x00)
#define SIDE_ATTACKER           (0x01)
#define SIDE_DEFENDER           (0x02)
#define SIDE_MINE               (0x03)
#define SIDE_ENEMY              (0x04)
#define SIDE_FAINTED            (0x05)
#define SIDE_SWITCHED           (0x06)
#define SIDE_ADDL_EFFECTS       (0x07)
#define SIDE_ABILITY            (0x08)
#define SIDE_MINE_SLOT_1        (0x09)
#define SIDE_ENEMY_SLOT_1       (0x0A)
#define SIDE_MINE_SLOT_2        (0x0B)
#define SIDE_ENEMY_SLOT_2       (0x0C)
#define SIDE_ATTACKER_WORK      (0x0E)
#define SIDE_DEFENDER_WORK      (0x0F)
#define SIDE_ATTACKER_PARTNER   (0x10)
#define SIDE_DEFENDER_PARTNER   (0x11)
#define SIDE_WHITE_OUT          (0x12)
#define SIDE_ATTACKER_ENEMY     (0x13)
#define SIDE_DEFENDER_ENEMY     (0x14)
#define SIDE_CLIENT_WORK        (0x15)
#define SIDE_SWITCHED_AFTER     (0x16)


// ========================================================================= //
//                     SERVER STATUS FLAG CONSTANTS                          //
// ========================================================================= //

#define SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE    (0x00000001)
#define SERVER_STATUS_FLAG_NO_DOUBLE_CHECK      (0x00000002)
#define SERVER_STATUS_FLAG_HIT_FLYING_MON       (0x00000004)
#define SERVER_STATUS_FLAG_HIT_DIGGING_MON      (0x00000008)
#define SERVER_STATUS_FLAG_HIT_DIVING_MON       (0x00000010)
#define SERVER_STATUS_FLAG_TURN_ONE_OF_TWO      (0x00000020)
#define SERVER_STATUS_FLAG_DO_NOT_BLINK         (0x00000040)
#define SERVER_STATUS_FLAG_SYNCHRONIZE          (0x00000080)
#define SERVER_STATUS_FLAG_BATON_PASS           (0x00000100)
#define SERVER_STATUS_FLAG_TURN_TWO_OF_TWO      (0x00000200)
#define SERVER_STATUS_FLAG_FLAT_HIT_RATE        (0x00000400)
#define SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS (0x00000800)    // this is specifically super/not-very effective modifiers
#define SERVER_STATUS_FLAG_CRASH_DAMAGE         (0x00001000)
#define SERVER_STATUS_FLAG_MOVE_SUCCESSFUL      (0x00002000)
#define SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF  (0x00004000)
#define SERVER_STATUS_FLAG_IGNORE_IMMUNITIES    (0x00008000)    // this is specifically for immunities
#define SERVER_STATUS_FLAG_MULTI_HIT_NO_MESSAGE (0x00010000)
#define SERVER_STATUS_FLAG_NO_MESSAGE_BETWEEN   (0x00020000)
#define SERVER_STATUS_FLAG_MESSAGE_AFTER_MISS   (0x00040000)
#define SERVER_STATUS_FLAG_HIT_SHADOW_FORCE     (0x00080000)
#define SERVER_STATUS_FLAG_NO_MOVE_SET          (0x00100000)
#define SERVER_STATUS_FLAG_TURN_OFF_MESSAGES    (0x00200000)
#define SERVER_STATUS_FLAG_EFFECT               (0x00400000)
#define SERVER_STATUS_FLAG_MOLD_BREAKER         (0x00800000)

#define SERVER_STATUS_FLAG_ANY_FAINTED_MON      (0x0F000000)    // this is 4 flags in 1, 1 for each client

#define SERVER_STATUS_FLAG_SELF_DESTRUCT        (0x10000000)
#define SERVER_STATUS_FLAG_ANY_SELF_DESTRUCTING (0xF0000000)    // this is also 4 flags in 1, 1 for each client

#define SERVER_STATUS_FLAG_START_OF_TURN        (SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE \
                                                | SERVER_STATUS_FLAG_NO_DOUBLE_CHECK \
                                                | SERVER_STATUS_FLAG_HIT_FLYING_MON \
                                                | SERVER_STATUS_FLAG_HIT_DIGGING_MON \
                                                | SERVER_STATUS_FLAG_HIT_DIVING_MON \
                                                | SERVER_STATUS_FLAG_TURN_ONE_OF_TWO \
                                                | SERVER_STATUS_FLAG_DO_NOT_BLINK \
                                                | SERVER_STATUS_FLAG_SYNCHRONIZE \
                                                | SERVER_STATUS_FLAG_BATON_PASS \
                                                | SERVER_STATUS_FLAG_TURN_TWO_OF_TWO \
                                                | SERVER_STATUS_FLAG_FLAT_HIT_RATE \
                                                | SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS \
                                                | SERVER_STATUS_FLAG_CRASH_DAMAGE \
                                                | SERVER_STATUS_FLAG_MOVE_SUCCESSFUL \
                                                | SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF \
                                                | SERVER_STATUS_FLAG_IGNORE_IMMUNITIES \
                                                | SERVER_STATUS_FLAG_MULTI_HIT_NO_MESSAGE \
                                                | SERVER_STATUS_FLAG_NO_MESSAGE_BETWEEN \
                                                | SERVER_STATUS_FLAG_MESSAGE_AFTER_MISS \
                                                | SERVER_STATUS_FLAG_HIT_SHADOW_FORCE \
                                                | SERVER_STATUS_FLAG_NO_MOVE_SET \
                                                | SERVER_STATUS_FLAG_TURN_OFF_MESSAGES \
                                                | SERVER_STATUS_FLAG_EFFECT) ^ ~0


// ========================================================================= //
//                    SERVER STATUS FLAG 2 CONSTANTS                         //
// ========================================================================= //

#define SERVER_STATUS_FLAG2_NO_EXPERIENCE_GIVEN (0x00000001)
#define SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES  (0x00000002)
#define SERVER_STATUS_FLAG2_DISPLAY_ATTACK_MSG  (0x00000004)
#define SERVER_STATUS_FLAG2_MAGIC_COAT_SWAP     (0x00000008)
#define SERVER_STATUS_FLAG2_PIVOT_MOVE          (0x00000010)
#define SERVER_STATUS_FLAG2_FIRST_DAMAGE_MSG    (0x00000020)
#define SERVER_STATUS_FLAG2_MOVE_FAILED_ON_USE  (0x00000040)
#define SERVER_STATUS_FLAG2_CHECK_STAT_STAGES   (0x00000080)
#define SERVER_STATUS_FLAG2_RECOVERY_EFFECT     (0x00000100)

#define SERVER_STATUS_FLAG2_FORM_CHANGE         (0x04000000)
#define SERVER_STATUS_FLAG2_RECALC_MON_STATS    (0x08000000)
#define SERVER_STATUS_FLAG2_BATTLER_GETS_EXP    (0xF0000000)    // 4 flags in 1, 1 for each client getting exp

#define SERVER_STATUS_FLAG2_START_OF_TURN       (SERVER_STATUS_FLAG2_UPDATE_STAT_STAGES \
                                                | SERVER_STATUS_FLAG2_DISPLAY_ATTACK_MSG \
                                                | SERVER_STATUS_FLAG2_MAGIC_COAT_SWAP \
                                                | SERVER_STATUS_FLAG2_PIVOT_MOVE \
                                                | SERVER_STATUS_FLAG2_MOVE_FAILED_ON_USE \
                                                | SERVER_STATUS_FLAG2_RECOVERY_EFFECT) ^ ~0


// ========================================================================= //
//                        SINGLE TURN STATUS FLAGS                           //
// ========================================================================= //

#define SINGLE_TURN_STATUS_FLAG_RESIST_BERRY    (0x00000001)
#define SINGLE_TURN_STATUS_FLAG_PLUCK_BERRY     (0x00000002)
#define SINGLE_TURN_STATUS_INFATUATED           (0x00000004)
#define SINGLE_TURN_STATUS_HIT_SUBSTITUTE       (0x00000008)


// ========================================================================= //
//                       MOVE STATUS FLAG CONSTANTS                          //
// ========================================================================= //

#define MOVE_STATUS_FLAG_MISSED                     (0x00000001)
#define MOVE_STATUS_FLAG_SUPER_EFFECTIVE            (0x00000002)
#define MOVE_STATUS_FLAG_NOT_VERY_EFFECTIVE         (0x00000004)
#define MOVE_STATUS_FLAG_DOES_NOT_AFFECT            (0x00000008)
#define MOVE_STATUS_FLAG_CRITICAL_HIT               (0x00000010)
#define MOVE_STATUS_FLAG_ONE_HIT_KO                 (0x00000020)
#define MOVE_STATUS_FLAG_FAILED                     (0x00000040)
#define MOVE_STATUS_FLAG_ENDURED                    (0x00000080)
#define MOVE_STATUS_FLAG_HELD_ON_WITH_ITEM          (0x00000100)
#define MOVE_STATUS_FLAG_NO_PP                      (0x00000200)
#define MOVE_STATUS_FLAG_LOCKED_ON                  (0x00000400)
#define MOVE_STATUS_FLAG_MISSED_BY_ABILITY          (0x00000800)
#define MOVE_STATUS_FLAG_ONE_HIT_KO_FAILED          (0x00001000)
#define MOVE_STATUS_FLAG_NOTHING_HAPPENED           (0x00002000)
#define MOVE_STATUS_FLAG_MISSED_IN_SERIES           (0x00004000)
#define MOVE_STATUS_FLAG_PROTECTED                  (0x00008000)
#define MOVE_STATUS_FLAG_MISSED_DURING_FLY          (0x00010000)    // also includes Bounce, Dive, Dig, Shadow Force
#define MOVE_STATUS_FLAG_LOST_FOCUS                 (0x00020000)
#define MOVE_STATUS_FLAG_PROTECTED_BY_WONDER_GUARD  (0x00040000)
#define MOVE_STATUS_FLAG_ENDURED_BY_STURDY          (0x00080000)    // specifically against OHKO moves, NOT gen5 sturdy
#define MOVE_STATUS_FLAG_MISSED_BY_MAGNET_RISE      (0x00100000)
// 0x00200000 unused
// 0x00400000 unused
// 0x00800000 unused
// 0x01000000 unused
// 0x02000000 unused
// 0x04000000 unused
// 0x08000000 unused
// 0x10000000 unused
// 0x20000000 unused
// 0x40000000 unused
#define MOVE_STATUS_FLAG_GENERAL_FAILURE            (0x80000000)

#define MOVE_STATUS_FLAG_DID_NOT_HIT                (MOVE_STATUS_FLAG_MISSED \
                                                    | MOVE_STATUS_FLAG_DOES_NOT_AFFECT \
                                                    | MOVE_STATUS_FLAG_FAILED \
                                                    | MOVE_STATUS_FLAG_MISSED_BY_ABILITY \
                                                    | MOVE_STATUS_FLAG_ONE_HIT_KO_FAILED \
                                                    | MOVE_STATUS_FLAG_MISSED_IN_SERIES \
                                                    | MOVE_STATUS_FLAG_PROTECTED \
                                                    | MOVE_STATUS_FLAG_MISSED_DURING_FLY \
                                                    | MOVE_STATUS_FLAG_LOST_FOCUS \
                                                    | MOVE_STATUS_FLAG_PROTECTED_BY_WONDER_GUARD \
                                                    | MOVE_STATUS_FLAG_ENDURED_BY_STURDY \
                                                    | MOVE_STATUS_FLAG_MISSED_BY_MAGNET_RISE)

#define MOVE_STATUS_FLAG_NO_HIT_EFFECTS             (MOVE_STATUS_FLAG_DID_NOT_HIT \
                                                    | MOVE_STATUS_FLAG_NO_PP \
                                                    | MOVE_STATUS_FLAG_GENERAL_FAILURE)


// ========================================================================= //
//                      POKEMON CONDITION CONSTANTS                          //
// ========================================================================= //

// These are non-volatile conditions: those which persist through switching,
// typically denoted by an icon on the HP gauge.
#define CONDITION_NONE              (0x00000000)
#define CONDITION_ASLEEP            (0x00000007)    // Bits 1 through 3 define how many turns of sleep remain for a Pokemon
#define CONDITION_POISONED          (0x00000008)    // Bit 4
#define CONDITION_BURNED            (0x00000010)    // Bit 5
#define CONDITION_FROZEN            (0x00000020)    // Bit 6
#define CONDITION_PARALYZED         (0x00000040)    // Bit 7
#define CONDITION_BADLY_POISONED    (0x00000080)    // Bit 8
#define CONDITION_TOXIC_COUNTER     (0x00000F00)    // Bits 9 through 12 define how many turns of Toxic damage have been accrued

#define CONDITION_STATUSED          (0x000000FF)
#define CONDITION_SYNCHRONIZED      (0x00000058)    // Synchronize can copy Burn, Paralysis, or (regular) Poison
#define CONDITION_BOOST_GUTS        (0x000000DF)
#define CONDITION_BOOST_FACADE      (0x000000D8)    // Facade is boosted by Burn, Paralysis, and Poison
#define CONDITION_POISON_ALL        (0x00000F88)    // Convenience for checking any type of Poison

#define CONDITION_CLEAR             (0xFFFFFFFF)
#define CONDITION_NOT_ASLEEP        (CONDITION_ASLEEP        ^ CONDITION_CLEAR)
#define CONDITION_NOT_POISONED      (CONDITION_POISONED      ^ CONDITION_CLEAR)
#define CONDITION_NOT_BURNED        (CONDITION_BURNED        ^ CONDITION_CLEAR)
#define CONDITION_NOT_FROZEN        (CONDITION_FROZEN        ^ CONDITION_CLEAR)
#define CONDITION_NOT_PARALYZED     (CONDITION_PARALYZED     ^ CONDITION_CLEAR)
#define CONDITION_ZERO_TOXIC_COUNT  (CONDITION_TOXIC_COUNTER ^ CONDITION_CLEAR)
#define CONDITION_REFRESH           (CONDITION_BOOST_FACADE  ^ CONDITION_CLEAR)
#define CONDITION_ALL_POISON_OFF    (CONDITION_POISON_ALL    ^ CONDITION_CLEAR)

#define CONDITION_TOXIC_COUNT_START (0x00000100)

// These are constants for the messages associated with each condition
#define	MSG_COND_ASLEEP     (0)
#define	MSG_COND_POISONED   (1)
#define	MSG_COND_BURNED     (2)
#define	MSG_COND_PARALYZED  (3)
#define	MSG_COND_FROZEN     (4)
#define	MSG_COND_CONFUSED   (5)
#define	MSG_COND_INFATUATED (6)

// These are volatile conditions: those which disappear upon switching.
#define CONDITION_V_NONE            (0x00000000)
#define CONDITION_V_CONFUSED        (0x00000007)    // Bits 1 through 3 define how many turns of confusion remain
#define CONDITION_V_FLINCHED        (0x00000008)    // Bit 4
#define CONDITION_V_UPROARING       (0x00000070)    // Bits 5 through 7 define how many turns of Uproar remain
#define CONDITION_V_TRI_ATTACK      (0x00000080)    // Bit 8
#define CONDITION_V_BIDING          (0x00000300)    // Bits 9 and 10 control how many turns of Bide remain
#define CONDITION_V_THRASHING       (0x00000C00)    // Bits 11 and 12 control how many turns of thrashing remain
#define CONDITION_V_CHARGING        (0x00001000)    // Bit 13; set by moves which continue over multiple turns (Bide, charge moves, etc.)
#define CONDITION_V_CLAMPED         (0x0000E000)    // Bits 14 through 16 control how many turns of binding remain
#define CONDITION_V_INFATUATED      (0x000F0000)    // Bits 17 through 20 are a mask defining which clients the mon is infatuated with
#define CONDITION_V_PUMPED          (0x00100000)    // Bit 21; Focus Energy
#define CONDITION_V_TRANSFORMED     (0x00200000)    // Bit 22
#define CONDITION_V_RECHARGING      (0x00400000)    // Bit 23; Hyper Beam
#define CONDITION_V_RAGING          (0x00800000)    // Bit 24
#define CONDITION_V_SUBSTITUTED     (0x01000000)    // Bit 25
#define CONDITION_V_DESTINY_BOUND   (0x02000000)    // Bit 26
#define CONDITION_V_MEAN_LOOKED     (0x04000000)    // Bit 27
#define CONDITION_V_NIGHTMARES      (0x08000000)    // Bit 28
#define CONDITION_V_CURSED          (0x10000000)    // Bit 29; specifically, Curse used by a Ghost
#define CONDITION_V_IDENTIFIED      (0x20000000)    // Bit 30; Foresight
#define CONDITION_V_DEFENSE_CURLED  (0x40000000)    // Bit 31; checked for by Rollout
#define CONDITION_V_TORMENTED       (0x80000000)    // Bit 32

#define CONDITION_V_CLEAR               (0xFFFFFFFF)
#define CONDITION_V_NOT_CONFUSED        (CONDITION_V_CONFUSED       ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_FLINCHED        (CONDITION_V_FLINCHED       ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_UPROARING       (CONDITION_V_UPROARING      ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_TRI_ATTACK      (CONDITION_V_TRI_ATTACK     ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_BIDING          (CONDITION_V_BIDING         ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_THRASHING       (CONDITION_V_THRASHING      ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_CHARGING        (CONDITION_V_CHARGING       ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_CLAMPED         (CONDITION_V_CLAMPED        ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_INFATUATED      (CONDITION_V_INFATUATED     ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_PUMPED          (CONDITION_V_PUMPED         ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_TRANSFORMED     (CONDITION_V_TRANSFORMED    ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_RECHARGING      (CONDITION_V_RECHARGING     ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_RAGING          (CONDITION_V_RAGING         ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_SUBSTITUTE      (CONDITION_V_SUBSTITUTED    ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_DESTINY_BOUND   (CONDITION_V_DESTINY_BOUND  ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_MEAN_LOOKED     (CONDITION_V_MEAN_LOOKED    ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_NIGHTMARES      (CONDITION_V_NIGHTMARES     ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_CURSED          (CONDITION_V_CURSED         ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_IDENTIFIED      (CONDITION_V_IDENTIFIED     ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_DEFENSE_CURLED  (CONDITION_V_DEFENSE_CURLED ^ CONDITION_V_CLEAR)
#define CONDITION_V_NOT_TORMENTED       (CONDITION_V_TORMENTED      ^ CONDITION_V_CLEAR)

#define CONDITION_V_BATON_PASSED    (CONDITION_V_PUMPED | CONDITION_V_MEAN_LOOKED | CONDITION_V_CONFUSED | CONDITION_V_CURSED | CONDITION_V_SUBSTITUTED)

#define CONFUSION_END   (0x00000001)
#define UPROAR_END      (0x00000010)
#define BIDE_TURNS      (0x00000200)
#define BIDE_END        (0x00000100)
#define THRASHING_END   (0x00000400)
#define CLAMPED_END     (0x00002000)


// ========================================================================= //
//                      CONSTANTS FOR ADDING STATUS                          //
// ========================================================================= //

#define ADDL_EFFECT_NONE                        (0x00000000)
#define ADDL_EFFECT_SLEEP                       (0x00000001)
#define ADDL_EFFECT_POISON                      (0x00000002)
#define ADDL_EFFECT_BURN                        (0x00000003)
#define ADDL_EFFECT_FREEZE                      (0x00000004)
#define ADDL_EFFECT_PARALYZE                    (0x00000005)
#define ADDL_EFFECT_BADLY_POISON                (0x00000006)
#define ADDL_EFFECT_CONFUSE                     (0x00000007)
#define ADDL_EFFECT_FLINCH                      (0x00000008)
#define ADDL_EFFECT_REST                        (0x00000009)
#define ADDL_EFFECT_UPROAR                      (0x0000000A)
#define ADDL_EFFECT_PAYDAY                      (0x0000000B)
#define ADDL_EFFECT_CHARGE_TURN                 (0x0000000C)
#define ADDL_EFFECT_TRAP                        (0x0000000D)
#define ADDL_EFFECT_TAKE_RECOIL_1_4             (0x0000000E)
#define ADDL_EFFECT_ATK_UP_1                    (0x0000000F)
#define ADDL_EFFECT_DEF_UP_1                    (0x00000010)
#define ADDL_EFFECT_SPE_UP_1                    (0x00000011)
#define ADDL_EFFECT_SPA_UP_1                    (0x00000012)
#define ADDL_EFFECT_SPD_UP_1                    (0x00000013)
#define ADDL_EFFECT_ACC_UP_1                    (0x00000014)
#define ADDL_EFFECT_EVA_UP_1                    (0x00000015)
#define ADDL_EFFECT_ATK_DOWN_1                  (0x00000016)
#define ADDL_EFFECT_DEF_DOWN_1                  (0x00000017)
#define ADDL_EFFECT_SPE_DOWN_1                  (0x00000018)
#define ADDL_EFFECT_SPA_DOWN_1                  (0x00000019)
#define ADDL_EFFECT_SPD_DOWN_1                  (0x0000001A)
#define ADDL_EFFECT_ACC_DOWN_1                  (0x0000001B)
#define ADDL_EFFECT_EVA_DOWN_1                  (0x0000001C)
#define ADDL_EFFECT_RECHARGE_TURN               (0x0000001D)
#define ADDL_EFFECT_BUILD_RAGE                  (0x0000001E)
#define ADDL_EFFECT_STEAL_ITEM                  (0x0000001F)
#define ADDL_EFFECT_MEAN_LOOKED                 (0x00000020)
#define ADDL_EFFECT_NIGHTMARE                   (0x00000021)
#define ADDL_EFFECT_ALL_UP_1                    (0x00000022)
#define ADDL_EFFECT_RAPID_SPIN                  (0x00000023)
#define ADDL_EFFECT_CURE_PARALYSIS              (0x00000024)
#define ADDL_EFFECT_SUPERPOWER                  (0x00000025)
#define ADDL_EFFECT_TAKE_RECOIL_1_3             (0x00000026)
#define ADDL_EFFECT_ATK_UP_2                    (0x00000027)
#define ADDL_EFFECT_DEF_UP_2                    (0x00000028)
#define ADDL_EFFECT_SPE_UP_2                    (0x00000029)
#define ADDL_EFFECT_SPA_UP_2                    (0x0000002A)
#define ADDL_EFFECT_SPD_UP_2                    (0x0000002B)
#define ADDL_EFFECT_ACC_UP_2                    (0x0000002C)
#define ADDL_EFFECT_EVA_UP_2                    (0x0000002D)
#define ADDL_EFFECT_ATK_DOWN_2                  (0x0000002E)
#define ADDL_EFFECT_DEF_DOWN_2                  (0x0000002F)
#define ADDL_EFFECT_SPE_DOWN_2                  (0x00000030)
#define ADDL_EFFECT_SPA_DOWN_2                  (0x00000031)
#define ADDL_EFFECT_SPD_DOWN_2                  (0x00000032)
#define ADDL_EFFECT_ACC_DOWN_2                  (0x00000033)
#define ADDL_EFFECT_EVA_DOWN_2                  (0x00000034)
#define ADDL_EFFECT_THRASH                      (0x00000035)
#define ADDL_EFFECT_KNOCK_OFF                   (0x00000036)
#define ADDL_EFFECT_COSMIC_POWER                (0x00000037)
#define ADDL_EFFECT_BULK_UP                     (0x00000038)
#define ADDL_EFFECT_TICKLE                      (0x00000039)
#define ADDL_EFFECT_CALM_MIND                   (0x0000003A)
#define ADDL_EFFECT_DRAGON_DANCE                (0x0000003B)
#define ADDL_EFFECT_DRAIN_HALF_DAMAGE           (0x0000003C)
#define ADDL_EFFECT_DREAM_EATER                 (0x0000003D)
#define ADDL_EFFECT_RESET_STAT_CHANGES          (0x0000003E)
#define ADDL_EFFECT_BIDING                      (0x0000003F)
#define ADDL_EFFECT_STRUGGLE                    (0x00000040)
#define ADDL_EFFECT_CONVERSION                  (0x00000041)
#define ADDL_EFFECT_RECOVER_HALF_HP             (0x00000042)
#define ADDL_EFFECT_LIGHT_SCREEN                (0x00000043)
#define ADDL_EFFECT_REFLECT                     (0x00000044)
#define ADDL_EFFECT_MIST                        (0x00000045)
#define ADDL_EFFECT_CRIT_UP_2                   (0x00000046)
#define ADDL_EFFECT_MIMIC                       (0x00000047)
#define ADDL_EFFECT_LEECH_SEED                  (0x00000048)
#define ADDL_EFFECT_DISABLE                     (0x00000049)
#define ADDL_EFFECT_ENCORE                      (0x0000004A)
#define ADDL_EFFECT_PAIN_SPLIT                  (0x0000004B)
#define ADDL_EFFECT_CONVERSION_2                (0x0000004C)
#define ADDL_EFFECT_LOCK_ON                     (0x0000004D)
#define ADDL_EFFECT_SKETCH                      (0x0000004E)
#define ADDL_EFFECT_FEINT                       (0x0000004F)
#define ADDL_EFFECT_DESTINY_BOND                (0x00000050)
#define ADDL_EFFECT_SPITE                       (0x00000051)
#define ADDL_EFFECT_PROTECT                     (0x00000052)
#define ADDL_EFFECT_HEAL_BELL                   (0x00000053)
#define ADDL_EFFECT_SUBSTITUTE                  (0x00000054)
#define ADDL_EFFECT_FORCE_SWITCH                (0x00000055)
#define ADDL_EFFECT_TRANSFORM                   (0x00000056)
#define ADDL_EFFECT_MINIMIZE                    (0x00000057)
#define ADDL_EFFECT_CURSE                       (0x00000058)
#define ADDL_EFFECT_GHOST_CURSE                 (0x00000059)
#define ADDL_EFFECT_PREPARE_MESSAGE             (0x0000005A)
#define ADDL_EFFECT_FORESIGHT                   (0x0000005B)
#define ADDL_EFFECT_PERISH_SONG                 (0x0000005C)
#define ADDL_EFFECT_SET_WEATHER                 (0x0000005D)
#define ADDL_EFFECT_SWAGGER                     (0x0000005E)
#define ADDL_EFFECT_ATTRACT                     (0x0000005F)
#define ADDL_EFFECT_SAFEGUARD                   (0x00000060)
#define ADDL_EFFECT_HEAL_TARGET                 (0x00000061)
#define ADDL_EFFECT_MAGNITUDE                   (0x00000062)
#define ADDL_EFFECT_BATON_PASS                  (0x00000063)
#define ADDL_EFFECT_BELLY_DRUM                  (0x00000064)
#define ADDL_EFFECT_TELEPORT                    (0x00000065)
#define ADDL_EFFECT_BEAT_UP                     (0x00000066)
#define ADDL_EFFECT_STOCKPILE                   (0x00000067)
#define ADDL_EFFECT_SWALLOW                     (0x00000068)
#define ADDL_EFFECT_TORMENT                     (0x00000069)
#define ADDL_EFFECT_FLATTER                     (0x0000006A)
#define ADDL_EFFECT_MEMENTO                     (0x0000006B)
#define ADDL_EFFECT_CHARGE                      (0x0000006C)
#define ADDL_EFFECT_TAUNT                       (0x0000006D)
#define ADDL_EFFECT_TRICK                       (0x0000006E)
#define ADDL_EFFECT_ROLE_PLAY                   (0x0000006F)
#define ADDL_EFFECT_BREAK_SCREENS               (0x00000070)
#define ADDL_EFFECT_YAWN                        (0x00000071)
#define ADDL_EFFECT_SKILL_SWAP                  (0x00000072)
#define ADDL_EFFECT_REFRESH                     (0x00000073)
#define ADDL_EFFECT_ROOST                       (0x00000074)
#define ADDL_EFFECT_CURE_SLEEP                  (0x00000075)
#define ADDL_EFFECT_GRAVITY                     (0x00000076)
#define ADDL_EFFECT_MIRACLE_EYE                 (0x00000077)
#define ADDL_EFFECT_HEALING_WISH                (0x00000078)
#define ADDL_EFFECT_TAILWIND                    (0x00000079)
#define ADDL_EFFECT_CLOSE_COMBAT                (0x0000007A)
#define ADDL_EFFECT_POWER_TRICK                 (0x0000007B)
#define ADDL_EFFECT_SUPPRESS_ABILITY            (0x0000007C)
#define ADDL_EFFECT_LUCKY_CHANT                 (0x0000007D)
#define ADDL_EFFECT_POWER_SWAP                  (0x0000007E)
#define ADDL_EFFECT_GUARD_SWAP                  (0x0000007F)
#define ADDL_EFFECT_WORRY_SEED                  (0x00000080)
#define ADDL_EFFECT_HEART_SWAP                  (0x00000081)
#define ADDL_EFFECT_FLARE_BLITZ                 (0x00000082)
#define ADDL_EFFECT_DEFOG                       (0x00000083)
#define ADDL_EFFECT_HEAL_BLOCK                  (0x00000084)
#define ADDL_EFFECT_U_TURN                      (0x00000085)
#define ADDL_EFFECT_EMBARGO                     (0x00000086)
#define ADDL_EFFECT_EAT_BERRY                   (0x00000087)
#define ADDL_EFFECT_FLING                       (0x00000088)
#define ADDL_EFFECT_VOLT_TACKLE                 (0x00000089)
#define ADDL_EFFECT_TAKE_RECOIL_1_2             (0x0000008A)
#define ADDL_EFFECT_BURN_AND_FLINCH             (0x0000008B)
#define ADDL_EFFECT_FREEZE_AND_FLINCH           (0x0000008C)
#define ADDL_EFFECT_PARALYZE_AND_FLINCH         (0x0000008D)
#define ADDL_EFFECT_CHATTER                     (0x0000008E)
#define ADDL_EFFECT_LUNAR_DANCE                 (0x0000008F)
#define ADDL_EFFECT_PSYCHO_SHIFT                (0x00000090)

#define ADDL_EFFECT_MASK                        (0x007FFFFF)    // to get any effect value

#define ADDL_EFFECT_FLAG_REMOVE_SCREENS         (0x00800000)    // Brick Break
#define ADDL_EFFECT_FLAG_REQUIRE_HP_LOSS        (0x01000000)    // Thief, Pay Day
#define ADDL_EFFECT_FLAG_CLAMPING               (0x02000000)    // Bind, Clamp, Whirlpool, Fire Spin
#define ADDL_EFFECT_HAS_PROBABILITY             (0x04000000)    // Flare Blitz, Volt Tackle
#define ADDL_EFFECT_NO_ABILITY                  (0x08000000)    // ?
#define ADDL_EFFECT_EXTRA_FAIL_CHECK            (0x10000000)    // Transform, Leech Seed, Mind Reader, etc.
#define ADDL_EFFECT_FLAG_UPDATE                 (0x20000000)    // Lots of moves
#define ADDL_EFFECT_ATTACKER                    (0x40000000)
#define ADDL_EFFECT_DEFENDER                    (0x80000000)

#define ADDL_EFFECT_NO_SOURCE                   (0)
#define ADDL_EFFECT_DIRECT                      (1)
#define ADDL_EFFECT_INDIRECT                    (2)
#define ADDL_EFFECT_FROM_ABILITY                (3)
#define ADDL_EFFECT_FROM_MOVE                   (4)
#define ADDL_EFFECT_FROM_ITEM                   (5)
#define ADDL_EFFECT_TOXIC_SPIKES                (6)
#define ADDL_EFFECT_DISOBEY                     (7)


// ========================================================================= //
//                        ACTUAL STATUS CONSTANTS                            //
// ========================================================================= //

#define STATUS_NONE             0
#define STATUS_ASLEEP           1
#define STATUS_POISONED         2
#define STATUS_BURNED           3
#define STATUS_FROZEN           4
#define STATUS_PARALYZED        5
#define STATUS_CONFUSED         6
#define STATUS_INFATUATED       7
#define STATUS_LEVEL_UP         8
#define STATUS_BAG_ITEM         9
#define STATUS_HELD_ITEM        10
#define STATUS_SHINY            11
#define STATUS_STAT_BOOST       12
#define STATUS_STAT_DROP        13
#define STATUS_RESTORE_HP       14
#define STATUS_SUB_OUT          15
#define STATUS_SUB_IN           16
#define STATUS_ITEM_ESCAPE      17
#define STATUS_WEATHER_FOG      18
#define STATUS_WEATHER_RAIN     19
#define STATUS_WEATHER_HAIL     20
#define STATUS_WEATHER_SAND     21
#define STATUS_WEATHER_SUN      22

#define STATUS_WEATHER_START    STATUS_WEATHER_FOG
#define STATUS_WEATHER_END      STATUS_WEATHER_SUN


// ========================================================================= //
//                         MOVE EFFECT CONSTANTS                             //
// ========================================================================= //

#define MOVE_EFFECT_LEECH_SEEDED_BY             (0x00000003)    // 2 flags in 1, determines which client gets the recovery
#define MOVE_EFFECT_LEECH_SEEDED                (0x00000004)
#define	MOVE_EFFECT_LOCKED_ON_BY                (0x00000018)    // 2 flags in 1, determines which of your clients circumvent the acc check
#define	MOVE_EFFECT_PERISH_SONG                 (0x00000020)    // just a check for if Perish Song is applied; nothing here to do with the count
#define	MOVE_EFFECT_AIRBORNE                    (0x00000040)    // applied by Fly and Bounce
#define	MOVE_EFFECT_UNDERGROUND                 (0x00000080)    // applied by Dig
#define	MOVE_EFFECT_MINIMIZED                   (0x00000100)
#define	MOVE_EFFECT_CHARGED                     (0x00000200)    // literally Charge
#define	MOVE_EFFECT_INGRAINED                   (0x00000400)
#define	MOVE_EFFECT_DROWSY                      (0x00001800)    // 2 flags in 1; marks both the drowsy turn and the fall-asleep turn
#define	MOVE_EFFECT_IMPRISON                    (0x00002000)    // applied to whatever mon used Imprison
#define	MOVE_EFFECT_GRUDGE                      (0x00004000)    // applied to whatever mon used Grudge
#define	MOVE_EFFECT_NO_CRITICAL                 (0x00008000)
#define	MOVE_EFFECT_MUD_SPORT                   (0x00010000)
#define	MOVE_EFFECT_WATER_SPORT                 (0x00020000)
#define	MOVE_EFFECT_UNDERWATER                  (0x00040000)    // applied by Dive
#define	MOVE_EFFECT_INTIMIDATE                  (0x00080000)    // doesn't appear to be set anywhere?
#define	MOVE_EFFECT_TRACE                       (0x00100000)    // doesn't appear to be set anywhere?
#define	MOVE_EFFECT_ABILITY_SUPPRESSED          (0x00200000)    // applied by Gastro Acid
#define	MOVE_EFFECT_MIRACLE_EYE                 (0x00400000)    // separate from Foresight
#define	MOVE_EFFECT_POWER_TRICK                 (0x00800000)
#define	MOVE_EFFECT_AQUA_RING                   (0x01000000)
#define	MOVE_EFFECT_HEAL_BLOCK                  (0x02000000)
#define	MOVE_EFFECT_EMBARGO                     (0x04000000)
#define	MOVE_EFFECT_MAGNET_RISE                 (0x08000000)
#define	MOVE_EFFECT_CAMOUFLAGE                  (0x10000000)    // used by the AI system
#define	MOVE_EFFECT_SHADOW_FORCE                (0x20000000)
#define	MOVE_EFFECT_IMPRISONED                  (0x40000000)    // applied to mons which are Imprisoned; used by the AI system


// ========================================================================= //
//                       FIELD CONDITION CONSTANTS                           //
// ========================================================================= //

#define	FIELD_CONDITION_RAINING_TEMP    (0x00000001)
#define	FIELD_CONDITION_RAINING_PERM    (0x00000002)
#define	FIELD_CONDITION_RAINING         (0x00000003)
#define	FIELD_CONDITION_SANDSTORM_TEMP  (0x00000004)
#define	FIELD_CONDITION_SANDSTORM_PERM  (0x00000008)
#define	FIELD_CONDITION_SANDSTORM       (0x0000000C)
#define	FIELD_CONDITION_SUNNY_TEMP      (0x00000010)
#define	FIELD_CONDITION_SUNNY_PERM      (0x00000020)
#define	FIELD_CONDITION_SUNNY           (0x00000030)
#define	FIELD_CONDITION_HAILING_TEMP    (0x00000040)
#define	FIELD_CONDITION_HAILING_PERM    (0x00000080)
#define	FIELD_CONDITION_HAILING         (0x000000C0)

#define	FIELD_CONDITION_UPROAR          (0x00000F00)    // 4 bits; also tracks which client is making the uproar
#define	FIELD_CONDITION_GRAVITY         (0x00007000)    // 3 bits; also tracks the remaining turns
#define	FIELD_CONDITION_DEEP_FOG        (0x00008000)
#define	FIELD_CONDITION_TRICK_ROOM      (0x00070000)    // 3 bits; also tracks the remaining turns

#define FIELD_CONDITION_FORECAST        (FIELD_CONDITION_RAINING | FIELD_CONDITION_SUNNY | FIELD_CONDITION_HAILING)
#define FIELD_CONDITION_WEATHER         (0x000080FF)    // Any weather in effect (includes Deep Fog)
#define FIELD_CONDITION_ANTI_SOLAR      (FIELD_CONDITION_RAINING | FIELD_CONDITION_SANDSTORM | FIELD_CONDITION_HAILING | FIELD_CONDITION_DEEP_FOG)


// ========================================================================= //
//                        SIDE CONDITION CONSTANTS                           //
// ========================================================================= //

#define SIDE_CONDITION_REFLECT          (0x00000001)
#define SIDE_CONDITION_LIGHT_SCREEN     (0x00000002)
#define SIDE_CONDITION_SPIKES           (0x00000004)
#define SIDE_CONDITION_SAFEGUARD        (0x00000008)
#define SIDE_CONDITION_FUTURE_SIGHT     (0x00000010)
#define SIDE_CONDITION_WISH             (0x00000020)
#define SIDE_CONDITION_MIST             (0x00000040)
#define SIDE_CONDITION_STEALTH_ROCK     (0x00000080)
#define SIDE_CONDITION_TAILWIND         (0x00000300)    // stores the turn-counter for tailwind (TODO: move this to expand to 4 turns)
#define SIDE_CONDITION_TOXIC_SPIKES     (0x00000400)    // TODO: maybe could move this up to give Tailwind more space?
#define SIDE_CONDITION_LUCKY_CHANT      (0x00007000)    // stores the turn-counter for lucky chant (max: 7)


// ========================================================================= //
//                        BATTLE STATUS CONSTANTS                            //
// ========================================================================= //

#define BATTLE_STATUS_FIRST_BATTLE          (0x00000001)    // Against your rival after geting your starter
#define BATTLE_STATUS_HONEY_TREE            (0x00000002)    // Changes the message to "<Pokemon> fell out of the tree!"
#define BATTLE_STATUS_NO_RUNNING_WILD       (0x00000004)    // Disables fleeing
#define BATTLE_STATUS_LEGENDARY             (0x00000008)    // Changes the message to "<Pokemon> appeared!"
#define BATTLE_STATUS_RECORDED              (0x00000010)
#define BATTLE_STATUS_RECORDED_CHILD        (0x00000020)
#define BATTLE_STATUS_GIRATINA_DISTORTION   (0x00000040)    // Special flag combination for Giratina in the Distortion World
#define BATTLE_STATUS_DISTORTION            (0x00000080)    // Any battle in the Distortion World


// ========================================================================= //
//                        BATTLE RESULT CONSTANTS                            //
// ========================================================================= //

#define BATTLE_RESULT_WIN                   (0x01)
#define BATTLE_RESULT_LOSE                  (0x02)
#define BATTLE_RESULT_DRAW                  (0x03)
#define BATTLE_RESULT_CAPTURE               (0x04)
#define BATTLE_RESULT_ESCAPE                (0x05)
#define BATTLE_RESULT_ENEMY_ESCAPE          (0x06)
#define BATTLE_RESULT_SELECT_PAUSE          (0x40)
#define BATTLE_RESULT_SELECT                (0x80)


// ========================================================================= //
//                            STAT ID CONSTANTS                              //
// ========================================================================= //

#define STAT_HP             0
#define STAT_ATTACK         1
#define STAT_DEFENSE        2
#define STAT_SPEED          3
#define STAT_SPATTACK       4
#define STAT_SPDEFENSE      5
#define STAT_ACCURACY       6
#define STAT_EVASION        7


// ========================================================================= //
//                         HP RECOVERY CONSTANTS                             //
// ========================================================================= //

// Special values for how much HP should be recovered as a percentage of max HP
#define RECOVER_ALL_HP      255
#define RECOVER_HALF_HP     254
#define RECOVER_QUARTER_HP  253


// ========================================================================= //
//                      COMMAND SELECTION CONSTANTS                          //
// ========================================================================= //

enum {
    SELECT_COMMAND_FIGHT = 1,
    SELECT_COMMAND_ITEM,
    SELECT_COMMAND_PARTY,
    SELECT_COMMAND_RUN,

    SELECT_SAFARI_THROW_BALL = SELECT_COMMAND_FIGHT,
    SELECT_SAFARI_THROW_BAIT,
    SELECT_SAFARI_THROW_MUD,
    SELECT_SAFARI_RUN,

    SELECT_PAL_PARK_THROW_BALL = SELECT_COMMAND_FIGHT,
    SELECT_PAL_PARK_RUN = SELECT_COMMAND_RUN,

    SELECT_MOVE_1 = 1,
    SELECT_MOVE_2,
    SELECT_MOVE_3,
    SELECT_MOVE_4,

    SELECT_POKEMON_1 = 1,
    SELECT_POKEMON_2,
    SELECT_POKEMON_3,
    SELECT_POKEMON_4,
    SELECT_POKEMON_5,
    SELECT_POKEMON_6,

    SELECT_TARGET_A = 1,
    SELECT_TARGET_B,
    SELECT_TARGET_C,
    SELECT_TARGET_D,

    SELECT_CANCEL = 0xFF,
};


// ========================================================================= //
//                       STRUCT AND FUNCTION DECLS                           //
// ========================================================================= //

struct Battle {
    void          *g3DManager;
    void          *bgl;
    struct Window *window;
    void          *fightMsgManager;
    void          *attackMsgManager;
    void          *wordset;
    struct String *preparedMessage;
    // etc.
};

/**
 * Gets the fight type for a battle.
 * 
 * Original function: 0x0223DF0C (overlay 16)
 * 
 * @param battle The battle structure.
 */
u32 __attribute__((long_call)) Battle_Type(void *battle);

/**
 * Gets the message manager for a battle.
 * 
 * Original function: 0x0223E05C (overlay 16)
 * 
 * @param battle The battle structure.
 */
void* __attribute__((long_call)) Battle_MessageManager(void *battle);

/**
 * @brief Gets a value from the battle struct's PRNG.
 * 
 * Original function: 0x0223F4BC (ov16)
 */
int __attribute__((long_call)) Battle_Random(void *battle);

/**
 * @brief Get an opponent for the input battler.
 * 
 * If side == 0, returns the opponent on our right.
 * If side == 2, returns the opponent on our left.
 * 
 * Original function: 0x0223E2A4 (ov16)
 * 
 * @param battle
 * @param battler
 * @param side
 */
int __attribute__((long_call)) Battle_Opponent(void *battle, int battler, int side);

/**
 * @brief Get any field weather associated with the battle zone.
 * 
 * Original function: 0x0223F21C (ov16)
 */
int __attribute__((long_call)) Battle_FieldWeather(void *battle);

/**
 * @brief Returns the status flags for a battle.
 * 
 * Original function: 0x0223EBEC (ov16)
 */
u32 __attribute__((long_call)) Battle_StatusFlag(void *battle);

/**
 * @brief Returns the number of battlers.
 * 
 * Original function: 0x0223DF1C (ov16)
 */
int __attribute__((long_call)) Battle_NumBattlers(void *battle);

#endif // __BATTLE_COMMON_H