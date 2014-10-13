#pragma once

#ifdef MD5_QUICK

#include <string>

#include "cocos2d.h"

using namespace cocos2d ;

#define MD5_BUFFER_LENGTH 16

class QuickMD5
{
public:
	static QuickMD5* getInstance() ;

	const std::string MD5File(const char* path);
    
    
private:
	QuickMD5(void) {}
	char* bin2hex(unsigned char* bin, int binLength);

	static QuickMD5* s_quickMd5 ;


	/** @brief Calculate MD5, get MD5 code (not string) */
	void MD5(void* input, int inputLength,
		unsigned char* output);

	const std::string MD5String(void* input, int inputLength);
};
#endif