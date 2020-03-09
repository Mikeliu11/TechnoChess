#include "abFirewall.h"

using namespace std;

bool Firewall::cast(Square &sq)
{
    if (used == true || sq.getSquareType(whose) != SquareType::Empty)
    {
        return false;
    }
    sq.setFirewall(whose);
    used = true;
    return true;
}

string Firewall::getName()
{
    return "Firewall";
}
