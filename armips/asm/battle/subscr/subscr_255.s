.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_255.s", 0

subscr_255:
    WaitFrames                          15
    Random                              3, 0
    If                                  EQUAL, VAR_CALC_WORK, 1, 16
    If                                  EQUAL, VAR_CALC_WORK, 2, 17
    If                                  EQUAL, VAR_CALC_WORK, 3, 18
    Message                             828, TAG_NICK, BATTLER_ATTACKER
    Jump                                18
    Message                             829, TAG_NICK, BATTLER_ATTACKER
    Jump                                12
    Message                             830, TAG_NICK, BATTLER_ATTACKER
    Jump                                6
    Message                             831, TAG_NICK, BATTLER_ATTACKER
    Jump                                0
    Wait                                
    WaitFrames                          30
    End                                 
