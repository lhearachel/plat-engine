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


.create "build/battle/scr/subscr/sub_seq_207.bin", 0

// SUBSCR_ITEM_HP_RESTORE_CNF
subscr_207:
    CallSubscript                       SUBSCR_ITEM_HP_RESTORE
    // "For {1}, the {0} was {2}!"
    Message                             594, TAG_ITEM_NICK_TASTE, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF | SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE
    SetVarFromVar                       OP_SET, VAR_EFFECT_TARGET, VAR_BATTLER_WORK
    SetVar                              OP_SET, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ITEM
    CallSubscript                       SUBSCR_APPLY_CONFUSION
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF | SERVER_STATUS_FLAG_NO_ATTACK_MESSAGE
    End                                 

.close