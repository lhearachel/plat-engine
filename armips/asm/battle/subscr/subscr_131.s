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


.create "build/battle/scr/subscr/sub_seq_131.bin", 0

// SUBSCR_CHARGE
subscr_131:
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, MOVE_EFFECT_FLAG_CHARGED
    // Set the counter to 2 (this turn and next turn)
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CHARGED_TURNS, 2
    // "{0} began charging power!"
    Message                             487, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Increase SpDefense by 1
    SetVarFromVar                       OP_SET, VAR_EFFECT_TARGET, VAR_ATTACKER
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_SPD_UP_1
    CallSubscript                       SUBSCR_BOOST_STATS
    End                                 

.close