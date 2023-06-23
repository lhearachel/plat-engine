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


.create "build/battle/scr/effscr/be_seq_148.bin", 0

// Future Sight effect
effscr_148:
    TryFutureSight                      effscr_148_FutureSightAlreadySet
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    // TODO: Need to remove the typeless check here and figure out how to otherwise set the type for later
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_HIT_THROUGH_VANISH | SERVER_STATUS_FLAG_IGNORE_IMMUNITIES | SERVER_STATUS_FLAG_FLAT_HIT_RATE
    End                                 

effscr_148_FutureSightAlreadySet:
    AttackMessage                       
    Wait                                
    WaitTime                            30
    CallSubscript                       SUBSCR_BUT_IT_FAILED
    End                                 

.close