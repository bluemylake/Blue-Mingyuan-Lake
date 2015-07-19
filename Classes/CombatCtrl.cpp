#include "CombatCtrl .h"

bool CombatCtrl::init() {
	if (!CCLayer::init()) {
		return false;
	}


	this->count = 0;
	setPointers(player,enemy,background);

	CsvUtil::sharedCsvUtil()->loadFile(A_CSV_PATH);

	CCSprite* menuImg = CCSprite::create(MENU_IMG_PATH);
	menuImg->setAnchorPoint(ccp(0,0));
	menuImg->setPosition(ccp(0,0));
	addChild(menuImg,1);

	menu1Enable=true;
	menu2Enable=false;

	initMenu1();
	return true;
}

void CombatCtrl::initMenu1(){
	CCLabelTTF *Label1 = CCLabelTTF::create("FIGHT", "Heiti SC", 40);
	CCLabelTTF *Label2 = CCLabelTTF::create("INFORMATION", "Heiti SC", 40);
	CCLabelTTF *Label3 = CCLabelTTF::create("RUN AWAY", "Heiti SC", 40);
	CCMenuItemLabel *item1 = CCMenuItemLabel::create(Label1, this, menu_selector(CombatCtrl::firstChoose));
	CCMenuItemLabel *item2 = CCMenuItemLabel::create(Label2, this, menu_selector(CombatCtrl::firstChoose));
	CCMenuItemLabel *item3 = CCMenuItemLabel::create(Label3, this, menu_selector(CombatCtrl::firstChoose));
	item1->setTag(0);
	item2->setTag(1);
	item3->setTag(2);
	item1->setPosition(ccp(250, 80));
	item2->setPosition(ccp(550, 80));
	item3->setPosition(ccp(850, 80));
	menu1 = CCMenu::create(item1, item2, item3, NULL);
	menu1->setPosition(CCPointZero);
	menu1->setTag(2);
	addChild(menu1, 3);
}

void CombatCtrl::initMenu2(){
	const char* ablName1;
	const char* ablName2;
	const char* ablName3;
	const char* ablName4;
	char num[10];
	sprintf(num,"%d",player->abilityNum[0]);
	ablName1 = CsvUtil::sharedCsvUtil()->get(CsvUtil::sharedCsvUtil()->findValueInWithLine(num,0,A_CSV_PATH),1,A_CSV_PATH);
	sprintf(num,"%d",player->abilityNum[1]);
	ablName2 = CsvUtil::sharedCsvUtil()->get(CsvUtil::sharedCsvUtil()->findValueInWithLine(num,0,A_CSV_PATH),1,A_CSV_PATH);
	sprintf(num,"%d",player->abilityNum[2]);
	ablName3 = CsvUtil::sharedCsvUtil()->get(CsvUtil::sharedCsvUtil()->findValueInWithLine(num,0,A_CSV_PATH),1,A_CSV_PATH);
	sprintf(num,"%d",player->abilityNum[3]);
	ablName4 = CsvUtil::sharedCsvUtil()->get(CsvUtil::sharedCsvUtil()->findValueInWithLine(num,0,A_CSV_PATH),1,A_CSV_PATH);
	CCLabelTTF *Label1 = CCLabelTTF::create("", "Heiti SC", 40);Label1->setString(ablName1);
	CCLabelTTF *Label2 = CCLabelTTF::create("", "Heiti SC", 40);Label2->setString(ablName2);
	CCLabelTTF *Label3 = CCLabelTTF::create("", "Heiti SC", 40);Label3->setString(ablName3);
	CCLabelTTF *Label4 = CCLabelTTF::create("", "Heiti SC", 40);Label4->setString(ablName4);



	CCLabelTTF *Label5 = CCLabelTTF::create("RETURN", "Heiti SC", 40);

	CCMenuItemLabel *item1 = CCMenuItemLabel::create(Label1, this, menu_selector(CombatCtrl::secondChoose));
	CCMenuItemLabel *item2 = CCMenuItemLabel::create(Label2, this, menu_selector(CombatCtrl::secondChoose));
	CCMenuItemLabel *item3 = CCMenuItemLabel::create(Label3, this, menu_selector(CombatCtrl::secondChoose));
	CCMenuItemLabel *item4 = CCMenuItemLabel::create(Label4, this, menu_selector(CombatCtrl::secondChoose));
	CCMenuItemLabel *item5 = CCMenuItemLabel::create(Label5, this, menu_selector(CombatCtrl::secondChoose));

	item1->setTag(0);
	item2->setTag(1);
	item3->setTag(2);
	item4->setTag(3);
	item5->setTag(4);

	item1->setPosition(ccp(400, 100));
	item2->setPosition(ccp(400, 60));
	item3->setPosition(ccp(700, 100));
	item4->setPosition(ccp(700, 60));
	item5->setPosition(ccp(900, 60));

	menu2 = CCMenu::create(item1, item2, item3,item4, item5,NULL);
	menu2->setPosition(CCPointZero);
	menu2->setTag(2);
	addChild(menu2, 3);
}





void CombatCtrl::firstChoose(CCObject *sender){
	if(menu1Enable==true){
		int item = ((CCNode *)sender)->getTag();
		switch(item){
		case 0:
			menu1->setVisible(false);
			menu1Enable=false;
			menu2Enable=true;
			//CsvUtil::sharedCsvUtil();
			initMenu2();
			break;
		case 1:
			break;
		case 2:
			CsvUtil::sharedCsvUtil()->releaseFile(A_CSV_PATH);
			CsvUtil::sharedCsvUtil()->releaseFile(M_CSV_PATH);
			popScene();

		};
	}
	else 
		return;
};

void CombatCtrl::secondChoose(CCObject *sender){
	if(menu2Enable==true){

	int item = ((CCNode *)sender)->getTag();
	switch(item){
	case 0:
		useAbility(item);
		break;
	case 1:
		break;
		CCLOG("case case:2");
	case 2:
		break;
	case 3:
		break;
	case 4:
		menu1Enable=true;
		menu1->setVisible(true);
		menu2->setVisible(false);
		menu2Enable=false;
		};
	}
	else 
		return;
}



void CombatCtrl::useAbility(int abilityNum){
	int hurtType=0;
	int hurt=player->giveHurt(abilityNum,hurtType);
	enemy->receiveHurt(hurt,hurtType);
	CCNotificationCenter::sharedNotificationCenter()->postNotification("gethurt",enemy);
	
	player->runAction( player->getGiveHurtAction(abilityNum) );
	CCSequence* seq = CCSequence::create(CCDelayTime::create(player->getGiveHurtAction(abilityNum)->getDuration()),player->getRecvHurtAction(abilityNum),NULL);
	enemy->runAction(seq);

	effectLabel = CCLabelTTF::create("", "Heiti SC", 40);this->addChild(effectLabel,10);
	effectLabel->setPosition(ccp(400,100));
	effectLabel->setTag(100);


	if (hurt>0&&enemy->remainHp>0&&player->remainHp>0)
	{
		menu2->setVisible(false);
		menu2Enable=false;
		effectLabel->setString("Successful!");
	}



	else if(hurt<=0&&enemy->remainHp>0&&player->remainHp>0)
	{
		menu2->setVisible(false);
		menu2Enable=false;
		effectLabel->setString("Failed");
	}
	
	this->setTouchEnabled(true);

	
}

void CombatCtrl::setPointers(Player1* player,Enemy* enemy,CCSprite *background)
{
	this->player=player;
	this->enemy=enemy;
	this->background=background;
}


void CombatCtrl::ccTouchesBegan(CCSet*pTouches,CCEvent*pEvent)
{
	if (count == 0)
	{
		int hurtType = 0;
		int heroRHP=player->remainHp,heroLvl=player->level;
		int enemyablnum = enemy->decideAbility(heroRHP,heroLvl);
		int hurt=enemy->giveHurt(enemyablnum,hurtType);
		player->receiveHurt(hurt,hurtType);
		enemy->runAction( enemy->getGiveHurtAction(enemyablnum) );
		CCSequence* seq = CCSequence::create(CCDelayTime::create(enemy->getGiveHurtAction(enemyablnum)->getDuration()),enemy->getRecvHurtAction(enemyablnum),NULL);
		player->runAction(seq);
		CCLabelTTF *effectLabel = CCLabelTTF::create("", "Heiti SC", 40);
		effectLabel = (CCLabelTTF *)this->getChildByTag(100);
		if (hurt>0)
		{
			effectLabel->setString("Be Attacked!");
		}
		else
		{
			effectLabel->setString("Enemy Failed");
		}
		if (enemy->remainHp<=0)
		{
			menu2->setVisible(false);
			menu2Enable=false;
			effectLabel = CCLabelTTF::create("", "Heiti SC", 40);this->addChild(effectLabel,10);
			effectLabel->setString("YOU WIN!");
			CCCallFunc* pop=CCCallFunc::create(this,callfunc_selector(CombatCtrl::popScene));
			CCSequence* seq = CCSequence::create(CCDelayTime::create(2),enemy->exitAction(),pop,NULL);
			enemy->runAction(seq);

		}

		if (player->remainHp<=0)
		{
			menu2->setVisible(false);
			menu2Enable=false;
			effectLabel->setString("YOU LOSE!");
			CCCallFunc* pop=CCCallFunc::create(this,callfunc_selector(CombatCtrl::popScene));
			CCSequence* seq = CCSequence::create(CCDelayTime::create(2),player->exitAction(),pop,NULL);
			player->runAction(seq);

		}

		CCNotificationCenter::sharedNotificationCenter()->postNotification("gethurt",player);
		count++;
	}
	else
	{
		CCLabelTTF *effectLabel = (CCLabelTTF *)this->getChildByTag(100);
		this->removeChild(effectLabel);
		this->setTouchEnabled(false);
		//this->initMenu1();
		menu1Enable=true;
		//menu1->setVisible(true);
		menu2->setVisible(true);
		menu2Enable=true;
		count=0;
	}
	

}

void CombatCtrl::popScene()
{
	CsvUtil::sharedCsvUtil()->releaseFile(M_CSV_PATH);
	CsvUtil::sharedCsvUtil()->releaseFile(A_CSV_PATH);

	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(672,448, kResolutionExactFit);
	CCDirector::sharedDirector()->popScene();
}