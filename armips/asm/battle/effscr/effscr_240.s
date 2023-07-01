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


.create "build/battle/scr/effscr/be_seq_240.bin", 0

// Lucky Chant
effscr_240:
    If                                  FLAG_EQ, VAR_ATTACKER_SIDE_CONDITIONS, SIDE_CONDITION_LUCKY_CHANT, effscr_240_LuckyChantAlreadyActive
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_LUCKY_CHANT
    End                                 

effscr_240_LuckyChantAlreadyActive:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close