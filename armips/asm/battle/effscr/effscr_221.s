.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_221.s", 0

effscr_221:
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_CALC_WORK, 2
    JumpIfMonData                       GREATER, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_CALC_WORK, 6
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
    Jump                                4
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 10
    CriticalCalc                        
    DamageCalc                          
    End                                 
