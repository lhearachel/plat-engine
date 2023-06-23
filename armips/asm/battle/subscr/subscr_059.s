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


.create "build/battle/scr/subscr/sub_seq_059.bin", 0

// SUBSCR_CLAMP_DAMAGE
subscr_059:
    // Different trapping moves have different effects
    CheckAbility                        MODE_HAVE, BATTLER_WORKING, ABILITY_MAGIC_GUARD, subscr_059_End
    If                                  EQUAL, VAR_MOVE_TEMP, MOVE_WRAP, subscr_059_Wrap
    If                                  EQUAL, VAR_MOVE_TEMP, MOVE_FIRE_SPIN, subscr_059_FireSpin
    If                                  EQUAL, VAR_MOVE_TEMP, MOVE_MAGMA_STORM, subscr_059_MagmaStorm
    If                                  EQUAL, VAR_MOVE_TEMP, MOVE_CLAMP, subscr_059_Clamp
    If                                  EQUAL, VAR_MOVE_TEMP, MOVE_WHIRLPOOL, subscr_059_Whirlpool
    If                                  EQUAL, VAR_MOVE_TEMP, MOVE_SAND_TOMB, subscr_059_SandTomb

subscr_059_Bind:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_BIND
    Branch                              subscr_059_Message

subscr_059_Wrap:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_WRAP
    Branch                              subscr_059_Message

subscr_059_FireSpin:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_FIRE_SPIN
    Branch                              subscr_059_Message

subscr_059_MagmaStorm:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_MAGMA_STORM
    Branch                              subscr_059_Message

subscr_059_Clamp:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_CLAMP
    Branch                              subscr_059_Message

subscr_059_Whirlpool:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_WHIRLPOOL
    Branch                              subscr_059_Message

subscr_059_SandTomb:
    SetStatusEffect                     BATTLER_WORKING, STATUS_DAMAGE_SAND_TOMB

subscr_059_Message:
    Wait                                
    // "{0} is hurt by {1}!"
    Message                             262, TAG_NICK_MOVE, BATTLER_WORKING, BATTLER_WORKING, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    SetVar                              OP_SET_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_DO_NOT_BLINK
    JumpTo                              SUBSCR_HP_CHANGE
subscr_059_End:
    End                                 

.close