
#pragma once

#include "square.hpp"
#include "element.hpp"
#include <vector>

class Board {
public:
	Board(Square*** squares);
	~Board();
	void printBoard();
private:
	Square*** squares;
	std::vector<Element>* elements;
	void generateElements();
};