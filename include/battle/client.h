#ifndef __BATTLE_CLIENT_H
#define __BATTLE_CLIENT_H

#include "ui/common.h"
#include "ui/window.h"

struct Gauge {
    u8  seqNum;

    struct CellActorSystem  *actorSys;
    struct CellActorSystem  *arrowActorSys;
    void                    *battle;
    void                    *taskControl;
    struct Window           nameWindow;

    u8  clientNum;
    u8  type;
    u8  selectedMonNum;
    u8  safariBallsLeft;

    s32 curHP;
    s32 maxHP;
    s32 damage;
    s32 hpWork;

    s32 curExp;
    s32 maxExp;
    s32 addExp;
    s32 expWork;

    u8  level;
    u8  gender;
    u8  status;
    u8  caughtBall;
    u8  commandCode;
    u8  inWait;
    u8  seWait;

    u8  dirInOut        :1,
        effectWaitInOut :1,
        effectWaitLvlUp :1,
        numMode         :1,
        _padding        :4;
    
    void    *sineTaskControl;
    u16     sineSeconds;
};

struct CursorState {
    s8 commandX;
    s8 commandY;

    s8 moveX;
    s8 moveY;

    s8 pokeX;
    s8 pokeY;
    s8 pokeType;

    u8 dummy[1];
};

struct ClientUI {
    TaskControlFunc selectCommand;
    TaskControlFunc selectMove;
    TaskControlFunc selectTarget;
    TaskControlFunc selectItem;
    TaskControlFunc selectPokemon;
    TaskControlFunc selectYesNo;
};

struct BattleClient {
    struct ClientUI         ui;
    struct CellActorSystem  *actorSys;
    void                    *trainerSprite;
    void                    *pokemonSprite;
    struct Window           *windows;
    struct Gauge            hpGauge;
    struct CursorState      cursorState;
    void                    *ballEffects;
    void                    *oamDrop;
    void                    *timeIcon;

    u8      commandBuffer[256];
    u8      clientNum;
    u8      clientType;
    u8      clientBoot;
    u8      bipFlag;

    void    *sineTaskControl;
    u16     sineSeconds;

    BOOL    substituteFlag;

    void    *archiveHandle;

    u8      clientBufferFlag;
    u8      dummy[3];
};

// ClientCommandReset
void __attribute__((long_call)) ClientCommand_Reset(struct BattleClient *client);

#endif