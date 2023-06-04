.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_228.bin", 0

subscr_228:
    MessageNoBattler                    854, TAG_TRNAME_NICK, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    Throw                               BATTLER_ME, THROW_SAFARI_ROCK
    Wait                                
    SetStatusEffect                     BATTLER_ENEMY, 29
    Wait                                
    If                                  EQUAL, VAR_TEMP_WORK, 0, 6
    MessageNoBattler                    855, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Branch                              4
    MessageNoBattler                    856, TAG_NICK, BATTLER_DEFENDER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close