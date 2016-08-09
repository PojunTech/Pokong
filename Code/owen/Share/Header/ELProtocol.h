//
//  ELProtocol.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef ELProtocol_h
#define ELProtocol_h

enum E2LProtocol
{
    e2l_login_click,                                    //  点击登录界面
    e2L_unconnected_click,                              //  点击无网络界面
    e2l_max
};

enum L2EProtocol
{
    l2e_show_login,                                     //  显示登录界面
    l2e_show_unconnected,                                //  显示无网络提示
    l2e_max
};

typedef struct __L2E_SHOW_LOGIN
{
    L2EProtocol                 eProtocol;
}L2E_SHOW_LOGIN;//  显示登录或无网络界面

typedef struct __E2L_CLICK_LOGIN
{
    E2LProtocol                 eProtocol;
}E2L_CLICK_LOGIN;//  点击登录或无网络界面
#endif /* ELProtocol_h */
