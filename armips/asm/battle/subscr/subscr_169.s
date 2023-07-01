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


.create "build/battle/scr/subscr/sub_seq_169.bin", 0

// SUBSCR_AQUA_RING_HEAL
subscr_169:
    // "{1} restored {0}'s HP!"
    Message                             1030, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    // Check for Big Root
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_WORKING, HOLD_EFFECT_BOOST_LEECHING, subscr_169_ApplyHeal
    GetItemPower                        BATTLER_WORKING, VAR_CALC_WORK
    SetVar                              OP_ADD, VAR_CALC_WORK, 100
    SetVarFromVar                       OP_MUL, VAR_HP_TEMP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_HP_TEMP, 100
subscr_169_ApplyHeal:
    SetStatusEffect                     BATTLER_WORKING, STATUS_RESTORE_HP
    Wait                                
    CallSubscript                       SUBSCR_HP_CHANGE
    End                                 

.close