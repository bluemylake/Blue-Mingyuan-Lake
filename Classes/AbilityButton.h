#ifndef __ABILITY_BUTTON_H__
#define __ABILITY_BUTTON_H__
#include "cocos2d.h"
#include "cocos-ext.h"
#include "time.h"

USING_NS_CC;
USING_NS_CC_EXT; 

typedef enum{
	fire,
	water,
	wood,
	metal
}tagForButton;

class AbilityButton :public CCNode
{
public:
	CREATE_FUNC(AbilityButton);
public:
	virtual bool init();
	//创建按钮
	void CreateButton();
	//设置位置
	void setButtonPosition(CCPoint pos);
	//绑定事件
	void BindButtonEvent();
	//
	void fireTouchUpOutside(CCObject* pSender, CCControlEvent event);
	void waterTouchUpOutside(CCObject* pSender, CCControlEvent event);
	void woodTouchUpOutside(CCObject* pSender, CCControlEvent event);
	//锁定触摸
	void LockButtonTouch();
	//解锁触摸
	void UnlockButtonTouch();
	//刷新技能伤害
	void updateDamage(int level);
	//获取伤害值
	int getDamageByTag(int tag);
	bool isTouch;
	int tag;
	int fireDamage,waterDamage,woodDamage;
private:
	CCControlButton* fireBtn; 
	CCControlButton* waterBtn; 
	CCControlButton* woodBtn; 
	CCLabelTTF *firetitle;
	CCLabelTTF *watertitle;
	CCLabelTTF *woodtitle;
};
#endif