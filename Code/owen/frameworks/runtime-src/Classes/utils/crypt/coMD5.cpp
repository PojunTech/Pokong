#include "base/MD5.h"
#include "coMD5.h"

//////////////////////////////////////////////////////////////////////////
// ת��
std::string coMD5(const std::string& str)
{
	MD5 md5 = MD5(str);
	return md5.hexdigest();
}