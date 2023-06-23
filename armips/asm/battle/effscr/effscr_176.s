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


.create "build/battle/scr/effscr/be_seq_176.bin", 0

// Helping Hand
effscr_176:
    TryHelpingHand                      effscr_176_Failure
    PrepareMessage                      503, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_HIT_THROUGH_VANISH
    End                                 

effscr_176_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close