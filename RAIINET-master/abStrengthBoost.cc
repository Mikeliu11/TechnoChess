#include "abStrengthBoost.h"

using namespace std;

bool StrengthBoost::cast(Square &sq)
{
    if (used == true || sq.getSquareType(whose) != SquareType::MyLink)
    {
        return false;
    }
    Link *l = sq.getLink();
    l->incrementStrength();
    used = true;
    return true;
}

string StrengthBoost::getName()
{
    return "StrengthBoost";
}
