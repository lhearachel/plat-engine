.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_275.s", 0

subscr_275:
    If                                  FLAG_EQ, VAR_BATTLE_TYPE, 512, 11
    Message                             857, TAG_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    Throw                               BATTLER_ME, THROW_SAFARI_BALL
    Jump                                8
    MessageNoBattler                    1225, TAG_NICK, BATTLER_ENEMY
    Wait                                
    Throw                               BATTLER_ME, THROW_PARK_BALL
    InitCapture                         CAPTURE_SAFARI
    Capture                             
    If                                  FLAG_EQ, VAR_BATTLE_RESULT, 4, 20
    If                                  NOT_EQUAL, VAR_SAFARI_BALL_COUNT, 0, 15
    PlaySound                           BATTLER_ATTACKER, 1521
    Message                             850, TAG_NONE
    Wait                                
    WaitFrames                          30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, 5
    End                                 
