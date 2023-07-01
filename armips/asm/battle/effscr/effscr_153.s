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


.create "build/battle/scr/effscr/be_seq_153.bin", 0

// Teleport
//
// This one will need to be overhauled for gen8
effscr_153:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TRAINER, effscr_153_FailInTrainerBattle
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_TELEPORT
    End                                 

effscr_153_FailInTrainerBattle:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close