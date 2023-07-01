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


.create "build/battle/scr/effscr/be_seq_184.bin", 0

// Recycle
effscr_184:
    // Check that the user is not holding an item
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 0, effscr_184_Failure
    TryRecycle                          effscr_184_Failure
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_HELD_ITEM, VAR_ITEM_TEMP
    PrepareMessage                      589, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    End

effscr_184_Failure:                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close