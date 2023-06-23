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


.create "build/battle/scr/subscr/sub_seq_146.bin", 0

// SUBSCR_SNATCH
subscr_146:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    SetVarFromVar                       OP_SET, VAR_ATTACKER_WORK, VAR_ATTACKER
    SetVarFromVar                       OP_SET, VAR_DEFENDER, VAR_ATTACKER
    SetVarFromVar                       OP_SET, VAR_ATTACKER, VAR_BATTLER_WORK
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    SetVar                              OP_SET, VAR_MOVE_TEMP, MOVE_SNATCH
    PlayAnimation                       BATTLER_WORKING
    Wait                                
    // "{0} snatched {1}'s move!"
    Message                             580, TAG_NICK_NICK, BATTLER_WORKING, BATTLER_ATTACKER_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 0
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    If                                  EQUAL, VAR_CURRENT_MOVE, MOVE_ACUPRESSURE, subscr_146_Acupressure
    SetVarFromVar                       OP_SET, VAR_DEFENDER, VAR_ATTACKER_WORK
    End                                 

subscr_146_Acupressure:
    SetVarFromVar                       OP_SET, VAR_DEFENDER, VAR_ATTACKER
    End                                 

.close