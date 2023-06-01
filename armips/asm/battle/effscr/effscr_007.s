.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_7.s", 0

effscr_007:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_ALL, ABILITY_DAMP, 34
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 4026531840, 26
    SetVar                              OP_SET, VAR_CALC_WORK, 268435456
    SetVarFromVar                       OP_LSH, VAR_CALC_WORK, VAR_ATTACKER
    SetVarFromVar                       OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, VAR_CALC_WORK
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_HP, 0
    SetVar                              OP_SET, VAR_HP_TEMP, 32767
    UpdateHPGauge                       BATTLER_ATTACKER
    Wait                                
    JumpToSubscript                     76
    CriticalCalc                        
    DamageCalc                          
    End                                 
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    Message                             628, TAG_NICK_ABILITY_NICK_MOVE, BATTLER_ABILITYSRC, BATTLER_ABILITYSRC, BATTLER_ATTACKER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 2
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 
