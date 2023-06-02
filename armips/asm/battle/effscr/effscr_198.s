.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_198.s", 0

effscr_198:
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_RECKLESS, 4
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 12
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536870950
    CriticalCalc                        
    DamageCalc                          
    End                                 
