#include "BagRecord.h"

bool BagRecord::addItemToRecord(int id)
{
    if(totalItem!=itemIDList.size())CCLog("'totalItem' inconsistent! ");
    for(int i=0;i<itemIDList.size();i++)
	if(itemIDList[i]==id)
	{
	    itemNumList[i]++;
	    return true;
	}

    totalItem++;
    if(totalItem>BAG_ITEM_MAX)
    {
	totalItem=BAG_ITEM_MAX;
	return false;
    }
    itemIDList[totalItem]=id;
    itemNumList[totalItem]=1;
}

int BagRecord::useItemToRecord(int id,bool isConsumptive)
{
    for(int i=0;i<itemIDList.size();i++)
	if(itemIDList[i]==id)
	    if(isConsumptive)
	    {
		if(itemNumList[i]>0)
		{
		    itemNumList[i]--;
		    if(itemNumList[i]==0)
		    {
			itemIDList.erase(itemIDList[i]);
			itemNumList.erase(itemNumList[i]);
			totalItem--;
			return ITEM_REMOVE;
		    }
		    return ITEM_REMAIN;
		}
		else
		    CCLog("Shouldn't have this item in record. Why ask?");
	    }
	    else
	    {
		if(itemUseList[i]==false)
		    itemUseList[i]=true;
		else
		    return ALREADY_EQUIPPED;
	    }
    return ITEM_REMAIN;
}
