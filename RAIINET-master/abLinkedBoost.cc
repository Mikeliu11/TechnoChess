#include "abLinkedBoost.h"

using namespace std;

bool LinkedBoost::cast(Square &sq)
{
    if (used == true || sq.getSquareType(whose) != SquareType::MyLink)
    {
        return false;
    }
    Link *l = sq.getLink();
    l->incrementSpeed();
    used = true;
    return true;
}

string LinkedBoost::getName()
{
    return "LinkedBoost";
}
