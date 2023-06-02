.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_145.s", 0

effscr_145:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, 4096, 25
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_SKIP_CHARGE_TURN, 13
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741836
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 1073741840
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 35
    End                                 
    JumpToSubscript                     292
    If                                  EQUAL, VAR_DEFENDER, 255, 2
    CriticalCalc                        
    DamageCalc                          
    JumpToSubscript                     259
    End                                 
