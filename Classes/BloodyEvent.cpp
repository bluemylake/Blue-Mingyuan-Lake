#include "BloodyEvent.h"
#include "GlobalState.h"

void BloodyEvent::happen()
{
	sGlobal->mapState->isBloody=true;
    rGlobal->map->layerNamed(WATER_MLYR)->setVisible(false);
}

void WateryEvent::happen()
{
	sGlobal->mapState->isBloody=false;
    rGlobal->map->layerNamed(WATER_MLYR)->setVisible(true);
}
