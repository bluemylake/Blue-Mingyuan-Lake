#ifndef __COMBATCTRL_H__
#define __COMBATCTRL_H__


#include "CombatScene.h"
#include "cocos2d.h"
#include "Player1.h"
#include "Enemy.h"
#include "Animation.h"
#include "CsvUtil.h"
//update:2014-10-1 16:10:48



class CombatCtrl : public cocos2d::CCLayer
{
public:
	virtual bool init();
	CREATE_FUNC(CombatCtrl);
	void initMenu1();
	void initMenu2();

	void firstChoose(CCObject *sender);
	void secondChoose(CCObject *sender);

	void useAbility(int abilityNum);
		void ccTouchesBegan(CCSet*pTouches,CCEvent*pEvent);
	void setPointers(Player1* player,Enemy* enemy,CCSprite *background);
	void popScene();

	CCLabelTTF *effectLabel;
private:
	CCMenu *menu1;
	CCMenu *menu2;
	int count;
	bool menu1Enable;
	bool menu2Enable;
	Player1* player;
	Enemy* enemy;
	CCSprite* background;
	
};

#endif /* defined(_________CombatScene__) */


