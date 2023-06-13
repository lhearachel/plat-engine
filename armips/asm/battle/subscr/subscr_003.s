.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_003.bin", 0

subscr_003:
    TryNaturalCure                      BATTLER_ME_SLOT_1, 5
    SetMonData                          OP_SET, BATTLER_ME_SLOT_1, BATTLE_MON_CONDITION, 0
    TryNaturalCure                      BATTLER_ME_SLOT_2, 5
    SetMonData                          OP_SET, BATTLER_ME_SLOT_2, BATTLE_MON_CONDITION, 0
    PlaySound                           BATTLER_ATTACKER, 1791
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 128, 42
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 4, 48
    CheckAbility                        MODE_HAVE, BATTLER_ATTACKER, ABILITY_RUN_AWAY, 10
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_ESCAPE_ENCOUNTER, 12
    Message                             781, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Branch                              12
    Message                             783, TAG_NICK_ABILITY, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Branch                              5
    Message                             782, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 5
    End                                 
    GiveUpMessage                       
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_CLEAR_FLAG, VAR_BATTLE_RESULT, 64
    End                                 
    EscapeMessage                       
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_CLEAR_FLAG, VAR_BATTLE_RESULT, 64
    End                                 

.close