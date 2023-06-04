.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_224.bin", 0

subscr_224:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_ITEM_HP_RESTORED, 0, 20
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_ITEM_HP_RESTORED, VAR_HP_TEMP
    SetMonData                          OP_SET, BATTLER_ATTACKER, BATTLE_MON_ITEM_HP_RESTORED, 0
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 64
    JumpToSubscript                     2
    End                                 

.close