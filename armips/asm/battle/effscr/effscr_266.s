.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_266.s", 0

effscr_266:
    If                                  FLAG_EQ, VAR_DEFENDER_SIDE_CONDITIONS, 128, 13
    SetVar                              OP_SET_FLAG, VAR_DEFENDER_SIDE_CONDITIONS, 128
    PrepareMessage                      1077, TAG_NONE_DIR, BATTLER_ATTACKER_ENEMY
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
