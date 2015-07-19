#include "BigWindow.h"
#include "AppMacros.h"

//update:2014-9-27 14:29:59

void BigWindow::initSprite()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	this->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,
		CCDirector::sharedDirector()->getWinSize().height/2));

	//对话框
	dialogBox = CCSprite::create("bigwindow.png");
	//dialogBox->setContentSize(CCSizeMake(CCDirector::sharedDirector()->getWinSize().width/2,
		//CCDirector::sharedDirector()->getWinSize().height/2));
    dialogBox->setOpacity(220);
	dialogBox->setTag(DIABOXSP);
    addChild(dialogBox);

	//图片
	picture = CCSprite::create();
	dialogBox->addChild(picture);
	
    
    //题目
    label = CCLabelTTF::create();
    label->setTag(LABELSP);
	label->setFontName("Microsoft YaHei.fnt");
	label->setFontSize(25);
	label->setHorizontalAlignment(kCCTextAlignmentLeft);
    dialogBox->addChild(label);
    
    //内容
    content = CCLabelTTF::create();
    content->setTag(CONTENTSP);
    content->setDimensions(CCSizeMake(200,120));
    content->setHorizontalAlignment(kCCTextAlignmentLeft);
	content->setFontName("微软简标宋");
	content->setFontSize(15);
    dialogBox->addChild(content);

	dialogBox->setScaleX(0);
	picture->setPosition(ccp(-100,2000));
	label->setPosition(ccp(-300,50));
	content->setPosition(ccp(20,-500));
}

void BigWindow::load(CCTMXTiledMap* map,CCDictionary *properties)
{
	const CCString* title=properties->valueForKey("title");
	const CCString* content=properties->valueForKey("content");
	const CCString* image=properties->valueForKey("image");
	picture->initWithFile(image->getCString());
}

void BigWindow::appear()
{
	//dialogBox->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,
		//CCDirector::sharedDirector()->getWinSize().height/2));
	picture->setPosition(ccp(0,0));
	label->setPosition(ccp(-300,50));
	content->setPosition(ccp(20,-500));
	this->setScale(1.0f);
	const float duration=0.3f;
	float scaleX=CCDirector::sharedDirector()->getWinSize().width*3/4/dialogBox->getContentSize().width;
	float scaleY=CCDirector::sharedDirector()->getWinSize().height*3/4/dialogBox->getContentSize().height;
	dialogBox->setScaleX(0);
	dialogBox->setScaleY(0);
	CCFiniteTimeAction* diaAct=CCScaleTo::create(duration,scaleX,scaleY);
	CCFiniteTimeAction* callnxt=CCCallFunc::create(this,callfunc_selector(Window::nextMove));
	CCFiniteTimeAction* allAct=CCSequence::create(diaAct,callnxt,NULL);
	dialogBox->runAction(allAct);
}

void BigWindow::nextMove()
{
	this->setScale(1.0);
	const float duration=1.0f;
	CCAction* picAct=CCMoveTo::create(duration/2,ccp(0,130)+convertCoord(picture));
	CCAction* labAct=CCMoveTo::create(duration/2,ccp(-10,30)+convertCoord(label));
	CCAction* conAct=CCMoveTo::create(duration/2,ccp(70,5)+convertCoord(content));
	picture->runAction(picAct);
	label->runAction(labAct);
	content->runAction(conAct);
}

void BigWindow::disappear()
{
	const float duration=0.5f;
	CCAction* closeAct=CCScaleTo::create(duration,1,0);
	this->runAction(closeAct);
}

void BigWindow::respond(CCTMXTiledMap* map,CCDictionary *properties)
{
	disappear();
	endRespond();
}
