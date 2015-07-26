#include "GlobalState.h"
#include "RcdUtil.h"
#define SAVE_INT CCUserDefault::sharedUserDefault()->setIntegerForKey
#define SAVE_BOOL CCUserDefault::sharedUserDefault()->setBoolForKey
#define SAVE_STRING CCUserDefault::sharedUserDefault()->setStringForKey
#define LOAD_INT CCUserDefault::sharedUserDefault()->getIntegerForKey
#define LOAD_BOOL CCUserDefault::sharedUserDefault()->getBoolForKey
#define LOAD_STRING CCUserDefault::sharedUserDefault()->getStringForKey

void GlobalState::load()
{
    loadMapState();
    loadSuperPower();
    loadPlayerState();
    loadDoneList();
}

void GlobalState::save()
{
	SAVE_INT(POSITIONX_MRCD, mapState->positionX);
	SAVE_INT(POSITIONY_MRCD, mapState->positionY);
	SAVE_INT(FACEDIR_MRCD, mapState->faceDir);
	SAVE_INT(MAPNO_MRCD, mapState->mapNo);
	SAVE_INT(STORYCNT_MRCD, mapState->storyCnt);
	SAVE_BOOL(HAS_SHADOW_MRCD, mapState->hasSh);
	SAVE_INT(SH_STAND_P_MRCD, mapState->standPos);

	SAVE_INT(SPEED_SRCD, superPower->speed);
	SAVE_BOOL(TELEPORT_SRCD, superPower->teleport);
	SAVE_BOOL(STEALTH_SRCD, superPower->stealth);
	SAVE_BOOL(SURF_SRCD, superPower->surf);
	saveDoneList();
}

void GlobalState::newr()
{
	SAVE_INT(POSITIONX_MRCD,POSITIONX_INI);
	SAVE_INT(POSITIONY_MRCD,POSITIONY_INI);
	SAVE_INT(FACEDIR_MRCD,FACEDIR_INI);
	SAVE_INT(MAPNO_MRCD,MAPNO_INI);
	SAVE_INT(STORYCNT_MRCD,STORYCNT_INI);
	SAVE_BOOL(HAS_SHADOW_MRCD,HAS_SHADOW_INI);
	SAVE_INT(SH_STAND_P_MRCD,SH_STAND_P_INI);

	SAVE_INT(SPEED_SRCD,SPEED_INI);
	SAVE_BOOL(TELEPORT_SRCD,TELEPORT_INI);
	SAVE_BOOL(STEALTH_SRCD,STEALTH_INI);
	SAVE_BOOL(SURF_SRCD,SURF_INI);
	SAVE_STRING(EVENTDONE_MRCD,EVENTDONE_INI);
}

GlobalState::~GlobalState()
{
    delete []doneList;
}



void GlobalState::loadMapState()
{
    mapState=new MapState;
    mapState->positionX = LOAD_INT(POSITIONX_MRCD, POSITIONX_INI);
    mapState->positionY = LOAD_INT(POSITIONY_MRCD, POSITIONY_INI);
    mapState->faceDir= LOAD_INT(FACEDIR_MRCD, FACEDIR_INI);
    mapState->mapNo = LOAD_INT(MAPNO_MRCD, MAPNO_INI);
    mapState->storyCnt = LOAD_INT(STORYCNT_MRCD, STORYCNT_INI);
	mapState->hasSh = LOAD_BOOL(HAS_SHADOW_MRCD, HAS_SHADOW_INI);
	mapState->standPos= LOAD_INT(SH_STAND_P_MRCD, SH_STAND_P_INI);
}

void GlobalState::loadSuperPower()
{
    superPower=new SuperPower;
    superPower->speed = LOAD_INT(SPEED_SRCD, SPEED_INI);
    superPower->teleport = LOAD_BOOL(TELEPORT_SRCD, TELEPORT_INI);
    superPower->stealth = LOAD_BOOL(STEALTH_SRCD, STEALTH_INI);
    superPower->surf = LOAD_BOOL(SURF_SRCD, SURF_INI);
    superPower->flash= LOAD_BOOL(FLASH_SRCD, FLASH_INI);
}

void GlobalState::loadDoneList()
{
	for(int i=0;i<MAX_DONE_LIST;i++)
		doneList[i]=false;
	CCString* rcd=CCString::create(LOAD_STRING(EVENTDONE_MRCD,EVENTDONE_INI));
	CCArray* list=RcdUtil::split(rcd,DEFUALT_DELIM);
	for(int i=0;i<list->count();i++)
	{
		CCString* str=(CCString*)list->objectAtIndex(i);
		doneList[str->intValue()]=true;
	}
}

void GlobalState::loadPlayerState()
{

}

void GlobalState::saveDoneList()
{
	CCArray* list=CCArray::create();
	for(int i=0;i<MAX_DONE_LIST;i++)
		if(doneList[i]==true)
		{
			char tmp[50];
			sprintf(tmp, "%d", i);
			CCString* str=CCString::create(tmp);
			list->addObject(str);
		}
	RcdUtil::saveList(list,DEFUALT_DELIM);
}
