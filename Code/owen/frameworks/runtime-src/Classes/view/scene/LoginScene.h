//
//  LoginScene.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef LoginScene_h
#define LoginScene_h

#include "cocos2d.h"
#include "ELProtocol.h"

class LoginScene : public cocos2d::Scene
{
public:
    LoginScene();
    ~LoginScene();
    
    bool init();
    
    void createLayer(L2E_SHOW_LOGIN &info);
    
    CREATE_FUNC(LoginScene);
};

#endif /* LoginScene_h */
