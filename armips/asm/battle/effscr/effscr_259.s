.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_259.bin", 0

effscr_259:
    If                                  FLAG_EQ, VAR_FIELD_CONDITIONS, 458752, 10
    SetVar                              OP_SET_FLAG, VAR_FIELD_CONDITIONS, 327680
    PrepareMessage                      1070, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Branch                              8
    SetVar                              OP_CLEAR_FLAG, VAR_FIELD_CONDITIONS, 458752
    PrepareMessage                      1073, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    TrickRoom                           
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close