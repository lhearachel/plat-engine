.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_187.s", 0

subscr_187:
    WaitFrames                          15
    SetMonDataFromVar                   OP_GET, 15, BATTLE_MON_ABILITY, VAR_CALC_WORK
    SetMonDataFromVar                   OP_SET, 255, BATTLE_MON_ABILITY, VAR_CALC_WORK
    Message                             679, TAG_NICK_NICK_ABILITY, BATTLER_WORKING, BATTLER_DEFENDER_WORK, BATTLER_DEFENDER_WORK
    Wait                                
    WaitFrames                          30
    End                                 
