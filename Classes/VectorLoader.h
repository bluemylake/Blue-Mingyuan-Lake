#ifndef _VECTOR_LOADER_H_
#define _VECTOR_LOADER_H_
#include <vector>
#include "cocos2d.h"
using namespace cocos2d;

//define the path of a walking man by listing the turning points
//VectorLoader translates turning points into movement vectors
class VectorLoader
{
public:
    static std::vector<CCPoint> start(CCArray* intArray);
};
#endif
