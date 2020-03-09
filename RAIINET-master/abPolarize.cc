#include "abPolarize.h"

using namespace std;

bool Polarize::cast(Square &sq)
{
    if (used == true || (sq.getSquareType(whose) != SquareType::MyLink && sq.getSquareType(whose) != SquareType::YourLink))
    {
        return false;
    }
    Link *l = sq.getLink();
    l->toggleType();
    used = true;
    return true;
}

string Polarize::getName()
{
    return "Polarize";
}
