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


.create "build/battle/scr/subscr/sub_seq_166.bin", 0

// SUBSCR_GUARD_SWAP
subscr_166:
    // Swap Defense stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_DEF_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_DEF_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_DEF_STAGE, VAR_CALC_WORK
    // Swap SpDefense stages
    SetMonDataFromVar                   OP_GET, BATTLER_ATTACKER, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_SPD_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_SPD_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_DEFENDER, BATTLE_MON_SPD_STAGE, VAR_CALC_WORK
    // "{0} switched all changes to its Defense and Sp. Defense with the target!"
    Message                             1018, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close