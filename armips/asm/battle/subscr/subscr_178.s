.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_178.s", 0

subscr_178:
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    JumpIfMonData                       EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_CALC_WORK, 19
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    Message                             635, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
    Message                             638, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
