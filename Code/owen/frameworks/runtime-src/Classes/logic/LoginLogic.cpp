//
//  LoginLogic.cpp
//  owen
//
//  Created by ff on 16/8/9.
//
//

#include "LoginLogic.h"
#include "ClientLogic.h"

void LoginLogic::clickUnconnected()
{
    C2S_EXIT_APP info;
    info.eProtocol = c2s_exit_app;
    ClientLogic::instance()->pass2Service(&info);
}

void LoginLogic::clickLogin()
{
    
}