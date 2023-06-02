.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_8.s", 0

effscr_008:
    CheckSubstitute                     BATTLER_DEFENDER, 13
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, 7, 7
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870973
    CriticalCalc                        
    DamageCalc                          
    End                                 
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             60, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
