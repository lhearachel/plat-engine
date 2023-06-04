.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_275.bin", 0

subscr_275:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 512, 11
    Message                             857, TAG_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    Throw                               BATTLER_ME, THROW_SAFARI_BALL
    Branch                              8
    MessageNoBattler                    1225, TAG_NICK, BATTLER_ENEMY, NaN, NaN, NaN, NaN, NaN
    Wait                                
    Throw                               BATTLER_ME, THROW_PARK_BALL
    InitCapture                         CAPTURE_SAFARI
    Capture                             
    If                                  FLAG_EQ, VAR_BATTLE_RESULT, 4, 20
    If                                  NOT_EQUAL, VAR_SAFARI_BALL_COUNT, 0, 15
    PlaySound                           BATTLER_ATTACKER, 1521
    Message                             850, TAG_NONE, NaN, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 5
    End                                 

.close