//
//  ProcessServerResponse.cpp
//  owen
//
//  Created by ff on 16/8/9.
//
//

#include "ClientLogic.h"

void ClientLogic::ProcessServiceResponse(void *pMsg)
{
    if (NULL == pMsg)
        return;
    
    S2CProtocol	eProtocol	= *((S2CProtocol*)pMsg);
    if (eProtocol >= s2c_max)
        return;
    //�ַ�������Э��Ĵ�����
    if (this->m_Service2ClientFunc[eProtocol] != NULL)
    {
        (this->*m_Service2ClientFunc[eProtocol])(pMsg);
    }
}