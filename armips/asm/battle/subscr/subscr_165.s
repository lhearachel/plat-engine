.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_165.bin", 0

subscr_165:
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    Message                             1015, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close