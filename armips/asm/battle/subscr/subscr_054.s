.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/subscr/subscr_54.s", 0

subscr_054:
    SetMist                             6
    PrepareMessage                      271, TAG_NONE_DIR, BATTLER_ATTACKER
    JumpToSubscript                     53
    End                                 
