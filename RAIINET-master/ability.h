#ifndef ABILITY_H
#define ABILITY_H

#include <string>
#include "square.h"

class Ability {
    protected: 
    bool used;
    int whose;
    public:
    Ability(int whose) : used{false}, whose{whose} {}
    virtual ~Ability() = default;
    virtual bool cast(Square &sq) = 0;
    virtual std::string getName() = 0;
    int getWhose();
    bool getUsed();
    void setUsed(bool used);
};
#endif

