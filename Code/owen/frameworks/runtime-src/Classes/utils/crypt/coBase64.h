#ifndef _coBase64_H_
#define _coBase64_H_

#include <string>
// ����
void coBase64Decode(std::string& outs, const std::string& ins);
// ����
void coBase64Encode(std::string& outs, const std::string& ins);

#endif // _coBase64_H_