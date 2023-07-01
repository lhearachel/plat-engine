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


.create "build/battle/scr/subscr/sub_seq_126.bin", 0

// SUBSCR_PRINT_MESSAGE
subscr_126:
    If                                  NOT_EQUAL, VAR_EFFECT_TYPE, ADDL_EFFECT_DIRECT, subscr_126_SkipAttackMessage
    AttackMessage                       
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
subscr_126_SkipAttackMessage:
    MessagePrepared                     
    Wait                                
    WaitTime                            30
    End                                 

.close