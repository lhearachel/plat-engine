.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_176.bin", 0

effscr_176:
    TryHelpingHand                      14
    PrepareMessage                      503, TAG_NICK_NICK, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    SetVar                              OP_SET, VAR_ADD_STATUS_INDIRECT, 536871002
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, 524316
    End                                 
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, 64
    End                                 

.close