#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "libs.h"

std::string gen_uuid()
{
	//����100000�ڵ������
	int num = 10000 + rand()%90000;
	printf("rand num:%6d\n", num);
	time_t second;
	time(&second);
	//��ȡ��ǰʱ��
	struct tm *p = localtime(&second);
	char buf[100] = {0};
	sprintf(buf, "%d-%d-%d-%d:%d:%d-%06d", 1900+p->tm_year, 1+p->tm_mon, p->tm_mday,
		p->tm_hour, p->tm_min, p->tm_sec, num);  //��ʽ��ʱ���������ַ����������buf��
	printf("guid:%s\n", buf);  //���guid������̨
	return buf;
}


std::string encode(const std::string& str)
{
	std::string strIn = str;
	std::string strOut;
	// aes ����
	coAesEncript(strIn, strOut);
	// base64
	coBase64Encode(strIn, strOut);
	return strIn;
}

std::string decode(const std::string& str)
{
	std::string strIn = str;
	std::string strOut;
	// base64
	coBase64Decode(strOut, strIn);
	// aes ����
	coAesDecript(strOut, strIn);
	return strIn;
}