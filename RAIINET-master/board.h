#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <string>
#include "player.h"
#include "square.h"

enum class Direction
{
    Up,
    Down,
    Left,
    Right
};

class Board
{
    std::vector<Player *> &players;
    std::vector<std::vector<Square>> &grid;
    int whoseTurn;

public:
    Board(std::vector<Player *> &players, std::vector<std::vector<Square>> &grid) : players{players}, grid{grid}, whoseTurn{1} {}
    ~Board() = default;
    bool isGameOver();
    int whoWon();
    bool hasLink(char ID);
    Square &getSquare(char ID);
    Square &getSquare(int row, int col);
    Square &getDestSquare(Square &sq, Direction d);
    Direction getDirection(std::string dir);
    bool move(Square &sq, std::string dir);
    bool useAbility(int index, Square &sq);
    void nextTurn();
    void printAbilities();
    Player &getPlayer(int index);
    std::vector<std::vector<Square>> getGrid();
    int getTurn();
};

#endif