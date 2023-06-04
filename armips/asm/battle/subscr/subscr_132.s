.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_132.bin", 0

subscr_132:
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TAUNTED_TURNS, 0, 23
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 18
    JumpToSubscript                     76
    Random                              2, 3
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_TAUNTED_TURNS, VAR_CALC_WORK
    Message                             500, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close