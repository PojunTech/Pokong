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
    c2s_check_connect,              //  请求检查是否联网
    c2s_exit_app,                   //  请求关闭应用
    c2s_recharge,                   //  充值请求
    c2s_cash_benefit_code,          //  救济金兑奖
    c2s_link_to_netgame,            //  跳转网页
    c2s_share,                      //  分享
    c2s_max
};

enum S2CProtocol
{
    s2c_check_connect,              //  返回联网状态
    s2c_recharge,                   //  充值结果
    s2c_cash_benefit_code,          //  兑奖结果
    s2c_share,                      //  分享结果
    s2c_max
};

typedef struct __C2S_CHECK_CONNECT
{
    C2SProtocol                     eProtocol;
}C2S_CHECK_CONNECT;//  请求检查是否联网

typedef struct __S2C_CHECK_CONNECT
{
    S2CProtocol                     eProtocol;
    bool                            result;
}S2C_CHECK_CONNECT;//  返回联网状态

typedef struct __C2S_EXIT_APP
{
    C2SProtocol                     eProtocol;
}C2S_EXIT_APP;//  请求关闭应用
#endif /* CSProtocol_h */
