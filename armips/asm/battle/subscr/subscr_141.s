.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_141.bin", 0

subscr_141:
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_INSOMNIA, 62
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_VITAL_SPIRIT, 57
    CheckCloudNine                      10
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 48, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_LEAF_GUARD, 45
    AttackMessage                       
    Wait                                
    CheckSubstitute                     BATTLER_EFFECTSRC, 51
    CheckAbility                        MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SOUNDPROOF, 5
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 3840, 41
    IfMonData                           NOT_EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION, 0, 35
    If                                  FLAG_EQ, VAR_EFFECTSRC_SIDE_CONDITIONS, 8, 36
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 65537, 25
    TryYawn                             23
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    Message                             545, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             734, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN
    Branch                              12
    WaitTime                            30
    JumpToSubscript                     75
    Branch                              13
    WaitTime                            30
    Message                             200, TAG_NICK, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 2147483648
    End                                 

.close