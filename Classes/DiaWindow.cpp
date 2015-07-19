#include "DiaWindow.h"
#include "AppMacros.h"

//update:2014-9-30 11:56:25

bool DiaWindow::init()
{
	initSprite();
	return true;
}

void DiaWindow::initSprite()
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	//对话框
	dialogBox = CCSprite::create(DIAWINDOW_IMG_PATH);
	dialogBox->setTag(DIABOXSP);
    addChild(dialogBox);
    
    //内容
    content = CCLabelTTF::create();
    content->setTag(CONTENTSP);
    //content->setDimensions(CCSizeMake(450,120));
    content->setHorizontalAlignment(kCCTextAlignmentLeft);
	content->setFontName("微软简标宋");
	content->setFontSize(20);
    dialogBox->addChild(content);
	CCPoint dBase=ccp(dialogBox->getContentSize().width/2,
		dialogBox->getContentSize().height/2);
	content->setPosition(dBase);

	this->setVisible(false);
	this->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2,
		dialogBox->getContentSize().height/2));
}

void DiaWindow::load(CCArray* dialog)
{
    this->dialog=dialog;
    nNext=0;
    nStr=dialog->count();
}

void DiaWindow::appear()
{
	this->setVisible(true);
}

void DiaWindow::disappear()
{
	this->setVisible(false);
}

void DiaWindow::respond()
{
	if(nNext==0)
		appear();
	if(nNext==nStr)
	{
		disappear();
		controllerListener->endRespond();
		nNext++;
		return;
	}
	CCString* str=(CCString*)dialog->objectAtIndex(nNext);
	content->setString(str->getCString());
	nNext++;
}

bool DiaWindow::hasTouchEnded()
{
	return nNext>nStr;
}
