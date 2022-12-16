//
//  element.cpp
//  SudokuSolver
//
//  Created by Henrik Hillestad Løvold on 11/12/2022.
//

#include "element.hpp"
#include "square.hpp"
#include <iostream>
#include <string>

Element::Element(Square** squares) {
	this->squares = squares;
	this->setSquareOwnership();
}

Element::~Element() {
	delete this->squares;
}

Square** Element::getSquares()
{
	return this->squares;
}

void Element::printValues() {
	for (int i = 0; i < 9; i++) {
		std::cout << this->squares[i]->getNumber() << std::endl;
	}
}

bool Element::checkValid(int num) {
	for (int i = 0; i < 9; i++) {
		if (this->squares[i]->getNumber() == num) {
			return false;
		}
	}
	return true;
}

void Element::setSquareOwnership() {
	for (int i = 0; i < 9; i++) {
		this->squares[i]->addElement(this);
	}
}
