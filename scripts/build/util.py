from enum import Enum


def signed_int(i: int) -> int:
    if i > 127:
        return (256 - i) * -1
    return i


class Type(Enum):
    NORMAL   = 0
    FIGHTING = 1
    FLYING   = 2
    POISON   = 3
    GROUND   = 4
    ROCK     = 5
    BUG      = 6
    GHOST    = 7
    STEEL    = 8
    FAIRY    = 9
    FIRE     = 10
    WATER    = 11
    GRASS    = 12
    ELECTRIC = 13
    PSYCHIC  = 14
    ICE      = 15
    DRAGON   = 16
    DARK     = 17
    NONE     = 31


class ItemHoldEffect(Enum):
    NONE                       = 0
    RESTORE_HP                 = 1
    GRISEOUS_ORB               = 2
    ADAMANT_ORB                = 3
    LUSTROUS_ORB               = 4
    CURE_PRZ                   = 5
    CURE_SLP                   = 6
    CURE_PSN                   = 7
    CURE_BRN                   = 8
    CURE_FRZ                   = 9
    RESTORE_PP                 = 10
    CURE_CNF                   = 11
    CURE_ALL                   = 12
    RESTORE_PERCENT_HP         = 13
    RESTORE_PERCENT_HP_SPICY   = 14
    RESTORE_PERCENT_HP_DRY     = 15
    RESTORE_PERCENT_HP_SWEET   = 16
    RESTORE_PERCENT_HP_BITTER  = 17
    RESTORE_PERCENT_HP_SOUR    = 18
    WEAKEN_SE_FIRE             = 19
    WEAKEN_SE_WATER            = 20
    WEAKEN_SE_ELECTRIC         = 21
    WEAKEN_SE_GRASS            = 22
    WEAKEN_SE_ICE              = 23
    WEAKEN_SE_FIGHTING         = 24
    WEAKEN_SE_POISON           = 25
    WEAKEN_SE_GROUND           = 26
    WEAKEN_SE_FLYING           = 27
    WEAKEN_SE_PSYCHIC          = 28
    WEAKEN_SE_BUG              = 29
    WEAKEN_SE_ROCK             = 30
    WEAKEN_SE_GHOST            = 31
    WEAKEN_SE_DRAGON           = 32
    WEAKEN_SE_DARK             = 33
    WEAKEN_SE_STEEL            = 34
    WEAKEN_NORMAL              = 35
    PINCH_BOOST_ATTACK         = 36
    PINCH_BOOST_DEFENSE        = 37
    PINCH_BOOST_SPEED          = 38
    PINCH_BOOST_SPATK          = 39
    PINCH_BOOST_SPDEF          = 40
    PINCH_BOOST_CRIT           = 41
    PINCH_SHARPLY_BOOST_RANDOM = 42
    RESTORE_HP_ON_SE           = 43
    PINCH_WIDE_LENS_ON_NEXT    = 44
    PINCH_MOVE_FIRST           = 45
    RECOIL_PHYSICAL            = 46
    RECOIL_SPECIAL             = 47
    REDUCE_ACCURACY            = 48
    WHITE_HERB                 = 49
    DOUBLE_EV_GAIN             = 50
    EXP_SHARE                  = 51
    QUICK_CLAW                 = 52
    FRIENDSHIP_UP              = 53
    MENTAL_HERB                = 54
    CHOICE_BAND                = 55
    KINGS_ROCK                 = 56
    BOOST_BUG                  = 57
    DOUBLE_PRIZE_MONEY         = 58
    REDUCE_ENCOUNTER_RATE      = 59
    SOUL_DEW                   = 60
    DEEP_SEA_TOOTH             = 61
    DEEP_SEA_SCALE             = 62
    ESCAPE_ENCOUNTER           = 63
    NO_EVOLUTION               = 64
    FOCUS_BAND                 = 65
    INCREASE_EXP_GAIN          = 66
    SCOPE_LENS                 = 67
    BOOST_STEEL                = 68
    LEFTOVERS                  = 69
    EVOLVE_SEADRA              = 70
    LIGHT_BALL                 = 71
    BOOST_GROUND               = 72
    BOOST_ROCK                 = 73
    BOOST_GRASS                = 74
    BOOST_DARK                 = 75
    BOOST_FIGHTING             = 76
    BOOST_ELECTRIC             = 77
    BOOST_WATER                = 78
    BOOST_FLYING               = 79
    BOOST_POISON               = 80
    BOOST_ICE                  = 81
    BOOST_GHOST                = 82
    BOOST_PSYCHIC              = 83
    BOOST_FIRE                 = 84
    BOOST_DRAGON               = 85
    BOOST_NORMAL               = 86
    EVOLVE_PORYGON             = 87
    SHELL_BELL                 = 88
    LUCKY_PUNCH                = 89
    METAL_POWDER               = 90
    THICK_CLUB                 = 91
    LEEK                       = 92
    WIDE_LENS                  = 93
    MUSCLE_BAND                = 94
    WISE_GLASSES               = 95
    EXPERT_BELT                = 96
    LIGHT_CLAY                 = 97
    LIFE_ORB                   = 98
    POWER_HERB                 = 99
    TOXIC_ORB                  = 100
    FLAME_ORB                  = 101
    QUICK_POWDER               = 102
    FOCUS_SASH                 = 103
    ZOOM_LENS                  = 104
    METRONOME                  = 105
    IRON_BALL                  = 106
    LAGGING_TAIL               = 107
    DESTINY_KNOT               = 108
    BLACK_SLUDGE               = 109
    EXTEND_HAIL                = 110
    EXTEND_SANDSTORM           = 111
    EXTEND_SUN                 = 112
    EXTEND_RAIN                = 113
    EXTEND_TRAPPING            = 114
    CHOICE_SCARF               = 115
    STICKY_BARB                = 116
    GAIN_ATK_EVS               = 117
    GAIN_DEF_EVS               = 118
    GAIN_SPA_EVS               = 119
    GAIN_SPD_EVS               = 120
    GAIN_SPE_EVS               = 121
    GAIN_HP_EVS                = 122
    SHED_SHELL                 = 123
    BIG_ROOT                   = 124
    CHOICE_SPECS               = 125
    BOOST_FIRE_PLATE           = 126
    BOOST_WATER_PLATE          = 127
    BOOST_ELECTRIC_PLATE       = 128
    BOOST_GRASS_PLATE          = 129
    BOOST_ICE_PLATE            = 130
    BOOST_FIGHTING_PLATE       = 131
    BOOST_POISON_PLATE         = 132
    BOOST_GROUND_PLATE         = 133
    BOOST_FLYING_PLATE         = 134
    BOOST_PSYCHIC_PLATE        = 135
    BOOST_BUG_PLATE            = 136
    BOOST_ROCK_PLATE           = 137
    BOOST_GHOST_PLATE          = 138
    BOOST_DRAGON_PLATE         = 139
    BOOST_DARK_PLATE           = 140
    BOOST_STEEL_PLATE          = 141
    EVOLVE_RHYDON              = 142
    EVOLVE_ELECTABUZZ          = 143
    EVOLVE_MAGMAR              = 144
    EVOLVE_PORYGON2            = 145
    EVOLVE_DUSKNOIR            = 146


class ItemMoveEffect(Enum):
    NONE                     = 0
    CURE_PRZ                 = 1
    CURE_SLP                 = 2
    CURE_PSN                 = 3
    CURE_BRN                 = 4
    CURE_FRZ                 = 5
    RECOVER_PP_10            = 6
    RECOVER_HP_20            = 7
    CURE_CNF                 = 8
    CURE_ANY                 = 9
    RESTORE_HP_QUARTER       = 10
    RESTORE_HP_SPICY         = 11 # Figy Berry
    RESTORE_HP_DRY           = 12 # Wiki Berry
    RESTORE_HP_SWEET         = 13 # Mago Berry
    RESTORE_HP_BITTER        = 14 # Aguav Berry
    RESTORE_HP_SOUR          = 15 # Iapapa Berry
    RAISE_ATTACK             = 16
    RAISE_DEFENSE            = 17
    RAISE_SPEED              = 18
    RAISE_SP_ATTACK          = 19
    RAISE_SP_DEFENSE         = 20
    RAISE_CRIT_RATIO         = 21
    SHARPLY_RAISE_RANDOM     = 22
    RAISE_ACCURACY_NEXT_MOVE = 23
    RESTORE_LOWERED_STATS    = 24
    CURE_MENTAL              = 25 # Infatuation, Taunt, etc.
    FLINCH_TARGET            = 26
    PRZ_TARGET               = 27
    PSN_TARGET               = 28
    TOX_TARGET               = 29
    BRN_TARGET               = 30


class FieldPocket(Enum):
    ITEMS        = 0
    MEDICINE     = 1
    POKEBALLS    = 2
    TMS_AND_HMS  = 3
    BERRIES      = 4
    MAIL         = 5
    BATTLE_ITEMS = 6
    KEY_ITEMS    = 7


class FieldFunction(Enum):
    NONE         = 0
    RECOVERY     = 1
    TOWN_MAP     = 2
    EXPLORER_KIT = 3
    BICYCLE      = 4
    JOURNAL      = 5
    TM_HM        = 6
    MAIL         = 7
    BERRY        = 8
    POFFIN_CASE  = 9
    PAL_PAD      = 10
    POKE_RADAR   = 11
    SPRAYDUCK    = 12
    MULCH        = 13
    HONEY        = 14
    VS_SEEKER    = 15
    OLD_ROD      = 16
    GOOD_ROD     = 17
    SUPER_ROC    = 18
    BAG_MESSAGE  = 19
    EVOLUTION    = 20
    ESCAPE_ROPE  = 21
    AZURE_FLUTE  = 22
    VS_ITEM      = 23
    GRACIDEA     = 24


# This one is actually a bitmask, hence the spread in values
class BattlePocket(Enum):
    NONE               = 0
    POKEBALLS          = 1
    BATTLE_ITEMS       = 2
    RECOVERY           = 4
    STATUS_HEALING     = 8
    STATUS_HP_RECOVERY = 12
    PP_RECOVERY        = 16


class BattleFunction(Enum):
    NONE        = 0
    POKEBALLS   = 1
    RECOVERY    = 2
    ESCAPE      = 3
