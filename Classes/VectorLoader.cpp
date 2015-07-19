#include "VectorLoader.h"

std::vector<CCPoint> VectorLoader::start(CCArray* intArray)
{
    std::vector<CCPoint> vectorList;
    CCInteger* vecX=(CCInteger*)intArray->objectAtIndex(0);
    CCInteger* vecY=(CCInteger*)intArray->objectAtIndex(1);
    CCPoint lastPos=CCPointMake(vecX->getValue(),vecY->getValue());
    for(int i=2;i<intArray->count();i+=2)
    {
	CCInteger* vecX=(CCInteger*)intArray->objectAtIndex(i);
	CCInteger* vecY=(CCInteger*)intArray->objectAtIndex(i+1);
	CCPoint curPos=CCPointMake(vecX->getValue(),vecY->getValue());
	vectorList.push_back(curPos-lastPos);
	lastPos=curPos;
    }
    return vectorList;
}
