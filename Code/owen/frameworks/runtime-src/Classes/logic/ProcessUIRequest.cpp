//
//  ProcessUIRequest.cpp
//  owen
//
//  Created by ff on 16/8/9.
//
//

#include "ClientLogic.h"
#include "LoginLogic.h"


void ClientLogic::ProcessUIRequest(void *pMsg)
{
    if (NULL == pMsg)
        return;
    
    E2LProtocol	eProtocol	= *((E2LProtocol*)pMsg);
    if (eProtocol >= e2l_max)
        return;
    //分发到各个协议的处理函数
    if (this->m_UI2LogicFunc[eProtocol] != NULL)
    {
        (this->*m_UI2LogicFunc[eProtocol])(pMsg);
    }
}

void ClientLogic::UIClickLogin(void *pMsg)
{
    LoginLogic::instance()->clickLogin();
}

void ClientLogic::UIClickUnconnected(void *pMsg)
{
    LoginLogic::instance()->clickUnconnected();
}