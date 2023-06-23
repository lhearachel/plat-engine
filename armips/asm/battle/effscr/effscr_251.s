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


.create "build/battle/scr/effscr/be_seq_251.bin", 0

// Aqua Ring
effscr_251:
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_AQUA_RING, effscr_251_AquaRingAlreadyActive
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_AQUA_RING
    PrepareMessage                      1027, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, ADDL_EFFECT_FLAG_UPDATE | ADDL_EFFECT_PREPARE_MESSAGE
    End

effscr_251_AquaRingAlreadyActive:                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close