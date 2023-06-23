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


.create "build/battle/scr/effscr/be_seq_233.bin", 0

// Fling
effscr_233:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ABILITY, ABILITY_MULTITYPE, effscr_233_CannotFling
    // Griseous Orb check
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 112, effscr_233_CannotFling
    TryFling                            effscr_233_CannotFling
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_FLING
    CriticalCalc                        
    DamageCalc                          
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             1144, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RemoveItem                          BATTLER_ATTACKER
    End                                 

effscr_233_CannotFling:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close