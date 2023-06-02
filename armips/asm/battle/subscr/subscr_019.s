.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_19.s", 0

subscr_019:
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_SOUNDPROOF, 11
    If                                  FLAG_NEQ, VAR_FIELD_CONDITIONS, 3840, 6
    Message                             305, TAG_NICK, BATTLER_WORKING
    Jump                                4
    Message                             302, TAG_NICK, BATTLER_WORKING
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NORMAL
    WaitFrames                          30
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION, 7
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, 134217728
    End                                 
