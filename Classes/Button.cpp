#include "Button.h"

//update£º2014-9-26 01:58:37

bool Button::init()
{
	initSprite();
	enable=true;disaDistr=0;
	setControllerListener(NULL);
	return true;
}

void Button::initSprite()
{
	//buttonImg=Sprite::create
	//addChild(buttonImg);
}

CCSprite* Button::getSprite()
{
	return buttonImg;
}

void Button::ccTouchesMoved(CCSet* pTouches, CCEvent *pEvent)
{
	ccTouchesBegan(pTouches,pEvent);
}

void Button::ccTouchesEnded(CCSet* pTouches, CCEvent *pEvent)
{
	controllerListener->endRespond();
}

CCRect Button::getBoundingBox()
{
	CCSize spriteSize=buttonImg->getContentSize();
	CCPoint entityPos=this->getPosition();

	return CCRectMake(
		entityPos.x-spriteSize.width/2,
		entityPos.y-spriteSize.height/2,
		spriteSize.width,
		spriteSize.height);
}

CCPoint Button::getTouchPos(CCSet* pTouches)
{
	CCTouch* touch=(CCTouch*)pTouches->anyObject();
	return CCDirector::sharedDirector()->convertToUI(
		touch->getLocationInView());
}

int Button::getDisaDistr()
{
	return disaDistr;
}
