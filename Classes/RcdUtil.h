#ifndef __RCD_UTIL__
#define __RCD_UTIL__

#include "cocos2d.h"
using namespace cocos2d;

class RcdUtil
{
public:
	static CCArray* split(CCString* line, char delim);
	static void saveList(CCArray* list, char delim);
};

#endif
