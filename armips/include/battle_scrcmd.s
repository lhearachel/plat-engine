.include "armips/include/battle_pokemon_params.s"
.include "armips/include/message_tag.s"

/*
 * Starts an encounter with the appropriate encounter effects.
 * This can be any sort of encounter: wild battle, trainer battle, etc.
 */
.macro SetEncounterEffects
    .word 0x00
.endmacro

BATTLER_ALL             equ 0
BATTLER_ATTACKER        equ 1
BATTLER_DEFENDER        equ 2
BATTLER_ME              equ 3
BATTLER_ENEMY           equ 4
BATTLER_FAINTING        equ 5
BATTLER_SWITCHING       equ 6
BATTLER_EFFECTSRC       equ 7
BATTLER_ABILITYSRC      equ 8
BATTLER_ME_SLOT_1       equ 9
BATTLER_ENEMY_SLOT_1    equ 10
BATTLER_ME_SLOT_2       equ 11
BATTLER_ENEMY_SLOT_2    equ 12
BATTLER_WORKING         equ 0xFF

/*
 * Sets the Pokemon for a wild encounter.
 *
 * Realistically, the input here should only ever be BATTLER_ENEMY, but
 * specifying BATTLER_ALL will set the Pokemon to all clients.
 *
 * Dex-seen flags are updated appropriately.
 */
.macro SetPokemonForEncounter,battler
    .word 0x01, battler
.endmacro

/*
 * Slides the Pokemon into view for a wild encounter.
 *
 * `battler` should be one of:
 * - BATTLER_ME
 * - BATTLER_ENEMY
 */
.macro PokemonSlideIn,battler
    .word 0x02, battler
.endmacro

/*
 * Shows a Pokemon sprite for a particular battler.
 *
 * This is typically used for switching, but is also used by the subscript
 * effect that forces a random switch (e.g. by Whirlwind or Roar).
 */
.macro PokemonAppear,battler
    .word 0x03, battler
.endmacro

/*
 * Returns a Pokemon to its ball (for switching).
 *
 * Also used by the BattleLost script, specifically for Battle Tower trainers.
 * Those trainers will return their mons and then display a message before
 * the battle interface closes.
 */
.macro PokemonReturn,battler
    .word 0x04, battler
.endmacro

/*
 * Deletes a Pokemon's sprite, e.g. for Whirlwind, Baton Pass, or U-turn.
 */
.macro PokemonDelete,battler
    .word 0x05, battler
.endmacro

/*
 * Sets the trainers for a particular side of the encounter.
 * 
 * `battler` should be one of:
 * - BATTLER_ALL   -> Set the trainers for all eligible slots.
 * - BATTLER_ME    -> Set the trainers for the player's slots.
 * - BATTLER_ENEMY -> Set the trainers for the enemy's slots.
 */
.macro SetTrainersForEncounter,battler
    .word 0x06, battler
.endmacro

THROW_POKE_BALL     equ 0
THROW_SAFARI_BALL   equ 1
THROW_SAFARI_ROCK   equ 2
THROW_SAFARI_BAIT   equ 3
THROW_PARK_BALL     equ 4

/*
 * Initializes the Throwing animation for a particular battler.
 */
.macro Throw,battler,type
    .word 0x07, battler, type
.endmacro

/*
 * Slides a trainer sprite off-screen.
 */
.macro TrainerSlideOut,side
    .word 0x08, side
.endmacro

POS_SINGLES_PLAYER  equ 0
POS_SINGLES_ENEMY   equ 1
POS_DOUBLES_PLAYER  equ 2
POS_DOUBLES_PARTNER equ 3
POS_DOUBLES_ENEMY_1 equ 4
POS_DOUBLES_ENEMY_2 equ 5

/*
 * Slides a trainer sprite on-screen to a specified position.
 *
 * Positions are parameterized by a set of fixed values which point to indices
 * in a pre-computed array deeper in the rendering code.
 */
.macro TrainerSlideIn,side,pos
    .word 0x09, side, pos
.endmacro

/*
 * Slides the battle input screen into the touch panel.
 */
.macro BattleInputSlideIn
    .word 0x0A
.endmacro

/*
 * Slides the HP gauge(s) for a battler into the top panel.
 *
 * Special param values:
 * - BATTLER_ALL   -> Slide in gauges for all battlers.
 * - BATTLER_ME    -> Slide in gauges for all player-side battlers.
 * - BATTLER_ENEMY -> Slide in gauges for all enemy-side battlers.
 */
.macro HPGaugeSlideIn,battler
    .word 0x0B, battler
.endmacro

/*
 * Slides the HP gauge(s) for a battler into the top panel.
 *
 * Special param values:
 * - BATTLER_ALL   -> Slide in gauges for all battlers.
 * - BATTLER_ME    -> Slide in gauges for all player-side battlers.
 * - BATTLER_ENEMY -> Slide in gauges for all enemy-side battlers.
 *
 * If BATTLER_ME or BATTLER_ENEMY are specified, then the gauges for each
 * respective battler on that side will be staggered on a 4-frame delay.
 */
.macro HPGaugeSlideWait,battler
    .word 0x0C, battler
.endmacro

/*
 * Slides the HP gauge(s) for a battler out from the top panel.
 *
 * Special param values:
 * - BATTLER_ALL   -> Slide in gauges for all battlers.
 * - BATTLER_ME    -> Slide in gauges for all player-side battlers.
 * - BATTLER_ENEMY -> Slide in gauges for all enemy-side battlers.
 */
.macro HPGaugeSlideOut,battler
    .word 0x0D, battler
.endmacro

/*
 * Wait until all other active commands have finished being processed.
 */
.macro Wait
    .word 0x0E
.endmacro

/*
 * Calculate the damage for the current move, accounting for the 15% roll
 * on damage-variance, and assign it to be deducted from the defender's HP.
 */
.macro DamageCalc
    .word 0x0F
.endmacro

/*
 * Calculate the maximum damage for the current move and assign it to be
 * deducted from the defender's HP.
 *
 * This is only used by vanilla Gen4 Spit Up, which is not affected by
 * damage variance.
 */
.macro DamageCalcMaximum
    .word 0x10
.endmacro

/*
 * Display the attack message for the current move.
 */
.macro AttackMessage
    .word 0x11
.endmacro

/*
 * Display a parameterized message.
 *
 * The value of `tag` specifies how many additional parameters are valid.
 * In essence, you should only provide as many parameters as the message's
 * parameter-set permits. A few examples:
 * - TAG_NICK_ITEM            -> 2 extra parameters
 * - TAG_NICK_ABILITY_NUM     -> 3 extra parameters
 * - TAG_TRTYPE_TRNAME_NICKx2 -> 6 extra parameters
 *
 * Message IDs specified correspond to entries in text archive 368.
 */
.macro Message,msg_id,tag,param1,param2,param3,param4,param5,param6
    .word 0x12, msg_id, tag
    .if tag == 0
    .elseif tag < TAG_NICK_NICK
        .word param1
    .elseif tag < TAG_NICK_NICK_MOVE
        .word param1, param2
    .elseif tag < TAG_NICK_ABILITY_NICK_MOVE
        .word param1, param2, param3
    .elseif tag < TAG_TRTYPE_TRNAME_NICKx2
        .word param1, param2, param3, param4
    .elseif
        .word param1, param2, param3, param4, param5, param6
    .endif
.endmacro

/*
 * Display a parameterized message without any battler information.
 *
 * This is like Message, but useful for more global-messages, e.g. the messages
 * displayed for weather effects, Trick Room, etc.
 */
.macro MessageNoBattler,msg_id,tag,param1,param2,param3,param4,param5,param6
    .word 0x13, msg_id, tag
    .if tag == 0
    .elseif tag < TAG_NICK_NICK
        .word param1
    .elseif tag < TAG_NICK_NICK_MOVE
        .word param1, param2
    .elseif tag < TAG_NICK_ABILITY_NICK_MOVE
        .word param1, param2, param3
    .elseif tag < TAG_TRTYPE_TRNAME_NICKx2
        .word param1, param2, param3, param4
    .elseif
        .word param1, param2, param3, param4, param5, param6
    .endif
.endmacro

/*
 * Display a pre-prepared message, stored on the server.
 */
.macro MessagePrepared
    .word 0x14
.endmacro

/*
 * Prepare a parameterized message to be stored on the server.
 *
 * For more details, see Message. The basic behavior here is the same, but the
 * message is stored for later display using MessagePrepared rather than being
 * displayed immediately.
 */
.macro PrepareMessage,msg_id,tag,param1,param2,param3,param4,param5,param6
    .word 0x15, msg_id, tag
    .if tag == 0
    .elseif tag < TAG_NICK_NICK
        .word param1
    .elseif tag < TAG_NICK_NICK_MOVE
        .word param1, param2
    .elseif tag < TAG_NICK_ABILITY_NICK_MOVE
        .word param1, param2, param3
    .elseif tag < TAG_TRTYPE_TRNAME_NICKx2
        .word param1, param2, param3, param4
    .elseif
        .word param1, param2, param3, param4, param5, param6
    .endif
.endmacro

/*
 * Show a message for a particular battler.
 * 
 * This is primarily used by the wear-off subscripts for Light Screen and Reflect.
 */
.macro MessageWithBattler,battler,msg_id,tag,param1,param2,param3,param4,param5,param6
    .word 0x16, battler, msg_id, tag
    .if tag == 0
    .elseif tag < TAG_NICK_NICK
        .word param1
    .elseif tag < TAG_NICK_NICK_MOVE
        .word param1, param2
    .elseif tag < TAG_NICK_ABILITY_NICK_MOVE
        .word param1, param2, param3
    .elseif tag < TAG_TRTYPE_TRNAME_NICKx2
        .word param1, param2, param3, param4
    .elseif
        .word param1, param2, param3, param4, param5, param6
    .endif
.endmacro

/*
 * Plays a move animation originating from the current attacker and targeting
 * the current defender, as specified by the server.
 */
.macro PlayAnimation,battler
    .word 0x17, battler
.endmacro

/*
 * Plays a move animation originating from an attacker and targeting a defender.
 *
 * If `battler` is specified as BATTLER_WORK, then the temporary move var will be
 * used as the move to animate; otherwise, the current move will be used.
 *
 * This is used by, e.g., the Future Sight and Focus Punch subscripts, since
 * their attacking sequences are delayed.
 */
.macro PlayAnimationAtoD,battler,attacker,defender
    .word 0x18, battler, attacker, defender
.endmacro

/*
 * Flickers the sprite in a particular battle slot, e.g. when a mon takes damage.
 */
.macro FlickerMon,battler
    .word 0x19, battler
.endmacro

/*
 * Update the HP for a battler after damage calculation.
 */
.macro UpdateHP,battler
    .word 0x1A, battler
.endmacro

/*
 * Update the HP gauge for a batter after damage has been applied.
 */
.macro UpdateHPGauge,battler
    .word 0x1B, battler
.endmacro

/*
 * Try to faint a given battler. If able to do so, store the battler that
 * is fainting into the server for animation playback.
 */
.macro TryFaintMon,battler
    .word 0x1C, battler
.endmacro

/*
 * Play the fainting animation for the battler specified on the server.
 */
.macro FaintAnimation
    .word 0x1D
.endmacro

/*
 * Wait a specified number of frames.
 */
.macro WaitTime,time
    .word 0x1E, time
.endmacro

/*
 * Play a given sound on the specified client.
 */
.macro PlaySound,battler,sdat_id
    .word 0x1F, battler, sdat_id
.endmacro

EQUAL       equ 0
NOT_EQUAL   equ 1
GREATER     equ 2
LESSER      equ 3
FLAG_EQ     equ 4
FLAG_NEQ    equ 5
FLAG_AND    equ 6

/*
 * Branch to a later instruction if a given pair of values match the input
 * condition.
 *
 * e.g.:
 *      If  EQUAL, value_1, value_2, jump_to_if_equal
 *      If  GREATER, value_1, value_2, jump_to_if_greater
 */
.macro If,condition,source,compare_to,jump_if_true
    .word 0x20, condition, source, compare_to
    .word ((jump_if_true - org()) / 4) - 1
.endmacro

/*
 * Branch to a later instruction if a given pair of values match the input
 * condition. The first value will be pulled from a given battler's Pokemon
 * data.
 */
.macro IfMonData,condition,battler,mon_param,compare_to,jump_if_true
    .word 0x21, condition, battler, mon_param, compare_to
    .word ((jump_if_true - org()) / 4) - 1
.endmacro

/*
 * Fade out from the battle screen.
 */
.macro FadeOut
    .word 0x22
.endmacro

/*
 * Jump to a specific subscript.
 */
.macro JumpToSubscript,num
    .word 0x23, num
.endmacro

/*
 * Jump to the effect script for the current move.
 */
.macro JumpToMoveEffectScript
    .word 0x24
.endmacro

/*
 * Jump to a specific effect script.
 */
.macro JumpToEffectScript,num
    .word 0x25, num
.endmacro

/*
 * Roll for a critical hit.
 */
.macro CriticalCalc
    .word 0x26
.endmacro

/*
 * Check if experience should be allocated (and also how much).
 */
.macro ShouldGetExp,jump_if_no_exp
    .word 0x27
    .word ((jump_if_no_exp - org()) / 4) - 1
.endmacro

/*
 * Initialize the experience allocation task.
 */
.macro InitGetExp
    .word 0x28
.endmacro

/*
 * Lock the battle progress flag so long as experience allocation is in-progress.
 */
.macro WaitExp
    .word 0x29
.endmacro

/*
 * Jump back to the WaitExp check.
 */
.macro ExpLoopback,jump_to
    .word 0x2A
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Show the party list for any switching client.
 */
.macro ShowMonList
    .word 0x2B
.endmacro

/*
 * Wait for a Pokemon to be selected from the party list.
 */
.macro WaitForMonSelection
    .word 0x2C
.endmacro

/*
 * Switch a selected Pokemon into the given battler slot. The selected
 * Pokemon should be previously-chosen by ShowMonList and WaitForMonSelection.
 */
.macro SwitchInAndUpdate,battler
    .word 0x2D, battler
.endmacro

/*
 * Perform a jump to the specified address if any battler is switching.
 */
.macro JumpIfAnySwitching,jump_to
    .word 0x2E
    .word ((jump_to - org()) / 4) - 1
.endmacro

CAPTURE_NORMAL  equ 0
CAPTURE_SAFARI  equ 1

/*
 * Initialize a capture process of a particular type.
 *
 * `capture_flag` should be one of either CAPTURE_NORMAL or CAPTURE_SAFARI.
 */
.macro InitCapture,capture_flag
    .word 0x2F, capture_flag
.endmacro

/*
 * Start the capture process of a type previously specified by InitCapture.
 */
.macro Capture
    .word 0x30
.endmacro

DOUBLE_HIT_FLAGS    equ 0x0000000D  // for spread-damage moves
MULTI_HIT_FLAGS     equ 0x000000FD  // for 2-5 hit moves
TRIPLE_KICK_FLAGS   equ 0x000000DD  // for ramping-power 3-hit moves

/*
 * Set the number of hits for a multi-hit move.
 *
 * If `hits` is 0, then a random number of hits will be specified from 2 to 5,
 * accounting for Skill Link.
 *
 * If `hits` is any other value, then that value will be set as the number of
 * hits (e.g. for moves like Double Kick, which hit exactly twice).
 *
 * `flags` is used to control special properties for the damage loop. These
 * toggle off certain checks that would otherwise be executed between hits,
 * such as badge-obedience, status, PP, Truant, and accuracy.
 */
.macro SetMultiHit,hits,flags
    .word 0x31, hits, flags
.endmacro

OP_SET          equ 7       // set a var to a specific value
OP_ADD          equ 8       // add a specific value to a var's current value
OP_SUB          equ 9       // subtract a specific value from a var's current value
OP_SET_FLAG     equ 10      // set a specific bitflag in a var's current value
OP_CLEAR_FLAG   equ 11      // clear a specific bitflag in a var's current value
OP_MUL          equ 12      // multiply a specific value into a var's current value
OP_DIV          equ 13      // divide a var's current value by a specific value
OP_LSH          equ 14      // shift a var's current value by a number of steps to the left
OP_RSH          equ 15      // shift a var's current value by a number of steps to the right
OP_TO_BIT       equ 16      // store a bitmask into the var with only a specific flag set
OP_GET          equ 17      // undefined
OP_SUB_TO_ZERO  equ 18      // same as OP_SUB, but set negative results to 0
OP_XOR          equ 19      // XOR a var's current value by a specific value
OP_AND          equ 20      // AND a var's current value by a specific value

VAR_BATTLE_TYPE                         equ 0
VAR_CRITICAL_CHANCE                     equ 1
VAR_ADD_STATUS_DIRECT                   equ 2
VAR_ADD_STATUS_INDIRECT                 equ 3
VAR_ADD_STATUS_ABILITY                  equ 4
VAR_EFFECT_TYPE                         equ 5
VAR_SERVER_STATUS_FLAG                  equ 6
VAR_FIELD_CONDITIONS                    equ 7
VAR_DAMAGE_MULTI                        equ 8
VAR_CALC_WORK                           equ 9
VAR_MOVE_STATUS_FLAG                    equ 10
VAR_ATTACKER_SIDE_CONDITIONS            equ 11
VAR_DEFENDER_SIDE_CONDITIONS            equ 12
VAR_EFFECTSRC_SIDE_CONDITIONS           equ 13
VAR_DAMAGE                              equ 14
VAR_ATTACKER                            equ 15
VAR_DEFENDER                            equ 16
VAR_EFFECTSRC                           equ 17
VAR_FAINTED_BATTLER                     equ 18
VAR_SWITCHED_BATTLER                    equ 19
VAR_BATTLER_WORK                        equ 20
VAR_BIDE_DAMAGE                         equ 21
VAR_PREPARED_MESSAGE                    equ 22
VAR_MONEY                               equ 23
VAR_CURRENT_MOVE                        equ 24
VAR_TURNS                               equ 25
VAR_ATTACKER_WORK                       equ 26
VAR_DEFENDER_WORK                       equ 27
VAR_MOVE_NUM_WORK                       equ 28
VAR_PUSH_CLIENT                         equ 29
VAR_DAMAGE_POWER                        equ 30
VAR_SWOAM_TYPE                          equ 31
VAR_HP_TEMP                             equ 32
VAR_BATTLE_RESULT                       equ 33
VAR_EFFECT_PARAMS                       equ 34
VAR_MOVE_TEMP                           equ 35
VAR_ITEM_TEMP                           equ 36
VAR_ABILITY_TEMP                        equ 37
VAR_WEATHER_COUNT                       equ 38
VAR_NTH_BATTLER_BY_SPEED                equ 39
VAR_IS_MULTIHIT                         equ 40
VAR_PHYSICAL_DAMAGE                     equ 41
VAR_SPECIAL_DAMAGE                      equ 42
VAR_TEMP_WORK                           equ 43
VAR_WAS_MOVE_CRITICAL                   equ 44
VAR_LAST_DAMAGING_ATTACKER              equ 45
VAR_LAST_DAMAGING_DEFENDER              equ 46
VAR_ATTACKER_ONE_TURN_STATUS_FLAGS      equ 47
VAR_DEFENDER_ONE_TURN_STATUS_FLAGS      equ 48
VAR_EFFECTSRC_ONE_TURN_STATUS_FLAGS     equ 49
VAR_FLING_TEMP                          equ 50
VAR_FLING_SUBSCRIPT                     equ 51
VAR_BATTLE_STATUS_FLAG                  equ 52
VAR_MOVE_CONTINUATION                   equ 53
VAR_HIT_DAMAGE                          equ 54
VAR_SAFARI_BALL_COUNT                   equ 55
VAR_SWITCHED_BATTLER_TEMP               equ 56
VAR_MOVE_TYPE                           equ 57
VAR_MOVE_EFFECT                         equ 58
VAR_RULESET                             equ 59
VAR_SERVER_STATUS_FLAG2                 equ 60
VAR_SPEED_COUNT                         equ 61
VAR_CLIENT_SET_MAX                      equ 62
VAR_ATTACKER_TEMP                       equ 63
VAR_DEFENDER_TEMP                       equ 64
VAR_DEFENDER_ONE_TURN_PHYSICAL_DAMAGE   equ 65
VAR_ATTACKER_ASSURANCE_DAMAGE           equ 66
VAR_DEFENDER_ASSURANCE_DAMAGE           equ 67
VAR_ATTACKER_SHELL_BELL_DAMAGE          equ 68
VAR_CLIENT_WORKING_COUNT                equ 69

/*
 * Assign a variable.
 *
 * The exact behavior here depends on `operator`, but the end result is always
 * an overwriting of the input variable.
 */
.macro SetVar,operator,var,value
    .word 0x32, operator, var, value
.endmacro

/*
 * Try to apply a stat boost change, and jump to a particular address if unable
 * to do so, depending on the reason.
 */
.macro StatBoostChange,jump_if_no_change,jump_if_blocked,jump_if_blocked_by_substitute
    .word 0x33
    .word ((jump_if_no_change - org()) / 4) - 3
    .word ((jump_if_blocked - org()) / 4) - 2
    .word ((jump_if_blocked_by_substitute - org()) / 4) - 1
.endmacro

/*
 * Assign a value to battler's Pokemon data.
 *
 * `operator` follows the same rules as SetVar.
 */
.macro SetMonData,operator,battler,mon_param,value
    .word 0x34, operator, battler, mon_param, value
.endmacro

/*
 * Clear a volatile status from a battler.
 *
 * Never used in vanilla gen-4.
 */
.macro ClearVolatileStatus,battler,value
    .word 0x35, battler, value
.endmacro

/*
 * Set the "vanished" flag for a battler. This flag is used for states where
 * the battler is flying, underground, diving, or in the shadows.
 */
.macro ToggleVanish,battler,num
    .word 0x36, battler, num
.endmacro

MODE_HAVE       equ 0
MODE_NOT_HAVE   equ 1

/*
 * Check if a battler has a particular ability, accounting for disruptive
 * effects (e.g., Mold Breaker).
 *
 * If `mode` is MODE_HAVE (0), then the address will be jumped to if the
 * battler has the ability.
 *
 * If `mode` is MODE_NOT_HAVE (1), then the address will be jumped to if the
 * battler does not have the ability.
 *
 * If `battler` is BATTLER_ALL, then the resulting jump will be applied if
 * any battler on the field matches the given condition.
 */
.macro CheckAbility,mode,battler,ability,jump_to
    .word 0x37, mode, battler, ability
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Generate a random number from 0 to `range`, offsetting the result as needed.
 *
 * e.g., to generate a random number from 0 to 4: `Random   5, 0`
 *       to generate a random number from 5 to 9: `Random   5, 5`
 */
.macro Random,range,offset
    .word 0x38, range, offset
.endmacro

/*
 * Assign the value of a variable to an operation applied on itself and another
 * variable.
 */
.macro SetVarFromVar,operator,var_dst,var_src
    .word 0x39, operator, var_dst, var_src
.endmacro

/*
 * Assign the value of a battler's Pokemon data to an operation applied on itself
 * and a variable's value.
 */
.macro SetMonDataFromVar,operator,battler,battler_param,var
    .word 0x3A, operator, battler, battler_param, var
.endmacro

/*
 * Jump to an address.
 */
.macro Jump,jump_to
    .word 0x3B
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Jump to a subscript by its numeric index.
 */
.macro JumpToSubscript,num
    .word 0x3C, num
.endmacro

/*
 * Jump to a subscript from a variable value.
 */
.macro JumpToSubscriptFromVar,var
    .word 0x3D, var
.endmacro

/*
 * Set the move copied by Mirror Move.
 */
.macro SetMirrorMove
    .word 0x3E
.endmacro

/*
 * Clear all stat stage changes.
 */
.macro ClearStatStages
    .word 0x3F
.endmacro

/*
 * Set the move continuation flag for a battler.
 *
 * This is used for moves which force themselves to be used over multiple
 * turns, e.g. Fly, Bide, and Thrash.
 */
.macro SetContinuation,battler
    .word 0x40, battler
.endmacro

/*
 * Clear the move continuation flag for a battler.
 */
.macro ClearContinuation,battler
    .word 0x41, battler
.endmacro

STATUS_NORMAL       equ 0
STATUS_ASLEEP       equ 1
STATUS_POISONED     equ 2
STATUS_BURNED       equ 3
STATUS_FROZEN       equ 4
STATUS_PARALYZED    equ 5

/*
 * Set a status icon onto a battler's HP gauge.
 */
.macro SetStatusIcon,battler,status
    .word 0x42, battler, status
.endmacro

TRAINER_MESSAGE_LOSE    equ 1
TRAINER_MESSAGE_LOSE_1  equ 4
TRAINER_MESSAGE_LOSE_2  equ 8
TRAINER_MESSAGE_WIN     equ 100

/*
 * Show a trainer message from a battler of a given type.
 */
.macro TrainerMessage,battler,type
    .word 0x43, battler, type
.endmacro

/*
 * Calculate the money payout after winning or losing a trainer battle.
 */
.macro CalcMoney
    .word 0x44
.endmacro

/*
 * Set a status effect on a given battler.
 */
.macro SetStatusEffect,battler,status
    .word 0x45, battler, status
.endmacro

/*
 * Set a status effect on multiple battlers (e.g., Teeter Dance).
 */
.macro SetStatusEffectMulti,mon1,mon2,status
    .word 0x46, mon1, mon2, status
.endmacro

/*
 * Set a status effect on a battler from a variable.
 */
.macro SetStatusEffectFromVar,battler,var
    .word 0x47, battler, var
.endmacro

/*
 * Show the message when calling a battler back to the party.
 */
.macro ReturnMessage,battler
    .word 0x48, battler
.endmacro

/*
 * Show the message when sending a new battler out.
 */
.macro SendOutMessage,battler
    .word 0x49, battler
.endmacro

/*
 * Show the message when starting a battle.
 *
 * `battler` realistically is only ever BATTLER_ENEMY.
 */
.macro EncounterStartMessage,battler
    .word 0x4A, battler
.endmacro

/*
 * Show the message for sending out Pokemon at the start of a battle.
 */
.macro EncounterSendOutMessage,battler
    .word 0x4B, battler
.endmacro

/*
 * Show the prepared message as a trainer message for the given battler.
 */
.macro TrainerMessagePrepared,battler
    .word 0x4C, battler
.endmacro

/*
 * Try to execute Conversion.
 */
.macro TryConversion,jump_on_failure
    .word 0x4D
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Jump to an address if the specified condition is met.
 */
.macro JumpIf,operator,source,compare_to,jump_to
    .word 0x4E, operator, source, compare_to
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Jump to an address if the specified condition is met, using battler
 * Pokemon data.
 */
.macro JumpIfMonData,operator,battler,mon_param,compare_to,jump_to
    .word 0x4F, operator, battler, mon_param, compare_to
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Add money from Pay Day.
 */
.macro AddPayDayMoney
    .word 0x50
.endmacro

/*
 * Try to set Light Screen for the current attacker.
 */
.macro SetLightScreen,jump_on_failure
    .word 0x51
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to set Reflect for the current attacker.
 */
.macro SetReflect,jump_on_failure
    .word 0x52
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to set Mist for the current attacker.
 */
.macro SetMist,jump_on_failure
    .word 0x53
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute an OHKO move (e.g., Guillotine).
 */
.macro TryOneHitKO
    .word 0x54
.endmacro

/*
 * Divide a variable by a specified value.
 */
.macro DamageDiv,var,divide_by
    .word 0x55, var, divide_by
.endmacro

/*
 * Divide a variable by a value from another variable.
 */
.macro DamageDivByVar,var,divide_by_var
    .word 0x56, var, divide_by_var
.endmacro

/*
 * Try to execute Mimic.
 */
.macro TryMimic,jump_on_failure
    .word 0x57
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Execute Metronome.
 */
.macro Metronome
    .word 0x58
.endmacro

/*
 * Try to execute Disable.
 */
.macro TryDisable,jump_on_failure
    .word 0x59
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Execute Counter.
 */
.macro Counter
    .word 0x5A
.endmacro

/*
 * Execute Mirror Coat.
 */
.macro MirrorCoat
    .word 0x5B
.endmacro

/*
 * Try to execute Encore.
 */
.macro TryEncore,jump_on_failure
    .word 0x5C
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Conversion2.
 */
.macro TryConversion2,jump_on_failure
    .word 0x5D
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Sketch.
 */
.macro TrySketch,jump_on_failure
    .word 0x5E
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Sleep Talk.
 */
.macro TrySleepTalk,jump_on_failure
    .word 0x5F
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculate the damage for Flail, using the current attacker's HP.
 */
.macro FlailDamageCalc
    .word 0x60
.endmacro

/*
 * Try to execute Spite.
 */
.macro TrySpite,jump_on_failure
    .word 0x61
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Execute Heal Bell.
 */
.macro HealBell
    .word 0x62
.endmacro

/*
 * Try to execute Thief.
 */
.macro TryThief,jump_on_failure,jump_if_sticky_hold
    .word 0x63
    .word ((jump_on_failure - org()) / 4) - 2
    .word ((jump_if_sticky_hold - org()) / 4) - 1
.endmacro

/*
 * Try to execute Protect.
 */
.macro TryProtect,jump_on_failure
    .word 0x64
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Substitute.
 */
.macro TrySubstitute,jump_on_failure
    .word 0x65
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Whirlwind.
 */
.macro TryWhirlwind,jump_on_failure
    .word 0x66
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Execute Transform. 
 */
.macro Transform
    .word 0x67
.endmacro

/*
 * Try to execute Spikes.
 */
.macro TrySpikes,jump_on_failure
    .word 0x68
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Check the Spikes entry effect for a battler.
 */
.macro CheckSpikes,battler,jump_on_failure
    .word 0x69, battler
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Perish Song.
 */
.macro TryPerishSong,jump_on_failure
    .word 0x6A
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Gets the next battler, according to speed order, and stores it in the
 * specified variable.
 *
 * This makes use of a parameter inside the server structure, which is accessible
 * via the scripting variable VAR_NTH_BATTLER_BY_SPEED. Vanilla uses this for
 * iterating over battlers for applying the following effects:
 * - Perish Song
 * - Weather
 * - Gravity
 * - Intimidate
 */
.macro GetBattlerBySpeedOrder,var
    .word 0x6B, var
.endmacro

/*
 * Jump to an address if the given variable's value is a valid battler.
 */
.macro JumpIfValidBattler,var,jump_to
    .word 0x6C, var
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Calculate the HP change applied to a battler as the result of weather.
 */
.macro WeatherDamageCalc,battler
    .word 0x6D, battler
.endmacro

/*
 * Calculate the damage for Rollout.
 */
.macro RolloutDamageCalc
    .word 0x6E
.endmacro

/*
 * Calculate the damage for Fury Cutter.
 */
.macro FuryCutterDamageCalc
    .word 0x6F
.endmacro

/*
 * Try to execute Attract.
 */
.macro TryAttract,jump_on_failure
    .word 0x70
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Safeguard.
 */
.macro TrySafeguard,jump_on_failure
    .word 0x71
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Present.
 */
.macro TryPresent,jump_on_failure
    .word 0x72
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculate the damage for Magnitude.
 */
.macro MagnitudeDamageCalc
    .word 0x73
.endmacro

/*
 * Try to switch a battler.
 *
 * If `open_party_flag` is set to 1, then the party list will be opened on success.
 */
.macro TrySwitchInMon,battler,open_party_flag,jump_on_failure
    .word 0x74, battler, open_party_flag
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Execute Rapid Spin.
 */
.macro RapidSpin
    .word 0x75
.endmacro

/*
 * Execute HP recovery moves which are affected by weather (e.g., Synthesis).
 */
.macro WeatherHPRecovery
    .word 0x76
.endmacro

/*
 * Calculate the damage for Hidden Power.
 */
.macro HiddenPowerDamageCalc
    .word 0x77
.endmacro

/*
 * Execute Psych Up.
 */
.macro PsychUp
    .word 0x78
.endmacro

/*
 * Try to execute Future Sight.
 */
.macro TryFutureSight,jump_on_failure
    .word 0x79
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Check if a move hits.
 */
.macro CheckHit,attacker,defender,move_id,jump_on_failure
    .word 0x7A, attacker, defender, move_id
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Teleport.
 */
.macro TryTeleport,jump_on_failure
    .word 0x7B
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculates the damage for a hit of Beat Up.
 */
.macro BeatUpDamageCalc
    .word 0x7C
.endmacro

/*
 * Executes Follow Me.
 */
.macro FollowMe
    .word 0x7D
.endmacro

/*
 * Try to execute Helping Hand.
 */
.macro TryHelpingHand,jump_on_failure
    .word 0x7E
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Trick.
 */
.macro TryTrick,jump_on_failure,jump_if_sticky_hold
    .word 0x7F
    .word ((jump_on_failure - org()) / 4) - 2
    .word ((jump_if_sticky_hold - org()) / 4) - 1
.endmacro

/*
 * Try to execute Wish.
 */
.macro TryWish,jump_on_failure
    .word 0x80
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Assist.
 */
.macro TryAssist,jump_on_failure
    .word 0x81
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to set Magic Coat.
 */
.macro TrySetMagicCoat,jump_on_failure
    .word 0x82
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Execute Magic Coat reflection.
 */
.macro MagicCoat
    .word 0x83
.endmacro

/*
 * Calculate the damage for Revenge.
 */
.macro RevengeDamageCalc
    .word 0x84
.endmacro

/*
 * Try to break Reflect and Light Screen.
 */
.macro TryBreakScreens,jump_on_failure
    .word 0x85
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Yawn.
 */
.macro TryYawn,jump_on_failure
    .word 0x86
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Knock Off.
 */
.macro TryKnockOff,jump_on_failure
    .word 0x87
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculate the damage for Eruption (and similar moves).
 */
.macro EruptionDamageCalc
    .word 0x88
.endmacro

/*
 * Try to execute Imprison.
 */
.macro TryImprison,jump_on_failure
    .word 0x89
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Grudge.
 */
.macro TryGrudge,jump_on_failure
    .word 0x8A
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Snatch.
 */
.macro TrySnatch,jump_on_failure
    .word 0x8B
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculate the damage for Low Kick (and similar moves).
 */
.macro LowKickDamageCalc,jump_on_failure
    .word 0x8C
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculate the damage for Weather Ball.
 */
.macro WeatherBallDamageCalc
    .word 0x8D
.endmacro

/*
 * Try to execute Pursuit.
 */
.macro TryPursuit,jump_on_failure
    .word 0x8E
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Update damage values according to the type of the current move and the
 * types of the current attacker and defender.
 *
 * This is where STAB and type-effectiveness multipliers are applied.
 */
.macro ApplyTypeMultipliers
    .word 0x8F
.endmacro

OTF_STRUGGLING      equ 0
OTF_PP_DECREMENT    equ 1
OTF_PROTECTED       equ 2
OTF_HELPING_HAND    equ 3
OTF_MAGIC_COAT      equ 4
OTF_SNATCHING       equ 5
OTF_ROOSTING        equ 6
OTF_FLEEING         equ 7
OTF_ENDURING        equ 8

/*
 * Check the single-turn effect flags for a battler and jump to the specified
 * address if it matches a given value.
 */
.macro CheckOneTurnFlag,battler,flag,compare_to,jump_if_equal
    .word 0x90, battler, flag, compare_to
    .word ((jump_if_equal - org()) / 4) - 1
.endmacro

/*
 * Sets a given single-turn effect flag for a battler to the specified value.
 */
.macro SetOneTurnFlag,battler,flag,value
    .word 0x91, battler, flag, value
.endmacro

/*
 * Calculate the damage for Gyro Ball.
 */
.macro GyroBallDamageCalc
    .word 0x92
.endmacro

/*
 * Try to calculate the damage for Metal Burst.
 */
.macro MetalBurstDamageCalc,jump_on_failure
    .word 0x93
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculate the damage for Payback.
 */
.macro PaybackDamageCalc
    .word 0x94
.endmacro

/*
 * Calculate the damage for Trump Card.
 */
.macro TrumpCardDamageCalc
    .word 0x95
.endmacro

/*
 * Calculate the damage for Wring Out.
 */
.macro WringOutDamageCalc
    .word 0x96
.endmacro

/*
 * Try to execute Me First.
 */
.macro TryMeFirst,jump_on_failure
    .word 0x97
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Copycat.
 */
.macro TryCopycat,jump_on_failure
    .word 0x98
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Calculate the damage for Punishment.
 */
.macro PunishmentDamageCalc
    .word 0x99
.endmacro

/*
 * Try to execute Sucker Punch.
 */
.macro TrySuckerPunch,jump_on_failure
    .word 0x9A
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

SIDE_CONDITION_MODE_CHECK_OFF   equ 0
SIDE_CONDITION_MODE_CHECK_ON    equ 1
SIDE_CONDITION_MODE_CLEAR       equ 2

SIDE_CONDITION_LIGHT_SCREEN_COUNT   equ 0
SIDE_CONDITION_REFLECT_COUNT        equ 1
SIDE_CONDITION_MIST_COUNT           equ 2
SIDE_CONDITION_SAFEGUARD_COUNT      equ 3
SIDE_CONDITION_SPIKES_COUNT         equ 4
SIDE_CONDITION_TOXIC_SPIKES_COUNT   equ 5

/*
 * Check for a side condition for a particular battler.
 */
.macro CheckSideCondition,battler,mode,condition_flag,jump_to
    .word 0x9B, battler, mode, condition_flag
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Try to execute Feint.
 */
.macro TryFeint,jump_if_no_protect
    .word 0x9C
    .word ((jump_if_no_protect - org()) / 4) - 1
.endmacro

/*
 * Try to execute Psycho Shift.
 */
.macro TryPsychoShift,jump_on_failure
    .word 0x9D
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Last Resort.
 */
.macro TryLastResort,jump_on_failure
    .word 0x9E
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Toxic Spikes.
 */
.macro TryToxicSpikes,jump_on_failure
    .word 0x9F
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Perform entry checks for Toxic Spikes for a battler.
 */
.macro CheckToxicSpikes,battler,jump_on_failure
    .word 0xA0
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Check if a given battler has an ability, accounting for Mold Breaker.
 */
.macro MoldBreakerAbilityCheck,mode,battler,ability,jump_to
    .word 0xA1, mode, battler, ability
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Checks if two battlers are on the same side.
 */
.macro CheckSameSide,mon1,mon2,jump_if_not_equal
    .word 0xA2, mon1, mon2
    .word ((jump_if_not_equal - org()) / 4) - 1
.endmacro

/*
 * Executes the end-of-battle Pickup routine.
 */
.macro PickupItem
    .word 0xA3
.endmacro

/*
 * Executes Trick Room.
 */
.macro TrickRoom
    .word 0xA4
.endmacro

/*
 * Checks if a battler's move is finished.
 */
.macro CheckMoveFinished,battler,jump_if_done
    .word 0xA5, battler
    .word ((jump_if_done - org()) / 4) - 1
.endmacro

/*
 * Evaluate the effect of a battler's held item.
 */
.macro CheckItemEffect,mode,battler,item_effect,jump_to
    .word 0xA6, mode, battler, item_effect
    .word ((jump_to - org()) / 4) - 1
.endmacro

/*
 * Get the hold effect of a battler's held item and store it in the given variable.
 */
.macro GetItemEffect,battler,var
    .word 0xA7, battler, var
.endmacro

/*
 * Get the effect power of a battler's held item and store it in the given variable.
 */
.macro GetItemPower,battler,var
    .word 0xA8, battler, var
.endmacro

/*
 * Try to execute Camouflage.
 */
.macro TryCamouflage,jump_on_failure
    .word 0xA9
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Execute Nature Power.
 */
.macro NaturePower
    .word 0xAA
.endmacro

/*
 * Execute Secret Power.
 */
.macro SecretPower
    .word 0xAB
.endmacro

/*
 * Try to execute Natural Gift.
 */
.macro TryNaturalGift,jump_on_failure
    .word 0xAC
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Try to execute Pluck.
 */
.macro TryPluck,jump_if_sticky_hold,jump_if_no_effect
    .word 0xAD
    .word ((jump_if_sticky_hold - org()) / 4) - 2
    .word ((jump_if_no_effect - org()) / 4) - 1
.endmacro

/*
 * Try to execute Fling.
 */
.macro TryFling,jump_on_failure
    .word 0xAE
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

YES_NO_BASIC            equ 0
YES_NO_FORGET_MOVE      equ 1
YES_NO_GIVE_UP_ON_MOVE  equ 2
YES_NO_NEXT_MON         equ 3
YES_NO_CHANGE_MON       equ 4
YES_NO_GIVE_NICKNAME    equ 5

/*
 * Show a Yes/No box of the given type.
 */
.macro YesNoBox,mode
    .word 0xAF, mode
.endmacro

/*
 * Wait for an input on a Yes/No box and jump to an address based on the input.
 */
.macro YesNoWait,jump_if_yes,jump_if_no
    .word 0xB0
    .word ((jump_if_yes - org()) / 4) - 2
    .word ((jump_if_no - org()) / 4) - 1
.endmacro

/*
 * Show the party list.
 */
.macro ShowPartyList
    .word 0xB1
.endmacro

/*
 * Wait for a party list input, jumping to the specified offset if CANCEL was
 * selected.
 */
.macro WaitPartyList,jump_if_canceled
    .word 0xB2
    .word ((jump_if_canceled - org()) / 4) - 1
.endmacro

/*
 * Set the battle result flag.
 */
.macro SetBattleResult
    .word 0xB3
.endmacro

/*
 * Check for Stealth Rock effects on entry for a battler.
 */
.macro CheckStealthRock,battler,jump_if_no_effect
    .word 0xB4, battler
    .word ((jump_if_no_effect - org()) / 4) - 1
.endmacro

/*
 * Check if a move's secondary effect should activate.
 */
.macro CheckSecondaryEffectActivation,jump_to_effect
    .word 0xB5
    .word ((jump_to_effect - org()) / 4) - 1
.endmacro

/*
 * Check if Chatter's secondary effect should activate.
 */
.macro CheckChatterActivation,jump_if_no_effect
    .word 0xB6
    .word ((jump_if_no_effect - org()) / 4) - 1
.endmacro

MOVE_PARAM_EFFECT           equ 0
MOVE_PARAM_PSS              equ 1
MOVE_PARAM_POWER            equ 2
MOVE_PARAM_TYPE             equ 3
MOVE_PARAM_HIT_RATE         equ 4
MOVE_PARAM_PP               equ 5
MOVE_PARAM_EFFECT_CHANCE    equ 6
MOVE_PARAM_RANGE            equ 7
MOVE_PARAM_PRIORITY         equ 8
MOVE_PARAM_FLAGS            equ 9
MOVE_PARAM_CONTEST_APPEAL   equ 10
MOVE_PARAM_CONTEST_TYPE     equ 11

/*
 * Get data about the current move, storing it in the VAR_CALC_WORK variable.
 */
.macro GetCurrentMoveData,move_param_id
    .word 0xB7, move_param_id
.endmacro

/*
 * Overlay a mosaic on the battler.
 */
.macro Mosaic,battler,phase,speed
    .word 0xB8, battler, phase, speed
.endmacro

/*
 * Change the form of a battler.
 */
.macro ChangeForm,battler
    .word 0xB9, battler
.endmacro

/*
 * Change the background of the battle interface.
 */
.macro ChangeBackground
    .word 0xBA
.endmacro

/*
 * Recover the status on a battler.
 */
.macro RecoverStatus,battler
    .word 0xBB
.endmacro

/*
 * Try to escape from a battle.
 */
.macro TryEscape,battler,jump_if_success
    .word 0xBC, battler
    .word ((jump_if_success - org()) / 4) - 1
.endmacro

/*
 * Show the ball gauge at the start of a fight.
 */
.macro ShowStartBallGauge,battler
    .word 0xBD, battler
.endmacro

/*
 * Hide the ball gauge at the start of a fight.
 */
.macro HideStartBallGauge,battler
    .word 0xBE, battler
.endmacro

/*
 * Show the ball gauge mid-fight.
 */
.macro ShowBallGauge,battler
    .word 0xBF, battler
.endmacro

/*
 * Hide the ball gauge mid-fight.
 */
.macro HideBallGauge,battler
    .word 0xC0, battler
.endmacro

/*
 * Load the graphics for the ball gauge.
 */
.macro LoadBallGaugeGraphics
    .word 0xC1
.endmacro

/*
 * Free the graphics for the ball gauge.
 */
.macro FreeBallGaugeGraphics
    .word 0xC2
.endmacro

CLIENT_TYPE_MINE        equ 0
CLIENT_TYPE_NOT_MINE    equ 1

/*
 * Increment game stats for a battler and client type.
 */
.macro IncGameStat,battler,client_type,stat_id
    .word 0xC3, battler, client_type, stat_id
.endmacro

/*
 * Transform back into the original mon for a battler. Useful for, e.g.,
 * Substitute.
 */
.macro TransformBack,battler
    .word 0xC4, battler
.endmacro

/*
 * Check for ability effects when a move connects.
 */
.macro CheckAbilityEffectOnHit,jump_if_no_effect
    .word 0xC5
    .word ((jump_if_no_effect - org()) / 4) - 1
.endmacro

/*
 * Convert a sprite to rendered OAM.
 */
.macro SpriteToOAM,battler
    .word 0xC6, battler
.endmacro

/*
 * Convert rendered OAM back to a sprite.
 */
.macro OAMToSprite,battler
    .word 0xC7, battler
.endmacro

/*
 * Check if there are no Pokemon left in the party to battle.
 */
.macro CheckWhiteOut,battler,jump_if_white_out
    .word 0xC8, battler
    .word ((jump_if_white_out - org()) / 4) - 1
.endmacro

/*
 * Try to execute Acupressure.
 */
.macro TryAcupressure,jump_on_failure
    .word 0xC9
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Remove the battler's held item.
 */
.macro RemoveItem,battler
    .word 0xCA, battler
.endmacro

/*
 * Try to execute Recycle.
 */
.macro TryRecycle,jump_if_no_item
    .word 0xCB
    .word ((jump_if_no_item - org()) / 4) - 1
.endmacro

/*
 * Check for item effects when a move connects.
 */
.macro CheckItemEffectOnHit,jump_if_no_effect
    .word 0xCC
    .word ((jump_if_no_effect - org()) / 4) - 1
.endmacro

/*
 * Show the battle result message. (Link battles)
 */
.macro BattleResultMessage
    .word 0xCD
.endmacro

/*
 * Show the escape message. (Link battles)
 */
.macro EscapeMessage
    .word 0xCE
.endmacro

/*
 * Show the give up message. (Link battles)
 */
.macro GiveUpMessage
    .word 0xCF
.endmacro

/*
 * Check if a battler should be left with 1 HP after damage (Focus Sash).
 */
.macro CheckLeaveWith1HP,battler
    .word 0xD0, battler
.endmacro

/*
 * Try to execute Natural Cure on a battler that is switching out.
 */
.macro TryNaturalCure,battler,jump_on_failure
    .word 0xD1, battler
    .word ((jump_on_failure - org()) / 4) - 1
.endmacro

/*
 * Check if a battler is behind Substitute.
 */
.macro CheckSubstitute,battler,jump_if_sub_active
    .word 0xD2, battler
    .word ((jump_if_sub_active - org()) / 4) - 1
.endmacro

/*
 * Check if any battler on the field has Cloud Nine.
 */
.macro CheckCloudNine,jump_if_active
    .word 0xD3
    .word ((jump_if_active - org()) / 4) - 1
.endmacro

/*
 * Get a random opponent for a battler.
 */
.macro GetRandomOpponent,battler
    .word 0xD4, battler
.endmacro

/*
 * Check for any item effects after U-turn (before switching out).
 */
.macro CheckUturnItemEffect,jump_if_no_effect
    .word 0xD5
    .word ((jump_if_no_effect - org()) / 4) - 1
.endmacro

/*
 * Swap a battler's sprite out for Substitute.
 */
.macro SwapToSubstituteSprite,battler
    .word 0xD6, battler
.endmacro

/*
 * Play the sound effects for the current move.
 */
.macro PlayMoveSoundEffect,battler
    .word 0xD7, battler
.endmacro

/*
 * Play a song in the background track.
 */
.macro PlayMusic,battler,bgm_id
    .word 0xD8, battler, bgm_id
.endmacro

/*
 * Check if the Safari game is done.
 */
.macro CheckSafariDone,jump_if_not_done
    .word 0xD9
    .word ((jump_if_not_done - org()) / 4) - 1
.endmacro

/*
 * Wait a specified number of frames.
 */
.macro WaitFrames,frames
    .word 0xDA, frames
.endmacro

/*
 * Check if the current move is of the given type. (Unused)
 */
.macro CheckMoveIsType,type,jump_if_equal
    .word 0xDB, type
    .word ((jump_if_equal - org()) / 4) - 1
.endmacro

/*
 * Get data from the base stats for a given dex + form combination.
 *
 * Used by Arceus and Giratina.
 */
.macro GetBaseStatsData,dex_num,form_num,mon_param
    .word 0xDC, dex_num, form_num, mon_param
.endmacro

/*
 * Refresh the Pokemon data for a battler.
 */
.macro RefreshMonData,battler
    .word 0xDD, battler
.endmacro

.macro End
    .word 0xDE
.endmacro
