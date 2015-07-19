#include "ItemEvent.h"

void ItemEvent::happen()
{
    CCInteger* intg=(CCInteger*)args->objectAtIndex(ITEM_ID_INDEX);
    int itemId=intg->getValue();
    //@ItemManager get the item object
    //@get the name of the item
    //CCString* str=CCString::createWithFormat(ACQUIRE_ITEM_DIA,itemId);
    CCString* str=CCString::create(ACQUIRE_ITEM_DIA);
    dialog->addObject(str);
    rGlobal->diawindow->load(dialog);
    rGlobal->diawindow->respond();
    //@backpack add item
}
