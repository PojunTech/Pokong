//
//  UIManager.cpp
//  owen
//
//  Created by ff on 16/8/9.
//
//

#include "UIManager.h"
#include "logic/ClientLogic.h"
#include "EventDefine.h"
#include "scene/LoginScene.h"

UIManager::UIManager()
{
    memset(m_Logic2EngineFunc, 0, sizeof(m_Logic2EngineFunc));
    m_Logic2EngineFunc[l2e_show_login] = &UIManager::showLogin;
    m_Logic2EngineFunc[l2e_show_unconnected] = &UIManager::showLogin;
}

void UIManager::loop(float dt)
{
    ClientLogic::instance()->mainLoop(dt);
}

void UIManager::processLogicResponse(void *pMsg)
{
    if (NULL == pMsg)
        return;
    
    L2EProtocol	eProtocol	= *((L2EProtocol*)pMsg);
    if (eProtocol >= l2e_max)
        return;
    if (this->m_Logic2EngineFunc[eProtocol] != NULL)
    {
        (this->*m_Logic2EngineFunc[eProtocol])(pMsg);
    }
}

void UIManager::showLogin(void *pMsg)
{
    L2E_SHOW_LOGIN &info = *static_cast<L2E_SHOW_LOGIN*>(pMsg);
    auto scene = LoginScene::create();
    cocos2d::Director::getInstance()->runWithScene(scene);
    scene->createLayer(info);
}
