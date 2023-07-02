#ifndef __MOVES_H
#define __MOVES_H

#include "typedefs.h"

#define SUBSCR_START_BATTLE                     (0)
#define SUBSCR_TRY_MOVE                         (1)
#define SUBSCR_HP_CHANGE                        (2)
#define SUBSCR_ESCAPE                           (3)
#define SUBSCR_BATTLE_WON                       (4)
#define SUBSCR_BATTLE_LOST                      (5)
#define SUBSCR_FAINT                            (6)
#define SUBSCR_MOVE_FAIL                        (7)
#define SUBSCR_ESCAPE_FAIL                      (8)
#define SUBSCR_SWITCH_POKEMON                   (9)
#define SUBSCR_PARTY_LIST                       (10)
#define SUBSCR_THROW_POKEBALL                   (11)
#define SUBSCR_BOOST_STATS                      (12)
#define SUBSCR_VANISH_ON_CHARGE_TURN            (13)
#define SUBSCR_TRY_FLINCH                       (14)
#define SUBSCR_MOVE_FAIL_FLINCHED               (15)
#define SUBSCR_CRITICAL_HIT                     (16)
#define SUBSCR_MULTI_HIT                        (17)
#define SUBSCR_APPLY_SLEEP                      (18)
#define SUBSCR_WAKE_UP                          (19)
#define SUBSCR_SLEEPING                         (20)
#define SUBSCR_MOVE_SUCCESS_MESSAGE             (21)
#define SUBSCR_APPLY_POISON                     (22)
#define SUBSCR_POISON_DAMAGE                    (23)
#define SUBSCR_DRAIN_HALF                       (24)
#define SUBSCR_APPLY_BURN                       (25)
#define SUBSCR_BURN_DAMAGE                      (26)
#define SUBSCR_APPLY_FREEZE                     (27)
#define SUBSCR_FROZEN                           (28)
#define SUBSCR_THAW_OUT                         (29)
#define SUBSCR_THAW_OUT_FROM_MOVE               (30)
#define SUBSCR_APPLY_PARALYSIS                  (31)
#define SUBSCR_FULLY_PARALYZED                  (32)
#define SUBSCR_DREAM_EATER                      (33)
#define SUBSCR_CLEAR_ALL_BOOSTS                 (34)
#define SUBSCR_START_BIDE                       (35)
#define SUBSCR_END_BIDE                         (36)
#define SUBSCR_APPLY_CONFUSION                  (37)
#define SUBSCR_CONFUSED                         (38)
#define SUBSCR_CONFUSED_SELF_HIT                (39)
#define SUBSCR_CONFUSED_NO_MORE                 (40)
#define SUBSCR_TRAINER_MESSAGE                  (41)
#define SUBSCR_NO_PP_LEFT                       (42)
#define SUBSCR_STRUGGLE                         (43)
#define SUBSCR_THRASHING                        (44)
#define SUBSCR_CONVERSION                       (45)
#define SUBSCR_RECOVER_HALF_HP                  (46)
#define SUBSCR_BADLY_POISON                     (47)
#define SUBSCR_PAY_DAY                          (48)
#define SUBSCR_LIGHT_SCREEN                     (49)
#define SUBSCR_WEAR_OFF                         (50)
#define SUBSCR_THRASH_END                       (51)
#define SUBSCR_REFLECT                          (52)
#define SUBSCR_ANIMATION_WITH_PREPARED_MESSAGE  (53)
#define SUBSCR_MIST                             (54)
#define SUBSCR_REST                             (55)
#define SUBSCR_UPROAR                           (56)
#define SUBSCR_SHOW_PREPARED_MESSAGE            (57)
#define SUBSCR_CLAMP_START                      (58)
#define SUBSCR_CLAMP_DAMAGE                     (59)
#define SUBSCR_CLAMP_END                        (60)
#define SUBSCR_CRASH_ON_MISS                    (61)
#define SUBSCR_FOCUS_ENERGY                     (62)
#define SUBSCR_RECOIL_1_4                       (63)
#define SUBSCR_RECHARGE_MOVE                    (64)
#define SUBSCR_RECHARGE_TURN                    (65)
#define SUBSCR_RAGE_SET                         (66)
#define SUBSCR_MIMIC                            (67)
#define SUBSCR_APPLY_LEECH_SEED                 (68)
#define SUBSCR_LEECH_SEED_DAMAGE                (69)
#define SUBSCR_APPLY_DISABLE                    (70)
#define SUBSCR_MOVE_IS_DISABLED                 (71)
#define SUBSCR_DISABLE_END                      (72)
#define SUBSCR_APPLY_ENCORE                     (73)
#define SUBSCR_ENCORE_END                       (74)
#define SUBSCR_BUT_IT_FAILED                    (75)
#define SUBSCR_ATTACK_MESSAGE_AND_ANIMATION     (76)
#define SUBSCR_PAIN_SPLIT                       (77)
#define SUBSCR_CONVERSION_2                     (78)
#define SUBSCR_LOCKON                           (79)
#define SUBSCR_SKETCH                           (80)
#define SUBSCR_FEINT                            (81)
#define SUBSCR_DESTINY_BOND                     (82)
#define SUBSCR_TRIGGER_ON_FAINTING              (83)
#define SUBSCR_SPITE                            (84)
#define SUBSCR_THIEF                            (85)
#define SUBSCR_MEAN_LOOK                        (86)
#define SUBSCR_PROTECT                          (87)
#define SUBSCR_HEAL_BELL                        (88)
#define SUBSCR_TRY_SUBSTITUTE                   (89)
#define SUBSCR_HIT_SUBSTITUTE                   (90)
#define SUBSCR_FORCE_OUT                        (91)
#define SUBSCR_TRANSFORM                        (92)
#define SUBSCR_APPLY_NIGHTMARE                  (93)
#define SUBSCR_NIGHTMARE_DAMAGE                 (94)
#define SUBSCR_MINIMIZE                         (95)
#define SUBSCR_CURSE_BOOST                      (96)
#define SUBSCR_CURSE_GHOST                      (97)
#define SUBSCR_CURSE_DAMAGE                     (98)
#define SUBSCR_HAZARDS_CHECK                    (99)
#define SUBSCR_FORESIGHT                        (100)
#define SUBSCR_START_PERISH_SONG                (101)
#define SUBSCR_COUNT_PERISH_SONG                (102)
#define SUBSCR_WEATHER_MESSAGE                  (103)
#define SUBSCR_WEATHER_EOT_EFFECT               (104)
#define SUBSCR_SWAGGER                          (105)
#define SUBSCR_APPLY_ATTRACT                    (106)
#define SUBSCR_INFATUATED                       (107)
#define SUBSCR_IMMOBILIZED_BY_LOVE              (108)
#define SUBSCR_APPLY_SAFEGUARD                  (109)
#define SUBSCR_END_SAFEGUARD                    (110)
#define SUBSCR_RECOVER_HP                       (111)
#define SUBSCR_PRESENT_HEAL                     (112)
#define SUBSCR_MAGNITUDE                        (113)
#define SUBSCR_BATON_PASS                       (114)
#define SUBSCR_RAPID_SPIN                       (115)
#define SUBSCR_BREAK_CLAMP                      (116)
#define SUBSCR_BLOW_AWAY_HAZARDS_MESSAGE        (117)
#define SUBSCR_SYNCHRONIZE                      (118)
#define SUBSCR_OMNIBOOST                        (119)
#define SUBSCR_BELLY_DRUM                       (120)
#define SUBSCR_FUTURE_SIGHT_DAMAGE              (121)
#define SUBSCR_TELEPORT                         (122)
#define SUBSCR_BEAT_UP_ATTACK_MESSAGE           (123)
#define SUBSCR_STOCKPILE                        (124)
#define SUBSCR_SWALLOW                          (125)
#define SUBSCR_PRINT_MESSAGE                    (126)
#define SUBSCR_APPLY_TORMENT                    (127)
#define SUBSCR_FLATTER                          (128)
#define SUBSCR_MEMENTO                          (129)
#define SUBSCR_HEAL_PARALYSIS                   (130)
#define SUBSCR_CHARGE                           (131)
#define SUBSCR_APPLY_TAUNT                      (132)
#define SUBSCR_MOVE_FAIL_TAUNTED                (133)
#define SUBSCR_TRICK                            (134)
#define SUBSCR_ROLE_PLAY                        (135)
#define SUBSCR_WISH_HEAL                        (136)
#define SUBSCR_INGRAIN_HEAL                     (137)
#define SUBSCR_SUPERPOWER_DEBUFF                (138)
#define SUBSCR_MAGIC_COAT                       (139)
#define SUBSCR_BREAK_SCREENS                    (140)
#define SUBSCR_YAWN                             (141)
#define SUBSCR_KNOCK_OFF                        (142)
#define SUBSCR_SKILL_SWAP                       (143)
#define SUBSCR_MOVE_IS_IMPRISONED               (144)
#define SUBSCR_REFRESH                          (145)
#define SUBSCR_SNATCH                           (146)
#define SUBSCR_RECOIL_1_3                       (147)
#define SUBSCR_TICKLE                           (148)
#define SUBSCR_COSMIC_POWER                     (149)
#define SUBSCR_BULK_UP                          (150)
#define SUBSCR_CALM_MIND                        (151)
#define SUBSCR_DRAGON_DANCE                     (152)
#define SUBSCR_PURSUIT                          (153)
#define SUBSCR_ROOST                            (154)
#define SUBSCR_FORCE_WAKE_UP                    (155)
#define SUBSCR_APPLY_GRAVITY                    (156)
#define SUBSCR_MOVE_FAIL_GRAVITY                (157)
#define SUBSCR_MIRACLE_EYE                      (158)
#define SUBSCR_HEALING_WISH                     (159)
#define SUBSCR_APPLY_TAILWIND                   (160)
#define SUBSCR_CLOSE_COMBAT_DEBUFF              (161)
#define SUBSCR_POWER_TRICK                      (162)
#define SUBSCR_GASTRO_ACID                      (163)
#define SUBSCR_APPLY_LUCKY_CHANT                (164)
#define SUBSCR_POWER_SWAP                       (165)
#define SUBSCR_GUARD_SWAP                       (166)
#define SUBSCR_WORRY_SEED                       (167)
#define SUBSCR_HEART_SWAP                       (168)
#define SUBSCR_AQUA_RING_HEAL                   (169)
#define SUBSCR_FLARE_BLITZ                      (170)
#define SUBSCR_DEFOG                            (171)
#define SUBSCR_DEFOG_MESSAGE                    (172)
#define SUBSCR_APPLY_HEAL_BLOCK                 (173)
#define SUBSCR_MOVE_FAILED_HEAL_BLOCK           (174)
#define SUBSCR_PIVOT_ATTACK                     (175)
#define SUBSCR_MOVE_FAIL_MISSED                 (176)
#define SUBSCR_MOLD_BREAKER                     (177)
#define SUBSCR_ABILITY_HP_RESTORE               (178)
#define SUBSCR_FLASH_FIRE                       (179)
#define SUBSCR_LIGHTNING_ROD                    (180)
#define SUBSCR_SOUNDPROOF                       (181)
#define SUBSCR_MOTOR_DRIVE                      (182)
#define SUBSCR_DRIZZLE                          (183)
#define SUBSCR_SAND_STREAM                      (184)
#define SUBSCR_DROUGHT                          (185)
#define SUBSCR_INTIMIDATE                       (186)
#define SUBSCR_TRACE                            (187)
#define SUBSCR_COLOR_CHANGE                     (188)
#define SUBSCR_ROUGH_SKIN                       (189)
#define SUBSCR_SHED_SKIN                        (190)
#define SUBSCR_LOAFING                          (191)
#define SUBSCR_ABILITY_HP_GRADUAL               (192)
#define SUBSCR_AFTERMATH_DAMAGE                 (193)
#define SUBSCR_ANTICIPATION                     (194)
#define SUBSCR_FOREWARN                         (195)
#define SUBSCR_APPLY_SLOW_START                 (196)
#define SUBSCR_SLOW_START_END                   (197)
#define SUBSCR_ITEM_HP_RESTORE                  (198)
#define SUBSCR_ITEM_RECOVER_PRZ                 (199)
#define SUBSCR_ITEM_RECOVER_SLP                 (200)
#define SUBSCR_ITEM_RECOVER_PSN                 (201)
#define SUBSCR_ITEM_RECOVER_BRN                 (202)
#define SUBSCR_ITEM_RECOVER_FRZ                 (203)
#define SUBSCR_ITEM_PP_RESTORE                  (204)
#define SUBSCR_ITEM_RECOVER_CNF                 (205)
#define SUBSCR_ITEM_RECOVER_ALL                 (206)
#define SUBSCR_ITEM_HP_RESTORE_CNF              (207)
#define SUBSCR_ITEM_STAT_BOOST                  (208)
#define SUBSCR_ITEM_RAISE_CRIT                  (209)
#define SUBSCR_ITEM_STAT_BOOST_2                (210)
#define SUBSCR_ITEM_RECOVER_STAT_DROP           (211)
#define SUBSCR_ITEM_RECOVER_INF                 (212)
#define SUBSCR_ITEM_HP_GRADUAL                  (213)
#define SUBSCR_ITEM_HP_LOSS                     (214)
#define SUBSCR_ITEM_TAKE_DAMAGE                 (215)
#define SUBSCR_ITEM_GIVE_STICKY_BARB            (216)
#define SUBSCR_ITEM_POWER_HERB                  (217)
#define SUBSCR_EMBARGO                          (218)
#define SUBSCR_PLUCK                            (219)
#define SUBSCR_FLING                            (220)
#define SUBSCR_ABILITY_RECOVER_CND              (221)
#define SUBSCR_ITEM_ESCAPE                      (222)
#define SUBSCR_BATTLE_ONLY_ITEM                 (223)
#define SUBSCR_BAG_ITEM_HP_RESTORE              (224)
#define SUBSCR_BAG_ITEM_PP_RESTORE              (225)
#define SUBSCR_VOLT_TACKLE                      (226)
#define SUBSCR_SAFARI_THROW_BAIT                (227)
#define SUBSCR_SAFARI_THROW_MUD                 (228)
#define SUBSCR_SAFARI_WATCHING_CAREFULLY        (229)
#define SUBSCR_ENEMY_ESCAPE                     (230)
#define SUBSCR_REPLACE_FAINTED                  (231)
#define SUBSCR_FOCUS_PUNCH_START                (232)
#define SUBSCR_TAILWIND_END                     (233)
#define SUBSCR_RAIN_END                         (234)
#define SUBSCR_SANDSTORM_END                    (235)
#define SUBSCR_SUN_END                          (236)
#define SUBSCR_HAIL_END                         (237)
#define SUBSCR_GRAVITY_END                      (238)
#define SUBSCR_CANNOT_HEAL                      (239)
#define SUBSCR_MAKING_AN_UPROAR                 (240)
#define SUBSCR_UPROAR_END                       (241)
#define SUBSCR_MAGNET_RISE_END                  (242)
#define SUBSCR_HEAL_BLOCK_END                   (243)
#define SUBSCR_EMBARGO_END                      (244)
#define SUBSCR_RAGE_IS_BUILDING                 (245)
#define SUBSCR_RECOIL_1_2                       (246)
#define SUBSCR_BURN_OR_FLINCH                   (247)
#define SUBSCR_FREEZE_OR_FLINCH                 (248)
#define SUBSCR_PARA_OR_FLINCH                   (249)
#define SUBSCR_LUCKY_CHANT_END                  (250)
#define SUBSCR_TRICK_ROOM_END                   (251)
#define SUBSCR_SNOW_WARNING                     (252)
#define SUBSCR_FRISK                            (253)
#define SUBSCR_DISOBEY_WHILE_ASLEEP             (254)
#define SUBSCR_DISOBEY                          (255)
#define SUBSCR_DISOBEY_ATTACK                   (256)
#define SUBSCR_DISOBEY_NAP                      (257)
#define SUBSCR_DISOBEY_SELF_HIT                 (258)
#define SUBSCR_CHARGE_MOVE_CLEANUP              (259)
#define SUBSCR_CHATTER                          (260)
#define SUBSCR_LUNAR_DANCE                      (261)
#define SUBSCR_CHANGE_FORM                      (262)
#define SUBSCR_BAD_DREAMS                       (263)
#define SUBSCR_TYPE_RESIST_BERRIES              (264)
#define SUBSCR_ITEM_ACC_UP_ONCE                 (265)
#define SUBSCR_ITEM_DAMAGE_BACK                 (266)
#define SUBSCR_BAG_HP_RESTORE                   (267)
#define SUBSCR_BAG_STATUS_HEAL                  (268)
#define SUBSCR_BAG_STAT_BOOST                   (269)
#define SUBSCR_BAG_GUARD_SPEC                   (270)
#define SUBSCR_OVERWORLD_RAIN                   (271)
#define SUBSCR_OVERWORLD_HAIL                   (272)
#define SUBSCR_OVERWORLD_SAND                   (273)
#define SUBSCR_OVERWORLD_FOG                    (274)
#define SUBSCR_SAFARI_THROW_BALL                (275)
#define SUBSCR_GET_EXP                          (276)
#define SUBSCR_BOOM                             (277)
#define SUBSCR_CHECK_QUICK_CLAW                 (278)
#define SUBSCR_PUSH_ATTACKER_DEFENDER           (279)
#define SUBSCR_POP_ATTACKER_DEFENDER            (280)
#define SUBSCR_NO_TARGET                        (281)
#define SUBSCR_BIDE_END_NO_TARGET               (282)
#define SUBSCR_LINK_WIN_LOSE                    (283)
#define SUBSCR_ESCAPE_SUCCESS                   (284)
#define SUBSCR_PRESSURE                         (285)
#define SUBSCR_ENEMY_ESCAPE_FAIL                (286)
#define SUBSCR_VANISH_OFF                       (287)
#define SUBSCR_TAUNT_END                        (288)
#define SUBSCR_FULL_RESTORE                     (289)
#define SUBSCR_PLUCK_CHECK                      (290)
#define SUBSCR_DISABLE_MOVE_ANIMATIONS          (291)
#define SUBSCR_POWER_HERB_SKULL_BASH            (292)
#define SUBSCR_SHAYMIN_FORM_CHECK               (293)
#define SUBSCR_OVERWORLD_SUN                    (294)
#define SUBSCR_OVERWORLD_TRICK_ROOM             (295)
#define SUBSCR_GIRATINA_FORM_CHECK              (296)
#define SUBSCR_GROWTH                           (297)

// new stuff below here
BOOL __attribute__((long_call)) Moves_IsPowder(u16 moveID);

#endif