#include "TurningMan.h"

bool TurningMan::init()
{
	return true;
}

TurningMan* TurningMan::create(int picNo,int id)
{
	TurningMan* man=create();
	man->picNo=picNo;
	man->setID(id);
	man->initSprite();
	man->initAnim(0);
	man->goWalking(0);
	return man;
}

void TurningMan::respond(int dir)
{
	setFaceDirection(dir);
	sprite->stopAllActions();
}

void TurningMan::endRespond()
{
	sprite->resumeSchedulerAndActions();
}




void TurningMan::initAnim(int dir)
{
	char addr[20]=MAN_IMG_PATH;
	IntToAddrForPNG(addr,MAN_PATH_LEN,picNo);
	CCTexture2D* HumanEntityTexture=CCTextureCache::sharedTextureCache()->addImage(addr);
	
	CCSpriteFrame* frame=new CCSpriteFrame;
	const int nFrames=4;float delay;
	CCArray* animFrames=CCArray::create();

	for(int i=0;i<nFrames+CCRANDOM_0_1()*6;i++)
	{
	    frame=CCSpriteFrame::createWithTexture(HumanEntityTexture,
		    cocos2d::CCRectMake(32*0,48*(int)(CCRANDOM_0_1()*4),32,48));
	    animFrames->addObject(frame);
	}
	delay=1.5f+CCRANDOM_0_1()*1;

	CCAnimation* animation=CCAnimation::createWithSpriteFrames(animFrames,delay);
	CCAnimate* anim=CCAnimate::create(animation);
	forever=CCRepeatForever::create(anim);
}

void TurningMan::goWalking(float dt)
{
	sprite->runAction(forever);
}
