#ifndef __CONSTANTS_MISC_H
#define __CONSTANTS_MISC_H

// ====== PSS ======

#define PSS_PHYSICAL 0
#define PSS_SPECIAL  1
#define PSS_STATUS   2

// ===== Types =====

#define TYPE_NORMAL   0x00
#define TYPE_FIGHTING 0x01
#define TYPE_FLYING   0x02
#define TYPE_POISON   0x03
#define TYPE_GROUND   0x04
#define TYPE_ROCK     0x05
#define TYPE_BUG      0x06
#define TYPE_GHOST    0x07
#define TYPE_STEEL    0x08
#define TYPE_MYSTERY  0x09
#define TYPE_FAIRY    0x09
#define TYPE_FIRE     0x0A
#define TYPE_WATER    0x0B
#define TYPE_GRASS    0x0C
#define TYPE_ELECTRIC 0x0D
#define TYPE_PSYCHIC  0x0E
#define TYPE_ICE      0x0F
#define TYPE_DRAGON   0x10
#define TYPE_DARK     0x11
#define TYPE_NONE     0x1F

#define NUM_TYPES     (TYPE_DARK + 1)

// ===== Body Colors ======

#define BODY_COLOR_RED      0x0
#define BODY_COLOR_BLUE     0x1
#define BODY_COLOR_YELLOW   0x2
#define BODY_COLOR_GREEN    0x3
#define BODY_COLOR_BLACK    0x4
#define BODY_COLOR_BROWN    0x5
#define BODY_COLOR_PURPLE   0x6
#define BODY_COLOR_GRAY     0x7
#define BODY_COLOR_WHITE    0x8
#define BODY_COLOR_PINK     0x9
#define BODY_COLOR_EGG      0xA

// ===== Growth Rates =====

#define GROWTH_MEDIUM_FAST  0
#define GROWTH_ERRATIC      1
#define GROWTH_FLUCTUATING  2
#define GROWTH_MEDIUM_SLOW  3
#define GROWTH_FAST         4
#define GROWTH_SLOW         5

// ===== Egg Groups =====

#define EGG_GROUP_NONE          0x0
#define EGG_GROUP_MONSTER       0x1
#define EGG_GROUP_WATER_1       0x2
#define EGG_GROUP_BUG           0x3
#define EGG_GROUP_FLYING        0x4
#define EGG_GROUP_FIELD         0x5
#define EGG_GROUP_FAIRY         0x6
#define EGG_GROUP_GRASS         0x7
#define EGG_GROUP_HUMAN_LIKE    0x8
#define EGG_GROUP_WATER_3       0x9
#define EGG_GROUP_MINERAL       0xA
#define EGG_GROUP_AMORPHOUS     0xB
#define EGG_GROUP_WATER_2       0xC
#define EGG_GROUP_DITTO         0xD
#define EGG_GROUP_DRAGON        0xE
#define EGG_GROUP_UNDISCOVERED  0xF

// ===== Flavors =====

#define FLAVOR_SPICY    0
#define FLAVOR_DRY      1
#define FLAVOR_SWEET    2
#define FLAVOR_BITTER   3
#define FLAVOR_SOUR     4
#define FLAVOR_NONE     5

// ===== Field Weather =====

#define WEATHER_CLEAR           0
#define WEATHER_CLOUDY          1
#define WEATHER_RAINING         2
#define WEATHER_HEAVY_RAIN      3
#define WEATHER_THUNDERSTORM    4
#define WEATHER_SNOWING         5
#define WEATHER_HEAVY_SNOW      6
#define WEATHER_BLIZZARD        7
#define WEATHER_CLEAR_8         8
#define WEATHER_SLOW_ASHFALL    9
#define WEATHER_SANDSTORM       10
#define WEATHER_HAILING         11
#define WEATHER_SPIRITS         12
#define WEATHER_CLEAR_13        13
#define WEATHER_FOG             14
#define WEATHER_DEEP_FOG        15
#define WEATHER_DARK_FLASH      16

#define WEATHER_HARSH_SUN       1001
#define WEATHER_TRICK_ROOM      1002

#endif // __CONSTANTS_MISC_H