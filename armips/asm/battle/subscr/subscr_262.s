.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_262.s", 0

subscr_262:
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 16777216, 11
    SetStatusEffect                     BATTLER_WORKING, 15
    Wait                                
    TransformBack                       BATTLER_WORKING
    Wait                                
    SetStatusEffect                     BATTLER_WORKING, 16
    Wait                                
    PlaySound                           BATTLER_WORKING, 1980
    Mosaic                              BATTLER_WORKING, 8, 1
    Wait                                
    ChangeForm                          BATTLER_WORKING
    PlaySound                           BATTLER_WORKING, 1984
    Mosaic                              BATTLER_WORKING, 0, 1
    Wait                                
    Message                             721, TAG_NICK, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    IfMonData                           FLAG_NEQ, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 16777216, 11
    SetStatusEffect                     BATTLER_WORKING, 15
    Wait                                
    SwapToSubstituteSprite              BATTLER_WORKING
    Wait                                
    SetStatusEffect                     BATTLER_WORKING, 16
    Wait                                
    End                                 
