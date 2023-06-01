.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_11.s", 0

subscr_011:
    Message                             857, TAG_TRNAME_ITEM, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    InitCapture                         CAPTURE_NORMAL
    Capture                             
    SetVarFromVar                       OP_GET, VAR_BATTLE_RESULT, VAR_TEMP_WORK
    SetVar                              OP_AND, VAR_TEMP_WORK, 255
    If                                  NOT_EQUAL, VAR_TEMP_WORK, 4, 8
    TryNaturalCure                      BATTLER_ME, 5
    SetMonData                          OP_SET, BATTLER_ME, BATTLE_MON_CONDITION, 0
    End                                 
