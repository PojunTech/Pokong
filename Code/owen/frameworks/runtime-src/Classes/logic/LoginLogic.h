//
//  LoginLogic.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef LoginLogic_h
#define LoginLogic_h

#include "utils/GameUtils.h"
#include "../../Share/Header/ELProtocol.h"
#include "../../Share/Header/CSProtocol.h"

class LoginLogic : public Singleton<LoginLogic>
{
public:
    void clickUnconnected();
    void clickLogin();
};

#endif /* LoginLogic_h */
