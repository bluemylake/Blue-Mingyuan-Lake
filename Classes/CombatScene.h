#ifndef __COMBAT_SCENE_H__
#define __COMBAT_SCENE_H__

#include "cocos2d.h"
#include "Blood.h"
#include "CPlayer.h"
#include "Monster.h"
#include "AbilityButton.h"

using namespace cocos2d;

typedef enum{
	playerWin,
	monsterWin,
	drawTie
}chechResult;


class Combat : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
    // implement the "static node()" method manually
    CREATE_FUNC(Combat);
	virtual void update(float delta);
	int checkButtonTag(int playerTag,int monsterTag);
	int damageCompute(int winner);
	//刷新血条
	void updateBlood(int winnerNum,int damage);
	void checkGameOver();
private:
	CPlayer* cplayer;
	Monster* monster;
	Blood* playerblood;
	Blood* monsterblood;
	AbilityButton* playerbutton;
	AbilityButton* monsterbutton;
	int monsterButtonTag;

};

#endif // __Combat_SCENE_H__
