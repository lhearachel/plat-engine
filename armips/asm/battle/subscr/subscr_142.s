.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_142.s", 0

subscr_142:
    CheckSubstitute                     BATTLER_DEFENDER, 30
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_ABILITY, 121, 24
    IfMonData                           EQUAL, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 112, 18
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_QUICK_CLAW_ACTIVE, 0, 12
    IfMonData                           NOT_EQUAL, BATTLER_DEFENDER, BATTLE_MON_TEMP_SPE_MAX, 0, 6
    TryKnockOff                         4
    MessagePrepared                     
    Wait                                
    WaitFrames                          30
    End                                 
