#ifndef _GLOBAL_TMP_H_
#define _GLOBAL_TMP_H_
#include "Singleton.hpp"

class GlobalTmp
{
public:
	CCArray* arrForReloads;
};
typedef Singleton<GlobalTmp> sGlobalTmp;
#define tGlobal sGlobalTmp::instance()
#endif
