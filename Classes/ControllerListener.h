#ifndef _ControllerListener_H_
#define _ControllerListener_H_

#include "cocos2d.h"
using namespace cocos2d;

//update:2014-9-26 12:00:58

class ControllerListener {
public:
	virtual void respond(int dir);
	//���ڳ���������ӦtouchEnd�����ڵ���������Ӧ����������ʧȥ����
	virtual void endRespond();
	virtual bool hasTouchEnded();
};

#endif
