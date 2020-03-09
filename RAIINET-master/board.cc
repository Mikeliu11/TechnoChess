#include "board.h"
#include <iostream>
#include <ostream>
using namespace std;

bool Board::move(Square &sq, string dir)
{
    if (!players[whoseTurn-1]->hasLink(sq.getLink()->getName())) {
        return false;
    }
    Direction direction;
    if (dir == "up")
    {
        direction = Direction::Up;
    }
    else if (dir == "right")
    {
        direction = Direction::Right;
    }
    else if (dir == "down")
    {
        direction = Direction::Down;
    }
    else if (dir == "left")
    {
        direction = Direction::Left;
    }
    else
    {
        return false;
    }

    int opponentPlayer = whoseTurn == 1 ? 2 : 1;
    Square &dest = getDestSquare(sq, direction);
    if (sq == dest)
    {
        if (sq.getLink() == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Link *sqLink = sq.getLink();
    Link *destLink = dest.getLink();
    LinkType sqLinkType = sqLink->getType();
    SquareType destType = dest.getSquareType(whoseTurn);

    if (destType == SquareType::MyServerPort || destType == SquareType::MyLink)
    {
        return false;
    }
    else if (destType == SquareType::Empty)
    {
        dest.setLink(sqLink);
        sq.setLink(nullptr);
    }
    else if (destType == SquareType::YourLink)
    {
        if (sq.getLink()->getStrength() >= dest.getLink()->getStrength())
        {
            destLink->setState({whoseTurn, destLink->getType()});
            destLink->notifyObservers();
            dest.setLink(sqLink);
            destLink->download();
            sq.setLink(nullptr);
        }
        else
        {
            sqLink->setState({opponentPlayer, sqLinkType});
            sqLink->notifyObservers();
            sqLink->download();
            sq.setLink(nullptr);
        }
    }
    else if (destType == SquareType::YourFirewall)
    {
        sqLink->reveal();
        if (sqLinkType == LinkType::Virus)
        {
            sqLink->setState({whoseTurn, sqLinkType});
            sqLink->notifyObservers();
            sqLink->download();
            sq.setLink(nullptr);
        }
        else
        {
            dest.setLink(sqLink);
            sq.setLink(nullptr);
        }
    }
    else if (destType == SquareType::MyFirewall)
    {
        dest.setLink(sqLink);
        sq.setLink(nullptr);
    }
    else if (destType == SquareType::YourServerPort)
    {
        sqLink->setState({opponentPlayer, sqLinkType});
        sqLink->notifyObservers();
        sqLink->download();
        sq.setLink(nullptr);
    }
    return true;
}

Square &Board::getDestSquare(Square &sq, Direction d)
{
    int row = sq.getRow();
    int col = sq.getCol();
    int speed = sq.getLink()->getSpeed();
    int size = grid.size();
    int temp;

    if (d == Direction::Up)
    {
        if (row - speed < 0)
        {
            temp = row;
            if (whoseTurn == 2)
            {
                sq.getLink()->setState({whoseTurn, sq.getLink()->getType()});
                sq.getLink()->notifyObservers();
                sq.getLink()->download();
                sq.setLink(nullptr);
            }
        }
        else
        {
            temp = row - speed;
        }
        return grid[temp][col];
    }
    else if (d == Direction::Right)
    {
        temp = col + speed >= size ? col : col + speed;
        return grid[row][temp];
    }
    else if (d == Direction::Down)
    {
        if (row + speed >= size)
        {
            temp = row;
            if (whoseTurn == 1)
            {
                sq.getLink()->setState({whoseTurn, sq.getLink()->getType()});
                sq.getLink()->notifyObservers();
                sq.getLink()->download();
                sq.setLink(nullptr);
            }
        }
        else
        {
            temp = row + speed;
        }
        return grid[temp][col];
    }
    else
    {
        temp = col - speed < 0 ? col : col - speed;
        return grid[row][temp];
    }
}

void Board::nextTurn()
{
    whoseTurn = whoseTurn == 1 ? 2 : 1;
}

bool Board::isGameOver()
{
    int size = players.size();
    for (int i = 0; i < size; ++i)
    {
        if (players[i]->getNumOfVirus() == 4 || players[i]->getNumOfData() == 4)
        {
            return true;
        }
    }
    return false;
}

int Board::whoWon()
{
    if (players[0]->getNumOfData() == 4 || players[1]->getNumOfVirus() == 4)
    {
        return 1;
    }
    return 2;
}

bool Board::hasLink(char ID)
{
    for (auto &p : players) {
        if (p->hasLink(ID)) {
            return true;
        }
    }
    return false; 
}

Square &Board::getSquare(char ID)
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (grid[i][j].getLink() != nullptr && grid[i][j].getLink()->getName() == ID)
            {
                return grid[i][j];
            }
        }
    }
    return grid[0][0];
}

Square &Board::getSquare(int row, int col)
{
    return grid[row][col];
}

void Board::printAbilities()
{
    players[whoseTurn - 1]->printAbilities();
}

bool Board::useAbility(int index, Square &sq)
{
    return players[whoseTurn - 1]->useAbility(index, sq);
}

Player &Board::getPlayer(int index)
{
    return *players[index - 1];
}

std::vector<std::vector<Square>> Board::getGrid()
{
    return grid;
}

int Board::getTurn()
{
    return whoseTurn;
}