#ifndef __CONFIG_H
#define __CONFIG_H

// The start address for all assembled routines and tables to be inserted into
// the expanded arm9 (as overlay 129).
#define START_ADDRESS 0x0

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