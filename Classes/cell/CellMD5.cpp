#include "CellMD5.h"

#ifndef MD5_QUICK

#include <iostream>

extern "C" {
#include "md5/md5.h"
}

CellMD5* CellMD5::s_cellMd5 = nullptr ;

CellMD5* CellMD5::getInstance()
{
	if (!s_cellMd5)
	{
		s_cellMd5 = new CellMD5() ;
	}

	return s_cellMd5 ;
}

const std::string CellMD5::MD5File(const char* path)
{
	Data data = FileUtils::getInstance()->getDataFromFile(path) ;
	return MD5String(data.getBytes(), data.getSize()) ;
}

const std::string CellMD5::MD5String(unsigned char* str, size_t str_size)
{
	md5_state_t state ;
	md5_byte_t digest[MD5_BUFFER_LENGTH] ;
	char hex_output[MD5_BUFFER_LENGTH*2 + 1] ;

	md5_init(&state) ;

	md5_append(&state, (const md5_byte_t*) str, str_size) ;

	//    int t_size = 0 ;
	//    
	//    for (int i = 0; i <= buf_size, t_size <= str_size; i++) {
	//        
	//    }

	md5_finish(&state, digest) ;

	for (int di = 0; di < 16; ++di) {
		sprintf(hex_output + di * 2, "%02x", digest[di]) ;
	}

	hex_output[16*2] = 0 ;

	return std::string(hex_output) ;
}
#endif