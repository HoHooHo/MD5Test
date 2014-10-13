#pragma once

#ifndef MD5_QUICK

#include <string>

#include "cocos2d.h"

using namespace cocos2d ;

#define MD5_BUFFER_LENGTH 16

class CellMD5
{
public:
	static CellMD5* getInstance() ;

	const std::string MD5File(const char* path);
    
    
private:
	CellMD5(void) {}

	static CellMD5* s_cellMd5 ;


	const std::string MD5String(unsigned char* str, size_t str_size);
};
#endif