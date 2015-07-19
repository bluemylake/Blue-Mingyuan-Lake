#include "TimeElapseEvent.h"

void TimeElapseEvent::happen()
{
    GlobalState::instance()->mapState->sTime++;
}
