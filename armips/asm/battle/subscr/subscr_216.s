.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_216.s", 0

subscr_216:
    SetMonDataFromVar                   OP_GET, 2, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, 1, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 0
    End                                 
