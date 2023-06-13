.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_091.bin", 0

subscr_091:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65536, 70
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_DEFENDER, ABILITY_SUCTION_CUPS, 70
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_MOVE_EFFECTS, 1024, 71
    If                                  EQUAL, VAR_BATTLE_TYPE, 74, 54
    TryWhirlwind                        52
    JumpToSubscript                     76
    TryNaturalCure                      BATTLER_DEFENDER, 5
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_CONDITION, 0
    PokemonDelete                       BATTLER_DEFENDER
    Wait                                
    If                                  FLAG_NEQ, VAR_BATTLE_TYPE, 1, 27
    HPGaugeSlideOut                     BATTLER_DEFENDER
    Wait                                
    SwitchInAndUpdate                   BATTLER_FORCED_OUT
    Wait                                
    PokemonAppear                       BATTLER_DEFENDER
    WaitFrames                          72
    HPGaugeSlideIn                      BATTLER_DEFENDER
    Wait                                
    Message                             603, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVarFromVar                       OP_SET, VAR_SWITCHED_BATTLER, VAR_DEFENDER
    JumpToSubscript                     99
    End                                 
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 5
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
    PrepareMessage                      659, TAG_NICK_ABILITY, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Branch                              4
    PrepareMessage                      542, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    AttackMessage                       
    Wait                                
    WaitTime                            30
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close