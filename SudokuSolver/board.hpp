
#pragma once

#include "square.hpp"

class Board {
public:
	Board(Square*** squares);
	~Board();

	void printBoard();
private:
	Square*** squares;
};