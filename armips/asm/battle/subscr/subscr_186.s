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


.create "build/battle/scr/subscr/sub_seq_186.bin", 0

// SUBSCR_INTIMIDATE
// TODO: add ability blockers
subscr_186:
    WaitTime                            15
    SetVar                              OP_SET, VAR_NTH_BATTLER_BY_SPEED, 0
    SetVarFromVar                       OP_SET, VAR_PUSH_CLIENT, VAR_ATTACKER
    SetVarFromVar                       OP_SET, VAR_ATTACKER, VAR_BATTLER_WORK
subscr_186_Loop:
    GetBattlerBySpeedOrder              VAR_EFFECT_TARGET
    CheckSameSide                       BATTLER_ATTACKER, BATTLER_EFFECT_TARGET, subscr_186_NextBattler
    CheckSubstitute                     BATTLER_EFFECT_TARGET, subscr_186_NextBattler
    IfMonData                           EQUAL, BATTLER_EFFECT_TARGET, BATTLE_MON_HP, 0, subscr_186_NextBattler
    SetVar                              OP_SET, VAR_EFFECT_PARAMS, ADDL_EFFECT_ATK_DOWN_1
    SetVar                              OP_SET, VAR_EFFECT_TYPE, ADDL_EFFECT_FROM_ABILITY
    CallSubscript                       SUBSCR_BOOST_STATS
subscr_186_NextBattler:
    SetVar                              OP_ADD, VAR_NTH_BATTLER_BY_SPEED, 1
    JumpIfValidBattler                  VAR_NTH_BATTLER_BY_SPEED, subscr_186_Loop
    SetVarFromVar                       OP_SET, VAR_ATTACKER, VAR_PUSH_CLIENT
    End                                 

.close