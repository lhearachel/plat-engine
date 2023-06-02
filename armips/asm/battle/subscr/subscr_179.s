.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_179.s", 0

subscr_179:
    AttackMessage                       
    Wait                                
    WaitFrames                          15
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_FLASH_FIRE_ACTIVE, 0, 14
    Message                             656, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    SetMonData                          OP_SET_FLAG, BATTLER_DEFENDER, BATTLE_MON_FLASH_FIRE_ACTIVE, 1
    End                                 
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
