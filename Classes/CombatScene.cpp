#include "CombatScene.h"
USING_NS_CC;

#define LABEL_FONT "Heiti SC"

#define LEVEL_LBL "Lv:%d"
#define HEALTH_LBL "Hp:%d"
#define YOU_WIN_LBL "YOU WIN!"
#define YOU_LOSE_LBL "YOU LOSE"

#define ANIMATION_MSG "animation"
#define GAME_OVER_MSG "gameover"

CCScene* Combat::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::create();
	// 'layer' is an autorelease object
	Combat *layer = Combat::create();
	// add layer as a child to scene
	scene->addChild(layer);
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Combat::init()
{
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
	//
	this->setTag(COMBATLAYER);
	monsterType = 0; //initial 
	isPlayingAnimation = false;

	return true;
}

bool Combat::init(int monsterType)
{
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	//角色创建
	cplayer = CPlayer::create();
	cplayer->setPlayer();
	this->addChild(cplayer);
	monster = Monster::create();
	monster->setMonster(monsterType);


	this->addChild(monster);
	//血条创建
	playerblood = Blood::create();
	playerblood->setBloodSlider();
	playerblood->setSliderPosition(ccp(150,visibleSize.height-50));
	playerblood->setTotalBlood(cplayer->healthPoint);
	playerblood->setCurrentBlood(cplayer->currentHp);	
	monsterblood = Blood::create();
	monsterblood->setBloodSlider();
	monsterblood->setSliderPosition(ccp(visibleSize.width-150,visibleSize.height-50));
	monsterblood->setTotalBlood(monster->healthPoint);
	monsterblood->setCurrentBlood(monster->currentHp);
	this->addChild(playerblood);
	this->addChild(monsterblood);

	//等级与当前血量label
	/*等级*/
	char level[10],blood[10];
	sprintf(level,LEVEL_LBL,cplayer->level);
	plevelLabel = CCLabelTTF::create(level, LABEL_FONT,20);
	plevelLabel->setPosition(ccp(60,visibleSize.height-20));
	this->addChild(plevelLabel,2);
	sprintf(level,LEVEL_LBL,monster->level);
	mlevelLabel = CCLabelTTF::create(level, LEVEL_LBL,20);
	mlevelLabel->setPosition(ccp(visibleSize.width-60,visibleSize.height-20));
	this->addChild(mlevelLabel,2);
	/*血量*/
	sprintf(blood,HEALTH_LBL,cplayer->currentHp);
	pbloodLabel = CCLabelTTF::create(blood,LABEL_FONT,20);
	pbloodLabel->setPosition(ccp(240,visibleSize.height-20));
	this->addChild(pbloodLabel,2);
	sprintf(blood,HEALTH_LBL,monster->currentHp);
	mbloodLabel = CCLabelTTF::create(blood,LABEL_FONT,20);
	mbloodLabel->setPosition(ccp(visibleSize.width-240,visibleSize.height-20));
	this->addChild(mbloodLabel,2);



	//按钮创建
	playerbutton = AbilityButton::create();
	monsterbutton = AbilityButton::create();
	playerbutton->CreateButton();
	playerbutton->setButtonPosition(ccp(50,50));
	playerbutton->updateDamage(cplayer->level);
	monsterbutton->CreateButton();
	monsterbutton->setButtonPosition(ccp(420,50));
	monsterbutton->LockButtonTouch();
	monsterbutton->updateDamage(monster->level);
	this->addChild(playerbutton);
	this->addChild(monsterbutton);

	//游戏结束Label
	winLabel = CCLabelTTF::create(YOU_WIN_LBL, LABEL_FONT, 80);
	loseLabel = CCLabelTTF::create(YOU_LOSE_LBL, LABEL_FONT, 80);
	winLabel->setPosition(ccp(visibleSize.width/2-20,visibleSize.height/2+20));
	loseLabel->setPosition(ccp(visibleSize.width/2-20,visibleSize.height/2+20));
	winLabel->setVisible(false);
	loseLabel->setVisible(false);
	this->addChild(winLabel);
	this->addChild(loseLabel);

	//schedule监听，每帧刷新一次
	this->scheduleUpdate();

	//订阅播放动画的消息
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(Combat::playAnimation),ANIMATION_MSG,NULL);
	//订阅游戏结束
	CCNotificationCenter::sharedNotificationCenter()->addObserver(this,callfuncO_selector(Combat::gameOver),GAME_OVER_MSG,NULL);

	return true;
}

void Combat::setMonsterType(int monsterType)
{
	this->monsterType=monsterType;
	init(monsterType);
}



void Combat::update(float delta)
{
	if (playerbutton->isTouch==true&&isPlayingAnimation==false)
	{
		//锁定playerbutton触摸
		playerbutton->LockButtonTouch();
		//怪物选择button
		monsterButtonTag = monster->chooseButton();
		//判断属性胜负
		winnerNum = checkButtonTag(playerbutton->tag,monsterButtonTag);
		CCLOG("win:%d",winnerNum);
		//伤害计算
		damage = damageCompute(winnerNum);
		CCLOG("damage:%d",damage);
		//播放战斗动画
		//post消息
		CCNotificationCenter::sharedNotificationCenter()->postNotification(ANIMATION_MSG,NULL);
		//更新血条
		updateBlood(winnerNum,damage);
		playerbutton->isTouch=false;
		//判断是否结束
		checkGameOver();
	}
}

//判断双方选择属性的胜负
int Combat::checkButtonTag(int playerTag,int monsterTag)
{
	CCLOG("tag:%d  tag:%d",playerTag,monsterTag);
	//平局
	if (playerTag==monsterTag)
	{
		if(playerbutton->getDamageByTag(playerTag)>=monsterbutton->getDamageByTag(monsterTag))
			return playerWin;
		else
			return monsterWin;
	}
	else if ((playerTag==0&&monsterTag==2)||(playerTag==1&&monsterTag==0)||(playerTag==2&&monsterTag==1))
	{
		return playerWin;
	}
	else
	{
		return monsterWin;
	}
}

//伤害计算
int Combat::damageCompute(int winnerNum)
{
	int damage,pdamage,mdamage;
	//平局情况伤害为双方差值
	if (playerbutton->tag==monsterButtonTag)
	{
		pdamage = playerbutton->getDamageByTag(playerbutton->tag);
		mdamage = monsterbutton->getDamageByTag(monsterButtonTag);
		damage = abs(pdamage-mdamage);
	}
	//非平局情况伤害值
	else
	{
		if (winnerNum==playerWin)
		{
			damage = playerbutton->getDamageByTag(playerbutton->tag);
		}
		else if (winnerNum==monsterWin)
		{
			damage = monsterbutton->getDamageByTag(monsterButtonTag);
		}
	}
	return damage;
}

//刷新血条
void Combat::updateBlood(int winnerNum,int damage)
{
	if (winnerNum==playerWin)
	{
		monster->currentHp-=damage; 
		if(monster->currentHp<=0)
			monster->currentHp=0;
	}
	else
	{
		cplayer->currentHp-=damage;
		if(cplayer->currentHp<=0)
			cplayer->currentHp=0;
	}

	playerblood->setCurrentBlood(cplayer->currentHp);
	monsterblood->setCurrentBlood(monster->currentHp);
	char blood[10];
	sprintf(blood,HEALTH_LBL,cplayer->currentHp);
	pbloodLabel->setString(blood);
	sprintf(blood,HEALTH_LBL,monster->currentHp);
	mbloodLabel->setString(blood);
}
//判断游戏是否结束
void Combat::checkGameOver()
{
	if (cplayer->currentHp<=0)
	{
		gameWinner = 1;
		CCNotificationCenter::sharedNotificationCenter()->postNotification(GAME_OVER_MSG,NULL);

		CCLOG("monster win!");
	}
	else if (monster->currentHp<=0)
	{
		gameWinner = 0;
		CCNotificationCenter::sharedNotificationCenter()->postNotification(GAME_OVER_MSG,NULL);

		CCLOG("player win!");
		cplayer->exp++;
		sGlobal->playerState->exp = cplayer->exp;
	}
	else
	{
		//刷新一次button
		playerbutton->updateDamage(cplayer->level);
		monsterbutton->updateDamage(monster->level);
	}

}


void Combat::playAnimation(CCObject* psender)
{
	int pZorder,mZorder;
	isPlayingAnimation=true;
	animationDone = false;
	CCBlink* blk = CCBlink::create(0.5,3);
	CCSequence* pblink = CCSequence::create(CCDelayTime::create(1.2),blk,NULL);
	playerAttack = Particles::create();
	monsterAttack = Particles::create();
	if (playerbutton->tag==0)
	{
		playerAttack->setFireParticle();
		playerAttack->playerAttack();
	}
	if (playerbutton->tag==1)
	{
		playerAttack->setWaterParticle();
		playerAttack->playerAttack();
	}
	if (playerbutton->tag==2)
	{
		playerAttack->setWoodParticle();
		playerAttack->playerAttack();
	}
	//monster
	if (monsterButtonTag==0)
	{
		monsterAttack->setFireParticle();
		monsterAttack->monsterAttack();
	}
	if (monsterButtonTag==1)
	{
		monsterAttack->setWaterParticle();
		monsterAttack->monsterAttack();
	}
	if (monsterButtonTag==2)
	{
		monsterAttack->setWoodParticle();
		monsterAttack->monsterAttack();
	}

	if (winnerNum==1)
	{//monster win
		pZorder=1;
		mZorder=2;
		playerAttack->setParticleLife(0.5);
		cplayer->runAction(pblink);

	}
	else
	{
		pZorder=2;
		mZorder=1;
		monsterAttack->setParticleLife(0.5);
		monster->runAction(pblink);
	}


	CCSequence* seq = CCSequence::create(CCDelayTime::create(1.5),CCCallFunc::create(this,callfunc_selector(Combat::setSignal)),NULL);

	playerbutton->runAction(seq);

	addChild(playerAttack,pZorder);
	addChild(monsterAttack,mZorder);
}

void Combat::setSignal()
{
	isPlayingAnimation=false;
	//恢复按钮可触摸状态
	playerbutton->UnlockButtonTouch();
}

void Combat::gameOver(CCObject* psender)
{
	if (gameWinner==0)
	{
		winLabel->setVisible(true);

	}
	else
	{
		loseLabel->setVisible(true);
	}
	CCSequence* seq = CCSequence::create(CCDelayTime::create(3.5),CCCallFunc::create(this,callfunc_selector(Combat::popCombat)),NULL);
	playerbutton->runAction(seq);
}

void Combat::popCombat()
{
	//存档


	//保存：经验值exp


	//移除观察者
	CCNotificationCenter::sharedNotificationCenter()->removeAllObservers(this);
	//popScene
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(672,448, kResolutionExactFit);
	CCDirector::sharedDirector()->popScene();
}
