.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_113.s", 0

subscr_113:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 16384, 11
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             448, TAG_NUM, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2086985, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    End                                 
