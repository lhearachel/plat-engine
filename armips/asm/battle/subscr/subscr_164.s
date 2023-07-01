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


.create "build/battle/scr/subscr/sub_seq_164.bin", 0

// SUBSCR_APPLY_LUCKY_CHANT
subscr_164:
    // 5 turns duration
    SetVar                              OP_SET, VAR_CALC_WORK, 0x5000
    SetVarFromVar                       OP_SET_FLAG, VAR_ATTACKER_SIDE_CONDITIONS, VAR_CALC_WORK
    // "The Lucky Chant shielded {your team/the foe} from critical hits!"
    Message                             1241, TAG_NONE_DIR, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close