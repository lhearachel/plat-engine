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


.create "build/battle/scr/subscr/sub_seq_083.bin", 0

// SUBSCR_TRIGGER_ON_FAINTING
subscr_083:
    // Check if the fainting mon has Destiny Bond active
    IfMonData                           FLAG_NEQ, BATTLER_FAINTING, BATTLE_MON_CONDITION_2, CONDITION_V_DESTINY_BOUND, subscr_081_CheckGrudge
    // Don't faint an ally that killed us (e.g. via Earthquake spread damage)
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_FAINTING, subscr_081_CheckGrudge
    // If the attacker is already dead (e.g. via Explosion), do not execute the Destiny Bond routine
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_HP, 0, subscr_081_CheckGrudge
    // "{0} took {1} down with it!"
    Message                             391, TAG_NICK_NICK, BATTLER_FAINTING, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    // Reduce the attacker's HP
    SetVarFromVar                       OP_GET, VAR_FAINTED_BATTLER, VAR_PUSH_CLIENT
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_HP, VAR_HP_TEMP
    SetVar                              OP_MUL, VAR_HP_TEMP, -1
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    FaintAnimation                      
    Wait                                
    // Faint the calling Pokemon
    HPGaugeSlideOut                     BATTLER_FAINTING
    // "{0} fainted!"
    Message                             30, TAG_NICK, BATTLER_FAINTING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Increment some game records (don't touch these)
    IncGameStat                         BATTLER_FAINTING, 1, 41
    IncGameStat                         BATTLER_FAINTING, 0, 96
    SetVarFromVar                       OP_GET, VAR_PUSH_CLIENT, VAR_FAINTED_BATTLER
subscr_081_CheckGrudge:
    TryGrudge                           subscr_081_NoEffect
    // "{0}'s {1} lost all its PP due to the grudge!"
    Message                             568, TAG_NICK_MOVE, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
subscr_081_NoEffect:
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_NO_EXPERIENCE_GIVEN
    CallSubscript                       SUBSCR_FAINT
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG2, SERVER_STATUS_FLAG2_NO_EXPERIENCE_GIVEN
    End                                 

.close