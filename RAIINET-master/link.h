#ifndef LINK_H
#define LINK_H

#include "subject.h"
#include "state.h"

class Link : public Subject
{
    const char name;
    int strength;
    LinkType type;
    int whoseLink;
    int speed;
    bool revealed;
    bool downloaded;

public:
    Link(char name, int strength, LinkType type, int whoseLink) : name{name}, strength{strength}, type{type}, whoseLink{whoseLink}, speed{1}, revealed{false}, downloaded{false} {}
    Link(const Link &other) : name{other.name}, strength{other.strength}, type{other.type}, whoseLink{other.whoseLink}, speed{1}, revealed{false}, downloaded{false} {}
    char getName();
    int getStrength();
    int getSpeed();
    int getWhose();
    LinkType getType();
    bool getDownloaded();
    bool getRevealed();
    void download();
    void reveal();
    void toggleType();
    void incrementSpeed();
    void incrementStrength();
    ~Link() = default;
};
#endif