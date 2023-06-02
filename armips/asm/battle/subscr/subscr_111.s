.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_111.s", 0

subscr_111:
    SetMonDataFromVar                   OP_GET, 255, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_WORKING, BATTLE_MON_HP, VAR_CALC_WORK, 26
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    If                                  FLAG_NEQ, VAR_SERVER_STATUS_FLAG2, 256, 4
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
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
