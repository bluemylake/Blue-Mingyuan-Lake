#ifndef _PATH_FINDING_H_
#define _PATH_FINDING_H_
class PathFinding
{
public:
    static CCArray* findPath(CCPoint start,CCPoint end,Emap* walkMap);
}
#endif
