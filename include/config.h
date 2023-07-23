#ifndef __CONFIG_H
#define __CONFIG_H

// Master debug flag. Don't leave this turned on for your final release.
#define DEBUG_MODE

#ifdef DEBUG_MODE
// #define DEBUG_ALL_CRITS
// #define DEBUG_NO_CRITS
#endif

// Generational constant definitions
#define GEN4    4
#define GEN5    5
#define GEN6    6
#define GEN7    7
#define GEN8    8
#define GEN9    9

// If this is defined, then overworld poison damage will be applied when taking
// steps around the map. Pokemon with the abilities Magic Guard, Immunity, and
// Poison Heal still will not take Poison damage.
#define OVERWORLD_POISON_DAMAGE

// If this is defined, determines the base multiplier used for critical hit damage.
//  - Values <= 5 will cause critical hits to multiply damage by 2x.
//  - Values >= 6 will cause critical hits to multiply damage by 1.5x.
//
// If this value is undefined, then it acts as GEN6.
// TODO: Pair with configurable Critical Rate
#define CRITICAL_DAMAGE_MULTIPLIER      GEN6

// If this is defined, determines the multiplier used for Gem activations on
// corresponding moves:
//  - Values <= 5 will cause Gems to multiply damage by 1.5x.
//  - Values >= 6 will cause Gems to multiply damage by 1.3x.
//
// If this value is undefined, then it acts as GEN6.
#define GEM_DAMAGE_MULTIPLIER           GEN6

// If this is defined, then the save structure will be expanded to allow for
// additional Pokedex entries and forme changes. This WILL break compatibility
// with PKHeX.
#define SAVE_EXPANSION

// If this is defined, then the bag pocket system will be expanded to allow for
// newly-implemented items from later generations.
// NOTE: This flag is ONLY functional if SAVE_EXPANSION is also toggled.
#define POCKET_EXPANSION

// If this is defined, then the TM expansion system will be compiled, allowing for
// up to 128 combined TMs and HMs.
#define TM_EXPANSION
// The number of available TMs.
#define NUM_TMS 92
// The number of available HMs.
#define NUM_HMS 8

// The number of moves that are learnable per Pokemon by level-up.
#define LEARNSET_SIZE 30
#define LEARNSET_SIZE_PLUS_TERMINATOR (LEARNSET_SIZE + 1)

// If set to 1, then the generated ROM will force set mode in battle. Primarily
// for difficulty-focused hacks.
#define BATTLE_MODE_FORCE_SET 0

// If defined, uncaps the frame rate in battle.
#define UNCAP_BATTLE_FRAME_RATE

// Set this to the generation whose experience formula you wish to implement.
// Generations 5, 7, and 8 use a scaled formula that accounts for differences
// in levels. Generations 1, 2, 3, 4, and 6 use a flat formula based on the
// fainted Pokemon's level.
#define EXPERIENCE_FORMULA_GEN 4

// If set, then the hidden ability system will be compiled. Commenting this
// line out will disable hidden abilities.
#define HIDDEN_ABILITIES
// Defines a script flag which, when set, will give a Pokemon its hidden
// ability (and be unset immediately after that process).
#define HIDDEN_ABILITIES_FLAG 2600

// If set, then the mega-evolution system will be compiled. This includes
// stone-based mega-evolution (e.g., Venusaur, Charizard-X), Primal Reversion
// (Kyogre, Groudon), and special megas (Rayquaza, Necrozma).
#define MEGA_EVOLUTIONS

#endif // __CONFIG_H