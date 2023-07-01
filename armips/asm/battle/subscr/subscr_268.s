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


.create "build/battle/scr/subscr/sub_seq_268.bin", 0

// SUBSCR_BAG_STATUS_HEAL
subscr_268:
    WaitTime                            15
    PlaySound                           BATTLER_ATTACKER, 1516
    // "{0} {1} used one {2}!"
    Message                             858, TAG_TRTYPE_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RecoverStatus                       BATTLER_ATTACKER
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, subscr_268_Confusion
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 1, subscr_268_Paralysis
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 2, subscr_268_Freeze
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 3, subscr_268_Burn
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 4, subscr_268_Poison
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 5, subscr_268_Sleep
    // "{0} normalized its status using {1}!"
    Message                             896, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_268_SetCondition

subscr_268_Confusion:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_ATTACKER, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED
    // "{0}'s {1} snapped it out of confusion!"
    Message                             890, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_268_Cleanup

subscr_268_Paralysis:
    // "{0}'s {1} cured its paralysis!"
    Message                             875, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_268_SetCondition

subscr_268_Freeze:
    // "{0}'s {1} defrosted it!"
    Message                             884, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_268_SetCondition

subscr_268_Burn:
    // "{0}'s {1} healed its burn!"
    Message                             881, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_268_SetCondition

subscr_268_Poison:
    // "{0}'s {1} cured its poison!"
    Message                             878, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_268_SetCondition

subscr_268_Sleep:
    // "{0}'s {1} woke it up!"
    Message                             887, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Branch                              subscr_268_SetCondition

subscr_268_SetCondition:
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
subscr_268_Cleanup:
    Wait                                
    SetStatusIcon                       BATTLER_ATTACKER, STATUS_NONE
    WaitTime                            30
    End                                 

.close