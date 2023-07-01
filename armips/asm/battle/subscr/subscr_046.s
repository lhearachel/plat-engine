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


.create "build/battle/scr/subscr/sub_seq_046.bin", 0

// SUBSCR_RECOVER_HALF_HP
subscr_046:
    AttackMessage                       
    Wait                                
    SetMonDataFromVar                   OP_GET, 1, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    DamageDiv                           VAR_HP_TEMP, 2
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    CallSubscript                       SUBSCR_RECOVER_HP
    End                                 

.close