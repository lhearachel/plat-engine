.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_45.bin", 0

effscr_045:
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_RECKLESS, 4
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 12
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 4096
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close