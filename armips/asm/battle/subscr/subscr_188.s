.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_188.s", 0

subscr_188:
    Message                             641, TAG_NICK_ABILITY_TYPE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_TYPE_1, VAR_PREPARED_MESSAGE
    SetMonDataFromVar                   OP_SET, 2, BATTLE_MON_TYPE_2, VAR_PREPARED_MESSAGE
    End                                 
