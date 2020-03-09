#ifndef SQUARE_H
#define SQUARE_H

#include "link.h"

enum class SquareType
{
    Empty,
    MyServerPort,
    YourServerPort,
    MyFirewall,
    YourFirewall,
    MyLink,
    YourLink
};
class Square
{
    int row;
    int col;
    int serverPort;
    int firewall;
    Link *link;

public:
    Square();
    Square(int row, int col, int serverPort = 0, int firewall = 0, Link *link = nullptr) : row{row}, col{col}, serverPort{serverPort}, firewall{firewall}, link{link} {}
    Square(const Square &other) : row{other.row}, col{other.col}, serverPort{other.serverPort}, firewall{other.firewall}, link{other.link} {}
    Square &operator=(const Square &other);
    ~Square();
    bool operator==(const Square &other);
    int getRow();
    int getCol();
    int getFirewall();
    int getServerPort();
    Link *getLink();
    SquareType getSquareType(int whoseTurn);
    void setLink(Link *l);
    void setFirewall(int playerNum);
    char print();
};

#endif
