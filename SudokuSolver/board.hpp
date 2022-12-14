
#pragma once

#include "square.hpp"
#include "element.hpp"
#include <vector>

class Board {
public:
	Board(Square*** squares);
	~Board();
	void printBoard();
	Square* getSquareAt(int x, int y);
private:
	Square*** squares;
	std::vector<Element>* elements;
	void generateElements();
};