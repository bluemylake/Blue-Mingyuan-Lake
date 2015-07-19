#ifndef _EVENT_H_
#define _EVENT_H_
#include "cocos2d.h"
using namespace cocos2d;
//the stucture of an Event
//executes Event polymorphically

class Event: public CCObject
{
public:
	CREATE_FUNC(Event);
	bool init();
	virtual void happen();
	~Event();
public:
	CCPoint coord;
	CCString* description;
	int id;
	int category;
	int type;
	int imgNo;
	int next;
	int nPre;
	CCArray* pres;
	int nDia;
	CCArray* dialog;
	int nArg;
	CCArray* args;
	bool repeat;
};
//imgNo for STAND_TRIG_IMGNO, ATRIG_NO_MAN_IMGNO and imageNo
//cat for STAND, TURN and WALK
//type for DIALOG, ITEM, BUILDING AND COMBAT
#endif
