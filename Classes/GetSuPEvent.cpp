#include "GlobalState.h"
#include "GetSuPEvent.h"

void GetSuPEvent::happen()
{
    sGlobal->superPower->speed = 3;
    sGlobal->superPower->teleport = true;
    sGlobal->superPower->stealth = true;
    sGlobal->superPower->surf = true;
    sGlobal->superPower->flash= true;
}
