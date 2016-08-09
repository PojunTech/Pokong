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
    e2l_login_click,                                    //  �����¼����
    e2L_unconnected_click,                              //  ������������
    e2l_max
};

enum L2EProtocol
{
    l2e_show_login,                                     //  ��ʾ��¼����
    l2e_show_unconnected,                                //  ��ʾ��������ʾ
    l2e_max
};

typedef struct __L2E_SHOW_LOGIN
{
    L2EProtocol                 eProtocol;
}L2E_SHOW_LOGIN;//  ��ʾ��¼�����������

typedef struct __E2L_CLICK_LOGIN
{
    E2LProtocol                 eProtocol;
}E2L_CLICK_LOGIN;//  �����¼�����������
#endif /* ELProtocol_h */
