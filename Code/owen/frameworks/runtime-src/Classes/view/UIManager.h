//
//  UIManager.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef UIManager_h
#define UIManager_h

#include "cocos2d.h"
#include "utils/GameUtils.h"
#include "../../Share/Header/ELProtocol.h"

class UIManager : public Singleton<UIManager>, public cocos2d::Ref
{
public:
    UIManager();
    
    void processLogicResponse(void *pMsg);
    void (UIManager::*m_Logic2EngineFunc[l2e_max])(void *pMsg);
    
    void loop(float dt);
private:
    void showLogin(void *pMsg);
};

#endif /* UIManager_h */
