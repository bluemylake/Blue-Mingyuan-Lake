#include "GlobalRes.h"
#include "HeroDisapEvent.h"

void HeroDisapEvent::happen() 
{
	rGlobal->hero->setVisible(false);
}

