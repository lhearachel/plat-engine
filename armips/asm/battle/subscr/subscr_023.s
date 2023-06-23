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


.create "build/battle/scr/subscr/sub_seq_023.bin", 0

// SUBSCR_POISON_DAMAGE
subscr_023:
    // If the affected battler has Magic Guard, do nothing.
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, subscr_023_Exit
    // If the affected battler does not have Poison Heal, proceed to poison damage.
    CheckAbility                        MODE_NOT_HAVE, BATTLER_WORKING, ABILITY_POISON_HEAL, susbcr_023_PoisonDamage
subscr_023_PoisonHeal:
    SetMonDataFromVar                   OP_GET, BATTLER_WORKING, BATTLE_MON_MAX_HP, VAR_HP_TEMP
    JumpIfMonData                       EQUAL, BATTLER_WORKING, BATTLE_MON_HP, VAR_HP_TEMP, subscr_023_Exit
    DamageDiv                           VAR_HP_TEMP, 8
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    CallSubscript                       SUBSCR_HP_CHANGE
    // "{0} restored HP using its {1}!"
    Message                             635, TAG_NICK_ABILITY, BATTLER_WORKING, BATTLER_CLIENT_WORK, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

susbcr_023_PoisonDamage:
    // "{0} is hurt by poison!"
    Message                             73, TAG_NICK, BATTLER_WORKING, NaN, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetStatusEffect                     BATTLER_WORKING, STATUS_POISONED
    Wait                                
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    JumpTo                              SUBSCR_HP_CHANGE

subscr_023_Exit:
    End                                 

.close