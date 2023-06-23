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


.create "build/battle/scr/effscr/be_seq_008.bin", 0

// Dream Eater
effscr_008:
    CheckSubstitute                     BATTLER_DEFENDER, effscr_009_Failure
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION, CONDITION_ASLEEP, effscr_009_Failure
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_DREAM_EATER
    CriticalCalc                        
    DamageCalc                          
    End                                 

// Failure due to Substitute, or due to the target not being asleep
effscr_009_Failure:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             60, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close