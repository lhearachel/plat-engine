.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_146.s", 0

subscr_146:
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    SetVarFromVar                       OP_SET, VAR_ATTACKER_WORK, VAR_ATTACKER
    SetVarFromVar                       OP_SET, VAR_DEFENDER, VAR_ATTACKER
    SetVarFromVar                       OP_SET, VAR_ATTACKER, VAR_BATTLER_WORK
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    SetVar                              OP_SET, VAR_MOVE_TEMP, 289
    PlayAnimation                       BATTLER_WORKING
    Wait                                
    Message                             580, TAG_NICK_NICK, BATTLER_WORKING, BATTLER_ATTACKER_WORK
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 0
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    If                                  EQUAL, VAR_CURRENT_MOVE, 367, 5
    SetVarFromVar                       OP_SET, VAR_DEFENDER, VAR_ATTACKER_WORK
    End                                 
    SetVarFromVar                       OP_SET, VAR_DEFENDER, VAR_ATTACKER
    End                                 
