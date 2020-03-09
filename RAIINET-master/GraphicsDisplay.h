#pragma once

#include "Display.h"
#include "window.h"

class GraphicsDisplay : public Display {
   public:
    GraphicsDisplay(Board* board) : Display{board} {}
    ~GraphicsDisplay() = default;
    void showBoard();
};
