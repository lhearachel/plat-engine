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


.create "build/battle/scr/subscr/sub_seq_215.bin", 0

// SUBSCR_ITEM_TAKE_DAMAGE
subscr_215:
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} is hurt by its {1}!"
    Message                             1132, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close