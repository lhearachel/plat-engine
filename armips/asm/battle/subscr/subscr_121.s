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


.create "build/battle/scr/subscr/sub_seq_121.bin", 0

// SUBSCR_FUTURE_SIGHT_DAMAGE
subscr_121:
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    CheckHit                            BATTLER_ATTACKER_WORK, BATTLER_WORKING, BATTLER_WORKING, subscr_121_Failure
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    PlayAnimationAtoD                   BATTLER_WORKING, BATTLER_ATTACKER_WORK, BATTLER_WORKING
    Wait                                
    // Always play the animation
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    // Check if we are hitting Substitute
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED, subscr_121_Hit
    // Compare the damage to the Substitute's remaining HP
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    JumpIfMonData                       LESSER, BATTLER_WORKING, BATTLE_MON_SUBSTITUTE_HP, VAR_HP_TEMP, subscr_121_BreakSubstitute
subscr_121_HitSubstitute:
    SetMonDataFromVar                   OP_SUB, BATTLER_WORKING, BATTLE_MON_SUBSTITUTE_HP, VAR_HP_TEMP
    Branch                              subscr_121_SubstituteCleanup

subscr_121_BreakSubstitute:
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_SUBSTITUTE_HP, 0
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_SUBSTITUTED
subscr_121_SubstituteCleanup:
    CallSubscript                       SUBSCR_HIT_SUBSTITUTE
    Branch                              subscr_121_Cleanup

subscr_121_Hit:
    CheckLeaveWith1HP                   BATTLER_WORKING
    CallSubscript                       SUBSCR_HP_CHANGE
    // Check if Rage needs to be updated (if it's active, if the mon is alive, if its attack is maxed)
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_RAGING, subscr_121_Cleanup
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_HP, 0, subscr_121_Cleanup
    IfMonData                           EQUAL, BATTLER_WORKING, BATTLE_MON_ATK_STAGE, 12, subscr_121_Cleanup
    // Apply the boost to Rage
    SetMonData                          OP_ADD, BATTLER_WORKING, BATTLE_MON_ATK_STAGE, 1
    // "{0}'s rage is building!"
    Message                             363, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_121_Cleanup:
    // Check if the defender held on for whatever reason
    If                                  FLAG_NEQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_HELD_ON_WITH_ITEM, subscr_121_Exit
    SetStatusEffect                     BATTLER_WORKING, STATUS_HELD_ITEM
    Wait                                
    // "{0} hung on using its {1}!"
    Message                             912, TAG_NICK_ITEM, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // If the defender is holding a Focus Sash, remove it
    CheckItemEffect                     MODE_NOT_HAVE, BATTLER_WORKING, HOLD_EFFECT_FOCUS_SASH, subscr_121_Exit
    RemoveItem                          BATTLER_WORKING
subscr_121_Exit:
    End                                 

subscr_121_Failure:
    WaitTime                            30
    // "But it failed!"
    Message                             796, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close