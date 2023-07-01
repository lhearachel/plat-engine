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


.create "build/battle/scr/effscr/be_seq_158.bin", 0

// Fake Out; always flinches, only usable on turn 1
effscr_158:
    JumpIfMonData                       NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_FAKE_OUT_TURNS, VAR_TURNS, effscr_158_NotFirstTurnOnField
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_DEFENDER | ADDL_EFFECT_FLINCH
    CriticalCalc                        
    DamageCalc                          
    End

effscr_158_NotFirstTurnOnField:                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close