#ifndef FIREWALL_H
#define FIREWALL_H

#include "ability.h"
#include "square.h"
#include <string>

class Firewall : public Ability {
    public:
    Firewall(int whose) : Ability(whose) {}
    bool cast(Square &sq) override;
    std::string getName() override;
};
#endif
