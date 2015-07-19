//
//  CombatScene.h
//  血色明远湖
//
//  Created by Ring King on 14-4-22.
//
//

#ifndef _________CombatScene__
#define _________CombatScene__

#include "cocos2d.h"
#include "Player1.h"
#include "Enemy.h"
#include "CombatCtrl .h"
#include "Animation.h"
//update:2014-10-4 19:37:23

class Combat : public cocos2d::CCLayer
{
public:
    static cocos2d::CCScene* scene();
    CREATE_FUNC(Combat);
	virtual bool init();
   
	void initSprite();
    void initLabel();
	void show();

	void ScaleBlood(CCObject* character);
private:
    Player1* player;
	Enemy* enemy;
	CCSprite *background;
	CCSprite *pBlood;
	CCSprite *eBlood;
	CCLabelTTF *pBloodLabel;
	CCLabelTTF *eBloodLabel;
};

#endif /* defined(_________CombatScene__) */


