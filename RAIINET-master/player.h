#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include "ability.h"
#include "link.h"
#include "subject.h"
#include "observer.h"

class Player : public Observer
{
    int numOfVirus = 0;
    int numOfData = 0;
    const int playerNum;
    std::vector<Ability *> abilities;
    std::vector<Link> &links;

public:
    Player(int playerNum, std::vector<Ability *> abilities, std::vector<Link> &links, std::vector<Link> &links2);
    ~Player();
    void notify(Subject &whoFrom) override;
    bool useAbility(int index, Square &sq);
    int getNumOfVirus();
    int getNumOfData();
    int getPlayerNum();
    bool hasLink(char ID);
    Link &getLink(char ID);
    void printAbilities();
    int getNumOfAbilities();
};

#endif