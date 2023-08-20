from enum import Enum, Flag, auto
import os
import json

from ndspy.narc import NARC

from .util import Type, MoveClass, signed_int, snake_case


BASE_MOVE_DATA_NARC = 'base/data/poketool/waza/pl_waza_tbl.narc'
BATTLE_MOVE_ARCHIVE = 0
MOVE_NAME_ARCHIVE = 647
MOVE_NAME_CAPS_ARCHIVE = 648


class MoveEffect(Enum):
    NONE                            = 0
    SLEEP_STATUS                    = 1
    POISON_ON_HIT                   = 2
    DRAIN_HALF_DAMAGE               = 3
    BURN_ON_HIT                     = 4
    FREEZE_ON_HIT                   = 5
    PARALYZE_ON_HIT                 = 6
    SELF_DESTRUCT                   = 7
    DREAM_EATER                     = 8
    MIRROR_MOVE                     = 9
    RAISE_ATK_STATUS                = 10
    RAISE_DEF_STATUS                = 11
    RAISE_SPE_STATUS                = 12
    RAISE_SPA_STATUS                = 13
    RAISE_SPD_STATUS                = 14
    RAISE_ACC_STATUS                = 15
    RAISE_EVA_STATUS                = 16
    ALWAYS_HIT                      = 17
    LOWER_ATK_STATUS                = 18
    LOWER_DEF_STATUS                = 19
    LOWER_SPE_STATUS                = 20
    LOWER_SPA_STATUS                = 21
    LOWER_SPD_STATUS                = 22
    LOWER_ACC_STATUS                = 23
    LOWER_EVA_STATUS                = 24
    RESET_STAT_CHANGES              = 25
    BIDE                            = 26
    THRASH                          = 27
    FORCE_SWITCH                    = 28
    MULTI_HIT                       = 29
    CONVERSION                      = 30
    FLINCH_ON_HIT                   = 31
    RESTORE_HALF_HP                 = 32
    BADLY_POISONS                   = 33
    PAY_DAY                         = 34
    LIGHT_SCREEN                    = 35
    TRI_ATTACK                      = 36
    REST                            = 37
    ONE_HIT_KO                      = 38
    CHARGE_TURN_HIGH_CRIT           = 39
    SUPER_FANG                      = 40
    DRAGON_RAGE                     = 41
    BINDING                         = 42
    HIGH_CRITICAL                   = 43
    HIT_TWICE                       = 44
    CRASH_DAMAGE                    = 45
    PREVENT_STAT_REDUCTION          = 46
    SHARPLY_RAISE_CRIT              = 47
    RECOIL_1_4                      = 48
    CONFUSION_STATUS                = 49
    SHARPLY_RAISE_ATK_STATUS        = 50
    SHARPLY_RAISE_DEF_STATUS        = 51
    SHARPLY_RAISE_SPE_STATUS        = 52
    SHARPLY_RAISE_SPA_STATUS        = 53
    SHARPLY_RAISE_SPD_STATUS        = 54
    SHARPLY_RAISE_ACC_STATUS        = 55
    SHARPLY_RAISE_EVA_STATUS        = 56
    TRANSFORM                       = 57
    SHARPLY_LOWER_ATK_STATUS        = 58
    SHARPLY_LOWER_DEF_STATUS        = 59
    SHARPLY_LOWER_SPE_STATUS        = 60
    SHARPLY_LOWER_SPA_STATUS        = 61
    SHARPLY_LOWER_ACC_STATUS        = 62
    SHARPLY_LOWER_EVA_STATUS        = 63
    SHARPLY_LOWER_SPD_STATUS        = 64
    REFLECT                         = 65
    POISON_STATUS                   = 66
    PARALYZE_STATUS                 = 67
    LOWER_ATK_ON_HIT                = 68
    LOWER_DEF_ON_HIT                = 69
    LOWER_SPE_ON_HIT                = 70
    LOWER_SPA_ON_HIT                = 71
    LOWER_SPD_ON_HIT                = 72
    LOWER_ACC_ON_HIT                = 73
    LOWER_EVA_ON_HIT                = 74
    CHARGE_TURN_HIGH_CRIT_FLINCH    = 75
    CONFUSE_ON_HIT                  = 76
    HIT_TWICE_POISON_ON_HIT         = 77
    VITAL_THROW                     = 78
    SUBSTITUTE                      = 79
    RECHARGE_TURN                   = 80
    RAISE_ATK_WHEN_HIT              = 81
    MIMIC                           = 82
    METRONOME                       = 83
    LEECH_SEED                      = 84
    SPLASH                          = 85
    DISABLE                         = 86
    DEAL_DAMAGE_EQUAL_TO_LEVEL      = 87
    PSYWAVE                         = 88
    COUNTER                         = 89
    ENCORE                          = 90
    PAIN_SPLIT                      = 91
    SNORE                           = 92
    CONVERSION2                     = 93
    NEXT_ATTACK_ALWAYS_HITS         = 94
    SKETCH                          = 95
    SLEEP_TALK                      = 97
    DESTINY_BOND                    = 98
    HIGHER_POWER_WITH_LESS_HP       = 99
    SPITE                           = 100
    LEAVE_WITH_1_HP                 = 101
    HEAL_BELL                       = 102
    PRIORITY_PLUS_1                 = 103
    TRIPLE_KICK                     = 104
    STEAL_HELD_ITEM                 = 105
    PREVENT_ESCAPE                  = 106
    NIGHTMARE                       = 107
    MINIMIZE                        = 108
    CURSE                           = 109
    PROTECT                         = 111
    SPIKES                          = 112
    FORESIGHT                       = 113
    PERISH_SONG                     = 114
    CAUSE_SANDSTORM                 = 115
    ENDURE                          = 116
    ROLLOUT                         = 117
    SWAGGER                         = 118
    FURY_CUTTER                     = 119
    INFATUATE                       = 120
    RETURN                          = 121
    PRESENT                         = 122
    FRUSTRATION                     = 123
    SAFEGUARD                       = 124
    THAW_AND_BURN_ON_HIT            = 125
    MAGNITUDE                       = 126
    BATON_PASS                      = 127
    PURSUIT                         = 128
    RAPID_SPIN                      = 129
    SONICBOOM                       = 130
    SYNTHESIS                       = 132
    HIDDEN_POWER                    = 135
    CAUSE_RAIN                      = 136
    CAUSE_SUN                       = 137
    RAISE_DEF_ON_HIT                = 138
    RAISE_ATK_ON_HIT                = 139
    RAISE_ALL_ON_HIT                = 140
    BELLY_DRUM                      = 142
    COPY_STAT_BOOSTS                = 143
    MIRROR_COAT                     = 144
    CHARGE_TURN_RAISE_DEF           = 145
    TWISTER                         = 146
    DOUBLE_DAMAGE_ON_DIG            = 147
    FUTURE_SIGHT                    = 148
    DOUBLE_DAMAGE_AIRBORNE          = 149
    STOMP                           = 150
    CHARGE_TURN_UNLESS_SUN          = 151
    THUNDER                         = 152
    FLEE_FROM_WILD_BATTLE           = 153
    BEAT_UP                         = 154
    FLY                             = 155
    DEFENSE_CURL                    = 156
    FAKE_OUT                        = 158
    UPROAR                          = 159
    STOCKPILE                       = 160
    SPIT_UP                         = 161
    SWALLOW                         = 162
    CAUSE_HAIL                      = 164
    TORMENT                         = 165
    FLATTER                         = 166
    BURN_STATUS                     = 167
    MEMENTO                         = 168
    FACADE                          = 169
    FOCUS_PUNCH                     = 170
    SMELLING_SALTS                  = 171
    FOLLOW_ME                       = 172
    NATURE_POWER                    = 173
    CHARGE                          = 174
    TAUNT                           = 175
    HELPING_HAND                    = 176
    SWITCH_HELD_ITEMS               = 177
    COPY_ABILITY                    = 178
    WISH                            = 179
    ASSIST                          = 180
    INGRAIN                         = 181
    SUPERPOWER                      = 182
    MAGIC_COAT                      = 183
    RECYCLE                         = 184
    REVENGE                         = 185
    REMOVE_SCREENS                  = 186
    YAWN                            = 187
    REMOVE_TARGET_HELD_ITEM         = 188
    ENDEAVOR                        = 189
    LOWER_POWER_WITH_LESS_HP        = 190
    SWITCH_ABILITIES                = 191
    IMPRISON                        = 192
    REFRESH                         = 193
    GRUDGE                          = 194
    SNATCH                          = 195
    LOW_KICK                        = 196
    SECRET_POWER                    = 197
    RECOIL_1_3                      = 198
    CONFUSION_ON_HIT                = 199
    HIGH_CRIT_BURN_ON_HIT           = 200
    MUD_SPORT                       = 201
    BADLY_POISON_ON_HIT             = 202
    WEATHER_BALL                    = 203
    SHARPLY_LOWER_OWN_SPA           = 204
    TICKLE                          = 205
    COSMIC_POWER                    = 206
    SKY_UPPERCUT                    = 207
    BULK_UP                         = 208
    HIGH_CRIT_POISON_ON_HIT         = 209
    WATER_SPORT                     = 210
    RAISE_SPA_AND_SPD_STATUS        = 211
    RAISE_ATK_AND_SPE_STATUS        = 212
    CAMOUFLAGE                      = 213
    ROOST                           = 214
    GRAVITY                         = 215
    WAKE_UP_SLAP                    = 216
    MIRACLE_EYE                     = 217
    LOWER_OWN_SPE                   = 218
    GYRO_BALL                       = 219
    HEALING_WISH                    = 220
    BRINE                           = 221
    NATURAL_GIFT                    = 222
    FEINT                           = 223
    CONSUME_TARGET_BERY             = 224
    TAILWIND                        = 225
    ACUPRESSURE                     = 226
    METAL_BURST                     = 227
    SWITCH_OUT_ON_HIT               = 228
    CLOSE_COMBAT                    = 229
    PAYBACK                         = 230
    ASSURANCE                       = 231
    EMBARGO                         = 232
    FLING                           = 233
    PSYCHO_SHIFT                    = 234
    TRUMP_CARD                      = 235
    HEAL_BLOCK                      = 236
    WRING_OUT                       = 237
    POWER_TRICK                     = 238
    SUPPRESS_TARGET_ABILITY         = 239
    LUCKY_CHANT                     = 240
    ME_FIRST                        = 241
    USE_LAST_USED_MOVE              = 242
    POWER_SWAP                      = 243
    GUARD_SWAP                      = 244
    PUNISHMENT                      = 245
    LAST_RESORT                     = 246
    WORRY_SEED                      = 247
    SUCKER_PUNCH                    = 248
    TOXIC_SPIKES                    = 249
    SWAP_STAT_CHANGES               = 250
    AQUA_RING                       = 251
    MAGNET_RISE                     = 252
    RECOIL_1_3_BURN_ON_HIT          = 253
    STRUGGLE                        = 254
    DIVE                            = 255
    DIG                             = 256
    DOUBLE_DAMAGE_ON_DIVE           = 257
    DEFOG                           = 258
    TRICK_ROOM                      = 259
    BLIZZARD                        = 260
    WHIRLPOOL                       = 261
    RECOIL_1_3_PARALYZE_ON_HIT      = 262
    BOUNCE                          = 263
    CAPTIVATE                       = 265
    STEALTH_ROCK                    = 266
    CHATTER                         = 267
    JUDGMENT                        = 268
    RECOIL_1_2                      = 269
    LUNAR_DANCE                     = 270
    SHARPLY_LOWER_SPD_ON_HIT        = 271
    SHADOW_FORCE                    = 272
    FLINCH_BURN_ON_HIT              = 273
    FLINCH_FREEZE_ON_HIT            = 274
    FLINCH_PARALYZE_ON_HIT          = 275
    RAISE_SPA_ON_HIT                = 276


class MoveTarget(Flag):
    ANY_SINGLE      = 0
    AUTOMATIC       = 1
    RANDOM          = 2
    BOTH_OPPONENTS  = 4         # Muddy Water
    ALL_BATTLERS    = 8         # Earthquake, Discharge
    USER            = 16        # Swords Dance
    USER_SIDE       = 32        # Reflect, Light Screen
    ENTIRE_FIELD    = 64        # Water Sport
    OPPONENT_SIDE   = 128       # Stealth Rock, Spikes
    HELPING_HAND    = 256       # Fails if no Ally
    ACUPRESSURE     = 512       # User or Ally
    ME_FIRST        = 1024      # Opponent (fails if target faints or moves first)


def dump_movedata(movedata_file: bytes, move_name: str):
    return {
        'name': move_name,
        'type': Type(movedata_file[4]).name,
        'category': MoveClass(movedata_file[2]).name,
        'power': movedata_file[3],
        'accuracy': movedata_file[5],
        'base_pp': movedata_file[6],
        'effect': MoveEffect(int.from_bytes(movedata_file[0:2], 'little')).name,
        'effect_chance': movedata_file[7],
        'target_type': MoveTarget(int.from_bytes(movedata_file[8:10], 'little')).name,
        'priority': signed_int(movedata_file[10]),
        'flags': {
            'make_contact': bool(movedata_file[11] & 1),
            'blocked_by_protect': bool(movedata_file[11] & (1 << 1)),
            'bounced_by_magic_coat': bool(movedata_file[11] & (1 << 2)),
            'stolen_by_snatch': bool(movedata_file[11] & (1 << 3)),
            'can_be_mirror_moved': bool(movedata_file[11] & (1 << 4)),
            'triggers_kings_rock': bool(movedata_file[11] & (1 << 5)),
            'animation_hides_hp_bars': bool(movedata_file[11] & (1 << 6)),
            'animation_hides_shadows': bool(movedata_file[11] & (1 << 7)),
        },
        'contest_effect': movedata_file[12],
        'contest_type': movedata_file[13]
    }


def dump_moves():
    if not os.path.exists('build/narc/movedata'):
        os.makedirs('build/narc/movedata')
    if not os.path.exists('build/movedata'):
        os.makedirs('build/movedata')
    if not os.path.exists('data/moves'):
        os.makedirs('data/moves')
    
    movedata_narc = NARC.fromFile(BASE_MOVE_DATA_NARC)
    movenames_txt = open('data/text/647.txt', 'r', encoding='utf8')
    for i, movedata_file in enumerate(movedata_narc.files):
        move_name = movenames_txt.readline().strip()
        print(f'dumping {i}: {move_name}')
        dump_data = dump_movedata(movedata_file, move_name)
        move_fname = f'move_{i:03}' if i in [0, 468, 469, 470] else snake_case(move_name)
        j = open(f'data/moves/{snake_case(move_fname)}.json', 'w', encoding='utf8')
        json.dump(dump_data, j, indent=4, ensure_ascii=False)
