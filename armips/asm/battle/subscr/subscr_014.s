.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_14.bin", 0

subscr_014:
    CheckMoveFinished                   BATTLER_EFFECTSRC, 23
    CheckSubstitute                     BATTLER_EFFECTSRC, 40
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_INNER_FOCUS, 16
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 2, 5
    MoldBreakerAbilityCheck             MODE_HAVE, BATTLER_EFFECTSRC, ABILITY_SHIELD_DUST, 5
    SetMonData                          OP_SET_FLAG, BATTLER_EFFECTSRC, BATTLE_MON_CONDITION_2, 8
    End                                 
    If                                  EQUAL, VAR_CURRENT_MOVE, 252, 5
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 8
    Message                             737, TAG_NICK_ABILITY, BATTLER_EFFECTSRC, BATTLER_EFFECTSRC, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, 1, 4
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close