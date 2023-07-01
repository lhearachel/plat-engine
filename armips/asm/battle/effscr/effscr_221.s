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


.create "build/battle/scr/effscr/be_seq_221.bin", 0

// Brine; double power if the target is below half HP
effscr_221:
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_MAX_HP, VAR_CALC_WORK
    SetVar                              OP_DIV, VAR_CALC_WORK, 2
    JumpIfMonData                       GREATER, BATTLER_DEFENDER, BATTLE_MON_HP, VAR_CALC_WORK, effscr_221_BaseMultiplier
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 20
    Branch                              effscr_221_Damage
effscr_221_BaseMultiplier:
    SetVar                              OP_SET, VAR_DAMAGE_MULTI, 10
effscr_221_Damage:
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close