#include "abScan.h"

using namespace std;

bool Scan::cast(Square &sq)
{
    if (used == true || (sq.getSquareType(whose) != SquareType::MyLink && sq.getSquareType(whose) != SquareType::YourLink))
    {
        return false;
    }
    Link *l = sq.getLink();
    l->reveal();
    used = true;
    return true;
}

string Scan::getName()
{
    return "Scan";
}
