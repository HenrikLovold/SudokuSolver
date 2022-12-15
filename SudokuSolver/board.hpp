
#pragma once

#include "square.hpp"
#include "element.hpp"
#include <vector>

class Board {
public:
	Board(Square*** squares, unsigned int boardNumber);
	~Board();
	void printBoard();
	Square* getSquareAt(int x, int y);
	bool solve(int idx);
	bool hasSolution();
private:
	Square*** squares;
	unsigned int boardNumber;
	unsigned int nSolutionsFound;
	std::vector<Element>* elements;
	void generateElements();
};