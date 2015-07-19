#include "Character.h"

bool Character::init()
{
	
	CsvUtil::sharedCsvUtil()->loadFile(M_CSV_PATH);
	//CsvUtil::sharedCsvUtil()->loadFile(A_CSV_PATH);

	return true;
}

int Character::giveHurt(int abilityNum,int& type)
{
	//Ability* ability=(Ability*)abilities->objectAtIndex(abilityNum);
	int ablnum;
	ablnum = CsvUtil::sharedCsvUtil()->getInt(this->ID,10+abilityNum,M_CSV_PATH);
	getability(ablnum);
	float chance=CCRANDOM_0_1();
	if(chance>ability->hitRate)return 0;
	int att;
	if(ability->type==COMABL)att=this->attack;
	else if(type==SPEABL)att=this->speAtt;
	type=ability->type;
	return ability->hurt+att+CCRANDOM_0_1()*ability->stability+level*ability->lvlBuff;
}

CCFiniteTimeAction* Character::getGiveHurtAction(int abilityNum)
{
	//Ability* ability=(Ability*)abilities->objectAtIndex(abilityNum);
	return Animation::getAction(ability->giveHurtActID,this->getChildByTag(IMGSP)->getContentSize());
}


CCFiniteTimeAction* Character::exitAction()
{
	return Animation::getAction(12,this->getChildByTag(IMGSP)->getContentSize());
}






void Character::receiveHurt(int hurt,int& type)
{//½ÓÊÜÉËº¦
	int def;
	if(type==COMABL)def=this->defence;
	else if(type==SPEABL)def=this->speDef;
	if (hurt > def)
	{
		remainHp = remainHp-(hurt-def);
	}
	if (remainHp<=0)
	{
		remainHp = 0;
	}
}

CCFiniteTimeAction* Character::getRecvHurtAction(int abilityNum)
{
//	Ability* ability=(Ability*)abilities->objectAtIndex(abilityNum);
	return Animation::getAction(ability->recvHurtActID,this->getChildByTag(IMGSP)->getContentSize());
}

bool Character::isDead()
{
	return remainHp<=0;
}

void Character::getability(int num)
{
	char number[10];
	sprintf(number,"%d",num);
	int type = CsvUtil::sharedCsvUtil()->getInt(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),2,A_CSV_PATH);
	int hurt = CsvUtil::sharedCsvUtil()->getInt(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),3,A_CSV_PATH);
	int stability = CsvUtil::sharedCsvUtil()->getInt(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),4,A_CSV_PATH);
	int lvlBuff = CsvUtil::sharedCsvUtil()->getInt(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),5,A_CSV_PATH);
	int hitRate = CsvUtil::sharedCsvUtil()->getInt(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),6,A_CSV_PATH);
	CCString description = CsvUtil::sharedCsvUtil()->get(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),7,A_CSV_PATH);
	int giveHurtActID = CsvUtil::sharedCsvUtil()->getInt(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),8,A_CSV_PATH);
	int receiveHurtActID = CsvUtil::sharedCsvUtil()->getInt(CsvUtil::sharedCsvUtil()->findValueInWithLine(number,0,A_CSV_PATH),9,A_CSV_PATH);
	ability = Ability::create(type,hurt,stability,lvlBuff,hitRate,description,giveHurtActID,receiveHurtActID);

}
