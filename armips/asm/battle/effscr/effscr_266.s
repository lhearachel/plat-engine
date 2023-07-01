.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/effscr/be_seq_266.bin", 0

// Stealth Rock
effscr_266:
    If                                  FLAG_EQ, VAR_DEFENDER_SIDE_CONDITIONS, SIDE_CONDITION_STEALTH_ROCK, effscr_266_StealthRockAlreadyActive
    SetVar                              OP_SET_FLAG, VAR_DEFENDER_SIDE_CONDITIONS, SIDE_CONDITION_STEALTH_ROCK
    // "Pointed stones float in the air around your {team | foe's team}!"
    PrepareMessage                      1077, TAG_NONE_DIR, BATTLER_ATTACKER_ENEMY, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    End                                 

effscr_266_StealthRockAlreadyActive:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close