#include "GlobalPath.h"
#include "AbilityButton.h"

using namespace cocos2d;

	
bool AbilityButton::init()
{
	srand(time(0));
	return true;
}

void AbilityButton::CreateButton()
{
	/* 正常状态下的按钮图片 */
	CCScale9Sprite* btnfire = CCScale9Sprite::create(FIRE_BTN_IMG_PATH);
	CCScale9Sprite* btnwater = CCScale9Sprite::create(WATER_BTN_IMG_PATH);
	CCScale9Sprite* btnwood = CCScale9Sprite::create(WOOD_BTN_IMG_PATH);
	/* 点击状态下的按钮图片 */  
    CCScale9Sprite* btnfireDown = CCScale9Sprite::create(FIRE_DOWN_BTN_IMG_PATH); 
	CCScale9Sprite* btnwaterDown = CCScale9Sprite::create(WATER_DOWN_BTN_IMG_PATH); 
	CCScale9Sprite* btnwoodDown = CCScale9Sprite::create(WOOD_DOWN_BTN_IMG_PATH); 
	/* 按钮标题 */  
	firetitle = CCLabelTTF::create("@@", "Marker Felt", 60);  
	watertitle = CCLabelTTF::create("@@", "Marker Felt", 60);  
	woodtitle = CCLabelTTF::create("@@", "Marker Felt", 60);  

//	fireBtn->setPreferredSize(CCSize(100, 100));
//	waterBtn->setPreferredSize(CCSize(100, 100));
//	woodBtn->setPreferredSize(CCSize(100, 100));
	/* 按钮的大小会根据标题自动调整 */
	fireBtn = CCControlButton::create(firetitle, btnfire);  
	waterBtn = CCControlButton::create(watertitle, btnwater); 
	woodBtn = CCControlButton::create(woodtitle, btnwood); 
	/* 设置按钮按下时的图片 */  
	fireBtn->setBackgroundSpriteForState(btnfireDown, CCControlStateSelected);  
	waterBtn->setBackgroundSpriteForState(btnwaterDown, CCControlStateSelected);  
	woodBtn->setBackgroundSpriteForState(btnwoodDown, CCControlStateSelected);  
	
	this->addChild(fireBtn); 
	this->addChild(waterBtn); 
	this->addChild(woodBtn); 

	BindButtonEvent();
}

void AbilityButton::setButtonPosition(CCPoint pos)
{
	fireBtn->setPosition(ccp(pos.x,pos.y));  
	waterBtn->setPosition(ccp(pos.x+80,pos.y));  
	woodBtn->setPosition(ccp(pos.x+80*2,pos.y));  
}

void AbilityButton::BindButtonEvent()
{
	fireBtn->addTargetWithActionForControlEvents(this,cccontrol_selector(AbilityButton::fireTouchUpOutside),CCControlEventTouchUpInside);
	waterBtn->addTargetWithActionForControlEvents(this,cccontrol_selector(AbilityButton::waterTouchUpOutside),CCControlEventTouchUpInside);
	woodBtn->addTargetWithActionForControlEvents(this,cccontrol_selector(AbilityButton::woodTouchUpOutside),CCControlEventTouchUpInside);
}

void AbilityButton::LockButtonTouch()
{
	fireBtn->setTouchEnabled(false);
	waterBtn->setTouchEnabled(false);
	woodBtn->setTouchEnabled(false);
}

void AbilityButton::UnlockButtonTouch()
{
	fireBtn->setTouchEnabled(true);
	waterBtn->setTouchEnabled(true);
	woodBtn->setTouchEnabled(true);
}

void AbilityButton::fireTouchUpOutside(CCObject* pSender, CCControlEvent event)
{
	this->isTouch = true;
	tag = fire;
	CCLOG("fire");
}
void AbilityButton::waterTouchUpOutside(CCObject* pSender, CCControlEvent event)
{
	this->isTouch = true;
	tag = water;
}
void AbilityButton::woodTouchUpOutside(CCObject* pSender, CCControlEvent event)
{
	this->isTouch = true;
	tag = wood;
}

void AbilityButton::updateDamage(int level)
{

	//刷新伤害算法
	fireDamage = (int)(CCRANDOM_0_1()*(40+level));
	waterDamage = (int)(CCRANDOM_0_1()*(40+level));
	woodDamage = (int)(CCRANDOM_0_1()*(40+level));
	//label显示
	char fireDamageString[10];
	char waterDamageString[10];
	char woodDamageString[10];
	sprintf(fireDamageString,"%d",fireDamage);
	sprintf(waterDamageString,"%d",waterDamage);
	sprintf(woodDamageString,"%d",woodDamage);
	firetitle->setString(fireDamageString);
	watertitle->setString(waterDamageString);
	woodtitle->setString(woodDamageString);
}

int AbilityButton::getDamageByTag(int tag)
{
	if (tag==fire)
		return fireDamage;
	else if (tag==water)
		return waterDamage;
	else if (tag==wood)
		return woodDamage;
	else
		return 0;
}
