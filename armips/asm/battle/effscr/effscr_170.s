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


.create "build/battle/scr/effscr/be_seq_170.bin", 0

// Focus Punch
effscr_170:
    If                                  NOT_EQUAL, VAR_PHYSICAL_DAMAGE, 0, effscr_170_LostFocus
    If                                  NOT_EQUAL, VAR_SPECIAL_DAMAGE, 0, effscr_170_LostFocus
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    CriticalCalc                        
    DamageCalc                          
    End                                 

effscr_170_LostFocus:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_LOST_FOCUS
    PrepareMessage                      600, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    End                                 

.close