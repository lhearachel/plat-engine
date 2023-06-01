.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_257.s", 0

subscr_257:
    WaitFrames                          15
    Message                             827, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetVarFromVar                       OP_SET, VAR_EFFECTSRC, VAR_ATTACKER
    SetVar                              OP_SET, VAR_EFFECT_TYPE, 7
    JumpToSubscript                     18
    End                                 
