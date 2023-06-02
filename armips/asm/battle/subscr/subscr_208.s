.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_208.s", 0

subscr_208:
    SetStatusEffect                     BATTLER_WORKING, 10
    Wait                                
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 14
    SetVarFromVar                       OP_ADD, VAR_EFFECT_PARAMS, VAR_PREPARED_MESSAGE
    SetVar                              OP_SET, VAR_EFFECT_TYPE, 5
    SetVarFromVar                       OP_SET, VAR_EFFECTSRC, VAR_BATTLER_WORK
    JumpToSubscript                     12
    JumpToSubscript                     290
    End                                 
