.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_109.bin", 0

effscr_109:
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TYPE_1, 7, 11
    IfMonData                           EQUAL, BATTLER_ATTACKER, BATTLE_MON_TYPE_2, 7, 5
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 1073741912
    End                                 
    JumpIf                              NOT_EQUAL, VAR_ATTACKER, VAR_DEFENDER, 2
    GetRandomOpponent                   BATTLER_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_DIRECT, 536871001
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    End                                 

.close