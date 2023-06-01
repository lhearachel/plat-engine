.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_173.s", 0

effscr_173:
    AttackMessage                       
    Wait                                
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    NaturePower                         
    Message                             490, TAG_MOVE_MOVE, BATTLER_ATTACKER, BATTLER_WORKING
    Wait                                
    WaitFrames                          30
    JumpToEffectScript                  0
