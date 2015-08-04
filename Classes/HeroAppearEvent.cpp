#include "GlobalRes.h"
#include "HeroAppearEvent.h"

void HeroAppearEvent::happen() 
{
	rGlobal->hero->setVisible(true);
}
