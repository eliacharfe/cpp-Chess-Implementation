#include "Location.h"


std::ostream& operator<<(std::ostream& os, const Location& location)
{
    os << "(" << location.l << "," << location.n << ")";
    	return os;
}
//----------------------------------------
const bool operator==(const Location& loc1, const Location& loc2)
{
    return (loc1.l == loc2.l) && (loc1.n == loc2.n);
}
//------------------------------------------------
const bool operator!=(const Location& loc1, const Location& loc2)
{
    return !(loc1 == loc2);
}