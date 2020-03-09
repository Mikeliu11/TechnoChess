#ifndef POLARIZE_H
#define POLARIZE_H

#include "ability.h"
#include "square.h"
#include <string>

class Polarize : public Ability {
    public:
    Polarize(int whose) : Ability(whose) {}
    bool cast(Square &sq) override;
    std::string getName() override;
};
#endif
