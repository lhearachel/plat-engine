.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_259.s", 0

effscr_259:
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 458752, 10
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 327680
    PrepareMessage                      1070, TAG_NICK, BATTLER_ATTACKER
    Jump                                8
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 458752
    PrepareMessage                      1073, TAG_NICK, BATTLER_ATTACKER
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    TrickRoom                           
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 
