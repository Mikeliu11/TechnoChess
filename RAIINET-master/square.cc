#include "square.h"

using namespace std;

Square::Square() {}

Square::~Square() {}

char Square::print()
{
    if (serverPort == 0 && firewall == 0 && link == nullptr)
    {
        return '.';
    }
    else if (serverPort != 0)
    {
        return 'S';
    }
    else if (link != nullptr)
    {
        return link->getName();
    }
    else if (firewall == 1)
    {
        return 'm';
    }
    else if (firewall == 2)
    {
        return 'w';
    }
    return 'x';
}

SquareType Square::getSquareType(int whoseTurn)
{
    if (serverPort == 0 && firewall == 0 && link == nullptr)
    {
        return SquareType::Empty;
    }
    else if (serverPort == whoseTurn)
    {
        return SquareType::MyServerPort;
    }
    else if (serverPort != 0 && serverPort != whoseTurn)
    {
        return SquareType::YourServerPort;
    }
    else if (link != nullptr && link->getWhose() == whoseTurn)
    {
        return SquareType::MyLink;
    }
    else if (link != nullptr && link->getWhose() != whoseTurn)
    {
        return SquareType::YourLink;
    }
    else if (firewall == whoseTurn)
    {
        return SquareType::MyFirewall;
    }
    else if (firewall != 0 && firewall != whoseTurn)
    {
        return SquareType::YourFirewall;
    }
    return SquareType::Empty;
}

bool Square::operator==(const Square &other)
{
    if (row == other.row && col == other.col)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Link *Square::getLink() { return link; }

int Square::getServerPort() { return serverPort; }

void Square::setFirewall(int playerNum) { firewall = playerNum; }

void Square::setLink(Link *l) { link = l; }

int Square::getRow()
{
    return row;
}

int Square::getCol()
{
    return col;
}
