.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/battle_pokemon_params.s"
.include "armips/include/battle_subscr_def.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"
.include "armips/include/types.s"


.create "build/battle/scr/subscr/sub_seq_221.bin", 0

// SUBSCR_ABILITY_RECOVER_CND
subscr_221:
    // "{0} cured its {2} status with its {1}!"
    Message                             740, TAG_NICK_ABILITY_COND, BATTLER_WORKING, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN
    Wait                                
    SetStatusIcon                       BATTLER_WORKING, STATUS_NONE
    WaitTime                            30
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 0, subscr_221_RecoverSleep
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 5, subscr_221_RecoverConfusion
    If                                  EQUAL, VAR_PREPARED_MESSAGE, 6, subscr_221_RecoverInfatuation
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    Branch                              subscr_221_Exit

subscr_221_RecoverSleep:
    SetMonData                          OP_SET, BATTLER_WORKING, BATTLE_MON_CONDITION, 0
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_NIGHTMARES
    Branch                              subscr_221_Exit

subscr_221_RecoverConfusion:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_CONFUSED
    Branch                              subscr_221_Exit

subscr_221_RecoverInfatuation:
    SetMonData                          OP_CLEAR_FLAG, BATTLER_WORKING, BATTLE_MON_CONDITION_2, CONDITION_V_INFATUATED
subscr_221_Exit:
    End                                 

.close