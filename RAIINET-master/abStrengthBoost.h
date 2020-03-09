#ifndef STRENGTH_BOOST_H
#define STRENGTH_BOOST_H

#include "ability.h"
#include "square.h"
#include <string>

class StrengthBoost : public Ability
{
public:
    StrengthBoost(int whose) : Ability(whose) {}
    bool cast(Square &sq) override;
    std::string getName() override;
};
#endif
