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


.create "build/battle/scr/subscr/sub_seq_021.bin", 0

// SUBSCR_MOVE_SUCCESS_MESSAGE
subscr_021:
    WaitTime                            15
    // Check for Splash
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_NOTHING_HAPPENED, subscr_021_CheckFocusSash
    // "But nothing happened!"
    Message                             795, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_021_Cleanup

subscr_021_CheckFocusSash:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_HELD_ON_WITH_ITEM, subscr_021_CheckEndure
    SetStatusEffect                     BATTLER_DEFENDER, STATUS_HELD_ITEM
    Wait                                
    // "{0} hung on using its {1}!"
    Message                             912, TAG_NICK_ITEM, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_DEFENDER, HOLD_EFFECT_FOCUS_SASH, subscr_021_SkipItemRemoval
    RemoveItem                          BATTLER_DEFENDER
subscr_021_SkipItemRemoval:
    Wait                                
    WaitTime                            30
    Branch                              subscr_021_CheckEffectiveness

subscr_021_CheckEndure:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ENDURED, subscr_021_CheckOHKO
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 1, subscr_021_CheckOHKO
    // "{0} endured the hit!"
    Message                             445, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Branch                              subscr_021_CheckEffectiveness

subscr_021_CheckOHKO:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_ONE_HIT_KO, subscr_021_CheckEffectiveness
    // "It's a one-hit KO!"
    Message                             775, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_021_Cleanup

subscr_021_CheckEffectiveness:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_IGNORE_EFFECTIVENESS, subscr_021_End
    If                                  FLAG_AND, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_NOT_VERY_EFFECTIVE | MOVE_STATUS_FLAG_SUPER_EFFECTIVE, subscr_021_End
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_SUPER_EFFECTIVE, subscr_021_CheckNotVeryEffective
    // "It's super effective!"
    Message                             780, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_021_Cleanup

subscr_021_CheckNotVeryEffective:
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_NOT_VERY_EFFECTIVE, subscr_021_End
    // "It's not very effective..."
    Message                             779, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
subscr_021_Cleanup:
    Wait                                
    WaitTime                            30
subscr_021_End:
    End                                 

.close