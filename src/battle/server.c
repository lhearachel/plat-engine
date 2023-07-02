#include "global.h"

#include "battle/common.h"
#include "battle/server.h"

#include "archive.h"
#include "moves.h"
#include "constants/item_hold_effects.h"

#if 0

static BOOL Server_CheckHitForMoveEffect(struct Battle *battle, struct BattleServer *server, int attacker, int defender, int moveID)
{
    // Charging moves do not check accuracy on their first turn
    if (server->serverStatusFlag & SERVER_STATUS_FLAG_TURN_ONE_OF_TWO) {
        return FALSE;
    }

    // if ((server->stFX[defender].protected)
    //         && (server->moveTable[moveID].flag & 0x02)) {
    //     if ((moveID != ))
    // }
}

// ST_ServerHukitobasiCheck
// https://bulbapedia.bulbagarden.net/wiki/Whirlwind_(move)
// https://bulbapedia.bulbagarden.net/wiki/Roar_(move)
static BOOL Server_CheckWhirlwind(struct Battle *battle, struct BattleServer *server)
{
    return (
            // In Trainer battles, Whirlwind will now succeed if it hits, regardless of either Pokémon's level.
            (Battle_FightType(battle) & BATTLE_TYPE_TRAINER)
            // In wild Pokémon battles, Whirlwind will now always fail if the user's level is less than the target's.
        ||  (server->activePokemon[server->attacker].level >= server->activePokemon[server->defender].level)
    );
}

enum PokeConditionCheck {
    CONDITION_CHECK_INGRAIN,        // no changes
    CONDITION_CHECK_AQUA_RING,      // no changes
    CONDITION_CHECK_ABILITY,        // Speed Boost, Shed Skin (separate function)
    CONDITION_CHECK_BERRY,          // separate function: restore HP, restore % HP, restore status, restore PP, pinch boosts, herbs (NOT Custap Berry)
    CONDITION_CHECK_LEFTOVERS,      // separate function; also black sludge
    CONDITION_CHECK_LEECH_SEED,     // no changes
    CONDITION_CHECK_POISON,         // no changes (here)
    CONDITION_CHECK_TOXIC,          // no changes
    CONDITION_CHECK_BURN,           // no changes (here)
    CONDITION_CHECK_NIGHTMARE,      // no changes (here)
    CONDITION_CHECK_CURSE,          // no changes (here)
    CONDITION_CHECK_TRAPPED,        // need to hook on this one to change the damage amount (and account for Binding Band)
    CONDITION_CHECK_BAD_DREAMS,     // no changes
    CONDITION_CHECK_UPROAR,         // script change to last exactly 3 turns
    CONDITION_CHECK_THRASH,         // hook here to account for missing on the final turn and still get confused
    CONDITION_CHECK_DISABLE,
    CONDITION_CHECK_ENCORE,
    CONDITION_CHECK_LOCK_ON,
    CONDITION_CHECK_GRAVITY,
    CONDITION_CHECK_TAUNT,
    CONDITION_CHECK_MAGNET_RISE,
    CONDITION_CHECK_HEAL_BLOCK,
    CONDITION_CHECK_EMBARGO,
    CONDITION_CHECK_YAWN,
    CONDITION_CHECK_STATUS_ORB,
    CONDITION_CHECK_STICKY_BARB,
    CONDITION_CHECK_END
};

#define CONDITION_V_CLAMPED_DEC 0x00002000

// Hook this into branch_224d394 and branch down to Function_224d972 when done
// r0 = server, r1 = client
// server is at 0x10 on the stack
// client comes in as r5?
static u8 Server_ClampDamage(struct BattleServer *server, int client)
{
    if ((server->activePokemon[client].condition2 & CONDITION_V_CLAMPED)
        && (server->activePokemon[client].curHP != 0)) {
        // TODO: Figure out how to make this support 7 total turns for Grip Claw
        // Reduce the turn count by 1
        server->activePokemon[client].condition2 -= CONDITION_V_CLAMPED_DEC;

        // If still bound, deal damage; else, call the cleanup subscript
        if (server->activePokemon[client].condition2 & CONDITION_V_CLAMPED) {
            int divFactor = 8;
            // ST_ServerSoubiEqpGet
            if (Server_HeldItemEffect(server, client) == HOLD_EFFECT_INCREASE_TRAPPING_DAMAGE) {
                divFactor = 6;
            }

            server->hpCalcWork = Server_Divide(server->activePokemon[client].maxHP * -1, divFactor);
            // ST_ServerSequenceLoad
            Server_LoadSequence(server, ARC_SUBSCR, SUBSCR_CLAMP_DAMAGE);
        } else {
            Server_LoadSequence(server, ARC_SUBSCR, SUBSCR_CLAMP_END);
        }
        
        server->moveWork      = server->activePokemon[client].moveEffects.bindingMove;
        server->clientWork    = client;
        server->serverSeqNext = server->serverSeqNum;
        server->serverSeqNum  = 21;     // TODO: Constant

        return 1;
    }

    return 0;
}

#endif
