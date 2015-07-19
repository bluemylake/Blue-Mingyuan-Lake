#include "DiaEvent.h"
#include "GlobalRes.h"

void DiaEvent::happen()
{
    rGlobal->diawindow->setControllerListener(NULL); //prepare 
    rGlobal->diawindow->load(dialog);
    rGlobal->diawindow->respond(); //action go
}
