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


.create "build/battle/scr/subscr/sub_seq_145.bin", 0

// SUBSCR_REFRESH
subscr_145:
    // Same condition checks as Facade
    IfMonData                           FLAG_NEQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION, CONDITION_BOOST_FACADE, subscr_145_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
    // "{0}'s status returned to normal!"
    Message                             491, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    WaitTime                            30
    End                                 

subscr_145_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close