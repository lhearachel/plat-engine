.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_162.s", 0

subscr_162:
    SetMonData                          OP_XOR, BATTLER_ATTACKER, BATTLE_MON_MOVE_EFFECTS, 8388608
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ATTACK, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_DEFENSE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ATTACK, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_DEFENSE, VAR_CALC_WORK
    Message                             1009, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
