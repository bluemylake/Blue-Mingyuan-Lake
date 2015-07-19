#include "WalkingMan.h"

WalkingMan* WalkingMan::create(int picNo,int id)
{
	WalkingMan* man=WalkingMan::create();
	man->picNo=picNo;
	man->setID(id);
	man->initSprite();
	man->initAnimation();
	return man;
}

bool WalkingMan::init()
{
	cnt=0;
	return true;
}

void WalkingMan::respond(int dir)
{
	if(isWalking)return;
	setFaceDirection(dir);
	sprite->stopAllActions();
}

void WalkingMan::endRespond()
{
	sprite->resumeSchedulerAndActions();
}

void WalkingMan::setRoute(std::vector<CCPoint> route)
{
	this->route=route;
	CCSequence* seq=(CCSequence*)initAnim(route);
	forever=CCRepeatForever::create(seq); 
	goWalking(0);
}

void WalkingMan::walk(CCArray* theRoute)
{
	sprite->runAction(initAnim(VectorLoader::start(theRoute)));
}




void WalkingMan::goWalking(float dt)
{
	sprite->runAction(forever);
}

void WalkingMan::initAnimation()
{
	walkAnimations=new CCAnimation*[4];
	for(int i=0;i<4;i++)
		walkAnimations[i]=createAnimationForDirection(i);
}

//
CCAnimation* WalkingMan::createAnimationForDirection(int dirc)
{
	char addr[20]=MAN_IMG_PATH;
	IntToAddrForPNG(addr,MAN_PATH_LEN,picNo);
	CCTexture2D* HumanEntityTexture=CCTextureCache::sharedTextureCache()->addImage(addr);

	CCSpriteFrame* frame=new CCSpriteFrame;
	const int nFrames=4;float delay;
	CCArray* animFrames=CCArray::create();
	if(dirc>=0&&dirc<4)
	{
		for(int i=0;i<nFrames;i++)
		{
			frame=CCSpriteFrame::createWithTexture(HumanEntityTexture,cocos2d::CCRectMake(32*i,48*dirc,32,48));
			animFrames->addObject(frame);
		}
		frame=CCSpriteFrame::createWithTexture(HumanEntityTexture,cocos2d::CCRectMake(32*0,48*dirc,32,48));
		delay=0.1f;
	}
	else if(dirc==5)//@wait to be transfered to Event
	{
		for(int i=0;i<nFrames;i++)
		{
			frame=CCSpriteFrame::createWithTexture(HumanEntityTexture,cocos2d::CCRectMake(32*0,48*i,32,48));
			animFrames->addObject(frame);
		}
		delay=0.1f;
	}
	else CCLog("Unexpected direction sent to HumanEntity::initAnimationWithDirection(int)");
	CCAnimation* animation=CCAnimation::createWithSpriteFrames(animFrames,delay);
	animation->retain();
	return animation;
}

CCActionInterval* WalkingMan::initAnim(std::vector<CCPoint> route)
{
	CCArray* arr=CCArray::create();
	this->route=route;
	for(int i=0;i<route.size();i++)
	{
		int step=rGlobal->map->getTileSize().height;
		CCMoveBy* move=CCMoveBy::create(STD_WALK_DURATION*route[i].getLength(),
			route[i]*step);

		CCCallFunc* preS=CCCallFunc::create(this,callfunc_selector(WalkingMan::beforeStep));
		CCDelayTime* delay=CCDelayTime::create(1.0f);//@macro
		CCCallFunc* goMan=CCCallFunc::create(this,callfunc_selector(WalkingMan::go));
		CCCallFunc* postS=CCCallFunc::create(this,callfunc_selector(WalkingMan::afterStep));

		arr->addObject(preS); arr->addObject(delay); arr->addObject(goMan);
		arr->addObject(move); arr->addObject(postS);
	}
	CCSequence* sequence=CCSequence::create(arr);
	return sequence;
}

FaceDirection WalkingMan::getDirection(CCPoint vect)
{
	if(vect.x>0)return Right;
	else if(vect.x<0)return Left;
	else if(vect.y>0)return Up;
	else if(vect.y<0)return Down;
	else CCLog("WalkingMan::getDirection says,'Why should someone walk(0,0)?'");
	return Down;
}

void WalkingMan::beforeStep()
{
	dir=getDirection(route[cnt]);
	CCAnimate* walk=CCAnimate::create(walkAnimations[dir]);//行走
	manWalk=CCRepeatForever::create(walk);
	manWalk->retain();

	cnt++; if(cnt==route.size())cnt=0; 
}

void WalkingMan::go()
{
	isWalking=true;
	sprite->runAction(manWalk);
}

void WalkingMan::afterStep()
{
	isWalking=false;
	sprite->stopAction(manWalk);
	this->setFaceDirection(dir);
	manWalk->release();
}
