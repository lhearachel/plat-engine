#ifndef __BATTLE_SCIO_H
#define __BATTLE_SCIO_H

#include "typedefs.h"

enum ClientCommand {
    CLIENT_SHOW_ENC_EFFECTS = 1,
    CLIENT_POKEMON_ENC,
    CLIENT_POKEMON_ENC_SHOW,
    CLIENT_POKEMON_APPEAR,
	CLIENT_POKEMON_RETURN,
    CLIENT_POKEMON_EAT_ITEM,
    CLIENT_POKEMON_DELETE,
    CLIENT_TRAINER_ENC,
    CLIENT_TRAINER_THROW,
    CLIENT_TRAINER_OUT,                 // 10
    CLIENT_TRAINER_IN,
    CLIENT_HP_GAUGE_IN,
    CLIENT_HP_GAUGE_OUT,
    CLIENT_SELECT_COMMAND,
    CLIENT_SELECT_MOVE,
    CLIENT_SELECT_TARGET,
    CLIETN_SELECT_ITEM,
    CLIENT_SELECT_POKEMON,
    CLIENT_SELECT_YES_NO,
    CLIENT_MESSAGE_ATTACK,              // 20
    CLIENT_MESSAGE,
    CLIENT_ATTACK_ANIMATION,
    CLIENT_POKEMON_BLINK,
    CLIENT_HP_GAUGE_CALC,
    CLIENT_EXP_GAUGE_CALC,
    CLIENT_FAINT,
    CLIENT_PLAY_SOUND,
    CLIENT_FADE_OUT,
    CLIENT_POKEMON_VANISH_TOGGLE,
    CLIENT_HP_GAUGE_SET_STATUS,         // 30
    CLIENT_MESSAGE_TRAINER,
    CLIENT_MESSAGE_CALL_BACK,
    CLIENT_MESSAGE_SEND_OUT,
    CLIENT_MESSAGE_ENCOUNTER,
    CLIENT_MESSAGE_ENCOUNTER_SEND_OUT,
    CLIENT_LEVEL_UP_EFFECT,
    CLIENT_MESSAGE_ALERT,
    CLIENT_HP_GAUGE_REFRESH,
    CLIENT_COPY_POKEMON_DATA,
    CLIENT_TRAINER_BG_SLIDE_IN,         // 40
    CLIENT_GAUGE_ANIMATION_STOP,
    CLIENT_POKEMON_REFRESH,
    CLIENT_MOVE_FORGET,
    CLIENT_MOSAIC_SET,
    CLIENT_FORM_CHANGE,
    CLIENT_BACKGROUND_CHANGE,
    CLIENT_SUB_BACKGROUND_PUT,
    CLIENT_BALL_GAUGE_ENCOUNTER_IN,
    CLIENT_BALL_GAUGE_ENCOUNTER_OUT,
    CLIENT_BALL_GAUGE_IN,               // 50
    CLIENT_BALL_GAUGE_OUT,
    CLIENT_BALL_GAUGE_RESOURCE_LOAD,
    CLIENT_BALL_GAUGE_RESOURCE_FREE,
    CLIENT_INC_RECORD,
    CLIENT_SIO_WAIT,
    CLIENT_CHR_POP,
    CLIENT_SS_TO_OAM_CALL,
    CLIENT_OAM_TO_SS_CALL,
    CLIENT_WIN_LOSE_MESSAGE,
    CLIENT_ESCAPE_MESSAGE,              // 60
    CLIENT_WHITE_OUT_MESSAGE,
    CLIENT_SUBSTITUTE_CHR_SET,
    CLIENT_MOVE_EFFECT_SOUND,
    CLIENT_PLAY_BGM,
    CLIENT_SET_WIN_LOSE,
    CLIENT_BLANK_MESSAGE,

    CLIENT_NUM_VANILLA_MESSAGES,

    // new commands here
    CLIENT_POPUP_RESOURCE_LOAD = CLIENT_NUM_VANILLA_MESSAGES,
    CLIENT_POPUP_RESOURCE_FREE,
    CLIENT_POPUP_IN,
    CLIENT_POPUP_OUT,                   // 70

    CLIENT_COMMAND_END
};

enum SCIOAccess {
    SCIO_SERVER = 0,
    SCIO_CLIENT,
    SCIO_SERVER_QUEUE
};

/**
 * Send a message for interfacing between the server and clients.
 * 
 * Original function: 0x02264A04 (overlay 16)
 * 
 * @param battle The battle structure.
 * @param access Who can access the message (server or client).
 * @param param  Either which client is responding to a message, which should receive the message,
 *               or which should be removed from the message queue.
 * @param data   Data buffer to be sent in the message.
 * @param size   Size of the data buffer.
 */
void __attribute__((long_call)) SCIO_Message(void *battle, int access, int param, void *data, u8 size);

/**
 * Clear an element from the message queue.
 * 
 * Original function: 0x02266ABC (overlay 16)
 * 
 * @param battle        The battle structure.
 * @param sendingClient The requesting client.
 * @param index         The index of the element to be cleared.
 */
void __attribute__((long_call)) SCIO_ClearQueue(void *battle, int sendingClient, int clientCommand);

#endif // __BATTLE_SCIO_H