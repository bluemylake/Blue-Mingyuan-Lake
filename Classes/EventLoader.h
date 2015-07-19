#ifndef _EVNET_LOADER_H_
#define _EVNET_LOADER_H_
#include "cocos2d.h"
#include "Event.h"
#include "FileLoadUtil.h"
#include "StringUtil.h"
using namespace cocos2d;

class EventLoader
{
public:
   static CCArray* start(const char* sFilePath);
};
#endif
