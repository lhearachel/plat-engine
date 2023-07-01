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


.create "build/battle/scr/subscr/sub_seq_003.bin", 0

// SUBSCR_ESCAPE
subscr_003:
    // Leaving a battle triggers Natural Cure
    TryNaturalCure                      BATTLER_ME_SLOT_1, subscr_003_CheckSlot2
    SetMonData                          OP_SET, BATTLER_ME_SLOT_1, BATTLE_MON_CONDITION, 0
subscr_003_CheckSlot2:
    TryNaturalCure                      BATTLER_ME_SLOT_2, subscr_003_Start
    SetMonData                          OP_SET, BATTLER_ME_SLOT_2, BATTLE_MON_CONDITION, 0

subscr_003_Start:
    PlaySound                           BATTLER_ATTACKER, 1791
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_TOWER, subscr_003_ForfeitTowerBattle
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, BATTLE_TYPE_LINK, subscr_003_ForfeitLinkBattle
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_RUN_AWAY, subscr_003_RunAwayMessage
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_ESCAPE_ENCOUNTER, subscr_003_SmokeBallMessage
subscr_003_GenericEscapeMessage:
    Message                             781, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              subscr_003_Continue
subscr_003_RunAwayMessage:
    Message                             783, TAG_NICK_ABILITY, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Branch                              subscr_003_Continue
subscr_003_SmokeBallMessage:
    Message                             782, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
subscr_003_Continue:
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, BATTLE_RESULT_ESCAPE
    End                                 

subscr_003_ForfeitTowerBattle:
    GiveUpMessage                       
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_CLEAR_FLAG, VAR_BATTLE_RESULT, BATTLE_RESULT_SELECT_PAUSE
    End                                 

subscr_003_ForfeitLinkBattle:
    EscapeMessage                       
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_CLEAR_FLAG, VAR_BATTLE_RESULT, BATTLE_RESULT_SELECT_PAUSE
    End                                 

.close