.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_131.s", 0

subscr_131:
    SetMonData                          OP_SET_FLAG, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 512
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_CHARGED_TURNS, 2
    Message                             487, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    SetVarFromVar                       OP_SET, VAR_EFFECTSRC, VAR_ATTACKER
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 19
    JumpToSubscript                     12
    End                                 
