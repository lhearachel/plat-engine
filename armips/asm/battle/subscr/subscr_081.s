.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_81.s", 0

subscr_081:
    If                                  EQUAL, VAR_CURRENT_MOVE, 364, 11
    CheckOneTurnFlag                    BATTLER_DEFENDER, OTF_PROTECTED, 0, 13
    Message                             1243, TAG_NICK, BATTLER_DEFENDER
    Jump                                4
    Message                             1048, TAG_NICK, BATTLER_DEFENDER
    Wait                                
    WaitFrames                          30
    SetOneTurnFlag                      BATTLER_DEFENDER, 2, 0
    End                                 
