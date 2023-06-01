.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_228.s", 0

subscr_228:
    MessageNoBattler                    854, TAG_TRNAME_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    Throw                               BATTLER_ME, THROW_SAFARI_ROCK
    Wait                                
    SetStatusEffect                     BATTLER_ENEMY, 29
    Wait                                
    If                                  EQUAL, VAR_TEMP_WORK, 0, 6
    MessageNoBattler                    855, TAG_NICK, BATTLER_DEFENDER
    Jump                                4
    MessageNoBattler                    856, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    End                                 
