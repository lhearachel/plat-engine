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


.create "build/battle/scr/subscr/sub_seq_122.bin", 0

// SUBSCR_TELEPORT
subscr_122:
    // Teleport fails in wild doubles with a partner
    If                                  EQUAL, VAR_BATTLE_TYPE, BATTLE_TYPE_AI | BATTLE_TYPE_2vs2 | BATTLE_TYPE_DOUBLES, subscr_122_Failure
    // This makes the check for a trainer battle
    // This needs to be modified to have a jump point param for a trainer battle to execute the pivot
    // functionality for gen-8 Teleport
    TryTeleport                         subscr_122_Failure
    CallSubscript                       SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
    // "{0} fled from battle!"
    Message                             469, TAG_NICK, BATTLER_ATTACKER, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    FadeOut                             
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_BATTLE_RESULT, BATTLE_RESULT_ESCAPE
    IncGameStat                         BATTLER_ATTACKER, 1, 99
    End                                 

subscr_122_Failure:
    SetVar                              OP_SET_FLAG, VAR_MOVE_STATUS_FLAG, MOVE_STATUS_FLAG_FAILED
    End                                 

.close