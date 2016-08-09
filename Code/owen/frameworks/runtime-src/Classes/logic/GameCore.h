//
//  GameCore.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef GameCore_h
#define GameCore_h

#include "utils/GameUtils.h"
#include "../../Share/Header/ELProtocol.h"

enum E_GAME_STATE
{
    GAME_STATE_INIT,
    GAME_STATE_LOADLOGIN,
    GAME_STATE_LOGIN,
    GAME_STATE_HALL,
    GAME_STATE_GAME,
    GAME_STATE_LOAD_GAME,
    GAME_STATE_GOLDEN_DIFF,
    GAME_STATE_SEL_GOLDEN,
    GAME_STATE_GOLDEN_RUNNER,
    GAME_STATE_LOAD_GOLDEN,
    GAME_STATE_GOLDEN_GAME,
    GAME_STATE_IN_TOWN,
    GAME_STATE_IN_WORLD_MAP,
    GAME_STATE_BEGIN_EMBATTLE,
    GAME_STATE_BEGIN_BATTLE,
    GAME_STATE_IN_BATTLE,
    GAME_STATE_FINISH_BATTLE,
    GAME_STATE_MAX,
};

class GameCore : public Singleton<GameCore>
{
    
};


#endif /* GameCore_h */
