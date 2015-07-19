#include "BloodyEvent.h"

void BloodyEvent::happen()
{
    rGlobal->map->layerNamed(WATER_MLYR)->setVisible(false);
}

void WateryEvent::happen()
{
    rGlobal->map->layerNamed(WATER_MLYR)->setVisible(true);
}
