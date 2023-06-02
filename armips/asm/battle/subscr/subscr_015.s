.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_15.s", 0

subscr_015:
    Message                             181, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    ClearContinuation                   BATTLER_ATTACKER
    CheckAbility                        MODE_NOT_HAVE, BATTLER_ATTACKER, ABILITY_STEADFAST, 14
    SetVar                              OP_SET, VAR_EFFECT_TYPE, 3
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 17
    SetVarFromVar                       OP_SET, VAR_EFFECTSRC, VAR_ATTACKER
    JumpToSubscript                     12
    End                                 
