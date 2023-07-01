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


.create "build/battle/scr/subscr/sub_seq_112.bin", 0

// SUBSCR_PRESENT_HEAL
subscr_112:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_COMPOSITE_MISSED, subscr_112_Exit
    AttackMessage                       
    Wait                                
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HEAL_BLOCK_TURNS, 0, subscr_112_HealBlockActive
    CallSubscript                       SUBSCR_RECOVER_HP
subscr_112_Exit:
    End                                 

subscr_112_HealBlockActive:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_HEAL_BLOCK
    // "{0} was prevented from healing due to {1}!"
    Message                             1054, TAG_NICK_MOVE, BATTLER_DEFENDER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close