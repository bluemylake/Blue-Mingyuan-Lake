#include "TimeElapseEvent.h"

void TimeElapseEvent::happen()
{
    (sGlobalRes->mapState->sTime)++;
}
