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


.create "build/battle/scr/effscr/be_seq_232.bin", 0

// Embargo
effscr_232:
    CheckSubstitute                     BATTLER_DEFENDER, effscr_232_Failure
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_EMBARGO
    End                                 

effscr_232_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close