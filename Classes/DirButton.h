#ifndef __DIR_BUTTON_H__
#define __DIR_BUTTON_H__
#include "cocos2d.h"
#include "Button.h"
using namespace cocos2d;

class DirButton: public Button
{
public:
	CREATE_FUNC(DirButton);
	virtual bool init();
	virtual void initSprite();
	virtual void ccTouchesBegan(CCSet* pTouches, CCEvent *pEvent);
};
	
#endif
