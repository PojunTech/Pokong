//
//  CSProtocol.h
//  owen
//
//  Created by ff on 16/8/9.
//
//

#ifndef CSProtocol_h
#define CSProtocol_h

enum C2SProtocol
{
    c2s_check_connect,              //  �������Ƿ�����
    c2s_exit_app,                   //  ����ر�Ӧ��
    c2s_recharge,                   //  ��ֵ����
    c2s_cash_benefit_code,          //  �ȼý�ҽ�
    c2s_link_to_netgame,            //  ��ת��ҳ
    c2s_share,                      //  ����
    c2s_max
};

enum S2CProtocol
{
    s2c_check_connect,              //  ��������״̬
    s2c_recharge,                   //  ��ֵ���
    s2c_cash_benefit_code,          //  �ҽ����
    s2c_share,                      //  ������
    s2c_max
};

typedef struct __C2S_CHECK_CONNECT
{
    C2SProtocol                     eProtocol;
}C2S_CHECK_CONNECT;//  �������Ƿ�����

typedef struct __S2C_CHECK_CONNECT
{
    S2CProtocol                     eProtocol;
    bool                            result;
}S2C_CHECK_CONNECT;//  ��������״̬

typedef struct __C2S_EXIT_APP
{
    C2SProtocol                     eProtocol;
}C2S_EXIT_APP;//  ����ر�Ӧ��
#endif /* CSProtocol_h */
