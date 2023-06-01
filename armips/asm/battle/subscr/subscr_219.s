.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_219.s", 0

subscr_219:
    TryPluck                            22, 21
    Message                             1141, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    RemoveItem                          BATTLER_DEFENDER
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    If                                  EQUAL, VAR_TEMP_WORK, 0, 2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    End                                 
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER
    Wait                                
    WaitFrames                          30
    End                                 
