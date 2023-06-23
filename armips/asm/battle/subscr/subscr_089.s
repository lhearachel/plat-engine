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


.create "build/battle/scr/subscr/sub_seq_089.bin", 0

// SUBSCR_TRY_SUBSTITUTE
subscr_089:
    AttackMessage                       
    Wait                                
    IfMonData                           FLAG_EQ, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED, subscr_089_AlreadySubstituted
    TrySubstitute                       subscr_089_CannotSubstitute
    // Play the animation for replacing the attacker with Substitute
    SetStatusEffect                     BATTLER_ATTACKER, STATUS_SUBSTITUTE_IN
    Wait                                
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} made a substitute!"
    Message                             348, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

subscr_089_CannotSubstitute:
    WaitTime                            30
    // "It was too weak to make a substitute!"
    Message                             819, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_089_Cleanup
subscr_089_AlreadySubstituted:
    WaitTime                            30
    // "{0} already has a substitute!"
    Message                             351, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
subscr_089_Cleanup:
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_GENERAL_FAILURE
    End                                 

.close