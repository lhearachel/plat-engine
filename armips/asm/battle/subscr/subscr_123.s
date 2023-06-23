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


.create "build/battle/scr/subscr/sub_seq_123.bin", 0

// SUBSCR_FUTURE_SIGHT_ATTACK_MESSAGE
subscr_123:
    AttackMessage                       
    Wait                                
    WaitTime                            15
    MessagePrepared                     
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    End                                 

.close