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


.create "build/battle/scr/subscr/sub_seq_085.bin", 0

// SUBSCR_THIEF
subscr_085:
    TryThief                            subscr_085_End, subscr_085_StickyHold
    SetVar                              OP_SET, VAR_MOVE_EFFECT, 1
    // Always play the Thief animation
    SetVar                              OP_CLEAR_FLAG, VAR_SERVER_STATUS_FLAG, SERVER_STATUS_FLAG_MOVE_ANIMATIONS_OFF
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    // "{0} stole {1}'s {2}!"
    Message                             401, TAG_NICK_NICK_ITEM, BATTLER_ATTACKER, BATTLER_DEFENDER, BATTLER_DEFENDER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    // Give the attacker the defender's item
    SetMonDataFromVar                   OP_GET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonDataFromVar                   OP_SET, BATTLER_ATTACKER, BATTLE_MON_HELD_ITEM, VAR_TEMP_WORK
    SetMonData                          OP_SET, BATTLER_DEFENDER, BATTLE_MON_HELD_ITEM, 0
    Branch                              subscr_085_End

subscr_085_StickyHold:
    // "{0}'s {1} made {2} ineffective!"
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30

subscr_085_End:
    End                                 

.close