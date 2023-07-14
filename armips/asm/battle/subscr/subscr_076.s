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


.create "build/battle/scr/subscr/sub_seq_076.bin", 0

// SUBSCR_ATTACK_MESSAGE_AND_ANIMATION
subscr_076:
    AttackMessage                       
    Wait                                
    CallSubscript                       SUBSCR_CHECK_TRIGGER_RESIST_BERRY
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    CallSubscript                       SUBSCR_CHECK_REMOVE_RESIST_BERRY
    End                                 

.close