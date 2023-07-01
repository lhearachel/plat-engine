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


.create "build/battle/scr/effscr/be_seq_122.bin", 0

// Present
effscr_122:
    // Try to execute a random Present effect:
    // - damage with 40 base power
    // - damage with 80 base power
    // - damage with 120 base power
    // - heal 1/4 of target's max HP
    TryPresent                          effscr_122_HealTarget
    CriticalCalc                        
    DamageCalc                          
    End                                 

effscr_122_HealTarget:
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_DEFENDER
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_HEAL_TARGET
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_IMMUNITIES
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    End                                 

.close