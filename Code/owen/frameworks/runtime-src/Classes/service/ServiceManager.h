//
//  SericeManager.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef SericeManager_h
#define SericeManager_h

#include "utils/GameUtils.h"
#include "../../Share/Header/CSProtocol.h"

class ServiceManager : public Singleton<ServiceManager>
{
public:
    ServiceManager();
    
    void processClientQuest(void *pMsg);
    void (ServiceManager::*m_Client2ServiceFunc[c2s_max])(void *pMsg);
    
private:
    void checkConnect(void *pMsg);
    
    void exitApp(void *pMsg);
};

#endif /* SericeManager_h */
