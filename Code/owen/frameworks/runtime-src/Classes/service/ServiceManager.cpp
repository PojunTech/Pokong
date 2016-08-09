//
//  SericeManager.cpp
//  owen
//
//  Created by ff on 16/8/9.
//
//

#include "ServiceManager.h"
#include "logic/ClientLogic.h"

ServiceManager::ServiceManager()
{
    memset(m_Client2ServiceFunc, 0, sizeof(m_Client2ServiceFunc));
    
    m_Client2ServiceFunc[c2s_check_connect] = &ServiceManager::checkConnect;
    m_Client2ServiceFunc[c2s_exit_app] = &ServiceManager::exitApp;
}

void ServiceManager::processClientQuest(void *pMsg)
{
    if (NULL == pMsg)
        return;
    
    C2SProtocol	eProtocol	= *((C2SProtocol*)pMsg);
    if (eProtocol >= c2s_max)
        return;
    if (this->m_Client2ServiceFunc[eProtocol] != NULL)
    {
        (this->*m_Client2ServiceFunc[eProtocol])(pMsg);
    }
}

void ServiceManager::checkConnect(void *pMsg)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    S2C_CHECK_CONNECT info;
    info.eProtocol = s2c_check_connect;
    info.result= false;
    ClientLogic::instance()->ProcessServiceResponse(&info);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#endif
}

void ServiceManager::exitApp(void *pMsg)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    exit(0);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    PayService::exitAndroidGame();
#endif

}
