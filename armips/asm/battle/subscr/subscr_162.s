.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_162.bin", 0

subscr_162:
    SetMonData                          OP_XOR, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 8388608
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ATTACK, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_DEFENSE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ATTACK, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_DEFENSE, VAR_CALC_WORK
    Message                             1009, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close