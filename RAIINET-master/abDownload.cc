#include "abDownload.h"

using namespace std;

bool Download::cast(Square &sq)
{
    if (used == true || sq.getSquareType(whose) != SquareType::YourLink)
    {
        return false;
    }
    Link *l = sq.getLink();
    l->setState({whose, l->getType()});
    l->notifyObservers();
    l->download();
    sq.setLink(nullptr);
    used = true;
    return true;
}

string Download::getName()
{
    return "Download";
}
