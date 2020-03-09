#pragma once

#include "board.h"

class Display {
	protected:
	Board* board;
public:
	Display(Board* board) : board{ board } {}
	virtual ~Display();
	virtual void showBoard() = 0;
	virtual Board* getBoard() const;
};