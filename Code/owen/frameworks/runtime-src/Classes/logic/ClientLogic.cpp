//
//  ClientLogic.cpp
//  owen
//
//  Created by ff on 16/8/9.
//
//

#include "ClientLogic.h"
#include "view/UIManager.h"
#include "service/ServiceManager.h"

ClientLogic::ClientLogic()
{
    m_eLastState = GAME_STATE_INIT;
    m_eState = GAME_STATE_INIT;
    
    memset(m_UI2LogicFunc, 0, sizeof(m_UI2LogicFunc));
    memset(m_LogicStateFunc, 0, sizeof(m_LogicStateFunc));
    
    m_UI2LogicFunc[e2l_login_click] = &ClientLogic::UIClickLogin;
    m_UI2LogicFunc[e2L_unconnected_click] = &ClientLogic::UIClickUnconnected;

    m_Service2ClientFunc[s2c_check_connect] = &ClientLogic::ResCheckConnect;
    m_LogicStateFunc[GAME_STATE_INIT] = &ClientLogic::onStateInit;
}

void ClientLogic::mainLoop(float dt)
{
    if (this->m_LogicStateFunc[m_eState] == nullptr) {
        return;
    }
    (this->*m_LogicStateFunc[m_eState])(dt);
}

//改变游戏状态
void ClientLogic::ChangeState(E_GAME_STATE eState)
{
    if(m_eState == eState)
        return;
    exitGameMode(m_eState);
    m_eLastState	= m_eState;
    m_eState		= eState;
    enterGameMode(eState);
}

//进入游戏状态前的准备处理
bool ClientLogic::enterGameMode(E_GAME_STATE next)
{
    switch(next)
    {
        case GAME_STATE_LOGIN:
        {
            C2S_CHECK_CONNECT info;
            info.eProtocol = c2s_check_connect;
            pass2Service(&info);
        }
            break;
        default:
            break;
    }
    return true;
}

//离开游戏状态的结束处理
void ClientLogic::exitGameMode(E_GAME_STATE currMode)
{
    switch (currMode) {
            
        default:
            break;
    }
}

//发送结构体通知给显示层
void ClientLogic::pass2Engine(void *pMsg)
{
    UIManager::instance()->processLogicResponse(pMsg);
}

void ClientLogic::pass2Service(void *pMsg)
{
    ServiceManager::instance()->processClientQuest(pMsg);
}

void ClientLogic::onStateInit(float dt)
{
    ChangeState(GAME_STATE_LOGIN);
}

void ClientLogic::ResCheckConnect(void *pMsg)
{
    S2C_CHECK_CONNECT info = *static_cast<S2C_CHECK_CONNECT*>(pMsg);
    L2E_SHOW_LOGIN L2Einfo;
    if (info.result) {
        L2Einfo.eProtocol = l2e_show_login;
    }else{
        L2Einfo.eProtocol = l2e_show_unconnected;
    }
    ClientLogic::instance()->pass2Engine(&L2Einfo);
}


