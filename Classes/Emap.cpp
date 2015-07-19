#include "AppMacros.h"
#include "Emap.h"

Emap::Emap()
{
	int height=rGlobal->map->getMapSize().height;
	int width=rGlobal->map->getMapSize().width;
	evmap=new int*[height];
	for(int i=0;i<height;i++)
		evmap[i]=new int[width];
	for(int i=0;i<height;i++)
		for(int j=0;j<width;j++)
			evmap[i][j]=NO_EVENT_FLAG;
}

Emap::~Emap()
{
	int height=rGlobal->map->getMapSize().height;
	for(int i=0;i<height;i++)
		delete[] evmap[i];
	delete evmap;
}

int Emap::tileAt(CCPoint coord)
{
	return evmap[(int)coord.y][(int)coord.x];
}

void Emap::takeTile(CCPoint coord, int eventType)
{
	evmap[(int)coord.y][(int)coord.x]=eventType;
}
