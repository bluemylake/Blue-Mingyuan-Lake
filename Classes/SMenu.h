#ifndef __SMENU_H__
#define __SMENU_H__


#include "cocos2d.h"

USING_NS_CC;

class SMenu: public CCMenu
{
public:
	CREATE_FUNC(SMenu);
	bool init();
	void menuStartCallback(CCObject* pSender);
	void menuMapCallback(CCObject* pSender);
	void menuSetCallback(CCObject* pSender);
	void menuQuitCallback(CCObject* pSender);
	CCArray* arr;
	~SMenu();
};
#endif
