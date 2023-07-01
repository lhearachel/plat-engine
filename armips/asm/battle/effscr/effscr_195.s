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


.create "build/battle/scr/effscr/be_seq_195.bin", 0

// Snatch
effscr_195:
    TrySnatch                           effscr_195_MoveCannotBeSnatched
    PrepareMessage                      577, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    End

effscr_195_MoveCannotBeSnatched:                                 
    SetVar                              OP_SET, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close