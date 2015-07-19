#include "RcdUtil.h"
#include "AppMacros.h"
#include "StringUtil.h"

CCArray* RcdUtil::split(CCString* line, char delim)
{
	return StringUtil::sharedStrUtil()->split(line->getCString(), ",");
}

void RcdUtil::saveList(CCArray* list, char delim)
{
	CCString str;
	std::string rcd = str.m_sString;
	for(int i=0;i<list->count();i++)
	{
		CCString* elem=(CCString*)list->objectAtIndex(i);
		rcd+=elem->m_sString; rcd+=delim;
	}
	CCUserDefault::sharedUserDefault()->setStringForKey(EVENTDONE_MRCD,rcd.c_str());
}
