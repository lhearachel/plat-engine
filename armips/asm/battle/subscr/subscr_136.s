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


.create "build/battle/scr/subscr/sub_seq_136.bin", 0

// SUBSCR_WISH_HEAL
subscr_136:
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    IfMonData                           NOT_EQUAL, BATTLER_WORKING, BATTLE_MON_HEAL_BLOCK_TURNS, 0, subscr_136_HealBlockActive
    SetMonDataFromVar                   OP_GET, BATTLER_WORKING, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_WORKING, BATTLE_MON_HP, VAR_CALC_WORK, subscr_136_FullHP
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetStatusEffect                     BATTLER_WORKING, STATUS_RESTORE_HP
    Wait                                
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} regained health!"
    Message                             184, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_136_FullHP:
    WaitTime                            30
    // "{0}'s HP is full!"
    Message                             187, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_136_HealBlockActive:
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_HEAL_BLOCK
    // "{0} was prevented from healing due to {1}!"
    Message                             1054, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close