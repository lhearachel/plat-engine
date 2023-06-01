.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_253.s", 0

effscr_253:
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_RECKLESS, 4
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 12
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 2214592642
    CriticalCalc                        
    DamageCalc                          
    End                                 
