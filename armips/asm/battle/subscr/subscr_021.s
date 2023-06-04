.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_21.bin", 0

subscr_021:
    WaitTime                            15
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 8192, 5
    Message                             795, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              84
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 256, 21
    SetStatusEffect                     BATTLER_DEFENDER, 10
    Wait                                
    Message                             912, TAG_NICK_ITEM, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_DEFENDER, HOLD_EFFECT_FOCUS_SASH, 2
    RemoveItem                          BATTLER_DEFENDER
    Wait                                
    WaitTime                            30
    Branch                              30
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 128, 15
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 1, 9
    Message                             445, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              10
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 32, 5
    Message                             775, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              28
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 2048, 26
    If                                  FLAG_AND, VAR_MOVE_STATUS_FLAG, 6, 21
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 2, 5
    Message                             780, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              8
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, 4, 6
    Message                             779, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close