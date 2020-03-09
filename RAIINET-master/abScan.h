#ifndef SCAN_H
#define SCAN_H

#include "ability.h"
#include "link.h"
#include "square.h"
#include <string>

class Scan : public Ability {
    public:
    Scan(int whose) : Ability(whose) {}
    bool cast(Square &sq) override;
    std::string getName() override;
};
#endif
