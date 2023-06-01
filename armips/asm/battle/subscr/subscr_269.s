.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_269.s", 0

subscr_269:
    WaitFrames                          15
    PlaySound                           BATTLER_ATTACKER, 1516
    Message                             858, TAG_TRTYPE_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    RecoverStatus                       BATTLER_ATTACKER
    Message                             756, TAG_NICK_ITEM_STAT, BATTLER_ATTACKER, BATTLER_WORKING, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    End                                 
