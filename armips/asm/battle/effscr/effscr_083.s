.nds
.thumb

.include "armips/include/battle_scrcmd.s"
.include "armips/include/abilities.s"
.include "armips/include/moves.s"

.create "build/move/battle/skill/effscr/effscr_83.s", 0

effscr_083:
    AttackMessage                       
    Wait                                
    WaitFrames                          30
    PlayAnimation                       BATTLER_ATTACKER
    Wait                                
    Metronome                           
    JumpToEffectScript                  0
