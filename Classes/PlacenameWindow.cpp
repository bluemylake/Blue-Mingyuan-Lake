#include "PlacenameWindow.h"
#include "AppMacros.h"

//update:2014-9-26 11:42:05

void PlacenameWindow::initSprite()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    //¶Ô»°¿ò
    dialogBox = CCSprite::create(RWINDOW_IMG_PATH);

    dialogBox->setOpacity(220);
    dialogBox->setTag(DIABOXSP);
    addChild(dialogBox);

    //ÄÚÈÝ
    content = CCLabelTTF::create();
    content->setTag(CONTENTSP);
    content->setHorizontalAlignment(kCCTextAlignmentLeft);
    content->setFontFillColor(ccc3(255,0,0),true);
    content->setFontSize(20);
    dialogBox->addChild(content,10);

    CCPoint base=ccp(CCDirector::sharedDirector()->getWinSize().width/2,
	    CCDirector::sharedDirector()->getWinSize().height/2);
    CCPoint dBase=ccp(dialogBox->getContentSize().width/2,
	    dialogBox->getContentSize().height/2);
    CCPoint diff=base-dBase;
    dialogBox->setPosition(ccp(-diff.x,diff.y));
    dialogBox->setOpacity(0);

	this->inAction=false;
}

void PlacenameWindow::load(CCTMXTiledMap* map,CCDictionary *properties)
{
    const CCString* placeID=properties->valueForKey("id");
    int dir=placeID->intValue();
    CCTMXObjectGroup* objGroup=map->objectGroupNamed(INFORMATION_GRP);
    if (objGroup)
    {
	CCDictionary *properties = objGroup->objectNamed(PLACENAMEID_OBJ);
	const CCString *name = properties->valueForKey(placeID->getCString());
	this->content->setString(name->getCString());
	CCPoint dBase=ccp(dialogBox->getContentSize().width/2,
		dialogBox->getContentSize().height/2);
	content->setPosition(dBase);
    }
}

void PlacenameWindow::appear()
{
	dialogBox->stopAllActions(); // don't know if this helps
	content->stopAllActions();
	dialogBox->setOpacity(255);
	content->setOpacity(255);

    CCFiniteTimeAction* in=CCFadeIn::create(0.5f);
    CCFiniteTimeAction* stay=CCDelayTime::create(2.0f);
    CCFiniteTimeAction* out=CCFadeOut::create(0.5f);
	CCCallFunc* reset=CCCallFunc::create(this,
			callfunc_selector(PlacenameWindow::setActionDone));
    CCAction* placenameAct;
	if(this->inAction) placenameAct=CCSequence::create(stay,out,reset,NULL);
	else placenameAct=CCSequence::create(in,stay,out,reset,NULL);

    CCAction* copyAct=(CCAction*)placenameAct->copy();
    dialogBox->runAction(placenameAct);
    content->runAction(copyAct);
	this->inAction=true;
}

void PlacenameWindow::nextMove()
{
}

void PlacenameWindow::disappear()
{
}

void PlacenameWindow::respond(int curPlaceID)
{
    if(curPlaceID!=prevPlaceID)
    {
	appear();
	prevPlaceID=curPlaceID;
    }
}

void PlacenameWindow::setActionDone()
{
	this->inAction=false;
}
