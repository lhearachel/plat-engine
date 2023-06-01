.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_182.s", 0

subscr_182:
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_SPE_STAGE, 12, 23
    SetStatusEffect                     BATTLER_DEFENDER, 12
    Wait                                
    SetMonData                          OP_ADD, BATTLER_DEFENDER, BATTLE_MON_SPE_STAGE, 1
    SetVar                              OP_SET, VAR_PREPARED_MESSAGE, 3
    Message                             622, TAG_NICK_ABILITY_STAT, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
    Message                             638, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
