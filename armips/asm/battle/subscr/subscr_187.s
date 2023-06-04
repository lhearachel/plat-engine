.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_187.bin", 0

subscr_187:
    WaitTime                            15
    SetMonDataFromVar                   OP_GET, 15, BATTLE_MON_ABILITY, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 255, BATTLE_MON_ABILITY, VAR_CALC_WORK
    Message                             679, TAG_NICK_NICK_ABILITY, BATTLER_WORKING, BATTLER_DEFENDER_WORK, BATTLER_DEFENDER_WORK, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close