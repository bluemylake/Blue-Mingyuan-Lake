#ifndef __PLAYER1_H__
#define __PLAYER1_H__

#include "cocos2d.h"
#include "Character.h"
#include "Entity.h"
using namespace cocos2d;


class Player1 : public Character{
public:
	CREATE_FUNC(Player1);
	virtual bool init();
	void levelUp();//�ж��Ƿ�����������������
	void evolution(int level); //������ͼƬ�����Ա仯
	void receiveExp(int exp);
	void fixAbility(int level);//���ŵȼ��������Ӽ���
	void getProperty();

public:
	int abilityNum[4];
	int myExp;
	int picNum;//���� ͼƬ	
};
#endif