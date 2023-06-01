.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_165.s", 0

subscr_165:
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_ATK_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_ATK_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_SPA_STAGE, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_SPA_STAGE, VAR_CALC_WORK
    Message                             1015, TAG_NICK, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
