#ifndef LINKED_BOOST_H
#define LINKED_BOOST_H

#include "ability.h"
#include "square.h"
#include <string>

class LinkedBoost : public Ability {
    public:
    LinkedBoost(int whose) : Ability(whose) {}
    bool cast(Square &sq) override;
    std::string getName() override;
};
#endif

