//
//  ClientLogic.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef ClientLogic_h
#define ClientLogic_h

#include "utils/GameUtils.h"
#include "../../Share/Header/ELProtocol.h"
#include "../../Share/Header/CSProtocol.h"

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

class ClientLogic : public Singleton<ClientLogic>
{
public:
    ClientLogic();
    
    void mainLoop(float dt);
    
    void (ClientLogic::*m_UI2LogicFunc[e2l_max])(void *pMsg);
    void (ClientLogic::*m_Service2ClientFunc[s2c_max])(void *pMsg);
    void (ClientLogic::*m_LogicStateFunc[GAME_STATE_MAX])(float dt);
    
    void ChangeState(E_GAME_STATE eState);
    
    //向显示层发送结构体消息
    void pass2Engine(void *pMsg);
    //处理显示层请求，实现见ProcessUIRequest.cpp
    void ProcessUIRequest(void *pMsg);
    
    //向服务层发送结构体消息
    void pass2Service(void *pMsg);
    //处理服务层响应，实现见ProcessServerResponse.cpp
    void ProcessServiceResponse(void *pMsg);
private:
    bool enterGameMode(E_GAME_STATE next);
    void exitGameMode(E_GAME_STATE currMode);
    void onStateInit(float dt);
    
    void UIClickLogin(void *pMsg);
    void UIClickUnconnected(void *pMsg);
    
    void ResCheckConnect(void *pMsg);
private:
    E_GAME_STATE m_eLastState;
    E_GAME_STATE m_eState;
    E_GAME_STATE cacheGameMode;

};

#endif /* ClientLogic_h */
