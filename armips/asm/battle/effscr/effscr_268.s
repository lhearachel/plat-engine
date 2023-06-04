.nds
.thumb

.include "armips/include/battle_scrcmd.s"

.include "armips/include/abilities.s"
.include "armips/include/battle_consts.s"
.include "armips/include/item_hold_effects.s"
.include "armips/include/moves.s"

.create "build/battle/scr/effscr/be_seq_268.bin", 0

effscr_268:
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FIGHTING_PLATE, 77
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FLYING_PLATE, 78
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_POISON_PLATE, 79
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GROUND_PLATE, 80
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ROCK_PLATE, 81
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_BUG_PLATE, 82
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GHOST_PLATE, 83
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_STEEL_PLATE, 84
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_FIRE_PLATE, 85
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_WATER_PLATE, 86
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_GRASS_PLATE, 87
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ELECTRIC_PLATE, 88
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_PSYCHIC_PLATE, 89
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_ICE_PLATE, 90
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_DRAGON_PLATE, 91
    CheckItemEffect                     MODE_HAVE, BATTLER_ATTACKER, HOLD_EFFECT_BOOST_DARK_PLATE, 92
    Branch                              94
    SetVar                              OP_SET, VAR_MOVE_TYPE, 1
    Branch                              88
    SetVar                              OP_SET, VAR_MOVE_TYPE, 2
    Branch                              82
    SetVar                              OP_SET, VAR_MOVE_TYPE, 3
    Branch                              76
    SetVar                              OP_SET, VAR_MOVE_TYPE, 4
    Branch                              70
    SetVar                              OP_SET, VAR_MOVE_TYPE, 5
    Branch                              64
    SetVar                              OP_SET, VAR_MOVE_TYPE, 6
    Branch                              58
    SetVar                              OP_SET, VAR_MOVE_TYPE, 7
    Branch                              52
    SetVar                              OP_SET, VAR_MOVE_TYPE, 8
    Branch                              46
    SetVar                              OP_SET, VAR_MOVE_TYPE, 10
    Branch                              40
    SetVar                              OP_SET, VAR_MOVE_TYPE, 11
    Branch                              34
    SetVar                              OP_SET, VAR_MOVE_TYPE, 12
    Branch                              28
    SetVar                              OP_SET, VAR_MOVE_TYPE, 13
    Branch                              22
    SetVar                              OP_SET, VAR_MOVE_TYPE, 14
    Branch                              16
    SetVar                              OP_SET, VAR_MOVE_TYPE, 15
    Branch                              10
    SetVar                              OP_SET, VAR_MOVE_TYPE, 16
    Branch                              4
    SetVar                              OP_SET, VAR_MOVE_TYPE, 17
    CriticalCalc                        
    DamageCalc                          
    End                                 

.close