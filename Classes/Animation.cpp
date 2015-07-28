#include "Animation.h"

//update:2014-10-3 01:30:47

CCFiniteTimeAction* Animation::getAction(int choice,CCSize size)
{
	CCFiniteTimeAction* action=NULL;
	switch(choice)
	{
	case TAISHANYADING:
		{
		CCMoveBy* dun=CCMoveBy::create(0.20f,ccp(0,-size.height/2));
		CCMoveBy* qi=CCMoveBy::create(0.20f,ccp(0,size.height/2));
		CCMoveBy* tui=CCMoveBy::create(0.20f,ccp(size.width/2,0));
		CCMoveBy* hui=CCMoveBy::create(0.20f,ccp(-size.width/2,0));
		action=CCSequence::create(dun,qi,tui,hui,NULL);
		}
		break;
	case STAGGER:
		{
		CCMoveBy* yao=CCMoveBy::create(0.28f,ccp(size.width,0));
		CCMoveBy* bai=CCMoveBy::create(0.28f,ccp(-size.width,0));
		action=CCSequence::create(yao,bai,yao,bai,NULL);
		}
	case STRIKE:
		{
		CCMoveBy* yao=CCMoveBy::create(0.10f,ccp(size.width/2,0));
		CCMoveBy* bai=CCMoveBy::create(0.10f,ccp(-size.width/2,0));
		action=CCSequence::create(yao,bai,NULL);
		}
		break;
	case ATTACK:
		{
		CCMoveBy* yao=CCMoveBy::create(0.15f,ccp(size.width/2,0));
		CCMoveBy* bai=CCMoveBy::create(0.15f,ccp(-size.width/2,0));
		action=CCSequence::create(yao,bai,NULL);
		}
		break;
	case UP:
		{
		CCMoveBy* up=CCMoveBy::create(0.35f,ccp(0,size.height));
		action=up;
		}
		break;
	case DOWN:
		{
		CCMoveBy* down=CCMoveBy::create(1.0f,ccp(0,-size.height));
		action=down;
		}
		break;
	case TELEPORTOUT:
		{
		CCBlink* shan=CCBlink::create(0.20f,2);
		CCHide* hide=CCHide::create();
		action=CCSequence::create(shan,hide,NULL);
		}
		break;
	case TELEPORTIN:
		{
		CCBlink* shan=CCBlink::create(0.20f,2);
		CCShow* show=CCShow::create();
		action=CCSequence::create(shan,show,NULL);
		}
		break;
	case STEALTHOUT:
		{
		CCFadeTo* fadeOut=CCFadeTo::create(0.50f,75);
		action=fadeOut;
		}
		break;
	case STEALTHIN:
		{
		CCFadeIn* fadeIn=CCFadeIn::create(0.50f);
		action=fadeIn;
		}
		break;
	case SWAY:
		{
		CCRotateTo* rotate = CCRotateTo::create(0.2,10,10);
		CCRotateTo* rotate1 = CCRotateTo::create(0.2,-10,-10);
		CCRotateTo* rotate2 = CCRotateTo::create(0.2,0,0);
		action = CCSequence::create(rotate,rotate1,rotate2,NULL);
		}
		break;
	case FADEOUT:
		{
			CCFadeTo* fadeTo = CCFadeTo::create(0.5,0);
			action = fadeTo;
		}
		break;
	case FADEIN:
		{
			CCFadeTo* fadeTo = CCFadeTo::create(0.5,255);
			action = fadeTo;
		}
	default:
		break;
	}
	return action;
}
