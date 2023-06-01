.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_184.s", 0

effscr_184:
    IfMonData                           NOT_EQUAL, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, 0, 17
    TryRecycle                          15
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_HELD_ITEM, VAR_ITEM_TEMP
    PrepareMessage                      589, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
