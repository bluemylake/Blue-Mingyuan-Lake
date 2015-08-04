#include "EventLoader.h"
#include "TalkManEvent.h"
#include "GetSuPEvent.h"
#include "DiaEvent.h"
#include "GetShdwEvent.h"
#include "ReloadEvent.h"
#include "BloodyEvent.h"
#include "DuelEvent.h"
#include "LoadNightEvent.h"
#include "LoadDayEvent.h"
#include "IsWinEvent.h"
#include "HeroDisapEvent.h"
#include "HeroAppearEvent.h"
#include "NPCMoveEvent.h"

CCArray* EventLoader::start(const char* sFilePath)
{
	CCArray* lines=FileLoadUtil::sharedFileLoadUtil()->getDataLines(sFilePath);
	CCArray* eventSet=CCArray::create();
	//coord, description, id, cat, type, imgNo, next, nPre, nDia, nArg, repeat, arg, dia, pre
	for(int i=1;i<lines->count();i++)
	{
		Event* event; int j=0;
		CCString* str=(CCString*)lines->objectAtIndex(i);
		CCArray* attList= StringUtil::sharedStrUtil()->split(str->getCString(), ",");

		CCString* strTmp=(CCString*)attList->objectAtIndex(5);
		int type=strTmp->intValue();
		switch(type)
		{
			case TALKMAN_EVT:
				event=TalkManEvent::create(); break;
			case GET_SUP_EVT:
				event=GetSuPEvent::create(); break;
			case DIALOG_EVT:
				event=DiaEvent::create(); break;
			case SHADOW_EVT:
				event=GetShdwEvent::create(); break;
			case RELOAD_EVT:
				event=ReloadEvent::create(); break;
			case BLOODY_EVT:
				event=BloodyEvent::create(); break;
			case WATERY_EVT:
				event=WateryEvent::create(); break;
			case DUEL_EVT:
				event=DuelEvent::create(); break;
			case LNIGHT_EVT:
				event=LoadNightEvent::create(); break;
			case LDAY_EVT:
				event=LoadDayEvent::create(); break;
			case IS_WIN_EVT:
				event=IsWinEvent::create(); break;
			case HERO_DIS_EVT:
				event=HeroDisapEvent::create(); break;
			case HERO_APP_EVT:
				event=HeroAppearEvent::create(); break;
			case NPC_MOVE_EVT:
				event=NPCMoveEvent::create(); break;
			default:break;
		}
		//CCLog("%s",typeid(*event).name());

		CCPoint point=ccp(0,0);
		strTmp=(CCString*)attList->objectAtIndex(j++);
		point.x=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		point.y=strTmp->intValue();
		event->coord=point;


		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->description=strTmp;

		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->id=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->category=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->type=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->imgNo=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->next=strTmp->intValue();

		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->nPre=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->nDia=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->nArg=strTmp->intValue();
		strTmp=(CCString*)attList->objectAtIndex(j++);
		event->repeat=strTmp->boolValue();

		event->args=CCArray::create();event->args->retain();
		event->dialog=CCArray::create();event->dialog->retain();
		event->pres=CCArray::create();event->pres->retain();
		for(int k=0;k<event->nArg;k++)
		{
			strTmp=(CCString*)attList->objectAtIndex(j++);
			CCInteger* intg=CCInteger::create(strTmp->intValue());
			event->args->addObject(intg);
		}
		for(int k=0;k<event->nDia;k++)
		{
			strTmp=(CCString*)attList->objectAtIndex(j++);
			CCString* strT=CCString::create(strTmp->getCString());
			event->dialog->addObject(strT);
		}
		for(int k=0;k<event->nPre;k++)
		{
			strTmp=(CCString*)attList->objectAtIndex(j++);
			CCInteger* intg=CCInteger::create(strTmp->intValue());
			event->pres->addObject(intg);
		}
		eventSet->addObject(event);
	}
	return eventSet;
}
