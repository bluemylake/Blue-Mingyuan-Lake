#include "CombatEvent.h"

void CombatEvent::happen()
{
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(JX_RESOLUWID, JX_RESOLUHEI, kResolutionExactFit);
    CCScene* combat=Combat::scene();
    CCDirector::sharedDirector()->pushScene(combat);
}
