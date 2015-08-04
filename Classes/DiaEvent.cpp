#include "DiaEvent.h"
#include "GlobalRes.h"
#include "Button.h"

void DiaEvent::happen()
{
	Button* dirButton=(Button*)rGlobal->panel->getChildByTag(DIRBUTTON);
	dirButton->enable=false;

    rGlobal->diawindow->setControllerListener(NULL); //prepare 
    rGlobal->diawindow->load(dialog);
    rGlobal->diawindow->respond(); //action go
}
