#include "player.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Player::Player(int playerNum, vector<Ability *> abilities, vector<Link> &links, vector<Link>& links2) : numOfVirus{0}, numOfData{0}, playerNum{playerNum}, abilities{abilities}, links{links}
{
    for (size_t i = 0; i < links.size(); ++i)
    {
        links[i].attach(this);
        links2[i].attach(this);
    }
}

Player::~Player()
{
    for (int i = 0; i < 5; ++i)
    {
        Ability *ab = abilities[i];
        abilities[i] = nullptr;
        delete ab;
    }
}

void Player::notify(Subject &whoFrom)
{
    State state = whoFrom.getState();
    if (state.downloadingPlayer == playerNum)
    {
        if (state.linkType == LinkType::Virus)
        {
            numOfVirus++;
        }
        else
        {
            numOfData++;
        }
    }
}

int Player::getNumOfVirus()
{
    return this->numOfVirus;
}

int Player::getNumOfData()
{
    return this->numOfData;
}

int Player::getPlayerNum()
{
    return this->playerNum;
}

bool Player::hasLink(char ID)
{
    for (auto l : links)
    {
        if (l.getName() == ID && l.getDownloaded() == false)
        {
            return true;
        }
    }
    return false;
}

Link &Player::getLink(char ID)
{
    for (auto &l : links)
    {
        if (l.getName() == ID)
        {
            return l;
        }
    }
    return links[0];
}

void Player::printAbilities()
{
    int size = abilities.size();
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << ": " << abilities[i]->getName();
        if (!abilities[i]->getUsed())
        {
            cout << " not";
        }
        cout << " used";
        cout << endl;
    }
}

bool Player::useAbility(int index, Square &sq)
{
    return abilities[index]->cast(sq);
}

int Player::getNumOfAbilities()
{
    int counter = 0;
    for (auto ab : abilities)
    {
        if (!ab->getUsed())
        {
            counter++;
        }
    }
    return counter;
}