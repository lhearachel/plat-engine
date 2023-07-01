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


.create "build/battle/scr/subscr/sub_seq_160.bin", 0

// SUBSCR_APPLY_TAILWIND
subscr_160:
    If                                  FLAG_EQ, VAR_ATTACKER_SIDE_CONDITIONS, SIDE_CONDITION_TAILWIND, subscr_160_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // "The tailwind blew from behind {your team/the foe}!"
    Message                             1230, TAG_NONE_DIR, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_ATTACKER_SIDE_CONDITIONS, SIDE_CONDITION_TAILWIND
    End                                 

subscr_160_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close