#pragma once
#include <iostream>
#include "board.h"
#include "Display.h"
#include "link.h"

using namespace std;

class TextDisplay : public Display {
   public:
    TextDisplay(Board *board) : Display{board} {}
    ~TextDisplay() = default;
    friend ostream &operator<<(ostream&, const TextDisplay&);
    void showBoard() override;
    string getDownloaded(int) const;
    string getLinks(int) const;
};
