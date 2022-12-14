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

void Element::setSquareOwnership() {
	std::cout << "adding element" << std::endl;
	for (int i = 0; i < 9; i++) {
		this->squares[i]->addElement(*this);
	}
}
