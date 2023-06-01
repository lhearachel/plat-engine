.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_85.s", 0

subscr_085:
    TryThief                            46, 37
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, 16384
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    Message                             401, TAG_NICK_NICK_ITEM, BATTLER_ATTACKER, BATTLER_DEFENDER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 0
    Jump                                9
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
