.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_081.bin", 0

subscr_081:
    If                                  EQUAL, VAR_CURRENT_MOVE, 364, 11
    CheckOneTurnFlag                    BATTLER_DEFENDER, OTF_PROTECTED, 0, 13
    Message                             1243, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              4
    Message                             1048, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetOneTurnFlag                      BATTLER_DEFENDER, 2, 0
    End                                 

.close