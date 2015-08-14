#ifndef __PMENU_H__
#define __PMENU_H__

#include "cocos2d.h"
#include "HelpScene.h"
#include "StaffScene.h"
USING_NS_CC;

class PMenu: public CCMenu
{
public:
	CREATE_FUNC(PMenu);
	bool init();
	void menuClearCallback(CCObject* pSender);
	void menuStaffCallback(CCObject* pSender);
	void menuInstructionCallback(CCObject* pSender);
	void menuBackCallback(CCObject* pSender);
};
#endif
