#ifndef _LibsHeader_H_
#define _LibsHeader_H_

#include "crypt/cryptHeader.h"
//#include "curl/coHttp.h"
//#include "coValue.h"
//#include "Convert.h"
//#include "PacketAide.h"
//#include "Url.h"
//#include "JsonAide.h"

// ����uuid
std::string gen_uuid();

// ���ܽ���
std::string encode(const std::string& str);
std::string decode(const std::string& str);
#endif // _LibsHeader_H_
