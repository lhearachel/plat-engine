.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_113.bin", 0

subscr_113:
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, 16384, 11
    AttackMessage                       
    Wait                                
    WaitTime                            30
    Message                             448, TAG_NUM, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, 2086985, 3
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    End                                 

.close