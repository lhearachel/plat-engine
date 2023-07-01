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


.create "build/battle/scr/subscr/sub_seq_113.bin", 0

// SUBSCR_MAGNITUDE
subscr_113:
    // ???
    If                                  FLAG_EQ, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF, subscr_113_AfterMessage
    AttackMessage                       
    Wait                                
    WaitTime                            30
    // "Magnitude {0}!"
    Message                             448, TAG_NUM, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30

subscr_113_AfterMessage:
    If                                  FLAG_EQ, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_COMPOSITE_MISSED, subscr_113_Exit
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_113_Exit:
    End                                 

.close