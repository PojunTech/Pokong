//
//  LoginScene.cpp
//  owen
//
//  Created by ff on 16/8/9.
//
//

#include "LoginScene.h"
#include "GameDefine.h"
#include "../layer/LoginLayer.h"
#include "../layer/NoNetLayer.h"

LoginScene::LoginScene()
{
    
}

LoginScene::~LoginScene()
{
    
}

bool LoginScene::init()
{
    if (!Scene::init()) {
        return false;
    }
    
    return true;
}

void LoginScene::createLayer(L2E_SHOW_LOGIN &info)
{
    if (info.eProtocol == l2e_show_login) {
        auto layer = LoginLayer::createCCBNodeAndAnmitionmanage(LOGIN_LAYER_CCB, LOGIN_LAYER_CCB);
        addChild(layer);
    }else if (info.eProtocol == l2e_show_unconnected) {
        auto layer = NoNetLayer::createCCBNodeAndAnmitionmanage(UNCONNET_LAYER_CCB, UNCONNET_LAYER_CCB);
        addChild(layer);
    }
}