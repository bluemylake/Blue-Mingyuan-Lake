#include "DirButton.h"

//update:2014-9-30 11:52:21

bool DirButton::init()
{
	return Button::init();
}

void DirButton::ccTouchesBegan(CCSet* pTouches, CCEvent *pEvent)
{
	if(!enable)return;

	CCPoint TouchesLocation = getTouchPos(pTouches);
	if(!getBoundingBox().containsPoint(TouchesLocation))return;

	int targetDirection;
	if (TouchesLocation.y<TouchesLocation.x)
		if(TouchesLocation.y>buttonImg->getContentSize().width-TouchesLocation.x)targetDirection=Right;
		else targetDirection=Down;
	else 
		if(TouchesLocation.y>buttonImg->getContentSize().width-TouchesLocation.x)targetDirection=Up;
		else targetDirection=Left;

	controllerListener->respond(targetDirection);
}

void DirButton::initSprite()
{
	this->buttonImg=CCSprite::create(DIRBUTTON_IMG_PATH);
	buttonImg->setTag(IMGSP);
	addChild(buttonImg);
}
