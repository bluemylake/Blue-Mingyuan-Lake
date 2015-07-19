#ifndef _EMAP_H_
#define _EMAP_H_
#include "cocos2d.h"
#include "GlobalRes.h"
using namespace cocos2d;
//map the Event on the map
//provide access to the map to EventManager

class Emap
{
private:
	int** evmap;
public:
	Emap();
	~Emap();
	int tileAt(CCPoint coord);
	void takeTile(CCPoint coord, int eventType);
};
#endif
