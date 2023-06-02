.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_88.s", 0

subscr_088:
    HealBell                            
    If                                  EQUAL, VAR_CURRENT_MOVE, 312, 5
    Message                             821, TAG_NONE
    Jump                                3
    Message                             592, TAG_NONE
    Wait                                
    WaitFrames                          30
    If                                  EQUAL, VAR_CURRENT_MOVE, 312, 28
    If                                  FLAG_NEQ, VAR_CALC_WORK, 1, 9
    Message                             689, TAG_NICK_ABILITY_MOVE, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    If                                  FLAG_NEQ, VAR_CALC_WORK, 2, 9
    Message                             689, TAG_NICK_ABILITY_MOVE, BATTLER_ATTACKER_PARTNER, BATTLER_ATTACKER_PARTNER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    If                                  FLAG_EQ, VAR_CALC_WORK, 4, 3
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NORMAL
    If                                  FLAG_EQ, VAR_CALC_WORK, 8, 3
    SetStatusIcon                       BATTLER_ATTACKER_PARTNER, STATUS_NORMAL
    End                                 
