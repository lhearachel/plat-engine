.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/effscr/be_seq_121.bin", 0

// Return (damage increases with increased Friendship)
effscr_121:
    // Formula is friendship * (10 / 25)
    // simplified: friendship / 2.5
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_FRIENDSHIP, VAR_DAMAGE_POWER
    SetVar                              OP_MUL, VAR_DAMAGE_POWER, 10
    SetVar                              OP_DIV, VAR_DAMAGE_POWER, 25
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close