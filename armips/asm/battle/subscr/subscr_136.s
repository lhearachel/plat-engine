.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_136.s", 0

subscr_136:
    MessagePrepared                     
    Wait                                
    WaitFrames                          30
    IfMonData                           NOT_EQUAL, BATTLER_WORKING, BATTLE_MON_HEAL_BLOCK_TURNS, 0, 39
    SetMonDataFromVar                   OP_GET, 255, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_WORKING, BATTLE_MON_HP, VAR_CALC_WORK, 18
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    SetStatusEffect                     BATTLER_WORKING, 14
    Wait                                
    JumpToSubscript                     2
    Message                             184, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
    WaitFrames                          30
    Message                             187, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
    SetVar                              OP_SET, VAR_MOVE_TEMP, 377
    Message                             1054, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
