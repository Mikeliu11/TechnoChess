#ifndef DOWNLOAD_H
#define DOWNLOAD_H

#include "ability.h"
#include "square.h"
#include <string>

class Download : public Ability {
    public:
    Download(int whose) : Ability(whose) {}
    bool cast(Square &sq) override;
    std::string getName() override;

};
#endif

