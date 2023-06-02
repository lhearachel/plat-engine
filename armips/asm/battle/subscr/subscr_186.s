.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_186.s", 0

subscr_186:
    WaitFrames                          15
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
    SetVarFromVar                       OP_SET, VAR_PUSH_CLIENT, VAR_ATTACKER
    SetVarFromVar                       OP_SET, VAR_ATTACKER, VAR_BATTLER_WORK
    GetBattlerBySpeedOrder              VAR_EFFECTSRC
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_EFFECTSRC, 19
    CheckSubstitute                     BATTLER_EFFECTSRC, 16
    IfMonData                           EQUAL, BATTLER_EFFECTSRC, BATTLE_MON_HP, 0, 10
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, 22
    SetVar                              OP_SET, VAR_EFFECT_TYPE, 3
    JumpToSubscript                     12
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, 4294967264
    SetVarFromVar                       OP_SET, VAR_ATTACKER, VAR_PUSH_CLIENT
    End                                 
