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


.create "build/battle/scr/subscr/sub_seq_175.bin", 0

// SUBSCR_PIVOT_ATTACK
subscr_175:
    // Check if the battle is over
    CheckWhiteOut                       BATTLER_DEFENDER, subscr_175_Exit
    TrySwitchInMon                      BATTLER_ATTACKER, 1, subscr_175_Exit
    CheckAbilityEffectOnHit             subscr_175_CheckItemEffects
    CallSubscriptFromVar                VAR_TEMP_WORK
subscr_175_CheckItemEffects:
    CheckUturnItemEffect                subscr_175_CheckDestinyBond
    CallSubscriptFromVar                VAR_TEMP_WORK
subscr_175_CheckDestinyBond:
    // Check if the target fainted
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, subscr_175_CheckGrudge
    // Check for Destiny Bond
    IfMonData                           FLAG_NEQ, BATTLER_DEFENDER, BATTLE_MON_CONDITION_2, CONDITION_V_DESTINY_BOUND, subscr_175_CheckGrudge
    // Check if we attacked an ally (do not trigger)
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_DEFENDER, subscr_175_CheckGrudge
    // Check if the attacker has fainted due to an ability/item effect
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, subscr_175_CheckGrudge
    // "{0} took {1} down with it!"
    Message                             391, TAG_NICK_NICK, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_HP_TEMP
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    FaintAnimation                      
    Wait                                
    HPGaugeSlideOut                     BATTLER_FAINTING
    // "{0} fainted!"
    Message                             30, TAG_NICK, BATTLER_FAINTING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    IncGameStat                         BATTLER_FAINTING, 1, 41
    IncGameStat                         BATTLER_FAINTING, 0, 96
subscr_175_CheckGrudge:
    SetVarFromVar                       OP_GET, VAR_FAINTED_BATTLER, VAR_PUSH_CLIENT
    SetVarFromVar                       OP_SET, VAR_FAINTED_BATTLER, VAR_DEFENDER
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_HP, 0, subscr_175_Resume
    TryGrudge                           subscr_175_Resume
    // "{0}'s {1} lost all its PP due to the grudge!"
    Message                             568, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_175_Resume:
    SetVarFromVar                       OP_SET, VAR_FAINTED_BATTLER, VAR_PUSH_CLIENT
    // If the attacker is dead, bail out
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, subscr_175_Exit
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER, VAR_ATTACKER
    // "{0} went back to {1}!"
    Message                             1067, TAG_NICK_TRNAME, BATTLER_SWITCHING, BATTLER_SWITCHING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Check for Pursuit interruption
    CallSubscript                       SUBSCR_PURSUIT
    // If the attacker is dead after Pursuit, bail out
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, subscr_175_Exit
    TryNaturalCure                      BATTLER_ATTACKER, subscr_175_AfterNaturalCure
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CONDITION, 0
subscr_175_AfterNaturalCure:
    // Show the recall animation
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    PokemonDelete                       BATTLER_ATTACKER
    Wait                                
    HPGaugeSlideOut                     BATTLER_ATTACKER
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_PIVOT_MOVE
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_SYNCHRONIZE
    SetVar                              OP_SET, VAR_ATTACKER_ONE_TURN_STATUS_FLAGS, 0
    JumpTo                              SUBSCR_PARTY_LIST

subscr_175_Exit:
    End                                 

.close