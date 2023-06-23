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


.create "build/battle/scr/subscr/sub_seq_019.bin", 0

// SUBSCR_WAKE_UP
subscr_019:
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_SOUNDPROOF, subscr_019_StandardMessage
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, FIELD_CONDITION_UPROAR, subscr_019_StandardMessage
    // "The uproar woke up {0}!"
    Message                             305, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_019_AfterMessage

subscr_019_StandardMessage:
    // "{0} woke up!"
    Message                             302, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
subscr_019_AfterMessage:
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NONE
    WaitTime                            30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION, CONDITION_ASLEEP
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_NIGHTMARES
    End                                 

.close