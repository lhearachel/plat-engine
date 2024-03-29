from ndspy.narc import NARC
from os import path, makedirs

import json
import tools.narcpy as narcpy

MOVE_EFFECTS = {
    'NONE':                                 0,
    'SLEEP_STATUS':                         1,
    'POISON_ON_HIT':                        2,
    'RECOVER_HALF_DAMAGE_DEALT':            3,
    'BURN_ON_HIT':                          4,
    'FREEZE_ON_HIT':                        5,
    'PARALYZE_ON_HIT':                      6,
    'SELF_DESTRUCT':                        7,
    'DREAM_EATER':                          8,
    'MIRROR_MOVE':                          9,
    'RAISE_ATK_STATUS':                     10,
    'RAISE_DEF_STATUS':                     11,
    'RAISE_SPE_STATUS':                     12,
    'RAISE_SPA_STATUS':                     13,
    'RAISE_SPD_STATUS':                     14,
    'RAISE_ACC_STATUS':                     15,
    'RAISE_EVA_STATUS':                     16,
    'ALWAYS_HIT':                           17,
    'LOWER_ATK_STATUS':                     18,
    'LOWER_DEF_STATUS':                     19,
    'LOWER_SPE_STATUS':                     20,
    'LOWER_SPA_STATUS':                     21,
    'LOWER_SPD_STATUS':                     22,
    'LOWER_ACC_STATUS':                     23,
    'LOWER_EVA_STATUS':                     24,
    'RESET_STAT_CHANGES':                   25,
    'BIDE':                                 26,
    'THRASH':                               27,
    'FORCE_SWITCH':                         28,
    'MULTI_HIT':                            29,
    'CONVERSION':                           30,
    'FLINCH_ON_HIT':                        31,
    'RESTORE_HALF_HP':                      32,
    'BADLY_POISONS':                        33,
    'PAY_DAY':                              34,
    'LIGHT_SCREEN':                         35,
    'RANDOM_BRN_PRZ_OR_PSN_ON_HIT':         36,
    'REST':                                 37,
    'ONE_HIT_KO':                           38,
    'CHARGE_TURN_HIGH_CRIT':                39,
    'SUPER_FANG':                           40,
    'DRAGON_RAGE':                          41,
    'BINDING':                              42,
    'HIGH_CRITICAL':                        43,
    'HIT_TWICE':                            44,
    'CRASH_DAMAGE':                         45,
    'PREVENT_STAT_REDUCTION':               46,
    'SHARPLY_RAISE_CRIT':                   47,
    'RECOIL_1_4':                           48,
    'CONFUSION_STATUS':                     49,
    'SHARPLY_RAISE_ATK_STATUS':             50,
    'SHARPLY_RAISE_DEF_STATUS':             51,
    'SHARPLY_RAISE_SPE_STATUS':             52,
    'SHARPLY_RAISE_SPA_STATUS':             53,
    'SHARPLY_RAISE_SPD_STATUS':             54,
    'SHARPLY_RAISE_ACC_STATUS':             55,
    'SHARPLY_RAISE_EVA_STATUS':             56,
    'TRANSFORM':                            57,
    'SHARPLY_LOWER_ATK_STATUS':             58,
    'SHARPLY_LOWER_DEF_STATUS':             59,
    'SHARPLY_LOWER_SPE_STATUS':             60,
    'SHARPLY_LOWER_SPA_STATUS':             61,
    'SHARPLY_LOWER_ACC_STATUS':             62,
    'SHARPLY_LOWER_EVA_STATUS':             63,
    'SHARPLY_LOWER_SPD_STATUS':             64,
    'REFLECT':                              65,
    'POISON_STATUS':                        66,
    'PARALYZE_STATUS':                      67,
    'LOWER_ATK_ON_HIT':                     68,
    'LOWER_DEF_ON_HIT':                     69,
    'LOWER_SPE_ON_HIT':                     70,
    'LOWER_SPA_ON_HIT':                     71,
    'LOWER_SPD_ON_HIT':                     72,
    'LOWER_ACC_ON_HIT':                     73,
    'LOWER_EVA_ON_HIT':                     74,
    'CHARGE_TURN_HIGH_CRIT_AND_FLINCH':     75,
    'CONFUSE_ON_HIT':                       76,
    'HIT_TWICE_POISON_ON_HIT':              77,
    'VITAL_THROW':                          78,
    'SUBSTITUTE':                           79,
    'RECHARGE_TURN':                        80,
    'RAISE_ATK_WHEN_HIT':                   81,
    'MIMIC':                                82,
    'METRONOME':                            83,
    'LEECH_SEED':                           84,
    'SPLASH':                               85,
    'DISABLE':                              86,
    'DEAL_DAMAGE_EQUAL_TO_LEVEL':           87,
    'PSYWAVE':                              88,
    'COUNTER':                              89,
    'ENCORE':                               90,
    'PAIN_SPLIT':                           91,
    'SNORE':                                92,
    'CONVERSION2':                          93,
    'NEXT_ATTACK_ALWAYS_HITS':              94,
    'SKETCH':                               95,
    'SLEEP_TALK':                           97,
    'DESTINY_BOND':                         98,
    'HIGHER_POWER_WITH_LESS_HP':            99,
    'SPITE':                                100,
    'LEAVE_WITH_1_HP':                      101,
    'HEAL_BELL':                            102,
    'PRIORITY_PLUS_1':                      103,
    'TRIPLE_KICK':                          104,
    'STEAL_HELD_ITEM':                      105,
    'PREVENT_ESCAPE':                       106,
    'NIGHTMARE':                            107,
    'MINIMIZE':                             108,
    'CURSE':                                109,
    'PROTECT':                              111,
    'SPIKES':                               112,
    'FORESIGHT':                            113,
    'PERISH_SONG':                          114,
    'CAUSE_SANDSTORM':                      115,
    'ENDURE':                               116,
    'ROLLOUT':                              117,
    'SHARPLY_RAISE_TARGET_ATK_AND_CONFUSE': 118,
    'DOUBLE_POWER_ON_CONSECUTIVE_HITS':     119,
    'INFATUATE':                            120,
    'RETURN':                               121,
    'PRESENT':                              122,
    'FRUSTRATION':                          123,
    'SAFEGUARD':                            124,
    'THAW_AND_BURN_ON_HIT':                 125,
    'MAGNITUDE':                            126,
    'BATON_PASS':                           127,
    'PURSUIT':                              128,
    'REMOVE_HAZARDS_AND_BINDING_EFFECTS':   129,
    'SONICBOOM':                            130,
    'SYNTHESIS':                            132,
    'HIDDEN_POWER':                         135,
    'CAUSE_RAIN':                           136,
    'CAUSE_SUN':                            137,
    'RAISE_DEF_ON_HIT':                     138,
    'RAISE_ATK_ON_HIT':                     139,
    'RAISE_ALL_ON_HIT':                     140,
    'BELLY_DRUM':                           142,
    'COPY_STAT_BOOSTS':                     143,
    'MIRROR_COAT':                          144,
    'CHARGE_TURN_RAISE_DEF':                145,
    'FLINCH_DOUBLE_DAMAGE_FLY_OR_BOUNCE':   146,
    'DOUBLE_DAMAGE_ON_DIG':                 147,
    'FUTURE_SIGHT':                         148,
    'DOUBLE_DAMAGE_FLY_OR_BOUNCE':          149,
    'DOUBLE_DAMAGE_MINIMIZE_FLINCH_ON_HIT': 150,
    'CHARGE_TURN_UNLESS_SUN':               151,
    'THUNDER':                              152,
    'FLEE_FROM_WILD_BATTLE':                153,
    'BEAT_UP':                              154,
    'FLY':                                  155,
    'RAISE_DEFENSE_DOUBLE_ROLLOUT_POWER':   156,
    'ALWAYS_FLINCH_ONLY_TURN_ONE':          158,
    'UPROAR':                               159,
    'STOCKPILE':                            160,
    'SPIT_UP':                              161,
    'SWALLOW':                              162,
    'CAUSE_HAIL':                           164,
    'TORMENT':                              165,
    'RAISE_TARGET_SPA_AND_CONFUSE':         166,
    'BURN_STATUS':                          167,
    'MEMENTO':                              168,
    'DOUBLE_POWER_IF_PSN_PRZ_BRN':          169,
    'FOCUS_PUNCH':                          170,
    'DOUBLE_POWER_AND_CURE_PRZ':            171,
    'FOLLOW_ME':                            172,
    'NATURE_POWER':                         173,
    'NEXT_MOVE_DOUBLE_DAMAGE_IF_ELECTRIC':  174,
    'TAUNT':                                175,
    'HELPING_HAND':                         176,
    'SWITCH_HELD_ITEMS':                    177,
    'COPY_ABILITY':                         178,
    'WISH':                                 179,
    'ASSIST':                               180,
    'INGRAIN':                              181,
    'LOWER_USER_ATK_AND_DEF':               182,
    'MAGIC_COAT':                           183,
    'RECYCLE':                              184,
    'DOUBLE_DAMAGE_IF_USER_HAS_BEEN_HIT':   185,
    'REMOVE_SCREENS':                       186,
    'YAWN':                                 187,
    'REMOVE_TARGET_HELD_ITEM':              188,
    'ENDEAVOR':                             189,
    'LOWER_POWER_WITH_LESS_HP':             190,
    'SWITCH_ABILITIES':                     191,
    'IMPRISON':                             192,
    'CURE_BRN_PSN_OR_PRZ':                  193,
    'GRUDGE':                               194,
    'SNATCH':                               195,
    'HIGHER_POWER_ON_HEAVIER_TARGETS':      196,
    'SECRET_POWER':                         197,
    'RECOIL_1_3':                           198,
    'CONFUSION_ON_HIT':                     199,
    'HIGH_CRIT_BURN_ON_HIT':                200,
    'MUD_SPORT':                            201,
    'BADLY_POISON_ON_HIT':                  202,
    'CHANGE_TYPE_WITH_WEATHER':             203,
    'SHARPLY_LOWER_USER_SPA_ON_HIT':        204,
    'LOWER_TARGET_ATK_AND_DEF_STATUS':      205,
    'RAISE_DEF_AND_SPD_STATUS':             206,
    'SKY_UPPERCUT':                         207,
    'RAISE_ATK_AND_DEF_STATUS':             208,
    'HIGH_CRIT_POISON_ON_HIT':              209,
    'WATER_SPORT':                          210,
    'RAISE_SPA_AND_SPD_STATUS':             211,
    'RAISE_ATK_AND_SPE_STATUS':             212,
    'CAMOUFLAGE':                           213,
    'ROOST':                                214,
    'GRAVITY':                              215,
    'DOUBLE_POWER_AND_CURE_SLP':            216,
    'MIRACLE_EYE':                          217,
    'LOWER_SPE_ON_HIT':                     218,
    'GYRO_BALL':                            219,
    'HEALING_WISH':                         220,
    'DOUBLE_POWER_IF_TARGET_BELOW_HALF':    221,
    'NATURAL_GIFT':                         222,
    'FEINT':                                223,
    'CONSUME_TARGET_BERY':                  224,
    'TAILWIND':                             225,
    'ACUPRESSURE':                          226,
    'METAL_BURST':                          227,
    'SWITCH_OUT_ON_HIT':                    228,
    'LOWER_DEF_AND_SPD_ON_HIT':             229,
    'PAYBACK':                              230,
    'DOUBLE_DAMAGE_IF_TARGET_HAS_BEEN_HIT': 231,
    'EMBARGO':                              232,
    'FLING':                                233,
    'PSYCHO_SHIFT':                         234,
    'TRUMP_CARD':                           235,
    'HEAL_BLOCK':                           236,
    'WRING_OUT':                            237,
    'SWAP_ATK_AND_DEF_STATS':               238,
    'SUPPRESS_TARGET_ABILITY':              239,
    'LUCKY_CHANT':                          240,
    'ME_FIRST':                             241,
    'USE_LAST_USED_MOVE':                   242,
    'POWER_SWAP':                           243,
    'GUARD_SWAP':                           244,
    'PUNISHMENT':                           245,
    'LAST_RESORT':                          246,
    'WORRY_SEED':                           247,
    'SUCKER_PUNCH':                         248,
    'TOXIC_SPIKES':                         249,
    'SWAP_STAT_CHANGES':                    250,
    'RESTORE_HP_AT_END_OF_TURN':            251,
    'MAGNET_RISE':                          252,
    'RECOIL_1_3_BURN_ON_HIT':               253,
    'STRUGGLE':                             254,
    'DIVE':                                 255,
    'DIG':                                  256,
    'DOUBLE_DAMAGE_ON_DIVE':                257,
    'DEFOG':                                258,
    'TRICK_ROOM':                           259,
    'BLIZZARD':                             260,
    'WHIRLPOOL':                            261,
    'RECOIL_1_3_PARALYZE_ON_HIT':           262,
    'BOUNCE':                               263,
    'CAPTIVATE':                            265,
    'STEALTH_ROCK':                         266,
    'CHATTER':                              267,
    'JUDGMENT':                             268,
    'RECOIL_1_2':                           269,
    'LUNAR_DANCE':                          270,
    'SHARPLY_LOWER_SPD_ON_HIT':             271,
    'SHADOW_FORCE':                         272,
    'FLINCH_BURN_ON_HIT':                   273,
    'FLINCH_FREEZE_ON_HIT':                 274,
    'FLINCH_PARALYZE_ON_HIT':               275,
    'RAISE_SPA_ON_HIT':                     276,
}

PSS = {
    'PHYSICAL': 0,
    'SPECIAL':  1,
    'STATUS':   2,
}

TYPES = {
    'NORMAL':   0,
    'FIGHTING': 1,
    'FLYING':   2,
    'POISON':   3,
    'GROUND':   4,
    'ROCK':     5,
    'BUG':      6,
    'GHOST':    7,
    'STEEL':    8,
    '???':      9,
    'FIRE':     10,
    'WATER':    11,
    'GRASS':    12,
    'ELECTRIC': 13,
    'PSYCHIC':  14,
    'ICE':      15,
    'DRAGON':   16,
    'DARK':     17,
}

TARGETS = {
    'ANY_SINGLE_TARGET':        0,
    'AUTOMATIC':                1,
    'RANDOM':                   2,
    'BOTH_OPPONENTS':           4,
    'BOTH_OPPONENTS_AND_ALLY':  8,
    'USER':                     16,
    'USER_SIDE':                32,
    'ENTIRE_FIELD':             64,
    'OPPONENT_SIDE':            128,
    'HELPING_HAND':             256,
    'ACUPRESSURE':              512,
    'ME_FIRST':                 102,
}

def build_flags(move_flags: dict) -> int:
    flags = 0
    if move_flags['make_contact']:
        flags = flags + 1
    if move_flags['blocked_by_protect']:
        flags = flags + 2
    if move_flags['bounced_by_magic_coat']:
        flags = flags + 4
    if move_flags['stolen_by_snatch']:
        flags = flags + 8
    if move_flags['can_be_mirror_moved']:
        flags = flags + 16
    if move_flags['triggers_kings_rock']:
        flags = flags + 32
    if move_flags['animation_hides_hp_bars']:
        flags = flags + 64
    if move_flags['animation_hides_shadow']:
        flags = flags + 128
    
    return flags


def to_binary(i: int, move_data: dict) -> bytes:
    byte_data = bytearray(16)

    priority = move_data['priority']
    priority = priority if priority >= 0 else 256 + priority

    byte_data[0:2]  = MOVE_EFFECTS[move_data['battle_effect']].to_bytes(2, 'little')
    byte_data[2]    = PSS[move_data['pss']]
    byte_data[3]    = move_data['power']
    byte_data[4]    = TYPES[move_data['type']]
    byte_data[5]    = move_data['accuracy']
    byte_data[6]    = move_data['pp']
    byte_data[7]    = move_data['effect_chance_percent']
    byte_data[8:10] = TARGETS[move_data['target']].to_bytes(2, 'little')
    byte_data[10]   = priority
    byte_data[11]   = build_flags(move_data['flags'])
    byte_data[12]   = move_data['contest_appeal']
    byte_data[13]   = move_data['contest_type']

    return bytes(byte_data)


def build_narc():
    if not path.isfile('data/move_data.json'):
        print(f'Couldn\'t find move_data.json file in data directory; no NARC built')
    
    move_dict = {}
    with open('data/move_data.json', 'r') as data_f:
        move_dict = json.load(data_f)

    # Make all the binary files for input to narcpy
    if not path.isdir('build/data/move_data'):
        makedirs('build/data/move_data')

    move_data_bytes = []
    for i in sorted(move_dict.keys()):
        move_data = move_dict[i]
        byte_data = to_binary(i, move_data)
        with open(f'build/data/move_data/pl_waza_tbl_{i}.bin', 'wb') as out:
            out.write(byte_data)

    # Invoke narcpy to make the new narc
    if not path.isdir('build/narc/poketool/waza'):
        makedirs('build/narc/poketool/waza')
        
    narcpy.create('build/narc/poketool/waza/pl_waza_tbl.narc', 'build/data/move_data')
