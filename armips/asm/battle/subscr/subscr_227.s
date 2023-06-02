.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_227.s", 0

subscr_227:
    MessageNoBattler                    851, TAG_TRNAME_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    Throw                               BATTLER_ME, THROW_SAFARI_BAIT
    Wait                                
    SetStatusEffect                     BATTLER_ENEMY, 27
    Wait                                
    SetStatusEffect                     BATTLER_ENEMY, 28
    Wait                                
    If                                  EQUAL, VAR_TEMP_WORK, 0, 6
    MessageNoBattler                    852, TAG_NICK, BATTLER_DEFENDER
    Jump                                4
    MessageNoBattler                    853, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
