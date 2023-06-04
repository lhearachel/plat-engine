.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/subscr/sub_seq_219.bin", 0

subscr_219:
    TryPluck                            22, 21
    Message                             1141, TAG_NICK_ITEM, BATTLER_ATTACKER, BATTLER_DEFENDER, NaN, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    RemoveItem                          BATTLER_DEFENDER
    SetVarFromVar                       OP_SET, VAR_BATTLER_WORK, VAR_ATTACKER
    If                                  EQUAL, VAR_TEMP_WORK, 0, 2
    JumpToSubscriptFromVar              VAR_TEMP_WORK
    End                                 
    Message                             714, TAG_NICK_ABILITY_MOVE, BATTLER_DEFENDER, BATTLER_DEFENDER, BATTLER_ATTACKER, NaN, NaN, NaN
    Wait                                
    WaitTime                            30
    End                                 

.close